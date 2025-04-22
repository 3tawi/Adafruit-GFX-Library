/*
 - ESP32_C3_Super_Mini
 * Written by 3tawi
 * Lien vidéo: https://youtu.be/zPvuzV2fqaA
 * library which can be found at  
    * https://github.com/3tawi/ESP32VGA3Bit
    * https://github.com/3tawi/GP_GFX
    * https://github.com/3tawi/EspDHT
    * https://github.com/Arduino-IRremote/Arduino-IRremote
    * https://github.com/kosme/arduinoFFT
 * Find All "Great Projects" Videos : https://www.youtube.com/c/GreatProjects
*/

#include "FonCommand.h"


FonCommand fonCom;

void(* resetFunc) (void) = 0;//declare reset function at address 0


void handleRoot() {
  server.send(200, "text/html", Main_Page);
}
void handlentpTime() {
  handleRoot();
  fonCom.GetntpDTime();
}
void handlezoneTime() {
  handleRoot();
  Tz = server.arg("locatz").toInt(); 
  Tdz = server.arg("locadz").toInt();
  if (Tz > 0 && Tdz < 0) {
    Tz -=1;
    Tdz +=60;
  }
  if (Tz < 0 && Tdz > 0) {
    Tz +=1;
    Tdz -=60;
  }
  fonCom.SendTime();
  configTime((Tz * 3600), (Tdz * 60), "", "");
  tmz_str = fonCom.settztstr(Tz, Tdz);
  fonCom.SendStting("mytimstz=", tmz_str);
  fonCom.SendCommand(0xF7);
  Serial.print("Zone Time Update : ");
  Serial.println(tmz_str);
  fonCom.printLocalTime();
  fonCom.Savestting0();
}
void handlelocaltime() { 
  handleRoot();
  rtc.setTime(server.arg("locadt").toInt()); 
  fonCom.SendTime();
  fonCom.SendCommand(0xF9);
  fonCom.printLocalTime();
  Serial.println("Local Time Update");
  fonCom.writeTime();
}
void handleMyTime() { 
  handleRoot();
  int hh = server.arg("htmie").toInt();
  int mm = server.arg("mtmie").toInt();
  int ss = server.arg("stmie").toInt();
  int dd = server.arg("ddate").toInt();
  int mo = server.arg("mdate").toInt();
  int yr = server.arg("ydate").toInt();
  rtc.setTime(ss, mm, hh, dd, mo, yr);
  fonCom.writeTime();
  fonCom.SendTime();
  fonCom.SendCommand(0xB1);
  fonCom.printLocalTime();
  Serial.println("Manually Time Update");
}
void handleSpe0() {
  handleRoot();
  sp0 = server.arg("Speed0").toInt();
  fonCom.SendStting("speed0=", sp0);
  fonCom.Savestting2();
}
void handleSpe1() {
  handleRoot();
  sp1 = server.arg("Speed1").toInt();
  fonCom.SendStting("speed1=", sp1);
  fonCom.Savestting2();
}
void handleSpe2() {
  handleRoot();
  sp2 = server.arg("Speed2").toInt();
  fonCom.SendStting("speed2=", sp2);
  fonCom.Savestting2();
}
void handleSpe3() {
  handleRoot();
  sp3 = server.arg("Speed3").toInt();
  fonCom.Savestting2();
}
void handleSpe4() {
  handleRoot();
  sp4 = server.arg("Speed4").toInt();
  fonCom.Savestting2();
}
void handleSpe5() {
  handleRoot();
  sp5 = server.arg("Speed5").toInt();
  fonCom.Savestting2();
}
void handleSpe6() {
  handleRoot();
  sp6 = server.arg("Speed6").toInt();
  if (ModeClAuto) SettickerCl();
  fonCom.Savestting2();
}
void handleSpe7() {
  handleRoot();
  sp7 = server.arg("Speed7").toInt();
  if (ModeClMu && ModeMcAuto) SettickerMc();
  fonCom.Savestting2();
}
void handlerotation() {
  handleRoot();
  fonCom.SetCommand(0xF);
}
void handleMesg() {
  handleRoot();
  Message = server.arg("Message");
  fonCom.SendMesg();
  fonCom.Savestting0();
}
void handleSMV() {
  handleRoot();
  fonCom.SetCommand(0xA);
}
void handleDot() {
  handleRoot();
  fonCom.SetCommand(0x18);
}
void handleModeClMc() {
  handleRoot();
  fonCom.SetCommand(0x1E);
}
void handleModeNexcl() {
  handleRoot();
  fonCom.SendCommand(0xF2);
}
void handleModePrecl() {
  handleRoot();
  fonCom.SendCommand(0xF3);
}
void handleModeNexmc() {
  handleRoot();
  fonCom.SetCommand(0x45);
}
void handleModePremc() {
  handleRoot();
  fonCom.SetCommand(0x49);
}
void handleModeNexsc() {
  handleRoot();
  fonCom.SetCommand(0x17);
}
void handleModePresc() {
  handleRoot();
  fonCom.SetCommand(0x1C);
}
void handleModeClAuto() {
  handleRoot();
  SetCommand(0x10);
}
void handleModeMcAuto() {
  handleRoot();
  SetCommand(0x41);
}
void handleMode24h() {
  handleRoot();
  fonCom.SetCommand(0x1F);
}
void handleWifi() { 
  handleRoot(); 
  Ssid = server.arg("usname");
  Pass = server.arg("pssw");
  fonCom.getWifi();
  fonCom.SendStting("myipadd=", textip);
  fonCom.SendCommand(0xF5);
  fonCom.Savewifi();
}
void handlesendate() { 
  handleRoot(); 
  datetxt = server.arg("daydate");
  datee = "/Temhumi/";
  datee += datetxt;
  datee += ".txt";
}
void getxtdate() {
  datetxt = rtc.getSTime("%F");
  datee = "/Temhumi/";
  datee += datetxt;
  datee += ".txt";
}
void handletxt() {
  if(datetxt=="") getxtdate();
  File fdate = SD.open(datee);
  if (fdate) {
    size_t sent = server.streamFile(fdate, "text/plain");
  } else {
    server.send(200, "text/plain", "file not fond");
  }
  fdate.close();
}
void handleRestesp() {  
  handleRoot();
  fonCom.SetCommand(0xB);
}

void NTPtimeavailable(struct timeval *t) {
  fonCom.SendCommand(0xB2);
  fonCom.SendTime();
  fonCom.writeTime();
  Serial.println("Got time adjustment from NTP!");
  fonCom.printLocalTime();
}
  void changclock() {
    fonCom.SendCommand(0xF2);
  }
  void changmusic() {
    fonCom.SetCommand(0x45);
  }
  
  void SettickerCl() {
    if (ModeClAuto) clauto.attach(sp6, changclock);
    else clauto.detach();
  }
  void SettickerMc() {
    if (ModeClMu && ModeMcAuto) mcauto.attach(sp7, changmusic);
    else mcauto.detach();
  }
  void SetCommand(uint8_t Comd) {
    switch(Comd) {
      case 0x10:
        ModeClAuto = !ModeClAuto;
        SettickerCl();
        fonCom.Savestting1();
        break;
      case 0x41:
        ModeMcAuto = !ModeMcAuto;
        SettickerMc();
        fonCom.Savestting1();
        break;
      default:
        fonCom.SetCommand(Comd);
        break;
    }
  }
  void setModemuclk() {
    if (ModeClAuto) SettickerCl();
    if (ModeClMu && ModeMcAuto) SettickerMc();
  }

void read_DHT() {
  dht.readSensor();
  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();
  if (!isnan(temperature) && !isnan(humidity)) {
    if (Temp != temperature || Humi != humidity) {
      fonCom.SendStting("mytemp=", temperature);
      fonCom.SendStting("myhumi=", humidity);
      Temp = temperature;
      Humi = humidity;
      fonCom.wirttemphu();
    }
  }
}

void SendFrame() {
  Serial0.write(DataBand);
  Serial0.write((uint8_t *)bValues, numBands);
  Serial0.write(EndBand);
}

void setup() {
  Serial.begin(115200);
  Serial0.begin(1500000, SERIAL_8E2);
  delay(2000);
  rtc.DSbegin();
  if(!SPIFFS.begin(true)){
    Serial.println("SPIFFS Mount Failed");
  } 
  if(!SD.begin(SS)){
    Serial.println("Card Mount Failed");
  }
  fonCom.Setup();
  sntp_set_time_sync_notification_cb(NTPtimeavailable);
  server.on("/", handleRoot); 
  server.on("/ntptime", handlentpTime); 
  server.on("/mytimezon", handlezoneTime); 
  server.on("/localdatime", handlelocaltime);
  server.on("/mydtime", handleMyTime);
  server.on("/readstt0", handlestt0);
  server.on("/readstt1", handlestt1);  
  server.on("/readstt2", handlestt2);
  server.on("/readstt3", handlestt3);
  server.on("/mySpeed0", handleSpe0);
  server.on("/mySpeed1", handleSpe1);
  server.on("/mySpeed2", handleSpe2);
  server.on("/mySpeed3", handleSpe3);
  server.on("/mySpeed4", handleSpe4);
  server.on("/mySpeed5", handleSpe5);
  server.on("/mySpeed6", handleSpe6);
  server.on("/mySpeed7", handleSpe7);
  server.on("/mymessg", handleMesg);
  server.on("/modedot", handleDot);
  server.on("/modesmv", handleSMV);
  server.on("/mode24h", handleMode24h);
  server.on("/rotation", handlerotation);
  server.on("/modeclmc", handleModeClMc);
  server.on("/modeautocl", handleModeClAuto);
  server.on("/modeautomc", handleModeMcAuto);
  server.on("/modenexcl", handleModeNexcl);
  server.on("/modeprecl", handleModePrecl);
  server.on("/modenexmc", handleModeNexmc);
  server.on("/modepremc", handleModePremc);
  server.on("/modenexsc", handleModeNexsc);
  server.on("/modepresc", handleModePresc);
  server.on("/Mywifi", handleWifi);
  server.on("/sendate", handlesendate);
  server.on("/readtext", handletxt);
  server.on("/restesp", handleRestesp);
  server.begin();
  Serial.println(" Ok ");
  Serial0.onReceive(onReceiveFunction, true); 
  ticker.attach(30, read_DHT);
  setModemuclk();
  read_DHT();
  delay(2000);
}

void loop() {
  newTime = millis();
  fonCom.readAudio();
  server.handleClient();
  irReceive();
  while ((millis() - newTime) < 3) { /* do nothing to wait */ }
}

void onReceiveFunction(void) {
  delay(2);
  while (Serial0.available())  {
    switch (Serial0.peek()) {
      case DataStting :
        fonCom.RedStting();
        break;
      case DataCommand :
        fonCom.ReadComand();
        break;
      default:
        Serial0.read();
        break;
    }
  }
}

void irReceive() {
  if (IrReceiver.decode()) {
    uint16_t received = IrReceiver.decodedIRData.command;
    if (received) {
      Serial.print("Command: 0x");
      Serial.println(received, HEX);
      SetCommand(received);
      delay(250);
    }
  }
  IrReceiver.resume();
}
void handlestt0() {
  String content = "<?xml version = \"1.0\" ?>";
  content += "<inputs><analog>";
  content += tmz_str;
  content += "</analog><analog>";
  content += Tz;
  content += "</analog><analog>";
  content += Tdz;
  content += "</analog><analog>";
  content += sp0;
  content += "</analog><analog>";
  content += sp1;
  content += "</analog><analog>";
  content += sp2;
  content += "</analog><analog>";
  content += sp3;
  content += "</analog><analog>";
  content += sp4;
  content += "</analog><analog>";
  content += sp5;
  content += "</analog><analog>";
  content += sp6;
  content += "</analog><analog>";
  content += sp7;
  content += "</analog></inputs>";
  server.sendHeader("Cache-Control", "no-cache");
  server.send(200, "text/xml", content); //Send web page
}
void handlestt1() {
  String content = "<?xml version = \"1.0\" ?>";
  content += "<inputs><analog>";
  content += Temp;
  content += "</analog><analog>";
  content += Humi;
  content += "</analog></inputs>";
  server.sendHeader("Cache-Control", "no-cache");
  server.send(200, "text/xml", content); //Send web page
}
void handlestt2() {
  onReceiveFunction();
  int cival = (ModeClMu) ? (MCi - 12) : (CCi + 1);
  String content = "<?xml version = \"1.0\" ?>";
  content += "<inputs><analog>";
  content += ModeClMu;
  content += "</analog><analog>";
  content += ModeClAuto;
  content += "</analog><analog>";
  content += ModeMcAuto;
  content += "</analog><analog>";
  content += cival;
  content += "</analog><analog>";
  content += Cia + 1;
  content += "</analog><analog>";
  content += Cis + 1;
  content += "</analog><analog>";
  content += Mode24h;
  content += "</analog><analog>";
  content += Modedot;
  content += "</analog><analog>";
  content += ModeSmv;
  content += "</analog></inputs>";
  server.sendHeader("Cache-Control", "no-cache");
  server.send(200, "text/xml", content); //Send web page
}
void handlestt3() {
  String content = "<?xml version = \"1.0\" ?>";
  content += "<inputs><analog>";
  content += datetxt;
  content += "</analog></inputs>";
  server.sendHeader("Cache-Control", "no-cache");
  server.send(200, "text/xml", content); //Send web page
}