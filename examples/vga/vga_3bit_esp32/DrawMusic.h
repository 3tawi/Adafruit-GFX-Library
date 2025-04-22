/*
 * Written by 3tawi
- Lien vidéo: https://youtu.be/zPvuzV2fqaA
*/

#ifndef DrawMusic_H
#define DrawMusic_H

class DrawMusic {
  private:
  uint8_t col0, col1, col2;
  uint8_t Exdot[numBands];
  uint8_t valBand0[numBands];
  uint8_t valBand1[numBands];
  int ydot0 = 0;
  int ydot1 = 0;
  int level0 = 0;
  int level1 = 0;
  int nextLevel0 = 0;
  int nextLevel1 = 0;
  float angle = -90.00f;

  public:


  void Updatetime() {
    rtc.readTime();
    sec = rtc.getsecond();
    if ( RTCs != sec ) { 
      men = rtc.getminute();
      RTCs = sec;
    }
  }

  void ReadBandval0() {
    for (int i = 0; i < numBands; i++) {
    valBand0[i]  = (valBand0[i] < valBand[i]) ? valBand[i] : valBand0[i];
    valBand1[i]  = (valBand1[i] + valBand[i]) / 2;
    valBand[i] /= 2;
    }
  }
  void ReadBandval1() {
    for (int i = 0; i < numBands; i++) {
    valBand0[i]  = (valBand0[i] < valBand[15-i]) ? valBand[15-i] : valBand0[i];
    valBand1[i]  = (valBand1[i] + valBand[15-i]) / 2;
    valBand[15-i] /= 2;
    }
  }
  void ReadBandval2() {
    for (int i = 0; i < numBands; i++) {
    valBand0[i]  = (valBand0[i] < valBand[i]) ? valBand[i] : valBand0[i];
    valBand1[i]  = (valBand1[i] + valBand[i]) / 2;
    Exdot[i]     = (Exdot[i] < valBand[i]) ? valBand[i] : Exdot[i];
    valBand[i] /= 2;
    }
  }
  void ReadBandval3() {
    for (int i = 0; i < numBands; i++) {
    valBand0[i]  = (valBand0[i] < valBand[15-i]) ? valBand[15-i] : valBand0[i];
    valBand1[i]  = (valBand1[i] + valBand[15-i]) / 2;
    Exdot[i]     = (Exdot[i] < valBand[15-i]) ? valBand[15-i] : Exdot[i];
    valBand[15-i] /= 2;
    }
  }
    
    void DrawMode(int mod, int cx, int xv, int yv, int wv, int hv, int wwv, float rx, float degangle) {
      switch(Modedot) {
        case 0:
          DrawModeA0(mod, cx, xv, yv, wv, hv, wwv, rx, degangle);
          break;
        case 1:
          DrawModeB0(mod, cx, xv, yv, wv, hv, wwv, rx, degangle);
          break;
      }
    }

    void DrawModeA0(int mod, int cx, int xv, int yv, int wv, int hv, int wwv, float rx, float degangle) {
      switch(mod) {
        case 0:
          ReadBandval0();
          DrawModeA0(xv, yv, wv, hv, wwv, 0);
          break;
        case 1:
          ReadBandval1();
          DrawModeA0(xv, yv, wv, hv, wwv, 0);
          break;
        case 2:
          ReadBandval0();
          DrawModeA0(xv, yv-hv/2, wv, hv/2, wwv, 1);
          break;
        case 3:
          ReadBandval1();
          DrawModeA0(xv, yv-hv/2, wv, hv/2, wwv, 1);
          break;
        case 4:
          ReadBandval0();
          DrawModeA0(xv, yv, wv/2, hv, wwv, 2);
          break;
        case 5:
          ReadBandval1();
          DrawModeA0(xv, yv, wv/2, hv, wwv, 2);
          break;
        case 6:
          ReadBandval0();
          DrawModeA0(xv, yv-hv/2, wv/2, hv/2, wwv, 3);
          break;
        case 7:
          ReadBandval1();
          DrawModeA0(xv, yv-hv/2, wv/2, hv/2, wwv, 3);
          break;
        case 8:
          ReadBandval0();
          DrawModeA0(xv, yv, wv, hv, wwv, 4);
          break;
        case 9:
          ReadBandval1();
          DrawModeA0(xv, yv, wv, hv, wwv, 4);
          break;
        case 10:
          ReadBandval0();
          DrawModeA0(xv, yv-hv/2, wv, hv/2, wwv, 5);
          break;
        case 11:
          ReadBandval1();
          DrawModeA0(xv, yv-hv/2, wv, hv/2, wwv, 5);
          break;
        case 12:
          ReadBandval0();
          DrawModeA0(xv, yv, wv/2, hv, wwv, 6);
          break;
        case 13:
          ReadBandval1();
          DrawModeA0(xv, yv, wv/2, hv, wwv, 6);
          break;
        case 14:
          ReadBandval0();
          DrawModeA0(xv, yv-hv/2, wv/2, hv/2, wwv, 7);
          break;
        case 15:
          ReadBandval1();
          DrawModeA0(xv, yv-hv/2, wv/2, hv/2, wwv, 7);
          break;
        case 16:
          ReadBandval0();
          DrawModeA0(xv, yv, wv, hv, wwv, 8);
          break;
        case 17:
          ReadBandval1();
          DrawModeA0(xv, yv, wv, hv, wwv, 8);
          break;
        case 18:
          ReadBandval0();
          DrawModeA0(xv, yv-hv/2, wv, hv/2, wwv, 9);
          break;
        case 19:
          ReadBandval1();
          DrawModeA0(xv, yv-hv/2, wv, hv/2, wwv, 9);
          break;
        case 20:
          ReadBandval0();
          DrawModeA0(xv, yv, wv/2, hv, wwv, 10);
          break;
        case 21:
          ReadBandval1();
          DrawModeA0(xv, yv, wv/2, hv, wwv, 10);
          break;
        case 22:
          ReadBandval0();
          DrawModeA0(xv, yv-hv/2, wv/2, hv/2, wwv, 11);
          break;
        case 23:
          ReadBandval1();
          DrawModeA0(xv, yv-hv/2, wv/2, hv/2, wwv, 11);
          break;
        case 24:
          ReadBandval0();
          DrawModeA1(xv, yv, wv, hv, wwv, 0);
          break;
        case 25:
          ReadBandval1();
          DrawModeA1(xv, yv, wv, hv, wwv, 0);
          break;
        case 26:
          ReadBandval0();
          DrawModeA1(xv, yv, wv, hv, wwv, 1);
          break;
        case 27:
          ReadBandval1();
          DrawModeA1(xv, yv, wv, hv, wwv, 1);
          break;
        case 28:
          ReadBandval0();
          DrawModeA1(xv, yv-hv/2, wv, hv/2, wwv, 2);
          break;
        case 29:
          ReadBandval1();
          DrawModeA1(xv, yv-hv/2, wv, hv/2, wwv, 2);
          break;
        case 30:
          ReadBandval0();
          DrawModeA1(xv, yv-hv/2, wv, hv/2, wwv, 3);
          break;
        case 31:
          ReadBandval1();
          DrawModeA1(xv, yv-hv/2, wv, hv/2, wwv, 3);
          break;
        case 32:
          ReadBandval0();
          DrawModeA1(xv, yv, wv/2, hv, wwv, 4);
          break;
        case 33:
          ReadBandval1();
          DrawModeA1(xv, yv, wv/2, hv, wwv, 4);
          break;
        case 34:
          ReadBandval0();
          DrawModeA1(xv, yv, wv/2, hv, wwv, 5);
          break;
        case 35:
          ReadBandval1();
          DrawModeA1(xv, yv, wv/2, hv, wwv, 5);
          break;
        case 36:
          ReadBandval0();
          DrawModeA1(xv, yv-hv/2, wv/2, hv/2, wwv, 6);
          break;
        case 37:
          ReadBandval1();
          DrawModeA1(xv, yv-hv/2, wv/2, hv/2, wwv, 6);
          break;
        case 38:
          ReadBandval0();
          DrawModeA1(xv, yv-hv/2, wv/2, hv/2, wwv, 7);
          break;
        case 39:
          ReadBandval1();
          DrawModeA1(xv, yv-hv/2, wv/2, hv/2, wwv, 7);
          break;
        case 40:
          ReadBandval0();
          DrawModeA1(xv, yv, wv, hv, wwv, 8);
          break;
        case 41:
          ReadBandval1();
          DrawModeA1(xv, yv, wv, hv, wwv, 8);
          break;
        case 42:
          ReadBandval0();
          DrawModeA1(xv, yv-hv/2, wv, hv/2, wwv, 9);
          break;
        case 43:
          ReadBandval1();
          DrawModeA1(xv, yv-hv/2, wv, hv/2, wwv, 9);
          break;
        case 44:
          ReadBandval0();
          DrawModeA1(xv, yv, wv/2, hv, wwv, 10);
          break;
        case 45:
          ReadBandval1();
          DrawModeA1(xv, yv, wv/2, hv, wwv, 10);
          break;
        case 46:
          ReadBandval0();
          DrawModeA1(xv, yv-hv/2, wv/2, hv/2, wwv, 11);
          break;
        case 47:
          ReadBandval1();
          DrawModeA1(xv, yv-hv/2, wv/2, hv/2, wwv, 11);
          break;
        case 48:
          ReadBandval0();
          DrawModeA1(xv, yv, wv, hv, wwv, 12);
          break;
        case 49:
          ReadBandval1();
          DrawModeA1(xv, yv, wv, hv, wwv, 12);
          break;
        case 50:
          ReadBandval0();
          DrawModeA1(xv, yv, wv, hv, wwv, 13);
          break;
        case 51:
          ReadBandval1();
          DrawModeA1(xv, yv, wv, hv, wwv, 13);
          break;
        case 52:
          ReadBandval0();
          DrawModeA1(xv, yv-hv/2, wv, hv/2, wwv, 14);
          break;
        case 53:
          ReadBandval1();
          DrawModeA1(xv, yv-hv/2, wv, hv/2, wwv, 14);
          break;
        case 54:
          ReadBandval0();
          DrawModeA1(xv, yv-hv/2, wv, hv/2, wwv, 15);
          break;
        case 55:
          ReadBandval1();
          DrawModeA1(xv, yv-hv/2, wv, hv/2, wwv, 15);
          break;
        case 56:
          ReadBandval0();
          DrawModeA1(xv, yv, wv/2, hv, wwv, 16);
          break;
        case 57:
          ReadBandval1();
          DrawModeA1(xv, yv, wv/2, hv, wwv, 16);
          break;
        case 58:
          ReadBandval0();
          DrawModeA1(xv, yv, wv/2, hv, wwv, 17);
          break;
        case 59:
          ReadBandval1();
          DrawModeA1(xv, yv, wv/2, hv, wwv, 17);
          break;
        case 60:
          ReadBandval0();
          DrawModeA1(xv, yv-hv/2, wv/2, hv/2, wwv, 18);
          break;
        case 61:
          ReadBandval1();
          DrawModeA1(xv, yv-hv/2, wv/2, hv/2, wwv, 18);
          break;
        case 62:
          ReadBandval0();
          DrawModeA1(xv, yv-hv/2, wv/2, hv/2, wwv, 19);
          break;
        case 63:
          ReadBandval1();
          DrawModeA1(xv, yv-hv/2, wv/2, hv/2, wwv, 19);
          break;
        case 64:
          ReadBandval0();
          DrawModeA1(xv, yv, wv, hv, wwv, 20);
          break;
        case 65:
          ReadBandval1();
          DrawModeA1(xv, yv, wv, hv, wwv, 20);
          break;
        case 66:
          ReadBandval0();
          DrawModeA1(xv, yv-hv/2, wv, hv/2, wwv, 21);
          break;
        case 67:
          ReadBandval1();
          DrawModeA1(xv, yv-hv/2, wv, hv/2, wwv, 21);
          break;
        case 68:
          ReadBandval0();
          DrawModeA1(xv, yv, wv/2, hv, wwv, 22);
          break;
        case 69:
          ReadBandval1();
          DrawModeA1(xv, yv, wv/2, hv, wwv, 22);
          break;
        case 70:
          ReadBandval0();
          DrawModeA1(xv, yv-hv/2, wv/2, hv/2, wwv, 23);
          break;
        case 71:
          ReadBandval1();
          DrawModeA1(xv, yv-hv/2, wv/2, hv/2, wwv, 23);
          break;
        case 72:
          ReadBandval0();
          DrawModeA2(cx, yv-hv/2, rx, hv/2, degangle*4, 0);
          break;
        case 73:
          ReadBandval1();
          DrawModeA2(cx, yv-hv/2, rx, hv/2, degangle*4, 0);
          break;
        case 74:
          ReadBandval0();
          DrawModeA2(cx, yv-hv/2, rx, hv/2, degangle*2, 1);
          break;
        case 75:
          ReadBandval1();
          DrawModeA2(cx, yv-hv/2, rx, hv/2, degangle*2, 1);
          break;
        case 76:
          ReadBandval0();
          DrawModeA2(cx, yv-hv/2, rx, hv/2, degangle, 2);
          break;
        case 77:
          ReadBandval1();
          DrawModeA2(cx, yv-hv/2, rx, hv/2, degangle, 2);
          break;
        case 78:
          ReadBandval0();
          DrawModeA2(cx, yv-hv/2, rx, hv/2, degangle, 3);
          break;
        case 79:
          ReadBandval1();
          DrawModeA2(cx, yv-hv/2, rx, hv/2, degangle, 3);
          break;
        case 80:
          ReadBandval0();
          DrawModeA2(cx, yv, rx, hv, degangle, 4);
          break;
        case 81:
          ReadBandval1();
          DrawModeA2(cx, yv, rx, hv, degangle, 4);
          break;
        case 82:
          ReadBandval0();
          DrawModeA2(cx, yv, rx, hv, degangle, 5);
          break;
        case 83:
          ReadBandval1();
          DrawModeA2(cx, yv, rx, hv, degangle, 5);
          break;
        case 84:
          ReadBandval0();
          DrawModeA2(cx, yv-hv/2, rx, hv/2, degangle*4, 6);
          break;
        case 85:
          ReadBandval1();
          DrawModeA2(cx, yv-hv/2, rx, hv/2, degangle*4, 6);
          break;
        case 86:
          ReadBandval0();
          DrawModeA2(cx, yv-hv/2, rx, hv/2, degangle*2, 7);
          break;
        case 87:
          ReadBandval1();
          DrawModeA2(cx, yv-hv/2, rx, hv/2, degangle*2, 7);
          break;
        case 88 :
          ReadBandval0();
          DrawModeA3(xv-wv/2, yv, wv, hv, wwv, 0);
          break;
        case 89 :
          ReadBandval1();
          DrawModeA3(xv-wv/2, yv, wv, hv, wwv, 0);
          break;
        case 90 :
          ReadBandval0();
          DrawModeA3(xv-wv/2, yv, wv/2, hv, wwv, 1);
          break;
        case 91 :
          ReadBandval1();
          DrawModeA3(xv-wv/2, yv, wv/2, hv, wwv, 1);
          break;
        case 92 :
          ReadBandval0();
          DrawModeA3(xv-wv/2, yv-hv/2, wv, hv/2, wwv, 2);
          break;
        case 93 :
          ReadBandval1();
          DrawModeA3(xv-wv/2, yv-hv/2, wv, hv/2, wwv, 2);
          break;
        case 94 :
          ReadBandval0();
          DrawModeA3(xv-wv/2, yv-hv/2, wv/2, hv/2, wwv, 3);
          break;
        case 95 :
          ReadBandval1();
          DrawModeA3(xv-wv/2, yv-hv/2, wv/2, hv/2, wwv, 3);
          break;
        case 96 :
          ReadBandval0();
          DrawModeA4(xv-wv/2, yv, wv, hv, wwv, 0);
          break;
        case 97 :
          ReadBandval1();
          DrawModeA4(xv-wv/2, yv, wv, hv, wwv, 0);
          break;
        case 98 :
          ReadBandval0();
          DrawModeA4(xv-wv/2, yv, wv/2, hv, wwv, 1);
          break;
        case 99 :
          ReadBandval1();
          DrawModeA4(xv-wv/2, yv, wv/2, hv, wwv, 1);
          break;
        case 100 :
          ReadBandval0();
          DrawModeA4(xv-wv/2, yv-hv/2, wv, hv/2, wwv, 2);
          break;
        case 101 :
          ReadBandval1();
          DrawModeA4(xv-wv/2, yv-hv/2, wv, hv/2, wwv, 2);
          break;
        case 102 :
          ReadBandval0();
          DrawModeA4(xv-wv/2, yv-hv/2, wv/2, hv/2, wwv, 3);
          break;
        case 103 :
          ReadBandval1();
          DrawModeA4(xv-wv/2, yv-hv/2, wv/2, hv/2, wwv, 3);
          break;
        case 104 :
          ReadBandval0();
          DrawModeA5(xv-wv/2, yv, wv, hv, wwv, 0);
          break;
        case 105 :
          ReadBandval1();
          DrawModeA5(xv-wv/2, yv, wv, hv, wwv, 0);
          break;
        case 106 :
          ReadBandval0();
          DrawModeA5(xv-wv/2, yv, wv/2, hv, wwv, 1);
          break;
        case 107 :
          ReadBandval1();
          DrawModeA5(xv-wv/2, yv, wv/2, hv, wwv, 1);
          break;
        case 108 :
          ReadBandval0();
          DrawModeA5(xv-wv/2, yv-hv/2, wv, hv/2, wwv, 2);
          break;
        case 109 :
          ReadBandval1();
          DrawModeA5(xv-wv/2, yv-hv/2, wv, hv/2, wwv, 2);
          break;
        case 110 :
          ReadBandval0();
          DrawModeA5(xv-wv/2, yv-hv/2, wv/2, hv/2, wwv, 3);
          break;
        case 111 :
          ReadBandval1();
          DrawModeA5(xv-wv/2, yv-hv/2, wv/2, hv/2, wwv, 3);
          break;
        case 112 :
          ReadBandval0();
          DrawModeA5(xv-wv/2, yv, wv, hv, wwv, 4);
          break;
        case 113 :
          ReadBandval1();
          DrawModeA5(xv-wv/2, yv, wv, hv, wwv, 4);
          break;
        case 114 :
          ReadBandval0();
          DrawModeA5(xv-wv/2, yv, wv/2, hv, wwv, 5);
          break;
        case 115 :
          ReadBandval1();
          DrawModeA5(xv-wv/2, yv, wv/2, hv, wwv, 5);
          break;
        case 116 :
          ReadBandval0();
          DrawModeA5(xv-wv/2, yv-hv/2, wv, hv/2, wwv, 6);
          break;
        case 117 :
          ReadBandval1();
          DrawModeA5(xv-wv/2, yv-hv/2, wv, hv/2, wwv, 6);
          break;
        case 118 :
          ReadBandval0();
          DrawModeA5(xv-wv/2, yv-hv/2, wv/2, hv/2, wwv, 7);
          break;
        case 119 :
          ReadBandval1();
          DrawModeA5(xv-wv/2, yv-hv/2, wv/2, hv/2, wwv, 7);
          break;
        case 120 :
          ReadBandval0();
          DrawModeA5(xv-wv/2, yv, wv, hv, wwv, 8);
          break;
        case 121 :
          ReadBandval1();
          DrawModeA5(xv-wv/2, yv, wv, hv, wwv, 8);
          break;
        case 122 :
          ReadBandval0();
          DrawModeA5(xv-wv/2, yv, wv/2, hv, wwv, 9);
          break;
        case 123 :
          ReadBandval1();
          DrawModeA5(xv-wv/2, yv, wv/2, hv, wwv, 9);
          break;
        case 124 :
          ReadBandval0();
          DrawModeA5(xv-wv/2, yv-hv/2, wv, hv/2, wwv, 10);
          break;
        case 125 :
          ReadBandval1();
          DrawModeA5(xv-wv/2, yv-hv/2, wv, hv/2, wwv, 10);
          break;
        case 126 :
          ReadBandval0();
          DrawModeA5(xv-wv/2, yv-hv/2, wv/2, hv/2, wwv, 11);
          break;
        case 127 :
          ReadBandval1();
          DrawModeA5(xv-wv/2, yv-hv/2, wv/2, hv/2, wwv, 11);
          break;
      }
    }
    void DrawModeB0(int mod, int cx, int xv, int yv, int wv, int hv, int wwv, float rx, float degangle) {
      switch(mod) {
        case 0:
          ReadBandval2();
          DrawModeB0(xv, yv, wv, hv, wwv, 0);
          break;
        case 1:
          ReadBandval3();
          DrawModeB0(xv, yv, wv, hv, wwv, 0);
          break;
        case 2:
          ReadBandval2();
          DrawModeB0(xv, yv-hv/2, wv, hv/2, wwv, 1);
          break;
        case 3:
          ReadBandval3();
          DrawModeB0(xv, yv-hv/2, wv, hv/2, wwv, 1);
          break;
        case 4:
          ReadBandval2();
          DrawModeB0(xv, yv, wv/2, hv, wwv, 2);
          break;
        case 5:
          ReadBandval3();
          DrawModeB0(xv, yv, wv/2, hv, wwv, 2);
          break;
        case 6:
          ReadBandval2();
          DrawModeB0(xv, yv-hv/2, wv/2, hv/2, wwv, 3);
          break;
        case 7:
          ReadBandval3();
          DrawModeB0(xv, yv-hv/2, wv/2, hv/2, wwv, 3);
          break;
        case 8:
          ReadBandval2();
          DrawModeB0(xv, yv, wv, hv, wwv, 4);
          break;
        case 9:
          ReadBandval3();
          DrawModeB0(xv, yv, wv, hv, wwv, 4);
          break;
        case 10:
          ReadBandval2();
          DrawModeB0(xv, yv-hv/2, wv, hv/2, wwv, 5);
          break;
        case 11:
          ReadBandval3();
          DrawModeB0(xv, yv-hv/2, wv, hv/2, wwv, 5);
          break;
        case 12:
          ReadBandval2();
          DrawModeB0(xv, yv, wv/2, hv, wwv, 6);
          break;
        case 13:
          ReadBandval3();
          DrawModeB0(xv, yv, wv/2, hv, wwv, 6);
          break;
        case 14:
          ReadBandval2();
          DrawModeB0(xv, yv-hv/2, wv/2, hv/2, wwv, 7);
          break;
        case 15:
          ReadBandval3();
          DrawModeB0(xv, yv-hv/2, wv/2, hv/2, wwv, 7);
          break;
        case 16:
          ReadBandval2();
          DrawModeB0(xv, yv, wv, hv, wwv, 8);
          break;
        case 17:
          ReadBandval3();
          DrawModeB0(xv, yv, wv, hv, wwv, 8);
          break;
        case 18:
          ReadBandval2();
          DrawModeB0(xv, yv-hv/2, wv, hv/2, wwv, 9);
          break;
        case 19:
          ReadBandval3();
          DrawModeB0(xv, yv-hv/2, wv, hv/2, wwv, 9);
          break;
        case 20:
          ReadBandval2();
          DrawModeB0(xv, yv, wv/2, hv, wwv, 10);
          break;
        case 21:
          ReadBandval3();
          DrawModeB0(xv, yv, wv/2, hv, wwv, 10);
          break;
        case 22:
          ReadBandval2();
          DrawModeB0(xv, yv-hv/2, wv/2, hv/2, wwv, 11);
          break;
        case 23:
          ReadBandval3();
          DrawModeB0(xv, yv-hv/2, wv/2, hv/2, wwv, 11);
          break;
        case 24:
          ReadBandval2();
          DrawModeB1(xv, yv, wv, hv, wwv, 0);
          break;
        case 25:
          ReadBandval3();
          DrawModeB1(xv, yv, wv, hv, wwv, 0);
          break;
        case 26:
          ReadBandval2();
          DrawModeB1(xv, yv, wv, hv, wwv, 1);
          break;
        case 27:
          ReadBandval3();
          DrawModeB1(xv, yv, wv, hv, wwv, 1);
          break;
        case 28:
          ReadBandval2();
          DrawModeB1(xv, yv-hv/2, wv, hv/2, wwv, 2);
          break;
        case 29:
          ReadBandval3();
          DrawModeB1(xv, yv-hv/2, wv, hv/2, wwv, 2);
          break;
        case 30:
          ReadBandval2();
          DrawModeB1(xv, yv-hv/2, wv, hv/2, wwv, 3);
          break;
        case 31:
          ReadBandval3();
          DrawModeB1(xv, yv-hv/2, wv, hv/2, wwv, 3);
          break;
        case 32:
          ReadBandval2();
          DrawModeB1(xv, yv, wv/2, hv, wwv, 4);
          break;
        case 33:
          ReadBandval3();
          DrawModeB1(xv, yv, wv/2, hv, wwv, 4);
          break;
        case 34:
          ReadBandval2();
          DrawModeB1(xv, yv, wv/2, hv, wwv, 5);
          break;
        case 35:
          ReadBandval3();
          DrawModeB1(xv, yv, wv/2, hv, wwv, 5);
          break;
        case 36:
          ReadBandval2();
          DrawModeB1(xv, yv-hv/2, wv/2, hv/2, wwv, 6);
          break;
        case 37:
          ReadBandval3();
          DrawModeB1(xv, yv-hv/2, wv/2, hv/2, wwv, 6);
          break;
        case 38:
          ReadBandval2();
          DrawModeB1(xv, yv-hv/2, wv/2, hv/2, wwv, 7);
          break;
        case 39:
          ReadBandval3();
          DrawModeB1(xv, yv-hv/2, wv/2, hv/2, wwv, 7);
          break;
        case 40:
          ReadBandval2();
          DrawModeB1(xv, yv, wv, hv, wwv, 8);
          break;
        case 41:
          ReadBandval3();
          DrawModeB1(xv, yv, wv, hv, wwv, 8);
          break;
        case 42:
          ReadBandval2();
          DrawModeB1(xv, yv-hv/2, wv, hv/2, wwv, 9);
          break;
        case 43:
          ReadBandval3();
          DrawModeB1(xv, yv-hv/2, wv, hv/2, wwv, 9);
          break;
        case 44:
          ReadBandval2();
          DrawModeB1(xv, yv, wv/2, hv, wwv, 10);
          break;
        case 45:
          ReadBandval3();
          DrawModeB1(xv, yv, wv/2, hv, wwv, 10);
          break;
        case 46:
          ReadBandval2();
          DrawModeB1(xv, yv-hv/2, wv/2, hv/2, wwv, 11);
          break;
        case 47:
          ReadBandval3();
          DrawModeB1(xv, yv-hv/2, wv/2, hv/2, wwv, 11);
          break;
        case 48:
          ReadBandval2();
          DrawModeB1(xv, yv, wv, hv, wwv, 12);
          break;
        case 49:
          ReadBandval3();
          DrawModeB1(xv, yv, wv, hv, wwv, 12);
          break;
        case 50:
          ReadBandval2();
          DrawModeB1(xv, yv, wv, hv, wwv, 13);
          break;
        case 51:
          ReadBandval3();
          DrawModeB1(xv, yv, wv, hv, wwv, 13);
          break;
        case 52:
          ReadBandval2();
          DrawModeB1(xv, yv-hv/2, wv, hv/2, wwv, 14);
          break;
        case 53:
          ReadBandval3();
          DrawModeB1(xv, yv-hv/2, wv, hv/2, wwv, 14);
          break;
        case 54:
          ReadBandval2();
          DrawModeB1(xv, yv-hv/2, wv, hv/2, wwv, 15);
          break;
        case 55:
          ReadBandval3();
          DrawModeB1(xv, yv-hv/2, wv, hv/2, wwv, 15);
          break;
        case 56:
          ReadBandval2();
          DrawModeB1(xv, yv, wv/2, hv, wwv, 16);
          break;
        case 57:
          ReadBandval3();
          DrawModeB1(xv, yv, wv/2, hv, wwv, 16);
          break;
        case 58:
          ReadBandval2();
          DrawModeB1(xv, yv, wv/2, hv, wwv, 17);
          break;
        case 59:
          ReadBandval3();
          DrawModeB1(xv, yv, wv/2, hv, wwv, 17);
          break;
        case 60:
          ReadBandval2();
          DrawModeB1(xv, yv-hv/2, wv/2, hv/2, wwv, 18);
          break;
        case 61:
          ReadBandval3();
          DrawModeB1(xv, yv-hv/2, wv/2, hv/2, wwv, 18);
          break;
        case 62:
          ReadBandval2();
          DrawModeB1(xv, yv-hv/2, wv/2, hv/2, wwv, 19);
          break;
        case 63:
          ReadBandval3();
          DrawModeB1(xv, yv-hv/2, wv/2, hv/2, wwv, 19);
          break;
        case 64:
          ReadBandval2();
          DrawModeB1(xv, yv, wv, hv, wwv, 20);
          break;
        case 65:
          ReadBandval3();
          DrawModeB1(xv, yv, wv, hv, wwv, 20);
          break;
        case 66:
          ReadBandval2();
          DrawModeB1(xv, yv-hv/2, wv, hv/2, wwv, 21);
          break;
        case 67:
          ReadBandval3();
          DrawModeB1(xv, yv-hv/2, wv, hv/2, wwv, 21);
          break;
        case 68:
          ReadBandval2();
          DrawModeB1(xv, yv, wv/2, hv, wwv, 22);
          break;
        case 69:
          ReadBandval3();
          DrawModeB1(xv, yv, wv/2, hv, wwv, 22);
          break;
        case 70:
          ReadBandval2();
          DrawModeB1(xv, yv-hv/2, wv/2, hv/2, wwv, 23);
          break;
        case 71:
          ReadBandval3();
          DrawModeB1(xv, yv-hv/2, wv/2, hv/2, wwv, 23);
          break;
        case 72:
          ReadBandval2();
          DrawModeB2(cx, yv-hv/2, rx, hv/2, degangle*4, 0);
          break;
        case 73:
          ReadBandval3();
          DrawModeB2(cx, yv-hv/2, rx, hv/2, degangle*4, 0);
          break;
        case 74:
          ReadBandval2();
          DrawModeB2(cx, yv-hv/2, rx, hv/2, degangle*4, 1);
          break;
        case 75:
          ReadBandval3();
          DrawModeB2(cx, yv-hv/2, rx, hv/2, degangle*4, 1);
          break;
        case 76:
          ReadBandval2();
          DrawModeB2(cx, yv-hv/2, rx, hv/2, degangle, 2);
          break;
        case 77:
          ReadBandval3();
          DrawModeB2(cx, yv-hv/2, rx, hv/2, degangle, 2);
          break;
        case 78:
          ReadBandval2();
          DrawModeB2(cx, yv-hv/2, rx, hv/2, degangle, 3);
          break;
        case 79:
          ReadBandval3();
          DrawModeB2(cx, yv-hv/2, rx, hv/2, degangle, 3);
          break;
        case 80:
          ReadBandval2();
          DrawModeB2(cx, yv, rx, hv, degangle, 4);
          break;
        case 81:
          ReadBandval3();
          DrawModeB2(cx, yv, rx, hv, degangle, 4);
          break;
        case 82:
          ReadBandval2();
          DrawModeB2(cx, yv, rx, hv, degangle, 5);
          break;
        case 83:
          ReadBandval3();
          DrawModeB2(cx, yv, rx, hv, degangle, 5);
          break;
        case 84:
          ReadBandval2();
          DrawModeB2(cx, yv-hv/2, rx, hv/2, degangle*4, 6);
          break;
        case 85:
          ReadBandval3();
          DrawModeB2(cx, yv-hv/2, rx, hv/2, degangle*4, 6);
          break;
        case 86:
          ReadBandval2();
          DrawModeB2(cx, yv-hv/2, rx, hv/2, degangle*2, 7);
          break;
        case 87:
          ReadBandval3();
          DrawModeB2(cx, yv-hv/2, rx, hv/2, degangle*2, 7);
          break;
        case 88 :
          ReadBandval2();
          DrawModeB3(xv-wv/2, yv, wv, hv, wwv, 0);
          break;
        case 89 :
          ReadBandval3();
          DrawModeB3(xv-wv/2, yv, wv, hv, wwv, 0);
          break;
        case 90 :
          ReadBandval2();
          DrawModeB3(xv-wv/2, yv, wv/2, hv, wwv, 1);
          break;
        case 91 :
          ReadBandval3();
          DrawModeB3(xv-wv/2, yv, wv/2, hv, wwv, 1);
          break;
        case 92 :
          ReadBandval2();
          DrawModeB3(xv-wv/2, yv-hv/2, wv, hv/2, wwv, 2);
          break;
        case 93 :
          ReadBandval3();
          DrawModeB3(xv-wv/2, yv-hv/2, wv, hv/2, wwv, 2);
          break;
        case 94 :
          ReadBandval2();
          DrawModeB3(xv-wv/2, yv-hv/2, wv/2, hv/2, wwv, 3);
          break;
        case 95 :
          ReadBandval3();
          DrawModeB3(xv-wv/2, yv-hv/2, wv/2, hv/2, wwv, 3);
          break;
        case 96 :
          ReadBandval2();
          DrawModeB4(xv-wv/2, yv, wv, hv, wwv, 0);
          break;
        case 97 :
          ReadBandval3();
          DrawModeB4(xv-wv/2, yv, wv, hv, wwv, 0);
          break;
        case 98 :
          ReadBandval2();
          DrawModeB4(xv-wv/2, yv, wv/2, hv, wwv, 1);
          break;
        case 99 :
          ReadBandval3();
          DrawModeB4(xv-wv/2, yv, wv/2, hv, wwv, 1);
          break;
        case 100 :
          ReadBandval2();
          DrawModeB4(xv-wv/2, yv-hv/2, wv, hv/2, wwv, 2);
          break;
        case 101 :
          ReadBandval3();
          DrawModeB4(xv-wv/2, yv-hv/2, wv, hv/2, wwv, 2);
          break;
        case 102 :
          ReadBandval2();
          DrawModeB4(xv-wv/2, yv-hv/2, wv/2, hv/2, wwv, 3);
          break;
        case 103 :
          ReadBandval3();
          DrawModeB4(xv-wv/2, yv-hv/2, wv/2, hv/2, wwv, 3);
          break;
        case 104 :
          ReadBandval2();
          DrawModeB5(xv-wv/2, yv, wv, hv, wwv, 0);
          break;
        case 105 :
          ReadBandval3();
          DrawModeB5(xv-wv/2, yv, wv, hv, wwv, 0);
          break;
        case 106 :
          ReadBandval2();
          DrawModeB5(xv-wv/2, yv, wv/2, hv, wwv, 1);
          break;
        case 107 :
          ReadBandval3();
          DrawModeB5(xv-wv/2, yv, wv/2, hv, wwv, 1);
          break;
        case 108 :
          ReadBandval2();
          DrawModeB5(xv-wv/2, yv-hv/2, wv, hv/2, wwv, 2);
          break;
        case 109 :
          ReadBandval3();
          DrawModeB5(xv-wv/2, yv-hv/2, wv, hv/2, wwv, 2);
          break;
        case 110 :
          ReadBandval2();
          DrawModeB5(xv-wv/2, yv-hv/2, wv/2, hv/2, wwv, 3);
          break;
        case 111 :
          ReadBandval3();
          DrawModeB5(xv-wv/2, yv-hv/2, wv/2, hv/2, wwv, 3);
          break;
        case 112 :
          ReadBandval2();
          DrawModeB5(xv-wv/2, yv, wv, hv, wwv, 4);
          break;
        case 113 :
          ReadBandval3();
          DrawModeB5(xv-wv/2, yv, wv, hv, wwv, 4);
          break;
        case 114 :
          ReadBandval2();
          DrawModeB5(xv-wv/2, yv, wv/2, hv, wwv, 5);
          break;
        case 115 :
          ReadBandval3();
          DrawModeB5(xv-wv/2, yv, wv/2, hv, wwv, 5);
          break;
        case 116 :
          ReadBandval2();
          DrawModeB5(xv-wv/2, yv-hv/2, wv, hv/2, wwv, 6);
          break;
        case 117 :
          ReadBandval3();
          DrawModeB5(xv-wv/2, yv-hv/2, wv, hv/2, wwv, 6);
          break;
        case 118 :
          ReadBandval2();
          DrawModeB5(xv-wv/2, yv-hv/2, wv/2, hv/2, wwv, 7);
          break;
        case 119 :
          ReadBandval3();
          DrawModeB5(xv-wv/2, yv-hv/2, wv/2, hv/2, wwv, 7);
          break;
        case 120 :
          ReadBandval2();
          DrawModeB5(xv-wv/2, yv, wv, hv, wwv, 8);
          break;
        case 121 :
          ReadBandval3();
          DrawModeB5(xv-wv/2, yv, wv, hv, wwv, 8);
          break;
        case 122 :
          ReadBandval2();
          DrawModeB5(xv-wv/2, yv, wv/2, hv, wwv, 9);
          break;
        case 123 :
          ReadBandval3();
          DrawModeB5(xv-wv/2, yv, wv/2, hv, wwv, 9);
          break;
        case 124 :
          ReadBandval2();
          DrawModeB5(xv-wv/2, yv-hv/2, wv, hv/2, wwv, 10);
          break;
        case 125 :
          ReadBandval3();
          DrawModeB5(xv-wv/2, yv-hv/2, wv, hv/2, wwv, 10);
          break;
        case 126 :
          ReadBandval2();
          DrawModeB5(xv-wv/2, yv-hv/2, wv/2, hv/2, wwv, 11);
          break;
        case 127 :
          ReadBandval3();
          DrawModeB5(xv-wv/2, yv-hv/2, wv/2, hv/2, wwv, 11);
          break;
      }
    }



  void DrawMusicA0(int x0, int y0, int l0, int l1, int nl0, int nl1, int dw0, int wwv, uint8_t clor0, uint8_t clor1, uint8_t clor2, int mod) {
    switch(mod) {
      case 0 :
        gfx.fillCare(x0, y0-l1, x0, y0-l0, x0+dw0, y0-nl0, x0+dw0, y0-nl1, Mycolor[clor1]);
        break;
      case 1 :
        gfx.fillCare(x0, y0-l1, x0, y0-l0, x0+dw0, y0-nl0, x0+dw0, y0-nl1, Mycolor[clor1]);
        gfx.fillCare(x0, y0+l1, x0, y0+l0, x0+dw0, y0+nl0, x0+dw0, y0+nl1, Mycolor[clor1]);
        break;
      case 2 :
        gfx.fillCare(x0, y0-l1, x0, y0-l0, x0+dw0, y0-nl0, x0+dw0, y0-nl1, Mycolor[clor1]);
        gfx.fillCare(wwv-x0-dw0, y0-nl1, wwv-x0-dw0, y0-nl0, wwv-x0, y0-l0, wwv-x0, y0-l1, Mycolor[clor1]);
        break;
      case 3 :
        gfx.fillCare(x0, y0-l1, x0, y0-l0, x0+dw0, y0-nl0, x0+dw0, y0-nl1, Mycolor[clor1]);
        gfx.fillCare(x0, y0+l1, x0, y0+l0, x0+dw0, y0+nl0, x0+dw0, y0+nl1, Mycolor[clor1]);
        gfx.fillCare(wwv-x0-dw0, y0-nl1, wwv-x0-dw0, y0-nl0, wwv-x0, y0-l0, wwv-x0, y0-l1, Mycolor[clor1]);
        gfx.fillCare(wwv-x0-dw0, y0+nl1, wwv-x0-dw0, y0+nl0, wwv-x0, y0+l0, wwv-x0, y0+l1, Mycolor[clor1]);
        break;
      case 4 :
        gfx.fillCare(x0, y0-l1, x0, y0-l0, x0+dw0, y0-nl0, x0+dw0, y0-nl1, Mycolor[clor1]);
        gfx.fillCare(x0, y0, x0, y0-l1, x0+dw0, y0-nl1, x0+dw0, y0, Mycolor[clor0]);
        break;
      case 5 :
        gfx.fillCare(x0, y0-l1, x0, y0-l0, x0+dw0, y0-nl0, x0+dw0, y0-nl1, Mycolor[clor1]);
        gfx.fillCare(x0, y0+l1, x0, y0+l0, x0+dw0, y0+nl0, x0+dw0, y0+nl1, Mycolor[clor1]);
        gfx.fillCare(x0, y0, x0, y0-l1, x0+dw0, y0-nl1, x0+dw0, y0, Mycolor[clor0]);
        gfx.fillCare(x0, y0+l1, x0, y0, x0+dw0, y0, x0+dw0, y0+nl1, Mycolor[clor0]);
        break;
      case 6 :
        gfx.fillCare(x0, y0-l1, x0, y0-l0, x0+dw0, y0-nl0, x0+dw0, y0-nl1, Mycolor[clor1]);
        gfx.fillCare(wwv-x0-dw0, y0-nl1, wwv-x0-dw0, y0-nl0, wwv-x0, y0-l0, wwv-x0, y0-l1, Mycolor[clor1]);
        gfx.fillCare(x0, y0, x0, y0-l1, x0+dw0, y0-nl1, x0+dw0, y0, Mycolor[clor0]);
        gfx.fillCare(wwv-x0-dw0, y0, wwv-x0-dw0, y0-nl1, wwv-x0, y0-l1, wwv-x0, y0, Mycolor[clor0]);
        break;
      case 7 :
        gfx.fillCare(x0, y0-l1, x0, y0-l0, x0+dw0, y0-nl0, x0+dw0, y0-nl1, Mycolor[clor1]);
        gfx.fillCare(x0, y0+l1, x0, y0+l0, x0+dw0, y0+nl0, x0+dw0, y0+nl1, Mycolor[clor1]);
        gfx.fillCare(wwv-x0-dw0, y0-nl1, wwv-x0-dw0, y0-nl0, wwv-x0, y0-l0, wwv-x0, y0-l1, Mycolor[clor1]);
        gfx.fillCare(wwv-x0-dw0, y0+nl1, wwv-x0-dw0, y0+nl0, wwv-x0, y0+l0, wwv-x0, y0+l1, Mycolor[clor1]);
        gfx.fillCare(x0, y0, x0, y0-l1, x0+dw0, y0-nl1, x0+dw0, y0, Mycolor[clor0]);
        gfx.fillCare(wwv-x0-dw0, y0, wwv-x0-dw0, y0-nl1, wwv-x0, y0-l1, wwv-x0, y0, Mycolor[clor0]);
        gfx.fillCare(x0, y0+l1, x0, y0, x0+dw0, y0, x0+dw0, y0+nl1, Mycolor[clor0]);
        gfx.fillCare(wwv-x0-dw0, y0+nl1, wwv-x0-dw0, y0, wwv-x0, y0, wwv-x0, y0+l1, Mycolor[clor0]);
        break;
      case 8 :
        gfx.fillCare(x0, y0-l1, x0, y0-l0, x0+dw0, y0-nl0, x0+dw0, y0-nl1, Mycolor[clor1]);
        gfx.fillCare(x0, y0, x0, y0-l1, x0+dw0, y0-nl1, x0+dw0, y0, Mycolor[clor2]);
        break;
      case 9 :
        gfx.fillCare(x0, y0-l1, x0, y0-l0, x0+dw0, y0-nl0, x0+dw0, y0-nl1, Mycolor[clor1]);
        gfx.fillCare(x0, y0+l1, x0, y0+l0, x0+dw0, y0+nl0, x0+dw0, y0+nl1, Mycolor[clor1]);
        gfx.fillCare(x0, y0, x0, y0-l1, x0+dw0, y0-nl1, x0+dw0, y0, Mycolor[clor2]);
        gfx.fillCare(x0, y0+l1, x0, y0, x0+dw0, y0, x0+dw0, y0+nl1, Mycolor[clor2]);
        break;
      case 10 :
        gfx.fillCare(x0, y0-l1, x0, y0-l0, x0+dw0, y0-nl0, x0+dw0, y0-nl1, Mycolor[clor1]);
        gfx.fillCare(wwv-x0-dw0, y0-nl1, wwv-x0-dw0, y0-nl0, wwv-x0, y0-l0, wwv-x0, y0-l1, Mycolor[clor1]);
        gfx.fillCare(x0, y0, x0, y0-l1, x0+dw0, y0-nl1, x0+dw0, y0, Mycolor[clor2]);
        gfx.fillCare(wwv-x0-dw0, y0, wwv-x0-dw0, y0-nl1, wwv-x0, y0-l1, wwv-x0, y0, Mycolor[clor2]);
        break;
      case 11 :
        gfx.fillCare(x0, y0-l1, x0, y0-l0, x0+dw0, y0-nl0, x0+dw0, y0-nl1, Mycolor[clor1]);
        gfx.fillCare(x0, y0+l1, x0, y0+l0, x0+dw0, y0+nl0, x0+dw0, y0+nl1, Mycolor[clor1]);
        gfx.fillCare(wwv-x0-dw0, y0-nl1, wwv-x0-dw0, y0-nl0, wwv-x0, y0-l0, wwv-x0, y0-l1, Mycolor[clor1]);
        gfx.fillCare(wwv-x0-dw0, y0+nl1, wwv-x0-dw0, y0+nl0, wwv-x0, y0+l0, wwv-x0, y0+l1, Mycolor[clor1]);
        gfx.fillCare(x0, y0, x0, y0-l1, x0+dw0, y0-nl1, x0+dw0, y0, Mycolor[clor2]);
        gfx.fillCare(wwv-x0-dw0, y0, wwv-x0-dw0, y0-nl1, wwv-x0, y0-l1, wwv-x0, y0, Mycolor[clor2]);
        gfx.fillCare(x0, y0+l1, x0, y0, x0+dw0, y0, x0+dw0, y0+nl1, Mycolor[clor2]);
        gfx.fillCare(wwv-x0-dw0, y0+nl1, wwv-x0-dw0, y0, wwv-x0, y0, wwv-x0, y0+l1, Mycolor[clor2]);
        break;
    }
  }
  void DrawMusicA1(int x0, int y0, int l0, int l1, int dw0, int wwv, uint8_t clor0, uint8_t clor1, uint8_t clor2, int mod) {
    switch(mod) {
      case 0 :
        gfx.DemifillEllipse(x0, y0-l1, (dw0/2)-4, l0-l1, Mycolor[clor1]);
        break;
      case 1 :
        gfx.DemifillEllipse(x0, y0, (dw0/2)-4, l0, Mycolor[clor1]);
        gfx.DemifillEllipse(x0, y0, (dw0/2)-8, l1, Mycolor[clor0]);
        break;
      case 2 :
        gfx.DemifillEllipse(x0, y0-l1, (dw0/2)-2, l0-l1, Mycolor[clor1]);
        gfx.DemifillEllipse(x0, y0+l1, (dw0/2)-2, l0-l1, Mycolor[clor1], false);
        break;
      case 3 :
        gfx.fillEllipse(x0, y0, (dw0/2)-4, l0, Mycolor[clor1]);
        gfx.fillEllipse(x0, y0, (dw0/2)-8, l1, Mycolor[clor0]);
        break;
      case 4 :
        gfx.DemifillEllipse(x0, y0-l1, (dw0/2)-4, l0-l1, Mycolor[clor1]);
        gfx.DemifillEllipse(wwv-x0, y0-l1, (dw0/2)-4, l0-l1, Mycolor[clor1]);
        break;
      case 5 :
        gfx.DemifillEllipse(x0, y0, (dw0/2)-2, l0, Mycolor[clor1]);
        gfx.DemifillEllipse(x0, y0, (dw0/2)-4, l1, Mycolor[clor0]);
        gfx.DemifillEllipse(wwv-x0, y0, (dw0/2)-2, l0, Mycolor[clor1]);
        gfx.DemifillEllipse(wwv-x0, y0, (dw0/2)-4, l1, Mycolor[clor0]);
        break;
      case 6 :
        gfx.DemifillEllipse(x0, y0-l1, (dw0/2)-2, l0-l1, Mycolor[clor1]);
        gfx.DemifillEllipse(wwv-x0, y0-l1, (dw0/2)-2, l0-l1, Mycolor[clor1]);
        gfx.DemifillEllipse(x0, y0+l1, (dw0/2)-4, l0-l1, Mycolor[clor1], false);
        gfx.DemifillEllipse(wwv-x0, y0+l1, (dw0/2)-2, l0-l1, Mycolor[clor1], false);
        break;
      case 7 :
        gfx.fillEllipse(x0, y0, (dw0/2)-2, l0, Mycolor[clor1]);
        gfx.fillEllipse(x0, y0, (dw0/2)-4, l1, Mycolor[clor0]);
        gfx.fillEllipse(wwv-x0, y0, (dw0/2)-2, l0, Mycolor[clor1]);
        gfx.fillEllipse(wwv-x0, y0, (dw0/2)-4, l1, Mycolor[clor0]);
        break;
      case 8 :
        gfx.DemifillEllipse(x0, y0, (dw0/2)-4, l0, Mycolor[clor1]);
        gfx.DemifillEllipse(x0, y0, (dw0/2)-8, l1, Mycolor[clor2]);
        break;
      case 9 :
        gfx.fillEllipse(x0, y0, (dw0/2)-4, l0, Mycolor[clor1]);
        gfx.fillEllipse(x0, y0, (dw0/2)-8, l1, Mycolor[clor2]);
        break;
      case 10 :
        gfx.DemifillEllipse(x0, y0, (dw0/2)-2, l0, Mycolor[clor1]);
        gfx.DemifillEllipse(x0, y0, (dw0/2)-4, l1, Mycolor[clor2]);
        gfx.DemifillEllipse(wwv-x0, y0, (dw0/2)-2, l0, Mycolor[clor1]);
        gfx.DemifillEllipse(wwv-x0, y0, (dw0/2)-4, l1, Mycolor[clor2]);
        break;
      case 11 :
        gfx.fillEllipse(x0, y0, (dw0/2)-2, l0, Mycolor[clor1]);
        gfx.fillEllipse(x0, y0, (dw0/2)-4, l1, Mycolor[clor2]);
        gfx.fillEllipse(wwv-x0, y0, (dw0/2)-2, l0, Mycolor[clor1]);
        gfx.fillEllipse(wwv-x0, y0, (dw0/2)-4, l1, Mycolor[clor2]);
        break;
      case 12 :
        gfx.DemifillParall(x0, y0-l1, (dw0/2)-4, l0-l1, Mycolor[clor1]);
        break;
      case 13 :
        gfx.DemifillParall(x0, y0, (dw0/2)-4, l0, Mycolor[clor0]);
        gfx.DemifillParall(x0, y0, (dw0/2)-8, l1, Mycolor[clor1]);
        break;
      case 14 :
        gfx.DemifillParall(x0, y0-l1, (dw0/2)-2, l0-l1, Mycolor[clor1]);
        gfx.DemifillParall(x0, y0+l1, (dw0/2)-2, l0-l1, Mycolor[clor1], false);
        break;
      case 15 :
        gfx.fillParallelogram(x0, y0, (dw0/2)-4, l0, Mycolor[clor0]);
        gfx.fillParallelogram(x0, y0, (dw0/2)-8, l1, Mycolor[clor1]);
        break;
      case 16 :
        gfx.DemifillParall(x0, y0-l1, (dw0/2)-4, l0-l1, Mycolor[clor1]);
        gfx.DemifillParall(wwv-x0, y0-l1, (dw0/2)-4, l0-l1, Mycolor[clor1]);
        break;
      case 17 :
        gfx.DemifillParall(x0, y0, (dw0/2)-2, l0, Mycolor[clor0]);
        gfx.DemifillParall(x0, y0, (dw0/2)-4, l1, Mycolor[clor1]);
        gfx.DemifillParall(wwv-x0, y0, (dw0/2)-2, l0, Mycolor[clor0]);
        gfx.DemifillParall(wwv-x0, y0, (dw0/2)-4, l1, Mycolor[clor1]);
        break;
      case 18 :
        gfx.DemifillParall(x0, y0-l1, (dw0/2)-2, l0-l1, Mycolor[clor1]);
        gfx.DemifillParall(wwv-x0, y0-l1, (dw0/2)-2, l0-l1, Mycolor[clor1]);
        gfx.DemifillParall(x0, y0+l1, (dw0/2)-4, l0-l1, Mycolor[clor1], false);
        gfx.DemifillParall(wwv-x0, y0+l1, (dw0/2)-2, l0-l1, Mycolor[clor1], false);
        break;
      case 19 :
        gfx.fillParallelogram(x0, y0, (dw0/2)-2, l0, Mycolor[clor0]);
        gfx.fillParallelogram(x0, y0, (dw0/2)-4, l1, Mycolor[clor1]);
        gfx.fillParallelogram(wwv-x0, y0, (dw0/2)-2, l0, Mycolor[clor0]);
        gfx.fillParallelogram(wwv-x0, y0, (dw0/2)-4, l1, Mycolor[clor1]);
        break;
      case 20 :
        gfx.DemifillParall(x0, y0, (dw0/2)-4, l0, Mycolor[clor1]);
        gfx.DemifillParall(x0, y0, (dw0/2)-8, l1, Mycolor[clor2]);
        break;
      case 21 :
        gfx.fillParallelogram(x0, y0, (dw0/2)-4, l0, Mycolor[clor1]);
        gfx.fillParallelogram(x0, y0, (dw0/2)-8, l1, Mycolor[clor2]);
        break;
      case 22 :
        gfx.DemifillParall(x0, y0, (dw0/2)-2, l0, Mycolor[clor1]);
        gfx.DemifillParall(x0, y0, (dw0/2)-4, l1, Mycolor[clor2]);
        gfx.DemifillParall(wwv-x0, y0, (dw0/2)-2, l0, Mycolor[clor1]);
        gfx.DemifillParall(wwv-x0, y0, (dw0/2)-4, l1, Mycolor[clor2]);
        break;
      case 23 :
        gfx.fillParallelogram(x0, y0, (dw0/2)-2, l0, Mycolor[clor1]);
        gfx.fillParallelogram(x0, y0, (dw0/2)-4, l1, Mycolor[clor2]);
        gfx.fillParallelogram(wwv-x0, y0, (dw0/2)-2, l0, Mycolor[clor1]);
        gfx.fillParallelogram(wwv-x0, y0, (dw0/2)-4, l1, Mycolor[clor2]);
        break;
    }
  }
  void DrawMusicA2(int cx, int cy, int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3, uint8_t clor0, uint8_t clor1, uint8_t clor2, int mod) {
    switch(mod) {
      case 0 :
        gfx.fillCare(cx+x1, cy-y1, cx+x0, cy-y0, cx+x2, cy-y2, cx+x3, cy-y3, Mycolor[clor1]);
        break;
      case 1 :
        gfx.fillCare(cx+x1, cy-y1, cx+x0, cy-y0, cx+x2, cy-y2, cx+x3, cy-y3, Mycolor[clor1]);
        gfx.fillCare(cx+x0, cy+y0, cx+x1, cy+y1, cx+x3, cy+y3, cx+x2, cy+y2, Mycolor[clor1]);
        break;
      case 2 :
        gfx.fillCare(cx+x1, cy-y1, cx+x0, cy-y0, cx+x2, cy-y2, cx+x3, cy-y3, Mycolor[clor1]);
        gfx.fillCare(cx+x0, cy+y0, cx+x1, cy+y1, cx+x3, cy+y3, cx+x2, cy+y2, Mycolor[clor1]);
        gfx.fillCare(cx-x3, cy-y3, cx-x2, cy-y2, cx-x0, cy-y0, cx-x1, cy-y1, Mycolor[clor1]);
        gfx.fillCare(cx-x2, cy+y2, cx-x3, cy+y3, cx-x1, cy+y1, cx-x0, cy+y0, Mycolor[clor1]);
        break;
      case 3 :
        gfx.fillCare(cx+x1, cy-y1, cx+x0, cy-y0, cx+x2, cy-y2, cx+x3, cy-y3, Mycolor[clor1]);
        gfx.fillCare(cx+x0, cy+y0, cx+x1, cy+y1, cx+x3, cy+y3, cx+x2, cy+y2, Mycolor[clor1]);
        gfx.fillCare(cx-x3, cy-y3, cx-x2, cy-y2, cx-x0, cy-y0, cx-x1, cy-y1, Mycolor[clor1]);
        gfx.fillCare(cx-x2, cy+y2, cx-x3, cy+y3, cx-x1, cy+y1, cx-x0, cy+y0, Mycolor[clor1]);
        gfx.fillTriangle(cx, cy, cx+x1, cy-y1, cx+x3, cy-y3, Mycolor[clor0]);
        gfx.fillTriangle(cx, cy, cx+x1, cy+y1, cx+x3, cy+y3, Mycolor[clor0]);
        gfx.fillTriangle(cx, cy, cx-x3, cy-y3, cx-x1, cy-y1, Mycolor[clor0]);
        gfx.fillTriangle(cx, cy, cx-x3, cy+y3, cx-x1, cy+y1, Mycolor[clor0]);
        break;
      case 4 :
        gfx.fillCare(cx+x1, cy-y1, cx+x0, cy-y0, cx+x2, cy-y2, cx+x3, cy-y3, Mycolor[clor1]);
        gfx.fillCare(cx-x3, cy-y3, cx-x2, cy-y2, cx-x0, cy-y0, cx-x1, cy-y1, Mycolor[clor1]);
        break;
      case 5 :
        gfx.fillCare(cx+x1, cy-y1, cx+x0, cy-y0, cx+x2, cy-y2, cx+x3, cy-y3, Mycolor[clor1]);
        gfx.fillCare(cx-x3, cy-y3, cx-x2, cy-y2, cx-x0, cy-y0, cx-x1, cy-y1, Mycolor[clor1]);
        gfx.fillTriangle(cx, cy, cx+x1, cy-y1, cx+x3, cy-y3, Mycolor[clor0]);
        gfx.fillTriangle(cx, cy, cx-x3, cy-y3, cx-x1, cy-y1, Mycolor[clor0]);
        break;
      case 6 :
        gfx.fillCare(cx+x1, cy-y1, cx+x0, cy-y0, cx+x2, cy-y2, cx+x3, cy-y3, Mycolor[clor1]);
        gfx.fillTriangle(cx, cy, cx+x1, cy-y1, cx+x3, cy-y3, Mycolor[clor0]);
        break;
      case 7 :
        gfx.fillCare(cx+x1, cy-y1, cx+x0, cy-y0, cx+x2, cy-y2, cx+x3, cy-y3, Mycolor[clor1]);
        gfx.fillCare(cx+x0, cy+y0, cx+x1, cy+y1, cx+x3, cy+y3, cx+x2, cy+y2, Mycolor[clor1]);
        gfx.fillTriangle(cx, cy, cx+x1, cy-y1, cx+x3, cy-y3, Mycolor[clor0]);
        gfx.fillTriangle(cx, cy, cx+x1, cy+y1, cx+x3, cy+y3, Mycolor[clor0]);
        break;
    }
  }
  void DrawMusicA3(int x0, int y0, int y1, int w, int h, int wwv, uint8_t clor0, int mod) {
    switch(mod) {
      case 0 :
        gfx.fillRoundRect(x0+4, y0, w-8, h, 15, Mycolor[clor0]);
        break;
      case 1 :
        gfx.fillRoundRect(x0+2, y0, w-4, h, 15, Mycolor[clor0]);
        gfx.fillRoundRect(wwv-(x0+w-2), y0, w-4, h, 15, Mycolor[clor0]);
        break;
      case 2 :
        gfx.fillRoundRect(x0+4, y0, w-8, h, 15, Mycolor[clor0]);
        gfx.fillRoundRect(x0+4, y1, w-8, h, 15, Mycolor[clor0]);
        break;
      case 3 :
        gfx.fillRoundRect(x0+2, y0, w-4, h, 15, Mycolor[clor0]);
        gfx.fillRoundRect(x0+2, y1, w-4, h, 15, Mycolor[clor0]);
        gfx.fillRoundRect(wwv-(x0+w-2), y0, w-4, h, 15, Mycolor[clor0]);
        gfx.fillRoundRect(wwv-(x0+w-2), y1, w-4, h, 15, Mycolor[clor0]);
        break;
    }
  }
  void DrawMusicA5(int x0, int yv, int y0, int y1, int w, int wwv, uint8_t clor0, uint8_t clor1, int mod) {
    switch(mod) {
      case 0 :
        gfx.fillRoundRect(x0+4, yv-y0, w-8, y0-y1, 15, Mycolor[clor0]);
        break;
      case 1 :
        gfx.fillRoundRect(x0+2, yv-y0, w-4, y0-y1, 15, Mycolor[clor0]);
        gfx.fillRoundRect(wwv-(x0+w-2), yv-y0, w-4, y0-y1, 15, Mycolor[clor0]);
        break;
      case 2 :
        gfx.fillRoundRect(x0+4, yv-y0, w-8, y0-y1, 15, Mycolor[clor0]);
        gfx.fillRoundRect(x0+4, yv+y1, w-8, y0-y1, 15, Mycolor[clor0]);
        break;
      case 3 :
        gfx.fillRoundRect(x0+2, yv-y0, w-4, y0-y1, 15, Mycolor[clor0]);
        gfx.fillRoundRect(x0+2, yv+y1, w-4, y0-y1, 15, Mycolor[clor0]);
        gfx.fillRoundRect(wwv-(x0+w-2), yv-y0, w-4, y0-y1, 15, Mycolor[clor0]);
        gfx.fillRoundRect(wwv-(x0+w-2), yv+y1, w-4, y0-y1, 15, Mycolor[clor0]);
        break;
      case 4 :
        gfx.fillRoundRect(x0+4, yv-y0, w-8, y0-y1, 15, Mycolor[clor0]);
        gfx.drawRoundRect(x0+4, yv-y0, w-8, y0-y1, 15, Mycolor[clor1]);
        break;
      case 5 :
        gfx.fillRoundRect(x0+2, yv-y0, w-4, y0-y1, 15, Mycolor[clor0]);
        gfx.fillRoundRect(wwv-(x0+w-2), yv-y0, w-4, y0-y1, 15, Mycolor[clor0]);
        gfx.drawRoundRect(x0+2, yv-y0, w-4, y0-y1, 15, Mycolor[clor1]);
        gfx.drawRoundRect(wwv-(x0+w-2), yv-y0, w-4, y0-y1, 15, Mycolor[clor1]);
        break;
      case 6 :
        gfx.fillRoundRect(x0+4, yv-y0, w-8, y0-y1, 15, Mycolor[clor0]);
        gfx.fillRoundRect(x0+4, yv+y1, w-8, y0-y1, 15, Mycolor[clor0]);
        gfx.drawRoundRect(x0+4, yv-y0, w-8, y0-y1, 15, Mycolor[clor1]);
        gfx.drawRoundRect(x0+4, yv+y1, w-8, y0-y1, 15, Mycolor[clor1]);
        break;
      case 7 :
        gfx.fillRoundRect(x0+2, yv-y0, w-4, y0-y1, 15, Mycolor[clor0]);
        gfx.fillRoundRect(x0+2, yv+y1, w-4, y0-y1, 15, Mycolor[clor0]);
        gfx.fillRoundRect(wwv-(x0+w-2), yv-y0, w-4, y0-y1, 15, Mycolor[clor0]);
        gfx.fillRoundRect(wwv-(x0+w-2), yv+y1, w-4, y0-y1, 15, Mycolor[clor0]);
        gfx.drawRoundRect(x0+2, yv-y0, w-4, y0-y1, 15, Mycolor[clor1]);
        gfx.drawRoundRect(x0+2, yv+y1, w-4, y0-y1, 15, Mycolor[clor1]);
        gfx.drawRoundRect(wwv-(x0+w-2), yv-y0, w-4, y0-y1, 15, Mycolor[clor1]);
        gfx.drawRoundRect(wwv-(x0+w-2), yv+y1, w-4, y0-y1, 15, Mycolor[clor1]);
        break;
      case 8 :
        gfx.fillRoundRect(x0+6, yv-y0, w-12, y0-y1, 15, Mycolor[clor0]);
        gfx.drawRoundRect(x0+4, yv-y0, w-8, y0, 15, Mycolor[clor1]);
        break;
      case 9 :
        gfx.fillRoundRect(x0+4, yv-y0, w-8, y0-y1, 15, Mycolor[clor0]);
        gfx.fillRoundRect(wwv-(x0+w-4), yv-y0, w-8, y0-y1, 15, Mycolor[clor0]);
        gfx.drawRoundRect(x0+2, yv-y0, w-4, y0, 15, Mycolor[clor1]);
        gfx.drawRoundRect(wwv-(x0+w-2), yv-y0, w-4, y0, 15, Mycolor[clor1]);
        break;
      case 10 :
        gfx.fillRoundRect(x0+6, yv-y0, w-12, y0-y1, 15, Mycolor[clor0]);
        gfx.fillRoundRect(x0+6, yv+y1, w-12, y0-y1, 15, Mycolor[clor0]);
        gfx.drawRoundRect(x0+4, yv-y0, w-8, y0*2, 15, Mycolor[clor1]);
        break;
      case 11 :
        gfx.fillRoundRect(x0+4, yv-y0, w-8, y0-y1, 15, Mycolor[clor0]);
        gfx.fillRoundRect(x0+4, yv+y1, w-8, y0-y1, 15, Mycolor[clor0]);
        gfx.fillRoundRect(wwv-(x0+w-4), yv-y0, w-8, y0-y1, 15, Mycolor[clor0]);
        gfx.fillRoundRect(wwv-(x0+w-4), yv+y1, w-8, y0-y1, 15, Mycolor[clor0]);
        gfx.drawRoundRect(x0+2, yv-y0, w-4, y0*2, 15, Mycolor[clor1]);
        gfx.drawRoundRect(wwv-(x0+w-2), yv-y0, w-4, y0*2, 15, Mycolor[clor1]);
        break;
    }
  }
  
void DrawMusicB0(int x0, int y0, int l0, int l1, int nl0, int nl1, int yd0, int yd1, int dw0, int wwv, uint8_t clor0, uint8_t clor1, uint8_t clor2, int mod) {
  switch(mod) {
    case 0 :
        gfx.fillCare(x0, y0-yd0+2, x0, y0-yd0, x0+dw0, y0-yd1, x0+dw0, y0-yd1+2, Mycolor[clor2]);
        gfx.fillCare(x0, y0-l1, x0, y0-l0, x0+dw0, y0-nl0, x0+dw0, y0-nl1, Mycolor[clor1]);
        break;
    case 1 :
        gfx.fillCare(x0, y0-yd0+2, x0, y0-yd0, x0+dw0, y0-yd1, x0+dw0, y0-yd1+2, Mycolor[clor2]);
        gfx.fillCare(x0, y0+yd0, x0, y0+yd0-2, x0+dw0, y0+yd1-2, x0+dw0, y0+yd1, Mycolor[clor2]);
        gfx.fillCare(x0, y0-l1, x0, y0-l0, x0+dw0, y0-nl0, x0+dw0, y0-nl1, Mycolor[clor1]);
        gfx.fillCare(x0, y0+l1, x0, y0+l0, x0+dw0, y0+nl0, x0+dw0, y0+nl1, Mycolor[clor1]);
        break;
    case 2 :
        gfx.fillCare(x0, y0-yd0+2, x0, y0-yd0, x0+dw0, y0-yd1, x0+dw0, y0-yd1+2, Mycolor[clor2]);
        gfx.fillCare(wwv-x0-dw0, y0-yd1+2, wwv-x0-dw0, y0-yd1, wwv-x0, y0-yd0, wwv-x0, y0-yd0+2, Mycolor[clor2]);
        gfx.fillCare(x0, y0-l1, x0, y0-l0, x0+dw0, y0-nl0, x0+dw0, y0-nl1, Mycolor[clor1]);
        gfx.fillCare(wwv-x0-dw0, y0-nl1, wwv-x0-dw0, y0-nl0, wwv-x0, y0-l0, wwv-x0, y0-l1, Mycolor[clor1]);
        break;
    case 3 :
        gfx.fillCare(x0, y0-yd0+2, x0, y0-yd0, x0+dw0, y0-yd1, x0+dw0, y0-yd1+2, Mycolor[clor2]);
        gfx.fillCare(x0, y0+yd0, x0, y0+yd0-2, x0+dw0, y0+yd1-2, x0+dw0, y0+yd1, Mycolor[clor2]);
        gfx.fillCare(wwv-x0-dw0, y0-yd1+2, wwv-x0-dw0, y0-yd1, wwv-x0, y0-yd0, wwv-x0, y0-yd0+2, Mycolor[clor2]);
        gfx.fillCare(wwv-x0-dw0, y0+yd1, wwv-x0-dw0, y0+yd1-2, wwv-x0, y0+yd0-2, wwv-x0, y0+yd0, Mycolor[clor2]);
        gfx.fillCare(x0, y0-l1, x0, y0-l0, x0+dw0, y0-nl0, x0+dw0, y0-nl1, Mycolor[clor1]);
        gfx.fillCare(x0, y0+l1, x0, y0+l0, x0+dw0, y0+nl0, x0+dw0, y0+nl1, Mycolor[clor1]);
        gfx.fillCare(wwv-x0-dw0, y0-nl1, wwv-x0-dw0, y0-nl0, wwv-x0, y0-l0, wwv-x0, y0-l1, Mycolor[clor1]);
        gfx.fillCare(wwv-x0-dw0, y0+nl1, wwv-x0-dw0, y0+nl0, wwv-x0, y0+l0, wwv-x0, y0+l1, Mycolor[clor1]);
        break;
    case 4 :
        gfx.fillCare(x0, y0-yd0+2, x0, y0-yd0, x0+dw0, y0-yd1, x0+dw0, y0-yd1+2, Mycolor[clor2]);
        gfx.fillCare(x0, y0-l1, x0, y0-l0, x0+dw0, y0-nl0, x0+dw0, y0-nl1, Mycolor[clor0]);
        gfx.fillCare(x0, y0, x0, y0-l1, x0+dw0, y0-nl1, x0+dw0, y0, Mycolor[clor1]);
        break;
    case 5 :
        gfx.fillCare(x0, y0-yd0+2, x0, y0-yd0, x0+dw0, y0-yd1, x0+dw0, y0-yd1+2, Mycolor[clor2]);
        gfx.fillCare(x0, y0+yd0, x0, y0+yd0-2, x0+dw0, y0+yd1-2, x0+dw0, y0+yd1, Mycolor[clor2]);
        gfx.fillCare(x0, y0-l1, x0, y0-l0, x0+dw0, y0-nl0, x0+dw0, y0-nl1, Mycolor[clor0]);
        gfx.fillCare(x0, y0+l1, x0, y0+l0, x0+dw0, y0+nl0, x0+dw0, y0+nl1, Mycolor[clor0]);
        gfx.fillCare(x0, y0, x0, y0-l1, x0+dw0, y0-nl1, x0+dw0, y0, Mycolor[clor1]);
        gfx.fillCare(x0, y0+l1, x0, y0, x0+dw0, y0, x0+dw0, y0+nl1, Mycolor[clor1]);
        break;
    case 6 :
        gfx.fillCare(x0, y0-yd0+2, x0, y0-yd0, x0+dw0, y0-yd1, x0+dw0, y0-yd1+2, Mycolor[clor2]);
        gfx.fillCare(wwv-x0-dw0, y0-yd1+2, wwv-x0-dw0, y0-yd1, wwv-x0, y0-yd0, wwv-x0, y0-yd0+2, Mycolor[clor2]);
        gfx.fillCare(x0, y0-l1, x0, y0-l0, x0+dw0, y0-nl0, x0+dw0, y0-nl1, Mycolor[clor0]);
        gfx.fillCare(wwv-x0-dw0, y0-nl1, wwv-x0-dw0, y0-nl0, wwv-x0, y0-l0, wwv-x0, y0-l1, Mycolor[clor0]);
        gfx.fillCare(x0, y0, x0, y0-l1, x0+dw0, y0-nl1, x0+dw0, y0, Mycolor[clor1]);
        gfx.fillCare(wwv-x0-dw0, y0, wwv-x0-dw0, y0-nl1, wwv-x0, y0-l1, wwv-x0, y0, Mycolor[clor1]);
        break;
    case 7 :
        gfx.fillCare(x0, y0-yd0+2, x0, y0-yd0, x0+dw0, y0-yd1, x0+dw0, y0-yd1+2, Mycolor[clor2]);
        gfx.fillCare(x0, y0+yd0, x0, y0+yd0-2, x0+dw0, y0+yd1-2, x0+dw0, y0+yd1, Mycolor[clor2]);
        gfx.fillCare(wwv-x0-dw0, y0-yd1+2, wwv-x0-dw0, y0-yd1, wwv-x0, y0-yd0, wwv-x0, y0-yd0+2, Mycolor[clor2]);
        gfx.fillCare(wwv-x0-dw0, y0+yd1, wwv-x0-dw0, y0+yd1-2, wwv-x0, y0+yd0-2, wwv-x0, y0+yd0, Mycolor[clor2]);
        gfx.fillCare(x0, y0-l1, x0, y0-l0, x0+dw0, y0-nl0, x0+dw0, y0-nl1, Mycolor[clor0]);
        gfx.fillCare(x0, y0+l1, x0, y0+l0, x0+dw0, y0+nl0, x0+dw0, y0+nl1, Mycolor[clor0]);
        gfx.fillCare(wwv-x0-dw0, y0-nl1, wwv-x0-dw0, y0-nl0, wwv-x0, y0-l0, wwv-x0, y0-l1, Mycolor[clor0]);
        gfx.fillCare(wwv-x0-dw0, y0+nl1, wwv-x0-dw0, y0+nl0, wwv-x0, y0+l0, wwv-x0, y0+l1, Mycolor[clor0]);
        gfx.fillCare(x0, y0, x0, y0-l1, x0+dw0, y0-nl1, x0+dw0, y0, Mycolor[clor1]);
        gfx.fillCare(wwv-x0-dw0, y0, wwv-x0-dw0, y0-nl1, wwv-x0, y0-l1, wwv-x0, y0, Mycolor[clor1]);
        gfx.fillCare(x0, y0+l1, x0, y0, x0+dw0, y0, x0+dw0, y0+nl1, Mycolor[clor1]);
        gfx.fillCare(wwv-x0-dw0, y0+nl1, wwv-x0-dw0, y0, wwv-x0, y0, wwv-x0, y0+l1, Mycolor[clor1]);
        break;
    case 8 :
        gfx.fillCare(x0, y0-yd0+2, x0, y0-yd0, x0+dw0, y0-yd1, x0+dw0, y0-yd1+2, Mycolor[clor2]);
        gfx.fillCare(x0, y0-l1, x0, y0-l0, x0+dw0, y0-nl0, x0+dw0, y0-nl1, Mycolor[clor1]);
        gfx.fillCare(x0, y0, x0, y0-l1, x0+dw0, y0-nl1, x0+dw0, y0, Mycolor[clor0]);
        break;
    case 9 :
        gfx.fillCare(x0, y0-yd0+2, x0, y0-yd0, x0+dw0, y0-yd1, x0+dw0, y0-yd1+2, Mycolor[clor2]);
        gfx.fillCare(x0, y0+yd0, x0, y0+yd0-2, x0+dw0, y0+yd1-2, x0+dw0, y0+yd1, Mycolor[clor2]);
        gfx.fillCare(x0, y0-l1, x0, y0-l0, x0+dw0, y0-nl0, x0+dw0, y0-nl1, Mycolor[clor1]);
        gfx.fillCare(x0, y0+l1, x0, y0+l0, x0+dw0, y0+nl0, x0+dw0, y0+nl1, Mycolor[clor1]);
        gfx.fillCare(x0, y0, x0, y0-l1, x0+dw0, y0-nl1, x0+dw0, y0, Mycolor[clor0]);
        gfx.fillCare(x0, y0+l1, x0, y0, x0+dw0, y0, x0+dw0, y0+nl1, Mycolor[clor0]);
        break;
    case 10 :
        gfx.fillCare(x0, y0-yd0+2, x0, y0-yd0, x0+dw0, y0-yd1, x0+dw0, y0-yd1+2, Mycolor[clor2]);
        gfx.fillCare(wwv-x0-dw0, y0-yd1+2, wwv-x0-dw0, y0-yd1, wwv-x0, y0-yd0, wwv-x0, y0-yd0+2, Mycolor[clor2]);
        gfx.fillCare(x0, y0-l1, x0, y0-l0, x0+dw0, y0-nl0, x0+dw0, y0-nl1, Mycolor[clor1]);
        gfx.fillCare(wwv-x0-dw0, y0-nl1, wwv-x0-dw0, y0-nl0, wwv-x0, y0-l0, wwv-x0, y0-l1, Mycolor[clor1]);
        gfx.fillCare(x0, y0, x0, y0-l1, x0+dw0, y0-nl1, x0+dw0, y0, Mycolor[clor0]);
        gfx.fillCare(wwv-x0-dw0, y0, wwv-x0-dw0, y0-nl1, wwv-x0, y0-l1, wwv-x0, y0, Mycolor[clor0]);
        break;
    case 11 :
        gfx.fillCare(x0, y0-yd0+2, x0, y0-yd0, x0+dw0, y0-yd1, x0+dw0, y0-yd1+2, Mycolor[clor2]);
        gfx.fillCare(x0, y0+yd0, x0, y0+yd0-2, x0+dw0, y0+yd1-2, x0+dw0, y0+yd1, Mycolor[clor2]);
        gfx.fillCare(wwv-x0-dw0, y0-yd1+2, wwv-x0-dw0, y0-yd1, wwv-x0, y0-yd0, wwv-x0, y0-yd0+2, Mycolor[clor2]);
        gfx.fillCare(wwv-x0-dw0, y0+yd1, wwv-x0-dw0, y0+yd1-2, wwv-x0, y0+yd0-2, wwv-x0, y0+yd0, Mycolor[clor2]);
        gfx.fillCare(x0, y0-l1, x0, y0-l0, x0+dw0, y0-nl0, x0+dw0, y0-nl1, Mycolor[clor1]);
        gfx.fillCare(x0, y0+l1, x0, y0+l0, x0+dw0, y0+nl0, x0+dw0, y0+nl1, Mycolor[clor1]);
        gfx.fillCare(wwv-x0-dw0, y0-nl1, wwv-x0-dw0, y0-nl0, wwv-x0, y0-l0, wwv-x0, y0-l1, Mycolor[clor1]);
        gfx.fillCare(wwv-x0-dw0, y0+nl1, wwv-x0-dw0, y0+nl0, wwv-x0, y0+l0, wwv-x0, y0+l1, Mycolor[clor1]);
        gfx.fillCare(x0, y0, x0, y0-l1, x0+dw0, y0-nl1, x0+dw0, y0, Mycolor[clor0]);
        gfx.fillCare(wwv-x0-dw0, y0, wwv-x0-dw0, y0-nl1, wwv-x0, y0-l1, wwv-x0, y0, Mycolor[clor0]);
        gfx.fillCare(x0, y0+l1, x0, y0, x0+dw0, y0, x0+dw0, y0+nl1, Mycolor[clor0]);
        gfx.fillCare(wwv-x0-dw0, y0+nl1, wwv-x0-dw0, y0, wwv-x0, y0, wwv-x0, y0+l1, Mycolor[clor0]);
        break;
  }
}
  void DrawMusicB1(int x0, int y0, int l0, int l1, int yd0, int dw0, int wwv, uint8_t clor0, uint8_t clor1, uint8_t clor2, int mod) {
    switch(mod) {
      case 0 :
        gfx.DemifillEllipse(x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillEllipse(x0, y0-l1, (dw0/2)-4, l0-l1, Mycolor[clor1]);
        break;
      case 1 :
        gfx.DemifillEllipse(x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillEllipse(x0, y0, (dw0/2)-4, l0, Mycolor[clor0]);
        gfx.DemifillEllipse(x0, y0, (dw0/2)-6, l1, Mycolor[clor1]);
        break;
      case 2 :
        gfx.DemifillEllipse(x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillEllipse(x0, y0+yd0, (dw0/2)-2, 3, Mycolor[clor2], false);
        gfx.DemifillEllipse(x0, y0-l1, (dw0/2)-2, l0-l1, Mycolor[clor1]);
        gfx.DemifillEllipse(x0, y0+l1, (dw0/2)-2, l0-l1, Mycolor[clor1], false);
        break;
      case 3 :
        gfx.DemifillEllipse(x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillEllipse(x0, y0+yd0, (dw0/2)-2, 3, Mycolor[clor2], false);
        gfx.fillEllipse(x0, y0, (dw0/2)-4, l0, Mycolor[clor0]);
        gfx.fillEllipse(x0, y0, (dw0/2)-6, l1, Mycolor[clor1]);
        break;
      case 4 :
        gfx.DemifillEllipse(x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillEllipse(wwv-x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillEllipse(x0, y0-l1, (dw0/2)-3, l0-l1, Mycolor[clor1]);
        gfx.DemifillEllipse(wwv-x0, y0-l1, (dw0/2)-3, l0-l1, Mycolor[clor1]);
        break;
      case 5 :
        gfx.DemifillEllipse(x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillEllipse(wwv-x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillEllipse(x0, y0, (dw0/2)-2, l0, Mycolor[clor0]);
        gfx.DemifillEllipse(x0, y0, (dw0/2)-3, l1, Mycolor[clor1]);
        gfx.DemifillEllipse(wwv-x0, y0, (dw0/2)-2, l0, Mycolor[clor0]);
        gfx.DemifillEllipse(wwv-x0, y0, (dw0/2)-3, l1, Mycolor[clor1]);
        break;
      case 6 :
        gfx.DemifillEllipse(x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillEllipse(wwv-x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillEllipse(x0, y0+yd0, (dw0/2)-2, 3, Mycolor[clor2], false);
        gfx.DemifillEllipse(wwv-x0, y0+yd0, (dw0/2)-2, 3, Mycolor[clor2], false);
        gfx.DemifillEllipse(x0, y0-l1, (dw0/2)-3, l0-l1, Mycolor[clor1]);
        gfx.DemifillEllipse(wwv-x0, y0-l1, (dw0/2)-3, l0-l1, Mycolor[clor1]);
        gfx.DemifillEllipse(x0, y0+l1, (dw0/2)-3, l0-l1, Mycolor[clor1], false);
        gfx.DemifillEllipse(wwv-x0, y0+l1, (dw0/2)-3, l0-l1, Mycolor[clor1], false);
        break;
      case 7 :
        gfx.DemifillEllipse(x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillEllipse(wwv-x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillEllipse(x0, y0+yd0, (dw0/2)-2, 3, Mycolor[clor2], false);
        gfx.DemifillEllipse(wwv-x0, y0+yd0, (dw0/2)-2, 3, Mycolor[clor2], false);
        gfx.fillEllipse(x0, y0, (dw0/2)-2, l0, Mycolor[clor0]);
        gfx.fillEllipse(x0, y0, (dw0/2)-3, l1, Mycolor[clor1]);
        gfx.fillEllipse(wwv-x0, y0, (dw0/2)-2, l0, Mycolor[clor0]);
        gfx.fillEllipse(wwv-x0, y0, (dw0/2)-3, l1, Mycolor[clor1]);
        break;
      case 8 :
        gfx.DemifillEllipse(x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillEllipse(x0, y0, (dw0/2)-4, l0, Mycolor[clor1]);
        gfx.DemifillEllipse(x0, y0, (dw0/2)-6, l1, Mycolor[clor0]);
        break;
      case 9 :
        gfx.DemifillEllipse(x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillEllipse(x0, y0+yd0, (dw0/2)-2, 3, Mycolor[clor2], false);
        gfx.fillEllipse(x0, y0, (dw0/2)-4, l0, Mycolor[clor1]);
        gfx.fillEllipse(x0, y0, (dw0/2)-6, l1, Mycolor[clor0]);
        break;
      case 10 :
        gfx.DemifillEllipse(x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillEllipse(wwv-x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillEllipse(x0, y0, (dw0/2)-2, l0, Mycolor[clor1]);
        gfx.DemifillEllipse(x0, y0, (dw0/2)-3, l1, Mycolor[clor0]);
        gfx.DemifillEllipse(wwv-x0, y0, (dw0/2)-2, l0, Mycolor[clor1]);
        gfx.DemifillEllipse(wwv-x0, y0, (dw0/2)-3, l1, Mycolor[clor0]);
        break;
      case 11 :
        gfx.DemifillEllipse(x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillEllipse(wwv-x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillEllipse(x0, y0+yd0, (dw0/2)-2, 3, Mycolor[clor2], false);
        gfx.DemifillEllipse(wwv-x0, y0+yd0, (dw0/2)-2, 3, Mycolor[clor2], false);
        gfx.fillEllipse(x0, y0, (dw0/2)-2, l0, Mycolor[clor0]);
        gfx.fillEllipse(x0, y0, (dw0/2)-4, l1, Mycolor[clor1]);
        gfx.fillEllipse(wwv-x0, y0, (dw0/2)-2, l0, Mycolor[clor0]);
        gfx.fillEllipse(wwv-x0, y0, (dw0/2)-4, l1, Mycolor[clor1]);
        break;
      case 12 :
        gfx.DemifillParall(x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillParall(x0, y0-l1, (dw0/2)-4, l0-l1, Mycolor[clor1]);
        break;
      case 13 :
        gfx.DemifillParall(x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillParall(x0, y0, (dw0/2)-4, l0, Mycolor[clor0]);
        gfx.DemifillParall(x0, y0, (dw0/2)-6, l1, Mycolor[clor1]);
        break;
      case 14 :
        gfx.DemifillParall(x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillParall(x0, y0+yd0, (dw0/2)-2, 3, Mycolor[clor2], false);
        gfx.DemifillParall(x0, y0-l1, (dw0/2)-2, l0-l1, Mycolor[clor1]);
        gfx.DemifillParall(x0, y0+l1, (dw0/2)-2, l0-l1, Mycolor[clor1], false);
        break;
      case 15 :
        gfx.DemifillParall(x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillParall(x0, y0+yd0, (dw0/2)-2, 3, Mycolor[clor2], false);
        gfx.fillParallelogram(x0, y0, (dw0/2)-4, l0, Mycolor[clor0]);
        gfx.fillParallelogram(x0, y0, (dw0/2)-8, l1, Mycolor[clor1]);
        break;
      case 16 :
        gfx.DemifillParall(x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillParall(wwv-x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillParall(x0, y0-l1, (dw0/2)-4, l0-l1, Mycolor[clor0]);
        gfx.DemifillParall(wwv-x0, y0-l1, (dw0/2)-4, l0-l1, Mycolor[clor1]);
        break;
      case 17 :
        gfx.DemifillParall(x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillParall(wwv-x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillParall(x0, y0, (dw0/2)-2, l0, Mycolor[clor0]);
        gfx.DemifillParall(x0, y0, (dw0/2)-4, l1, Mycolor[clor1]);
        gfx.DemifillParall(wwv-x0, y0, (dw0/2)-2, l0, Mycolor[clor0]);
        gfx.DemifillParall(wwv-x0, y0, (dw0/2)-4, l1, Mycolor[clor1]);
        break;
      case 18 :
        gfx.DemifillParall(x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillParall(wwv-x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillParall(x0, y0+yd0, (dw0/2)-2, 3, Mycolor[clor2], false);
        gfx.DemifillParall(wwv-x0, y0+yd0, (dw0/2)-2, 3, Mycolor[clor2], false);
        gfx.DemifillParall(x0, y0-l1, (dw0/2)-4, l0-l1, Mycolor[clor1]);
        gfx.DemifillParall(wwv-x0, y0-l1, (dw0/2)-4, l0-l1, Mycolor[clor1]);
        gfx.DemifillParall(x0, y0+l1, (dw0/2)-4, l0-l1, Mycolor[clor1], false);
        gfx.DemifillParall(wwv-x0, y0+l1, (dw0/2)-4, l0-l1, Mycolor[clor1], false);
        break;
      case 19 :
        gfx.DemifillParall(x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillParall(wwv-x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillParall(x0, y0+yd0, (dw0/2)-2, 3, Mycolor[clor2], false);
        gfx.DemifillParall(wwv-x0, y0+yd0, (dw0/2)-2, 3, Mycolor[clor2], false);
        gfx.fillParallelogram(x0, y0, (dw0/2)-2, l0, Mycolor[clor1]);
        gfx.fillParallelogram(x0, y0, (dw0/2)-4, l1, Mycolor[clor0]);
        gfx.fillParallelogram(wwv-x0, y0, (dw0/2)-2, l0, Mycolor[clor1]);
        gfx.fillParallelogram(wwv-x0, y0, (dw0/2)-4, l1, Mycolor[clor0]);
        break;
      case 20 :
        gfx.DemifillParall(x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillParall(x0, y0, (dw0/2)-4, l0, Mycolor[clor1]);
        gfx.DemifillParall(x0, y0, (dw0/2)-8, l1, Mycolor[clor0]);
        break;
      case 21 :
        gfx.DemifillParall(x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillParall(x0, y0+yd0, (dw0/2)-2, 3, Mycolor[clor2], false);
        gfx.fillParallelogram(x0, y0, (dw0/2)-4, l0, Mycolor[clor1]);
        gfx.fillParallelogram(x0, y0, (dw0/2)-8, l1, Mycolor[clor0]);
        break;
      case 22 :
        gfx.DemifillParall(x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillParall(wwv-x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillParall(x0, y0, (dw0/2)-2, l0, Mycolor[clor1]);
        gfx.DemifillParall(x0, y0, (dw0/2)-4, l1, Mycolor[clor0]);
        gfx.DemifillParall(wwv-x0, y0, (dw0/2)-2, l0, Mycolor[clor1]);
        gfx.DemifillParall(wwv-x0, y0, (dw0/2)-4, l1, Mycolor[clor0]);
        break;
      case 23 :
        gfx.DemifillParall(x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillParall(wwv-x0, y0-yd0, (dw0/2)-2, 3, Mycolor[clor2]);
        gfx.DemifillParall(x0, y0+yd0, (dw0/2)-2, 3, Mycolor[clor2], false);
        gfx.DemifillParall(wwv-x0, y0+yd0, (dw0/2)-2, 3, Mycolor[clor2], false);
        gfx.fillParallelogram(x0, y0, (dw0/2)-2, l0, Mycolor[clor1]);
        gfx.fillParallelogram(x0, y0, (dw0/2)-4, l1, Mycolor[clor0]);
        gfx.fillParallelogram(wwv-x0, y0, (dw0/2)-2, l0, Mycolor[clor1]);
        gfx.fillParallelogram(wwv-x0, y0, (dw0/2)-4, l1, Mycolor[clor0]);
        break;
    }
  }
  void DrawMusicB2(int cx, int cy, int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3, int xd0, int yd0, int xd1, int yd1, uint8_t clor0, uint8_t clor1, uint8_t clor2, int mod) {
    switch(mod) {
      case 0 :
        gfx.fillCare(cx+xd0-2, cy-yd0-2, cx+xd0, cy-yd0, cx+xd1, cy-yd1, cx+xd1-2, cy-yd1-2, Mycolor[clor2]);
        gfx.fillCare(cx+x1, cy-y1, cx+x0, cy-y0, cx+x2, cy-y2, cx+x3, cy-y3, Mycolor[clor1]);
        break;
      case 1 :
        gfx.fillCare(cx+xd0-2, cy-yd0-2, cx+xd0, cy-yd0, cx+xd1, cy-yd1, cx+xd1-2, cy-yd1-2, Mycolor[clor2]);
        gfx.fillCare(cx+xd0-2, cy+yd0+2, cx+xd0, cy+yd0, cx+xd1, cy+yd1, cx+xd1-2, cy+yd1+2, Mycolor[clor2]);
        gfx.fillCare(cx+x1, cy-y1, cx+x0, cy-y0, cx+x2, cy-y2, cx+x3, cy-y3, Mycolor[clor1]);
        gfx.fillCare(cx+x0, cy+y0, cx+x1, cy+y1, cx+x3, cy+y3, cx+x2, cy+y2, Mycolor[clor1]);
        break;
      case 2 :
        gfx.fillCare(cx+xd0-2, cy-yd0-2, cx+xd0, cy-yd0, cx+xd1, cy-yd1, cx+xd1-2, cy-yd1-2, Mycolor[clor2]);
        gfx.fillCare(cx+xd0-2, cy+yd0+2, cx+xd0, cy+yd0, cx+xd1, cy+yd1, cx+xd1-2, cy+yd1+2, Mycolor[clor2]);
        gfx.fillCare(cx-xd0+2, cy-yd0-2, cx-xd0, cy-yd0, cx-xd1, cy-yd1, cx-xd1+2, cy-yd1-2, Mycolor[clor2]);
        gfx.fillCare(cx-xd0+2, cy+yd0+2, cx-xd0, cy+yd0, cx-xd1, cy+yd1, cx-xd1+2, cy+yd1+2, Mycolor[clor2]);
        gfx.fillCare(cx+x1, cy-y1, cx+x0, cy-y0, cx+x2, cy-y2, cx+x3, cy-y3, Mycolor[clor1]);
        gfx.fillCare(cx+x0, cy+y0, cx+x1, cy+y1, cx+x3, cy+y3, cx+x2, cy+y2, Mycolor[clor1]);
        gfx.fillCare(cx-x3, cy-y3, cx-x2, cy-y2, cx-x0, cy-y0, cx-x1, cy-y1, Mycolor[clor1]);
        gfx.fillCare(cx-x2, cy+y2, cx-x3, cy+y3, cx-x1, cy+y1, cx-x0, cy+y0, Mycolor[clor1]);
        break;
      case 3 :
        gfx.fillCare(cx+xd0-2, cy-yd0-2, cx+xd0, cy-yd0, cx+xd1, cy-yd1, cx+xd1-2, cy-yd1-2, Mycolor[clor2]);
        gfx.fillCare(cx+xd0-2, cy+yd0+2, cx+xd0, cy+yd0, cx+xd1, cy+yd1, cx+xd1-2, cy+yd1+2, Mycolor[clor2]);
        gfx.fillCare(cx-xd0+2, cy-yd0-2, cx-xd0, cy-yd0, cx-xd1, cy-yd1, cx-xd1+2, cy-yd1-2, Mycolor[clor2]);
        gfx.fillCare(cx-xd0+2, cy+yd0+2, cx-xd0, cy+yd0, cx-xd1, cy+yd1, cx-xd1+2, cy+yd1+2, Mycolor[clor2]);
        gfx.fillCare(cx+x1, cy-y1, cx+x0, cy-y0, cx+x2, cy-y2, cx+x3, cy-y3, Mycolor[clor1]);
        gfx.fillCare(cx+x0, cy+y0, cx+x1, cy+y1, cx+x3, cy+y3, cx+x2, cy+y2, Mycolor[clor1]);
        gfx.fillCare(cx-x3, cy-y3, cx-x2, cy-y2, cx-x0, cy-y0, cx-x1, cy-y1, Mycolor[clor1]);
        gfx.fillCare(cx-x2, cy+y2, cx-x3, cy+y3, cx-x1, cy+y1, cx-x0, cy+y0, Mycolor[clor1]);
        gfx.fillTriangle(cx, cy, cx+x1, cy-y1, cx+x3, cy-y3, Mycolor[clor0]);
        gfx.fillTriangle(cx, cy, cx+x1, cy+y1, cx+x3, cy+y3, Mycolor[clor0]);
        gfx.fillTriangle(cx, cy, cx-x3, cy-y3, cx-x1, cy-y1, Mycolor[clor0]);
        gfx.fillTriangle(cx, cy, cx-x3, cy+y3, cx-x1, cy+y1, Mycolor[clor0]);
        break;
      case 4 :
        gfx.fillCare(cx+xd0-2, cy-yd0-2, cx+xd0, cy-yd0, cx+xd1, cy-yd1, cx+xd1-2, cy-yd1-2, Mycolor[clor2]);
        gfx.fillCare(cx-xd0+2, cy-yd0-2, cx-xd0, cy-yd0, cx-xd1, cy-yd1, cx-xd1+2, cy-yd1-2, Mycolor[clor2]);
        gfx.fillCare(cx+x1, cy-y1, cx+x0, cy-y0, cx+x2, cy-y2, cx+x3, cy-y3, Mycolor[clor1]);
        gfx.fillCare(cx-x3, cy-y3, cx-x2, cy-y2, cx-x0, cy-y0, cx-x1, cy-y1, Mycolor[clor1]);
        break;
      case 5 :
        gfx.fillCare(cx+xd0-2, cy-yd0-2, cx+xd0, cy-yd0, cx+xd1, cy-yd1, cx+xd1-2, cy-yd1-2, Mycolor[clor2]);
        gfx.fillCare(cx-xd0+2, cy-yd0-2, cx-xd0, cy-yd0, cx-xd1, cy-yd1, cx-xd1+2, cy-yd1-2, Mycolor[clor2]);
        gfx.fillCare(cx+x1, cy-y1, cx+x0, cy-y0, cx+x2, cy-y2, cx+x3, cy-y3, Mycolor[clor1]);
        gfx.fillCare(cx-x3, cy-y3, cx-x2, cy-y2, cx-x0, cy-y0, cx-x1, cy-y1, Mycolor[clor1]);
        gfx.fillTriangle(cx, cy, cx+x1, cy-y1, cx+x3, cy-y3, Mycolor[clor0]);
        gfx.fillTriangle(cx, cy, cx-x3, cy-y3, cx-x1, cy-y1, Mycolor[clor0]);
        break;
      case 6 :
        gfx.fillCare(cx+xd0-2, cy-yd0-2, cx+xd0, cy-yd0, cx+xd1, cy-yd1, cx+xd1-2, cy-yd1-2, Mycolor[clor2]);
        gfx.fillCare(cx+x1, cy-y1, cx+x0, cy-y0, cx+x2, cy-y2, cx+x3, cy-y3, Mycolor[clor1]);
        gfx.fillTriangle(cx, cy, cx+x1, cy-y1, cx+x3, cy-y3, Mycolor[clor0]);
        break;
      case 7 :
        gfx.fillCare(cx+xd0-2, cy-yd0-2, cx+xd0, cy-yd0, cx+xd1, cy-yd1, cx+xd1-2, cy-yd1-2, Mycolor[clor2]);
        gfx.fillCare(cx+xd0-2, cy+yd0+2, cx+xd0, cy+yd0, cx+xd1, cy+yd1, cx+xd1-2, cy+yd1+2, Mycolor[clor2]);
        gfx.fillCare(cx+x1, cy-y1, cx+x0, cy-y0, cx+x2, cy-y2, cx+x3, cy-y3, Mycolor[clor1]);
        gfx.fillCare(cx+x0, cy+y0, cx+x1, cy+y1, cx+x3, cy+y3, cx+x2, cy+y2, Mycolor[clor1]);
        gfx.fillTriangle(cx, cy, cx+x1, cy-y1, cx+x3, cy-y3, Mycolor[clor0]);
        gfx.fillTriangle(cx, cy, cx+x1, cy+y1, cx+x3, cy+y3, Mycolor[clor0]);
        break;
    }
  }
  void DrawMusicB3(int x0, int y0, int y1, int w, int wwv, uint8_t clor0, int mod) {
    switch(mod) {
      case 0 :
        gfx.Demiellipse(x0, y0, w, 3, Mycolor[clor0]);
        break;
      case 1 :
        gfx.Demiellipse(x0, y0, w, 3, Mycolor[clor0]);
        gfx.Demiellipse(wwv-x0, y0, w, 3, Mycolor[clor0]);
        break;
      case 2 :
        gfx.Demiellipse(x0, y0, w, 3, Mycolor[clor0]);
        gfx.Demiellipse(x0, y1, w, 3, Mycolor[clor0], false);
        break;
      case 3 :
        gfx.Demiellipse(x0, y0, w, 3, Mycolor[clor0]);
        gfx.Demiellipse(wwv-x0, y0, w, 3, Mycolor[clor0]);
        gfx.Demiellipse(x0, y1, w, 3, Mycolor[clor0], false);
        gfx.Demiellipse(wwv-x0, y1, w, 3, Mycolor[clor0], false);
        break;
    }
  }


  void DrawModeA0(int xval, int yval, int dw, int hval, int wwv, int mod) {
    col0 = map(hue+men, 0, 300, 0, 8) % 7;
    for(int x=0; x<numBands-1; x++) {
      int xd = (x * dw) + xval;
      int xn = x + 1;
      level0 = map(valBand0[x], 0 ,255, 0, hval);
      level1 = map(valBand1[x], 0 ,255, 0, hval);
      nextLevel0 = map(valBand0[xn], 0 ,255, 0, hval);
      nextLevel1 = map(valBand1[xn], 0 ,255, 0, hval);
      col1 = map((valBand0[x] + men), 0, 315, 0, 8) % 7;
      col2 = map((valBand1[x] + men), 0, 315, 0, 8) % 7;
      DrawMusicA0(xd, yval, level0, level1, nextLevel0, nextLevel1, dw, wwv, col0, col1, col2, mod);
      valBand0[x] = (valBand0[x]<sp1) ? 0 : (valBand0[x]-sp1);
    }
    valBand0[15] = (valBand0[15]<sp1) ? 0 : (valBand0[15]-sp1);
  }
  void DrawModeA1(int xval, int yval, int dw, int hval, int wwv, int mod) {
    col0 = map(hue+men, 0, 300, 0, 8) % 7;
    for(int x=0; x<numBands; x++) {
      int xd = (x * dw) + xval;
      level0 = map(valBand0[x], 0 ,255, 0, hval);
      level1 = map(valBand1[x], 0 ,255, 0, hval);
      col1 = map((valBand0[x] + men), 0, 315, 0, 8) % 7;
      col2 = map((valBand1[x] + men), 0, 315, 0, 8) % 7;
      DrawMusicA1(xd, yval, level0, level1, dw, wwv, col0, col1, col2, mod);
      valBand0[x] = (valBand0[x]<sp1) ? 0 : (valBand0[x]-sp1);
    }
  }
  void DrawModeA2(int cx, int cy, float rx, float ry, float degLine, int mod) {
    angle = -90.00f;
    col0 = map((hue+men), 0, 300, 0, 8) % 7;
    for(int x=0; x<numBands-1; x++) {
      int xn = x + 1;
      level0 = valBand0[x];
      level1 = valBand1[x];
      nextLevel0 = valBand0[xn];
      nextLevel1 = valBand1[xn];
      col1 = map((level0 + men), 0, 315, 0, 8) % 7;
      col2 = map((level1 + men), 0, 315, 0, 8) % 7;
      float radians = radians(angle);
      int x0 = level0 * rx * sin(radians) / 255;
      int y0 = level0 * ry * cos(radians) / 255;
      int x1 = level1 * rx * sin(radians) / 255;
      int y1 = level1 * ry * cos(radians) / 255;
      radians = radians(angle + degLine);
      int x2 = nextLevel0 * rx * sin(radians) / 255;
      int y2 = nextLevel0 * ry * cos(radians) / 255;
      int x3 = nextLevel1 * rx * sin(radians) / 255;
      int y3 = nextLevel1 * ry * cos(radians) / 255;
      DrawMusicA2(cx, cy, x0, y0, x1, y1, x2, y2, x3, y3, col0, col1, col2, mod);
      valBand0[x] = (valBand0[x]<sp1) ? 0 : (valBand0[x]-sp1);
      angle += degLine;
    }
    valBand0[15] = (valBand0[15]<sp1) ? 0 : (valBand0[15]-sp1);
  }
  void DrawModeA3(int xval, int yval, int dw, int hval, int wwv, int mod) {
    int dw0 = hval/numBands;
    for(int x=0; x<numBands; x++) {
      int xd0 = xval+(x*dw);
      level0 = map(valBand0[x], 0, 255, 0, numBands);
      level1 = map(valBand1[x], 0, 255, 0, numBands);
      col0 = (map(valBand0[x], 0, 255, 0, 8) + men) % 7;
      for (int y = level1; y < level0; y++) {
        int yd0 = yval - y * dw0;
        int yd1 = yval - dw0 + y * dw0;
        DrawMusicA3(xd0, yd0, yd1, dw, dw0, wwv, col0, mod);
      }
      valBand0[x] = (valBand0[x]<sp1) ? 0 : (valBand0[x]-sp1);
    }
  }
  void DrawModeA4(int xval, int yval, int dw, int hval, int wwv, int mod) {
    int dw0 = hval/numBands;
    for(int x=0; x<numBands; x++) {
      int xd0 = xval+(x*dw);
      level0 = map(valBand0[x], 0, 255, 0, numBands);
      level1 = map(valBand1[x], 0, 255, 0, numBands);
      col0 = (map(valBand0[x], 0, 255, 0, 8) + men) % 7;
      col1 = (map(valBand1[x], 0, 255, 0, 8) + men) % 7;
      for (int y = 0; y < level1; y++) {
        int yd0 = yval - y * dw0;
        int yd1 = yval - dw0 + y * dw0;
        DrawMusicA3(xd0, yd0, yd1, dw, dw0-1, wwv, col0, mod);
      }
      for (int y = level1; y < level0; y++) {
        int yd0 = yval - y * dw0;
        int yd1 = yval - dw0 + y * dw0;
        DrawMusicA3(xd0, yd0, yd1, dw, dw0-1, wwv, col1, mod);
      }
      valBand0[x] = (valBand0[x]<sp1) ? 0 : (valBand0[x]-sp1);
    }
  }
  void DrawModeA5(int xval, int yval, int dw, int hval, int wwv, int mod) {
    for(int x=0; x<numBands; x++) {
      int xd0 = xval+(x*dw);
      level0 = map(valBand0[x], 0, 255, 0, hval);
      level1 = map(valBand1[x], 0, 255, 0, hval);
      col0 = (map(valBand0[x], 0, 255, 0, 8) + men) % 7;
      col1 = (map(valBand1[x], 0, 255, 0, 8) + men) % 7;
      DrawMusicA5(xd0, yval, level0, level1, dw, wwv, col0, col1, mod);
      valBand0[x] = (valBand0[x]<sp1) ? 0 : (valBand0[x]-sp1);
    }
  }

  void DrawModeB0(int xval, int yval, int dw, int hval, int wwv, int mod) {
    col0 = map((hue+men), 0, 300, 0, 7) % 7;
    for(int x=0; x<numBands-1; x++) {
      int xd = (x * dw) + xval;
      int xn = x + 1;
      level0 = map(valBand0[x], 0 ,255, 0, hval);
      level1 = map(valBand1[x], 0 ,255, 0, hval);
      nextLevel0 = map(valBand0[xn], 0 ,255, 0, hval);
      nextLevel1 = map(valBand1[xn], 0 ,255, 0, hval);
      ydot0 = map(Exdot[x], 0 ,255, 0, hval);
      ydot1 = map(Exdot[xn], 0 ,255, 0, hval);
      col1 = map((valBand0[x] + men), 0, 300, 0, 7) % 7;
      col2 = map((Exdot[x] + men), 0, 300, 0, 7) % 7;
      DrawMusicB0(xd, yval, level0, level1, nextLevel0, nextLevel1, ydot0, ydot1, dw, wwv, col0, col1, col2, mod);
      valBand0[x] = (valBand0[x]<sp1) ? 0 : (valBand0[x]-sp1);
      Exdot[x]    = (Exdot[x]<sp2) ? 0 : (Exdot[x]-sp2);
    }
    valBand0[15] = (valBand0[15]<sp1) ? 0 : (valBand0[15]-sp1);
    Exdot[15]    = (Exdot[15]<sp2) ? 0 : (Exdot[15]-sp2);
  }
  void DrawModeB1(int xval, int yval, int dw, int hval, int wwv, int mod) {
    col0 = map((hue+men), 0, 300, 0, 7) % 7;
    for(int x=0; x<numBands; x++) {
      int xd = (x * dw) + xval;
      level0 = map(valBand0[x], 0 ,255, 0, hval);
      level1 = map(valBand1[x], 0 ,255, 0, hval);
      ydot0 = map(Exdot[x], 0 ,255, 0, hval);
      col1 = map((valBand0[x] + men), 0, 300, 0, 7) % 7;
      col2 = map((Exdot[x] + men), 0, 300, 0, 7) % 7;
      DrawMusicB1(xd, yval, level0, level1, ydot0, dw, wwv, col0, col1, col2, mod);
      valBand0[x] = (valBand0[x]<sp1) ? 0 : (valBand0[x]-sp1);
      Exdot[x]    = (Exdot[x]<sp2) ? 0 : (Exdot[x]-sp2);
    }
  }
  void DrawModeB2(int cx, int cy, float rx, float ry, float degLine, int mod) {
    angle = -90.00f;
    col0 = (map(hue, 0, 255, 0, 8) + men) % 7;
    for(int x=0; x<numBands-1; x++) {
      int xn = x + 1;
      level0 = valBand0[x];
      level1 = valBand1[x];
      nextLevel0 = valBand0[xn];
      nextLevel1 = valBand1[xn];
      ydot0 = Exdot[x];
      ydot1 = Exdot[xn];
      col1 = (map(level0, 0, 255, 0, 8) + men) % 7;
      col2 = (map(ydot0, 0, 255, 0, 8) + men) % 7;
      float radians = radians(angle);
      int x0 = level0 * rx * sin(radians) / 255;
      int y0 = level0 * ry * cos(radians) / 255;
      int x1 = level1 * rx * sin(radians) / 255;
      int y1 = level1 * ry * cos(radians) / 255;
      int xd0 = ydot0 * rx * sin(radians) / 255;
      int yd0 = ydot0 * ry * cos(radians) / 255;
      radians = radians(angle + degLine);
      int x2 = nextLevel0 * rx * sin(radians) / 255;
      int y2 = nextLevel0 * ry * cos(radians) / 255;
      int x3 = nextLevel1 * rx * sin(radians) / 255;
      int y3 = nextLevel1 * ry * cos(radians) / 255;
      int xd1 = ydot1 * rx * sin(radians) / 255;
      int yd1 = ydot1 * ry * cos(radians) / 255;
      DrawMusicB2(cx, cy, x0, y0, x1, y1, x2, y2, x3, y3, xd0, yd0, xd1, yd1, col0, col1, col2, mod);
      valBand0[x] = (valBand0[x]<sp1) ? 0 : (valBand0[x]-sp1);
      Exdot[x]    = (Exdot[x]<sp2) ? 0 : (Exdot[x]-sp2);
      angle += degLine;
    }
    valBand0[15] = (valBand0[15]<sp1) ? 0 : (valBand0[15]-sp1);
    Exdot[15]    = (Exdot[15]<sp2) ? 0 : (Exdot[15]-sp2);
  }
  void DrawModeB3(int xval, int yval, int dw, int hval, int wwv, int mod) {
    int dw0 = hval/numBands;
    for(int x=0; x<numBands; x++) {
      int xd0 = xval+(x*dw);
      level0 = map(valBand0[x], 0, 255, 0, numBands);
      level1 = map(valBand1[x], 0, 255, 0, numBands);
      int ydot = map(Exdot[x], 0, 255, 0, hval);
      ydot0 = yval - ydot;
      ydot1 = yval + ydot;
      col0 = (map(valBand0[x], 0, 255, 0, 8) + men) % 7;
      col1 = (map(Exdot[x], 0, 255, 0, 8) + men) % 7;
      DrawMusicB3(xd0+(dw/2), ydot0, ydot1, dw/2, wwv, col1, mod);
      for (int y = level1; y < level0; y++) {
        int yd0 = yval - y * dw0;
        int yd1 = yval - dw0 + y * dw0;
        DrawMusicA3(xd0, yd0, yd1, dw, dw0-1, wwv, col0, mod);
      }
      valBand0[x] = (valBand0[x]<sp1) ? 0 : (valBand0[x]-sp1);
      Exdot[x]    = (Exdot[x]<sp2) ? 0 : (Exdot[x]-sp2);
    }
  }
  void DrawModeB4(int xval, int yval, int dw, int hval, int wwv, int mod) {
    int dw0 = hval/numBands;
    for(int x=0; x<numBands; x++) {
      int xd0 = xval+(x*dw);
      level0 = map(valBand0[x], 0, 255, 0, numBands);
      level1 = map(valBand1[x], 0, 255, 0, numBands);
      int ydot = map(Exdot[x], 0, 255, 0, hval);
      ydot0 = yval - ydot;
      ydot1 = yval + ydot;
      col0 = (map(valBand0[x], 0, 255, 0, 8) + men) % 7;
      col1 = (map(valBand1[x], 0, 255, 0, 8) + men) % 7;
      col2 = (map(Exdot[x], 0, 255, 0, 8) + men) % 7;
      DrawMusicB3(xd0+(dw/2), ydot0, ydot1, dw/2, wwv, col2, mod);
      for (int y = 0; y < level1; y++) {
        int yd0 = yval - y * dw0;
        int yd1 = yval - dw0 + y * dw0;
        DrawMusicA3(xd0, yd0, yd1, dw, dw0-1, wwv, col0, mod);
      }
      for (int y = level1; y < level0; y++) {
        int yd0 = yval - y * dw0;
        int yd1 = yval - dw0 + y * dw0;
        DrawMusicA3(xd0, yd0, yd1, dw, dw0-1, wwv, col1, mod);
      }
      valBand0[x] = (valBand0[x]<sp1) ? 0 : (valBand0[x]-sp1);
      Exdot[x]    = (Exdot[x]<sp2) ? 0 : (Exdot[x]-sp2);
    }
  }
  void DrawModeB5(int xval, int yval, int dw, int hval, int wwv, int mod) {
    for(int x=0; x<numBands; x++) {
      int xd0 = xval+(x*dw);
      level0 = map(valBand0[x], 0, 255, 0, hval);
      level1 = map(valBand1[x], 0, 255, 0, hval);
      int ydot = map(Exdot[x], 0, 255, 0, hval);
      ydot0 = yval - ydot;
      ydot1 = yval + ydot;
      col0 = (map(valBand0[x], 0, 255, 0, 8) + men) % 7;
      col1 = (map(Exdot[x], 0, 255, 0, 8) + men) % 7;
      DrawMusicB3(xd0+(dw/2), ydot0, ydot1, dw/2, wwv, col1, mod%4);
      DrawMusicA5(xd0, yval, level0, level1, dw, wwv, col0, col1, mod);
      valBand0[x] = (valBand0[x]<sp1) ? 0 : (valBand0[x]-sp1);
      Exdot[x]    = (Exdot[x]<sp2) ? 0 : (Exdot[x]-sp2);
    }
  }

};

#endif
