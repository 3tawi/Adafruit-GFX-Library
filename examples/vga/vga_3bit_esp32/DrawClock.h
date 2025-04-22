/*
 * Written by 3tawi
- Lien vidéo: https://youtu.be/zPvuzV2fqaA
*/

#ifndef DrawClock_H
#define DrawClock_H

int hor, men, sec;

class DrawClock {
private:
    #define C_X 319
    #define C_Y 199
    #define bw 639
    #define bh 399
    int16_t xb = C_X;
    int16_t yb = C_Y;
    int16_t xfc = 3;
    int16_t yfc = 2;
    int16_t xfdir = -1;
    int16_t yfdir = -1;
    uint8_t col0, col1;
    int xdm0, ydm0;

public:


void Updatetime() {
  rtc.readTime();
  sec = rtc.getsecond();
  if ( RTCs != sec ) { 
    men = rtc.getminute();
    flasher = rtc.getflasher();
    RTCs = sec;
  }
  if ( RTCm != men ) { 
    hor = (Mode24h) ? rtc.getSTime("%H").toInt() : rtc.getSTime("%I").toInt();
    Messgdate = rtc.getDate();
    Minflasher = !Minflasher;
    RTCm = men;
  }
}
void Updatetime(int sx) {
  rtc.readTime();
  sec = rtc.getsecond();
  if ( RTCs != sec ) { 
    men = rtc.getminute();
    flasher = rtc.getflasher();
    RTCs = sec;
  }
  if ( RTCm != men ) { 
    hor = (Mode24h) ? rtc.getSTime("%H").toInt() : rtc.getSTime("%I").toInt();
    Messgdate = rtc.getDate();
    xdm0 = setting.getxCur(Messgdate, sx);
    Minflasher = !Minflasher;
    setting.SendCommand(0xA1);
    RTCm = men;
  }
}

void writehue0(const char *buffer, size_t size) {
  while (size--){
    uint8_t charstr  = *buffer++;
    col0  = (cl + cl0) % 7;
    if (charstr == 0x20) cl++;
    uint16_t color = Mycolor[col0];
    gfx.setTextColor(color);
    if (gfx.write(charstr)) break;
  }
  cl++;
}
void writehue1(const char *buffer, size_t size) {
  while (size--){
    uint8_t charstr  = *buffer++;
    if (charstr == 0x20) cl++;
    col0  = (ColorFreq[(cl % 16)] + cl0) % 7;
    uint16_t color = Mycolor[col0];
    gfx.setTextColor(color);
    if (gfx.write(charstr)) break;
  }
  cl0++;
}

void writehue2(const char *buffer, size_t size) {
  while (size--){
    uint8_t charstr  = *buffer++;
    col0  = (cl + cl0) % 7;
    uint16_t color = (charstr != 0x3A) ? Mycolor[col0] : Mycolor[(6-col0)];
    gfx.setTextColor(color);
    if (gfx.write(charstr)) break;
  }
  cl++;
}
void writehue3(const char *buffer, size_t size) {
  while (size--){
    uint8_t charstr  = *buffer++;
    if (charstr == 0x3A) cl++;
    col0  = (ColorFreq[(cl % 16)] + cl0) % 7;
    if (charstr == 0x3A || charstr == 0x20) cl++;
    uint16_t color = (charstr != 0x3A) ? Mycolor[col0] : Mycolor[6-col0];
    gfx.setTextColor(color);
    if (gfx.write(charstr)) break;
  }
  cl++;
}

void printhue(const String &s) {
  (ModeSmv) ? writehue0(s.c_str(), s.length()) : writehue1(s.c_str(), s.length());
}
void printhue(const float vai) {
  String s = String(vai);
  (ModeSmv) ? writehue0(s.c_str(), s.length()) : writehue1(s.c_str(), s.length());
}
void printhue0(const String &s) {
  (ModeSmv) ? writehue2(s.c_str(), s.length()) : writehue3(s.c_str(), s.length());
}

void drawdigiHHMM1(int x0, int y0, int sx, int sy) {
  String txt = rtc.getflashHrMn();
  drawhmsmssg(txt, x0, y0, sx, sy);
}
void drawdigiSS1(int x0, int y0, int sx, int sy) {
  String txt = rtc.getSTime("%S");
  drawhmsmssg(txt, x0, y0, sx, sy);
}
void drawdigiAmPm1(int x0, int y0, int sx, int sy) {
  String txt = rtc.getampm();
  drawhmsmssg(txt, x0, y0, sx, sy);
}
void drawhmsmssg(String txt, int x0, int y0, int sx, int sy) {
  gfx.setFont(&atawi8x6);
  gfx.setTextSize(sx, sy);
  gfx.setCursor(x0, y0);
  printhue0(txt);
}

void drawdatemssg(int y0, int sx, int sy) {
  gfx.setFont(&atawi8x6);
  gfx.setTextSize(sx, sy);
  gfx.setCursor(xdm0, y0);
  printhue(Messgdate);
}
void drawMessage(String txt, int y, int sx, int sy, int wmsg) {
  gfx.setFont(&atawi8x6);
  gfx.setTextSize(sx, sy);
  gfx.setCursor(xmesg, y);
  printhue(txt);
  xmesg -= sp0;
  if(gfx.getCursorX()<0) {
    setting.Setmesgtext();
    xmesg = wmsg;
  }
}
void drawMessage0(String txt, int y, int sx, int sy, int wmsg) {
  if(xmesg>wmsg) xmesg = wmsg;
  gfx.setFont(&atawi8x6);
  gfx.setTextSize(sx, sy);
  gfx.setCursor(xmesg, y);
  printhue(txt);
  gfx.fillRect(0, y, 639-wmsg, sy*8, 0);
  gfx.fillRect(wmsg, y, 639-wmsg, sy*8, 0);
  xmesg -= sp0;
  if(gfx.getCursorX()<639-wmsg) {
    setting.Setmesgtext();
    xmesg = wmsg;
  }
}
void drawTempHumi(int y0, int sx, int sy, int sth) {
  gfx.setFont(&atawi8x6);
  gfx.setTextSize(sx, sy);
  gfx.setTextColor(Mycolor[0]);
  gfx.setCursor(xthm0, y0);
  gfx.print(Temp);
  gfx.setTextSize(sth);
  gfx.setTextColor(Mycolor[coltmp]);
  gfx.print("°C");
  gfx.setTextSize(sx, sy);
  gfx.print("   ");
  gfx.setTextColor(Mycolor[4]);
  gfx.print(Humi);
  gfx.setTextSize(sth);
  gfx.setTextColor(Mycolor[colth]);
  gfx.print("%");
}

void drawanalog0() {
  gfx.setFont(&fontclock);
  drawfixdot0(C_X, C_Y, 185, 2, 1.70f);
  drawfixblackdot(C_X, C_Y, 185, 3, 1.70f);
  drawfixdot1(C_X, C_Y, 160, 4, 1.70f);
  drawfixfont(C_X, C_Y, 180, 3, 1.70f);
  float angle = (30 * hor) + (men / 2);
  drawHMS(angle, C_X, C_Y, 100, 90, 10, 4, 1.70f, 0);
  angle = (6 * men);
  drawHMS(angle, C_X, C_Y, 140, 130, 8, 4, 1.70f, 2);
  angle =  (sec * 6);
  col0  = (ColorFreq[(cl%numBands)] + men) % 7;
  drawHMS(angle, C_X, C_Y, 170, 150, 8, 4, 1.70f, col0);
}
void drawfixdot0(int x0, int y0, int r0, int vs, float vx) {
  for (int i = 0; i < 60; i++) {
    float radians = radians(i * 6);
    int x1 = x0 + r0 * vx * sin(radians);
    int y1 = y0 - r0 * cos(radians);
    uint8_t col  = (ColorFreq[(i%numBands)] + cl) % 7;
    gfx.fillCircle(x1, y1, vs, Mycolor[col]);
    cl++;
  }
}
void drawfixblackdot(int x0, int y0, int r0, int vs, float vx) {
  for (int i = 0; i < 60; i+=5) {
    float radians = radians(i * 6);
    int x1 = x0 + r0 * vx * sin(radians);
    int y1 = y0 - r0 * cos(radians);
    gfx.fillCircle(x1, y1, vs, 0x0);
  }
}
void drawfixdot1(int x0, int y0, int r0, int vs, float vx) {
  for (int i = 0; i < 60; i+=5) {
    float radians = radians(i * 6);
    int x1 = x0 + r0 * vx * sin(radians);
    int y1 = y0 - r0 * cos(radians);
    gfx.fillCircle(x1, y1, vs, Mycolor[cl%7]);
  }
}
void drawfixfont(int x0, int y0, int r0, int vs, float vx) {
  int j = 48;
  gfx.setTextSize(vs);
  for (int i = 0; i < 60; i+=5) {
    String txt = (String)(char(j++));
    float radians = radians(i * 6);
    int x1 = x0 + r0 * vx * sin(radians);
    int y1 = y0 - r0 * cos(radians);
    gfx.setCursor(x1, y1);
    printhue(txt);
  }
}

void drawanalog1() {
  gfx.setFont(&fontclock1);
  drawrotatfont(C_X, C_Y, 190, 2, 1.60f);
  drawrotatdot(C_X, C_Y, 170, 5, 1.60f);
  drawrotatdot(C_X, C_Y, 160, 3, 1.60f);
  drawfixdot0(C_X, C_Y, 170, 4, 1.60f);
  drawfixdot1(C_X, C_Y, 170, 2, 1.60f);
  gfx.fillTriangle(C_X, 40, C_X-5, 52, C_X+5, 52, Mycolor[(cl%7)]);
}
void drawrotatfont(int x0, int y0, int r0, int vs, float vx) {
  int j = 48;
  gfx.setTextSize(vs);
  for (int i = 0; i < 60; i+=5) {
    String txt = (String)(char(j++));
    uint8_t loc = i + 60 - sec;
    float radians = radians(360 -(loc * 6));
    int x1 = x0 + r0 * vx * sin(radians);
    int y1 = y0 - r0 * cos(radians);
    gfx.setCursor(x1, y1);
    printhue(txt);
  }
}
void drawrotatdot(int x0, int y0, int r0, int vs, float vx) {
  for (int i = 60; i < 120; i+=5) {
    uint8_t loc = i - sec;
    float radians = radians(360 - (loc * 6));
    int x1 = x0 + r0 * vx * sin(radians);
    int y1 = y0 - r0 * cos(radians);
    col0  = (ColorFreq[(i%numBands)] + cl) % 7;
    gfx.fillCircle(x1, y1, vs, Mycolor[col0]);
  }
}
void drawrotatblackdot(int x0, int y0, int r0, int vs, float vx) {
  for (int i = 0; i < 60; i+=5) {
    uint8_t col = i + 60 - sec;
    float radians = radians(360 -(col * 6));
    int x1 = x0 + r0 * vx * sin(radians);
    int y1 = y0 - r0 * cos(radians);
    gfx.DemifillCircle(x1, y1, vs, 0x0);
  }
}

void drawHMS(float angle, int CEN_X, int CEN_Y, int xr0, int xr1, int w0, int w1, float sv, uint8_t col) {
  float radians = radians(angle); 
  int x0 = C_X + xr0 * sv * sin(radians);
  int y0 = C_Y - xr0 * cos(radians);
  int x1 = C_X + w0 * sv * sin(radians+1);
  int y1 = C_Y - w0 * cos(radians+1);
  int x2 = C_X + w0 * sv * sin(radians-1);
  int y2 = C_Y - w0 * cos(radians-1);
  radians = radians(angle+w1); 
  int x3 = C_X + xr1 * sv * sin(radians);
  int y3 = C_Y - xr1 * cos(radians);
  radians = radians(angle-w1); 
  int x4 = C_X + xr1 * sv * sin(radians);
  int y4 = C_Y - xr1 * cos(radians);
  gfx.fillTriangle(x0, y0, x1, y1, x2, y2, Mycolor[col]);
  gfx.fillTriangle(x0, y0, x3, y3, x4, y4, Mycolor[col]);
}

void Displaysegment(int x0, int y0, int xr, int yr, uint8_t cs0, uint8_t cs1, int mod) {
  switch(mod) {
    case 0 :
        gfx.fillParallelogram(x0, y0, xr, yr, Mycolor[cs0]);
        break;
    case 1 :
        gfx.fillEllipse(x0, y0, xr, yr, Mycolor[cs0]);
        break;
    case 2 :
        gfx.fillParallelogram(x0, y0, (xr*0.8f), (yr*.8f), Mycolor[cs0]);
        break;
    case 3 :
        gfx.fillEllipse(x0, y0, (xr*0.8f), (yr*.8f), Mycolor[cs0]);
        break;
    case 4 :
        gfx.fillParallelogram(x0, y0, (xr*0.8f), (yr*.8f), Mycolor[cs0]);
        gfx.parallelogram(x0, y0, (xr*0.8f), (yr*.8f), Mycolor[cs1]);
        break;
    case 5 :
        gfx.fillEllipse(x0, y0, (xr*0.8f), (yr*.8f), Mycolor[cs0]);
        gfx.ellipse(x0, y0, (xr*0.8f), (yr*.8f), Mycolor[cs1]);
        break;
    case 6 :
        gfx.fillParallelogram(x0, y0, (xr*0.8f), (yr*.8f), Mycolor[cs0]);
        gfx.parallelogram(x0, y0, (xr*0.8f), (yr*.8f), Mycolor[cs1]);
        gfx.fillParallelogram(x0, y0, (xr*0.6f), (yr*.6f), 0);
        break;
    case 7 :
        gfx.fillEllipse(x0, y0, (xr*0.8f), (yr*.8f), Mycolor[cs0]);
        gfx.ellipse(x0, y0, (xr*0.8f), (yr*.8f), Mycolor[cs1]);
        gfx.fillEllipse(x0, y0, (xr*0.6f), (yr*.6f), 0);
        break;
    case 8 :
        gfx.fillParallelogram(x0, y0, (xr*0.8f), (yr*.8f), Mycolor[cs0]);
        gfx.fillParallelogram(x0, y0, (xr*0.6f), (yr*.6f), 0);
        break;
    case 9 :
        gfx.fillEllipse(x0, y0, (xr*0.8f), (yr*.8f), Mycolor[cs0]);
        gfx.fillEllipse(x0, y0, (xr*0.6f), (yr*.6f), 0);
        break;
    case 10 :
        gfx.fillParallelogram(x0, y0, (xr*0.8f), (yr*.8f), Mycolor[cs0]);
        gfx.fillEllipse(x0, y0, (xr*0.6f), (yr*.6f), 0);
        break;
    case 11 :
        gfx.fillEllipse(x0, y0, (xr*0.8f), (yr*.8f), Mycolor[cs0]);
        gfx.fillParallelogram(x0, y0, (xr*0.6f), (yr*.6f), 0);
        break;
    case 12 :
        gfx.fillParallelogram(x0, y0, (xr*0.8f), (yr*.8f), Mycolor[cs0]);
        gfx.fillEllipse(x0, y0, (xr*0.6f), (yr*.6f), 0);
        gfx.parallelogram(x0, y0, (xr*0.8f), (yr*.8f), Mycolor[cs1]);
        break;
    case 13 :
        gfx.fillEllipse(x0, y0, (xr*0.8f), (yr*.8f), Mycolor[cs0]);
        gfx.fillParallelogram(x0, y0, (xr*0.6f), (yr*.6f), 0);
        gfx.ellipse(x0, y0, (xr*0.8f), (yr*.8f), Mycolor[cs1]);
        break;
    case 14 :
        gfx.fillParallelogram(x0, y0, (xr*0.8f), (yr*.8f), Mycolor[cs0]);
        gfx.fillEllipse(x0, y0, (xr*0.6f), (yr*.6f), 0);
        gfx.ellipse(x0, y0, (xr*0.6f), (yr*.6f), Mycolor[cs1]);
        break;
    case 15 :
        gfx.fillEllipse(x0, y0, (xr*0.8f), (yr*.8f), Mycolor[cs0]);
        gfx.fillParallelogram(x0, y0, (xr*0.6f), (yr*.6f), 0);
        gfx.parallelogram(x0, y0, (xr*0.6f), (yr*.6f), Mycolor[cs1]);
        break;
  }
}
void DisplayNumber(int xval, int xs, int ys, int hs, int ws, uint8_t cs0, uint8_t cs1, int mode0) {
  if(xval != 1 && xval != 4)                           { Displaysegment(xs+hs, ys, hs, ws, cs0, cs1, mode0);            }    // a
  if(xval != 5 && xval != 6)                           { Displaysegment(xs+(hs*2), ys+hs, ws, hs, cs0, cs1, mode0);     }    // b
  if(xval != 2)                                        { Displaysegment(xs+(hs*2), ys+(hs*3), ws, hs, cs0, cs1, mode0); }    // c
  if(xval != 1 && xval != 4 && xval != 7)              { Displaysegment(xs+hs, ys+(hs*4), hs, ws, cs0, cs1, mode0);     }    // d
  if(xval == 0 || xval == 2 || xval == 6 || xval == 8) { Displaysegment(xs, ys+(hs*3), ws, hs, cs0, cs1, mode0);        }    // e
  if(xval != 1 && xval != 2 && xval != 3 && xval != 7) { Displaysegment(xs, ys+hs, ws, hs, cs0, cs1, mode0);            }    // f
  if(xval != 0 && xval != 1 && xval != 7)              { Displaysegment(xs+hs, ys+(hs*2), hs, ws, cs0, cs1, mode0);     }    // g
}
void drawSegmentHMs(int hrms, int x0, int x1, int y, int sx, int sy, int mode0) {
  int dig1 = hrms / 10;
  int dig2 = hrms - (dig1 * 10);
  col0  = (ColorFreq[(cl++ % 16)] + cl0) % 7;
  col1  = (hue + col0) % 7;
  DisplayNumber(dig1, x0, y, sx, sy, col0, col1, mode0);
  col0  = (ColorFreq[(cl++ % 16)] + cl0) % 7;
  col1  = (hue + col0) % 7;
  DisplayNumber(dig2, x1, y, sx, sy, col0, col1, mode0);
}
void drawDotsec(int x0, int y0, int y1, int sx, int sy, int mode0) {
  if (flasher) {
    col0  = (hue + sec) % 7;
    Displaysegment(x0, y0, sx, sy, col0, col1, mode0);
    Displaysegment(x0, y1, sx, sy, col0, col1, mode0);
  }
}

void getSyTemp(int xs, int ys) {
  gfx.setTextColor(Mycolor[6]);
  gfx.setTextSize(1);
  for(int x=ys+30; x<ys+171; x+=20) {
    gfx.fillRect(xs+34, x, 6, 1, Mycolor[1]);
    gfx.setCursor(xs+45, x-3);
    gfx.print((ys+130-x)/2);
  }
  gfx.fillRect(xs+16, ys+10, 18, 180, Mycolor[1]);
  gfx.fillEllipse(xs+25, ys, 10, 20, Mycolor[1]);
  gfx.fillEllipse(xs+25, ys, 8, 16, 0x0);
  gfx.fillCircle(xs+25, ys+200, 24, Mycolor[1]);
  gfx.fillRect(xs+20, ys+12, 10, 200, 0x0);
  gfx.fillCircle(xs+25, ys+200, 20, Mycolor[2]);
  gfx.fillCircle(xs+25, ys+200, 16, Mycolor[0]);
  for(int x=ys+20; x<ys+171; x+=2)
    gfx.fillRect(xs+32, x, 3, 1, Mycolor[4]);
  int tec = map(Temp, -20, 60, ys+170, ys+10);
  int yec = ys+200-tec;
  gfx.fillRect(xs+21, ys, 8, 180, 0x0);
  gfx.fillRect(xs+22, tec, 7, yec, Mycolor[0]);
}

void drawdrapo(int cx0, int cy0, int level, int level1, int Line, int dw, int wl, float rx) {
  float degreesPerLine = 360/Line;
  float angle = degreesPerLine * Line;
  gfx.fillEllipse(cx0, cy0, level1 * rx, level1, Mycolor[0]);
  gfx.ellipse(cx0, cy0, level1 * rx, level1, Myblack);
  for(int x=0; x<Line; x++) {
    float radians = radians(angle-dw);
    int x0 = cx0 + level * rx * sin(radians);
    int y0 = cy0 - level * cos(radians);
    radians = radians(angle+dw);
    int x1 = cx0 + level * rx * sin(radians);
    int y1 = cy0 - level * cos(radians);
    radians = radians(angle + dw + degreesPerLine*wl);
    int x2 = cx0 + level * rx * sin(radians);
    int y2 = cy0 - level * cos(radians);
    radians = radians(angle - dw + degreesPerLine*wl);
    int x3 = cx0 + level * rx * sin(radians);
    int y3 = cy0 - level * cos(radians);
    gfx.fillCare(x1, y1, x0, y0, x2, y2, x3, y3, Mycolor[2]);
    gfx.DrawCare(x1, y1, x0, y0, x2, y2, x3, y3, Mycolor[0]);
    angle += degreesPerLine;
  }
}
  void drawdrapo(int level, int level1, int Line, int dw, int wl, float rx) {
    bool updDir = false;
    int w = level1 * rx, h = level1;
    int x = xb, y = yb;

    if (x >= (bw-w-2)) x = bw-w-2;
    if (x <= (w+2)) x = w+2;
    if (y >= (bh-h-2)) y = bh-h-2;
    if (y <= h+2) y = h+2;

    drawdrapo(x, y, level, level1, Line, dw, wl, rx);

    xb += xfc*xfdir;
    yb += yfc*yfdir;
    
    if (xb >= (bw-w))   { xfdir = -1; updDir = true ; }
    if (xb <= w)      { xfdir =  1; updDir = true ; }
    
    if (yb >= (bh-h))   { yfdir = -1; updDir = true ; }
    if (yb <= h)      { yfdir =  1; updDir = true ; }

    if (updDir) {
      // Add -1, 0 or 1 but bind result to 1 to 1.
      // Let's take 3 is a minimum speed, otherwise it's too slow.
      xfc = constrain(xfc + random(-1, 2), 1, 16);
      yfc = constrain(xfc + random(-1, 2), 1, 10);
    }
  }
  
};

#endif
