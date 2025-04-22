/*
 * Written by 3tawi
- Lien vidéo: https://youtu.be/zPvuzV2fqaA
*/

#ifndef Setting_H
#define Setting_H

//including the needed header
#include <ESP32VGA3Bit.h>
#include <GP_GFX.h>
#include <VGAWrapper.h>
#include <GPfonts/atawi8x6.h>
#include <GPfonts/fontclock.h>
#include <GPfonts/fontclock1.h>
#include "GpTime.h"


GpTime rtc;
VGA3BitI vga;
VGAWrapper<VGA3BitI> gfx(vga, 639, 399);

//vga pin configuration
const int redPin = 14;
const int greenPin = 19;
const int bluePin = 27;
const int hsyncPin = 32;
const int vsyncPin = 33;

#define DataBand    0xE0
#define DataTime    0xE1
#define DataMesg    0xE2
#define DataStting  0xE3
#define DataCommand 0xE4


const int numBands = 16;
uint8_t valBand[numBands];
uint8_t ColorFreq[numBands];
uint8_t coltmp = 0, colth = 4;
uint8_t hue = 0, cl = 0, cl0 = 0, cl1 = 0;
uint8_t RTCm = 60, RTCs = 60;
int sp0 = 6, sp1 = 40, sp2 = 30, rta = 0;
bool ModeClMu = true;
bool Mode24h = true;
bool Modedot = false, ModeSmv = true;
bool flasher = false, Minflasher = false;
float Temp = NAN, Humi = NAN;
int xthm0, xh0, xs0;
int xmesg = 0, mesg = 4;
int CCi = 0, MCi = 13;
int Cis = 0, Cia = 0;

String textmsg, textip, tmz_str;
String Messgdate, Messgtmhu;
String Message = "Great Projects wish you a very nice day.";
const uint16_t Myblack = 0;
const uint16_t Mycolor[7] = {0xF800, 0xFFE0, 0x07E0, 0x07FF, 0x001F, 0xF81F, 0xFFFF};

class Setting {
  private:
    #define EndCommand 0xA4
    #define C_X 319
    #define C_Y 199
    int sth0[26] ={5, 5, 5, 5, 5, 7, 7, 6, 7, 7, 6, 6, 6,  6, 6, 0, 0, 6, 6, 0, 0, 5, 0, 0, 4, 0};
    int sth1[26] ={2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,  3, 3, 0, 0, 3, 3, 0, 0, 2, 0, 0, 2, 0};
    int sith[26] ={639, 639, 639, 639, 639, 639, 639, 550, 550, 550, 550, 550, 550,  639, 639, 0, 0, 639, 639, 0, 0, 639, 0, 0, 639, 0};

  public:

    void Setup(int mod) {
      xthm0 = getxCurtmhu(mod);
      xh0 = getxCur(rtc.getflashHrMn(), 14);
      xs0 = getxCur(rtc.getSTime("%S"), 4);
    }

    void SendCommand(uint8_t comd) {
      Serial.write(DataCommand);
      Serial.write(comd);
      Serial.write(EndCommand);
      delay(2);
     }
    void write(const char *buffer, size_t size) {
      while (size--)
        gfx.getwidth(*buffer++);
    }
    void print(const float vai) {
      String s = String(vai);
      write(s.c_str(), s.length());
    }
    void print(const String &s) {
      write(s.c_str(), s.length());
    }

    void drawdrapo(int level, int level1, int Line, int dw, int wl, float rx) {
      float degreesPerLine = 360/Line;
      float angle = degreesPerLine * Line;
      gfx.fillEllipse(C_X, C_Y, level1 * rx, level1, Mycolor[0]);
      gfx.ellipse(C_X, C_Y, level1 * rx, level1, Myblack);
      for(int x=0; x<Line; x++) {
        float radians = radians(angle-dw);
        int x0 = C_X + level * rx * sin(radians);
        int y0 = C_Y - level * cos(radians);
        radians = radians(angle+dw);
        int x1 = C_X + level * rx * sin(radians);
        int y1 = C_Y - level * cos(radians);
        radians = radians(angle + dw + degreesPerLine*wl);
        int x2 = C_X + level * rx * sin(radians);
        int y2 = C_Y - level * cos(radians);
        radians = radians(angle - dw + degreesPerLine*wl);
        int x3 = C_X + level * rx * sin(radians);
        int y3 = C_Y - level * cos(radians);
        gfx.fillCare(x1, y1, x0, y0, x2, y2, x3, y3, Mycolor[2]);
        gfx.DrawCare(x1, y1, x0, y0, x2, y2, x3, y3, Mycolor[0]);
        angle += degreesPerLine;
      }
    }

    int16_t getxCur(String txt, int sx) {
      gfx.setFont(&atawi8x6);
      gfx.setTextSize(sx, 1);
      gfx.setCursor(0, 0);
      print(txt);
  	return (gfx.width() - gfx.getCursorX() + 2) / 2;
    }
  int16_t getxCurtmhu(int mod) {
    int sx0 = sth0[mod];
    int sx1 = sth1[mod];
    int sx2 = sith[mod];
    gfx.setFont(&atawi8x6);
    gfx.setTextSize(sx0, 1);
    gfx.setCursor(0, 0);
    print(Temp);
    gfx.setTextSize(sx1, 1);
    print("°C");
    gfx.setTextSize(sx0, 1);
    print("   ");
    print(Humi);
    gfx.setTextSize(sx1, 1);
    print("%");
	  return (sx2 - gfx.getCursorX()) / 2;
  }
  void setcolTemp() {
    if       (Temp<=16           )   coltmp = 4;
    else if  (Temp>16 && Temp<=21)   coltmp = 3;
    else if  (Temp>21 && Temp<=29)   coltmp = 2;
    else if  (Temp>29 && Temp<=35)   coltmp = 1;
    else if  (Temp>35            )   coltmp = 0;
  }
  void setcolHumi() {
    if       (Humi<=20           )   colth = 0;
    else if  (Humi>20 && Humi<=30)   colth = 1;
    else if  (Humi>30 && Humi<=60)   colth = 2;
    else if  (Humi>60 && Humi<=70)   colth = 3;
    else if  (Humi>70            )   colth = 4;
  }

  void Setmesgtext() {
    switch(mesg) {
    case 0:
        textmsg = Message;
        mesg++;
        break;
    case 1:
        textmsg = rtc.getSTime("%A - %d %B %Y");
        mesg++;
        break;
    case 2:
        textmsg = "Temperature : ";
        textmsg += Temp;
        textmsg += " °C";
        mesg++;
        break;
    case 3:
        textmsg = "Humidity : ";
        textmsg += Humi;
        textmsg += " %";
        mesg = 0;
        break;
    case 4:
        textmsg = textip;
        mesg = 0;
        break;
    }
  } 


};

#endif
