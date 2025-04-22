/* 
 * Written by 3tawi
 * Lien vidéo: https://youtu.be/zPvuzV2fqaA
*/
 

#ifndef FonCommand_H
#define FonCommand_H

#define DECODE_NEC
#include <Arduino.h>
#include <driver/i2s.h>
#include <WiFi.h>
#include <WebServer.h>
#include "GpTime.h"
#include "sntp.h"
#include "SD.h"
#include "SPIFFS.h"
#include "EspDHT.h"
#include <IRremote.hpp>
#include "arduinoFFT.h"
#include <Ticker.h>
#include "index.h"

#define Mic_SCK 0
#define Mic_WS 1
#define Mic_SD 2

#define I2S_PORT I2S_NUM_0
#define SAMPLEBLOCK 512
#define SAMPLING_FREQ   44000
const int numBands = 16;
float vReal[SAMPLEBLOCK];
float vImag[SAMPLEBLOCK];
int16_t sBuffer[SAMPLEBLOCK];
int bandValues[numBands];
uint8_t bValues[(numBands+1)];

/* Create FFT object with weighing factor storage */
ArduinoFFT<float> FFT = ArduinoFFT<float>(vReal, vImag, SAMPLEBLOCK, SAMPLING_FREQ, false);
 
WebServer server(80);
GpTime rtc;
EspDHT dht;
Ticker ticker;
Ticker clauto;
Ticker mcauto;

const char* ntpServer1 = "pool.ntp.org";
const char* ntpServer2 = "time.nist.gov";

unsigned long newTime;
String tmz_str = "GMT +00:00";
int rta = 0, Tz = 1, Tdz = 0;
int sp0 = 10, sp1 = 14, sp2 = 7, sp3 = 210;
int sp4 = 50, sp5 = 80, sp6 = 12, sp7 = 12;
int CCi = 0, MCi = 9, Cis = 2, Cia = 0;
float Temp, Humi;
String textip;
String datetxt, datee, ddate;
String Message = "Great Projects wish you a very nice day.";
String  Ssid = "Your-Ssid", Pass = "Your-Password";
bool ModeClMu = false, Mode24h = true;
bool ModeClAuto = false, ModeMcAuto = false;
bool Modedot = false, ModeSmv = true;
long hue;


#define DataCommand 0xE4
#define DataStting  0xE3

class FonCommand {
  protected: 

  private:
    #define DataBand    0xE0
    #define DataTime    0xE1
    #define DataMesg    0xE2
    #define EndBand     0xA0
    #define EndTime     0xA1
    #define EndMesg     0xA2
    #define EndStting   0xA3
    #define EndCommand  0xA4
    const char* Apssid = "Esp32_C3";
    const char* Appassword = "3tawi-GP";

  public:
    bool wifiok = false;

    void Setup() {
      updateTime();
      readStting("/datasting0.txt");
      readStting("/datasting1.txt");
      readStting("/datasting2.txt");
      readStting("/datawifi.txt");
      getWifi();
      prepacard();
      IrReceiver.begin(3); // data pin 3
      dht.setup(10, EspDHT::DHT22);    // data pin 10  DHT22
      // dht.setup(10, EspDHT::DHT11); // data pin 10  DHT11
      Serial.println("Setup I2S ...");
      delay(1000);
      i2s_install();
      i2s_start(I2S_PORT);
      delay(500);
    }
    void i2s_install(){
      const i2s_config_t i2s_config = {
      .mode = i2s_mode_t(I2S_MODE_MASTER | I2S_MODE_RX),
     .sample_rate = 10000,
      .bits_per_sample = i2s_bits_per_sample_t(16),
      .channel_format = I2S_CHANNEL_FMT_ALL_RIGHT,
      .communication_format = i2s_comm_format_t(I2S_COMM_FORMAT_I2S),
      .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1, // default interrupt priority
      .dma_buf_count = 8,
      .dma_buf_len = SAMPLEBLOCK,
      .use_apll = false,
      .tx_desc_auto_clear = false,
      .fixed_mclk = 0
    };

    const i2s_pin_config_t pin_config = {
      .bck_io_num = Mic_SCK,
      .ws_io_num = Mic_WS,
      .data_out_num = -1,
      .data_in_num = Mic_SD
    };

    i2s_driver_install(I2S_PORT, &i2s_config, 0, NULL);
    i2s_set_pin(I2S_PORT, &pin_config);
    i2s_set_clk(I2S_PORT, 10000, I2S_BITS_PER_SAMPLE_16BIT, I2S_CHANNEL_MONO);
  }


  void prepacard() { 
    File root = SD.open("/Temhumi");
    if(!root.isDirectory()){
        SD.mkdir("/Temhumi");
    }
  }
  void getWifi() {
    WiFi.mode(WIFI_STA);
    int lengthSsid = Ssid.length();
    int lengthPass = Pass.length();
    char user[lengthSsid], pasw[lengthPass];
    Ssid.toCharArray(user, lengthSsid+1);
    Pass.toCharArray(pasw, lengthPass+1);
    //WiFi.config(ip, gateway, subnet);
    WiFi.begin(user, pasw);
    int xc = 0;
    while (WiFi.status() != WL_CONNECTED && xc < 10) {
    delay(500);
    xc++;
    }
    if (WiFi.status() == WL_CONNECTED) { 
      textip = "CONNECTED To : 3tawi IP Address : http://";
      textip += WiFi.localIP().toString().c_str(); 
      Serial.print(textip);
      //WiFi.softAPdisconnect(true);
      wifiok = true;
    } else { 
    getAPWifi();
    wifiok = false;
    }
  }
  void getAPWifi() {
    WiFi.mode(WIFI_AP);
    //WiFi.softAPConfig(ip, gatewayap, subnet);
    WiFi.softAP(Apssid, Appassword);
    textip = "Local Wifi : ";
    textip += Apssid;
    textip += " IP Address : http://";
    textip += WiFi.softAPIP().toString().c_str();
    Serial.print(textip);
  }

  void RedStting() {
    if (Serial0.read() != DataStting)
      return;
    String Line = Serial0.readStringUntil('\n');
    if (Serial0.read() != EndStting)
      return;
    readLine(Line);
  }
  void ReadComand() {
    if (Serial0.read() != DataCommand)
      return;
    uint8_t Comd = Serial0.read();
    if (Serial0.read() != EndCommand)
      return;
    SetCommand(Comd);
  }

  void SendMesg() {
    Serial0.write(DataMesg);
    Serial0.println(Message);
    Serial0.write(EndMesg);
    delay(2);
  }
  void SendTime() {
    long timezon = (Tz * 3600) + (Tdz * 60);
    Serial0.write(DataTime);
    Serial0.println(timezon + rtc.getEpoch());
    Serial0.write(EndTime);
    delay(2);
  }
  void SendStting(String sendtex, int seval) {
    String strtex  =  sendtex;
           strtex +=  seval;
    Serial0.write(DataStting);
    Serial0.println(strtex);
    Serial0.write(EndStting);
    delay(2);
  }
  void SendStting(String sendtex, float seval) {
    String strtex  =  sendtex;
           strtex +=  seval;
    Serial0.write(DataStting);
    Serial0.println(strtex);
    Serial0.write(EndStting);
    delay(2);
  }
  void SendStting(String sendtex, String seval) {
    String strtex  =  sendtex;
           strtex +=  seval;
    Serial0.write(DataStting);
    Serial0.println(strtex);
    Serial0.write(EndStting);
    delay(2);
  }
  void SendCommand(uint8_t cod) {
    Serial0.write(DataCommand);
    Serial0.write(cod);
    Serial0.write(EndCommand);
    delay(2);
  }

  void SetCommand(uint8_t Comd) {
    switch(Comd) {
      case 0x1E:
        ModeClMu = !ModeClMu;
        SendStting("modeclmu=", ModeClMu);
        Savestting1();
        break;
      case 0xD:
        SendCommand(0xF2);
        break;
      case 0x46:
        SendCommand(0xF3);
        break;
      case 0x18:
        Modedot = !Modedot;
        SendStting("modedot=", Modedot);
        Savestting1();
        break;
      case 0xA:
        ModeSmv = !ModeSmv;
        SendStting("smvindex=", ModeSmv);
        Savestting1();
        break;
      case 0x45:
        Cia++;
        if (Cia>127) Cia = 0;
        SendStting("caindex=", Cia);
        Savestting1();
        break;
      case 0x49:
        Cia--;
        if (Cia<0) Cia = 127;
        SendStting("caindex=", Cia);
        Savestting1();
        break;
      case 0x17:
        Cis++;
        if (Cis>15) Cis = 0;
        SendStting("csindex=", Cis);
        Savestting1();
        break;
      case 0x1C:
        Cis--;
        if (Cis<0) Cis = 15;
        SendStting("csindex=", Cis);
        Savestting1();
        break;
      case 0xF:
        rta = (rta == 0) ? 2 : 0;
        SendStting("rotation=", rta);
        Savestting0();
        break;
      case 0x1F:
        Mode24h = !Mode24h;
        SendStting("m24h=", Mode24h);
        Savestting0();
        break;
      case 0x11:
        sp0--;
        if (sp0<1) sp0 = 1;
        SendStting("speed0=", sp0);
        Savestting2();
        break;
      case 0xC:
        sp0++;
        if (sp0>30) sp0 = 30;
        SendStting("speed0=", sp0);
        Savestting2();
        break;
      case 0x4C:
        sp1--;
        if (sp1<1) sp1 = 1;
        SendStting("speed1=", sp1);
        Savestting2();
        break;
      case 0x57:
        sp1++;
        if (sp1>50) sp0 = 50;
        SendStting("speed1=", sp1);
        Savestting2();
        break;
      case 0x58:
        sp2--;
        if (sp2<1) sp2 = 1;
        SendStting("speed2=", sp2);
        Savestting2();
        break;
      case 0x55:
        sp2++;
        if (sp2>50) sp2 = 50;
        SendStting("speed2=", sp2);
        Savestting2();
        break;
      case 0x4B:
        GetntpDTime();
        break;
      case 0x5F:
        SendallStting();
        break;
      case 0xB:
        SendCommand(0xF1);
        delay(2000);  
        ESP.restart();
        break;
      default:
        SendCommand(Comd);
        break;
    }
  }

  void readLine(String Line) {
    if (Line.startsWith("rotation=")) {
      Line = Line.substring(9);
      if (Line.length() > 0) {
        rta = Line.toInt();
      }
    }
    else if (Line.startsWith("mytimz=")) {
      Line = Line.substring(7);
      if (Line.length() > 0) {
        Tz = Line.toInt();
      }
    }
    else if (Line.startsWith("mytimdz=")) {
      Line = Line.substring(8);
      if (Line.length() > 0) {
        Tdz = Line.toInt();
      }
    }
    else if (Line.startsWith("mytimstz=")) {
      Line = Line.substring(9);
      if (Line.length() > 0) {
        tmz_str = Line;
      }
    }
    else if (Line.startsWith("mymsge=")) {
      Line = Line.substring(7);
      if (Line.length() > 0) {
        Message = Line;
      }
    }
    else if (Line.startsWith("m24h=")) {
      Line = Line.substring(5);
      if (Line.length() > 0) {
      Mode24h = Line.toInt();
      }
    }
    else if (Line.startsWith("modeclmu=")) {
      Line = Line.substring(9);
      if (Line.length() > 0) {
        ModeClMu = Line.toInt();
      }
    }
    else if (Line.startsWith("mcindex=")) {
      Line = Line.substring(8);
      if (Line.length() > 0) {
        MCi = Line.toInt();
      }
    }
    else if (Line.startsWith("ccindex=")) {
      Line = Line.substring(8);
      if (Line.length() > 0) {
        CCi = Line.toInt();
      }
    }
    else if (Line.startsWith("csindex=")) {
      Line = Line.substring(8);
      if (Line.length() > 0) {
        Cis = Line.toInt();
      }
    }
    else if (Line.startsWith("caindex=")) {
      Line = Line.substring(8);
      if (Line.length() > 0) {
        Cia = Line.toInt();
      }
    }
    else if (Line.startsWith("clauto=")) {
      Line = Line.substring(7);
      if (Line.length() > 0) {
        ModeClAuto = Line.toInt();
      }
    }
    else if (Line.startsWith("muauto=")) {
      Line = Line.substring(7);
      if (Line.length() > 0) {
        ModeMcAuto = Line.toInt();
      }
    }
    else if (Line.startsWith("modedot=")) {
      Line = Line.substring(8);
      if (Line.length() > 0) {
        Modedot = Line.toInt();
      }
    }
    else if (Line.startsWith("smvindex=")) {
      Line = Line.substring(9);
      if (Line.length() > 0) {
        ModeSmv = Line.toInt();
      }
    }
    else if (Line.startsWith("speed0=")) {
      Line = Line.substring(7);
      if (Line.length() > 0) {
       sp0 = Line.toInt();
      }
    }
    else if (Line.startsWith("speed1=")) {
      Line = Line.substring(7);
      if (Line.length() > 0) {
        sp1 = Line.toInt();
      }
    }
    else if (Line.startsWith("speed2=")) {
      Line = Line.substring(7);
      if (Line.length() > 0) {
        sp2 = Line.toInt();
      }
    }
    else if (Line.startsWith("speed3=")) {
      Line = Line.substring(7);
      if (Line.length() > 0) {
        sp3 = Line.toInt();
      }
    }
    else if (Line.startsWith("speed4=")) {
      Line = Line.substring(7);
      if (Line.length() > 0) {
        sp4 = Line.toInt();
      }
    }
    else if (Line.startsWith("speed5=")) {
      Line = Line.substring(7);
      if (Line.length() > 0) {
        sp5 = Line.toInt();
      }
    }
    else if (Line.startsWith("speed6=")) {
      Line = Line.substring(7);
      if (Line.length() > 0) {
        sp6 = Line.toInt();
      }
    }
    else if (Line.startsWith("speed7=")) {
      Line = Line.substring(7);
      if (Line.length() > 0) {
        sp7 = Line.toInt();
      }
    }
    else if (Line.startsWith("Ssid=")) {
      Line = Line.substring(5);
      if (Line.length() > 0) {
        Ssid = Line;
      }
    }
    else if (Line.startsWith("Pass=")) {
      Line = Line.substring(5);
      if (Line.length() > 0) {
        Pass = Line;
      }
    }
  }

  void printLocalTime() {
    rtc.readTime();
    Serial.println(rtc.getSTime("%A, %B %d %Y %H:%M:%S"));
  }
  String settztstr(int Tz, int Tdz) {
    String tz_str;
    int tza = abs(Tz);
    int tdza = abs(Tdz);
    if (Tz < 0 || Tdz < 0) tz_str = "GMT -";
    else tz_str = "GMT +";
    if (tza>9) tz_str += tza;
    else {
      tz_str += "0";
      tz_str += tza;
    } 
    tz_str += ":";
    if (tdza>9) tz_str += tdza;
    else {
      tz_str += "0";
      tz_str += tdza;
    } 
	  return tz_str;
  }
  void GetntpDTime() {
    SendCommand(0xF8);
    printLocalTime();
    configTime(Tz * 3600, Tdz * 60, ntpServer1, ntpServer2);
    Serial.println("get Time from NTP......");
  }
  void updateTime() {
    configTime((Tz * 3600), (Tdz * 60), "", "");
    rtc.settimefromDS();
  }
  void writeTime() {
    rtc.DSsetTime();
  }
  void wirttemphu() {
    rtc.readTime();
    String path = "/Temhumi/";
         path += rtc.getSTime("%F");
         path += ".txt";
    String mesgtoapp  = rtc.getTime();
           mesgtoapp += "  Temperature : ";
           mesgtoapp += Temp;
           mesgtoapp += " °C  Humidity : ";
           mesgtoapp += Humi;
           mesgtoapp += " %";
    writeFileSD(path, mesgtoapp);
  }
  void writeFileSD(const String path, const String mesgtoapp){
    File file = SD.open(path, FILE_APPEND);
    if(!file){
      Serial.println("Failed to open file for appending");
      return;
    }
    if(file.println(mesgtoapp)){
      Serial.println("Message appended");
    } else {
      Serial.println("Append failed");
    }
    file.close();
  }
  void Savewifi() {
    File file = SPIFFS.open("/datawifi.txt", FILE_WRITE);
    if (file) {
      String textw  = "Ssid=";
             textw += Ssid;
             textw += "\nPass=";
             textw += Pass;
             textw += "\n";
      file.print(textw);
    }
    file.close();
  }
  void readStting(String datastting) {
    File file = SPIFFS.open(datastting);
    if(file) {
      String line = "";
      while (file.available()) {
        int savednum = file.read();
        if ((char)savednum == '\n') {
          readLine(line);
          line = "";
        } else
          line += (char)savednum;
        }
    }
    file.close();
  }
  void Savestting0() {
    File file = SPIFFS.open("/datasting0.txt", FILE_WRITE);
    if (file) {
      String text =  "rotation=";
             text += rta;
             text += "\nmytimz=";
             text += Tz;
             text += "\nmytimdz=";
             text += Tdz;
             text += "\nmytimstz=";
             text += tmz_str;
             text += "\nm24h=";
             text += Mode24h;
             text += "\nmymsge=";
             text += Message;
             text += "\n";
      file.print(text);
    }
    file.close();
  }
  void Savestting1() {
    File file = SPIFFS.open("/datasting1.txt", FILE_WRITE);
    if (file) {
      String text =  "clauto=";
            text += ModeClAuto;
            text += "\nmuauto=";
            text += ModeMcAuto;
            text += "\nccindex=";
            text += CCi;
            text += "\nmcindex=";
            text += MCi;
            text += "\ncaindex=";
            text += Cia;
            text += "\ncsindex=";
            text += Cis;
            text += "\nmodedot=";
            text += Modedot;
            text += "\nmodeclmu=";
            text += ModeClMu;
            text += "\nsmvindex=";
            text += ModeSmv;
            text += "\n";
      file.print(text);
    }
    file.close();
  }
  void Savestting2() {
    File file = SPIFFS.open("/datasting2.txt", FILE_WRITE);
    if (file) {
      String text =  "speed0=";
             text += sp0;
             text += "\nspeed1=";
             text += sp1;
             text += "\nspeed2=";
             text += sp2;
             text += "\nspeed3=";
             text += sp3;
             text += "\nspeed4=";
             text += sp4;
             text += "\nspeed5=";
             text += sp5;
             text += "\nspeed6=";
             text += sp6;
             text += "\nspeed7=";
             text += sp7;
             text += "\n";
      file.print(text);
    }
    file.close();
  }
  void SendallStting() {
    SendStting("muauto=", ModeMcAuto);
    SendStting("clauto=", ModeClAuto);
    SendStting("smvindex=", ModeSmv);
    SendStting("modedot=", Modedot);
    SendStting("m24h=", Mode24h);
    SendStting("rotation=", rta);
    SendStting("ccindex=", CCi);
    SendStting("mcindex=", MCi);
    SendStting("modeclmu=", ModeClMu);
    SendStting("speed0=", sp0);
    SendStting("speed1=", sp1);
    SendStting("speed2=", sp2);
    SendStting("csindex=", Cis);
    SendStting("caindex=", Cia);
    SendStting("mymsge=", Message);
    SendStting("myipadd=", textip);
    SendTime();
    delay(500);
    SendCommand(0xF4);
  }
  void readAudio() {
    size_t bytesIn = 0;
    i2s_read(I2S_PORT, (void*)sBuffer, sizeof(int16_t) * SAMPLEBLOCK, &bytesIn, portMAX_DELAY);
    for (int i = 0; i < SAMPLEBLOCK; i++) {
      vReal[i] = sBuffer[i];
      vImag[i] = 0.0;
    }
  
    FFT.dcRemoval();
    FFT.windowing(FFTWindow::Hamming, FFTDirection::Forward);	/* Weigh data */
    FFT.compute(FFTDirection::Forward); /* Compute FFT */
    FFT.complexToMagnitude(); /* Compute magnitudes */
    int fftmajor = constrain(FFT.majorPeak(), 200, (sp5 * 100));
    if(fftmajor < sp3) return;
    for (int i = 2; i < (SAMPLEBLOCK/2); i++) {
      if (vReal[i] > sp4) {       
          //16 bands, 12kHz top band
               if (i<=2           ) bandValues[0]   += (int)vReal[i];
          else if (i>2   && i<=3  ) bandValues[1]   += (int)vReal[i];
          else if (i>3   && i<=5  ) bandValues[2]   += (int)vReal[i];
          else if (i>5   && i<=7  ) bandValues[3]   += (int)vReal[i];
          else if (i>7   && i<=9  ) bandValues[4]   += (int)vReal[i];
          else if (i>9   && i<=13 ) bandValues[5]   += (int)vReal[i];
          else if (i>13  && i<=18 ) bandValues[6]   += (int)vReal[i];
          else if (i>18  && i<=25 ) bandValues[7]   += (int)vReal[i];
          else if (i>25  && i<=36 ) bandValues[8]   += (int)vReal[i];
          else if (i>36  && i<=50 ) bandValues[9]   += (int)vReal[i];
          else if (i>50  && i<=69 ) bandValues[10]  += (int)vReal[i];
          else if (i>69  && i<=94 ) bandValues[11]  += (int)vReal[i];
          else if (i>94  && i<=120) bandValues[12]  += (int)vReal[i];
          else if (i>120 && i<=155) bandValues[13]  += (int)vReal[i];
          else if (i>155 && i<=200) bandValues[14]  += (int)vReal[i];
          else if (i>200          ) bandValues[15]  += (int)vReal[i];
      }
    }

    bValues[numBands] = map(fftmajor, 200, (sp5 * 100), 0, 255);
    int maxValues = sp5 * 1000;
    for ( int i=0; i<numBands;i++)
      bandValues[i] = constrain(bandValues[i], 0, maxValues);

    for ( int i=0; i<numBands;i++) {
      bValues[i] = map(bandValues[i], 0, maxValues, 0, 255);
      bandValues[i] = 0;
    }
    Serial0.write(DataBand);
    Serial0.write(bValues, (numBands+1));
    Serial0.write(EndBand);
  }

};

#endif
