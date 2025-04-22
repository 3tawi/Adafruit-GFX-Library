/*
 * Written by 3tawi
- Lien vidéo: https://youtu.be/zPvuzV2fqaA
*/

#ifndef Clock_H

#include "DrawClock.h"
#include "DrawMusic.h"

class AClock0 : public Play {
  private:
  #define CEN_X 319
  #define CEN_Y 199
  uint8_t col0, col1;
  DrawClock drawclock;
  

  public:
  AClock0() {
    name = (char *)"A-Clock0";
  }

  unsigned int playframe() {
    vga.clear(0);
    drawclock.Updatetime(3);
    cl = 0, cl0 = men;
    drawclock.drawdatemssg(295, 3, 4);
    drawclock.drawdigiAmPm1(305, 60, 2, 2);
    drawclock.drawTempHumi(90, 5, 6, 2);
    drawclock.drawanalog0();
    drawclock.drawdrapo(CEN_X, CEN_Y, 14, 15, 5, 5, 2, 1.60f);
    vga.show();
    return 0;
  }
};

class AClock1 : public Play {
  private:
  #define CEN_X 319
  #define CEN_Y 199
  uint8_t col0, col1;
  DrawClock drawclock;
  

  public:
  AClock1() {
    name = (char *)"A-Clock1";
  }

  unsigned int playframe() {
    vga.clear(0);
    drawclock.Updatetime(3);
    cl = 0, cl0 = men;
    drawclock.drawdigiSS1(xs0+1, 60, 4, 4);
    drawclock.drawdigiAmPm1(305, 150, 2, 2);
    drawclock.drawdigiHHMM1(xh0+5, 160, 14, 16);
    drawclock.drawanalog1();
    drawclock.drawdatemssg(295, 3, 4);
    drawclock.drawTempHumi(95, 5, 6, 2);
    drawclock.drawdrapo(12, 16, 5, 5, 2, 1.60f);
    vga.show();
    return 0;
  }
};

class AClock2 : public Play {
  private:
  #define CEN_X 319
  #define CEN_Y 199
  uint8_t col0, col1;
  DrawClock drawclock;
  

  public:
  AClock2() {
    name = (char *)"A-Clock2";
  }

  unsigned int playframe() {
    vga.clear(0);
    drawclock.Updatetime(3);
    cl = 0, cl0 = men;
    drawclock.drawSegmentHMs(hor, 120, 215, 160, 28, 14, Cis);
    drawclock.drawSegmentHMs(men, 365, 460, 160, 28, 14, Cis);
    drawclock.drawDotsec(CEN_X, CEN_Y-2, CEN_Y+38, 8, 12, Cis);
    cl0++;
    drawclock.drawSegmentHMs(sec, 294, 326, 60, 8, 4, Cis);
    drawclock.drawdigiAmPm1(305, 150, 2, 2);
    drawclock.drawdatemssg(295, 3, 4);
    drawclock.drawTempHumi(100, 5, 6, 2);
    drawclock.drawanalog1();
    drawclock.drawdrapo(12, 16, 5, 5, 2, 1.60f);
    vga.show();
    return 0;
  }
};

class AClock3 : public Play {
  private:
  #define CEN_X 319
  #define CEN_Y 199
  uint8_t col0, col1;
  DrawClock drawclock;
  DrawMusic Drawmusic;

  public:
    AClock3() {
        name = (char *)"AClock3";
    }

    unsigned int playframe() {
    vga.clear(0);
    drawclock.Updatetime(3);
    cl0 = 0, cl = 0;
    drawclock.drawdigiAmPm1(305, 60, 2, 2);
    (Minflasher) ? drawclock.drawTempHumi(90, 5, 4, 2) : drawclock.drawdatemssg(90, 3, 4);
    drawclock.drawMessage0(textmsg, 290, 5, 4, 520);
    drawclock.drawanalog0();
    drawclock.drawdrapo(CEN_X, CEN_Y, 14, 15, 5, 5, 2, 1.60f);
    vga.show();
    return 0;
    }
};

class AClock4 : public Play {
  private:
  #define CEN_X 319
  #define CEN_Y 199
  uint8_t col0, col1;
  DrawClock drawclock;
  DrawMusic Drawmusic;

  public:
    AClock4() {
        name = (char *)"AClock4";
    }

    unsigned int playframe() {
    vga.clear(0);
    drawclock.Updatetime(3);
    cl0 = men, cl = 0;
    drawclock.drawMessage0(textmsg, 80, 5, 4, 520);
    drawclock.drawdigiAmPm1(305, 60, 2, 2);
    (Minflasher) ? drawclock.drawTempHumi(280, 5, 4, 2) : drawclock.drawdatemssg(280, 3, 4);
    drawclock.drawanalog0();
    drawclock.drawdrapo(CEN_X, CEN_Y, 14, 15, 5, 5, 2, 1.60f);
    vga.show();
    return 0;
    }
};


class DClock0 : public Play {
  private:
  #define CEN_X 319
  #define CEN_Y 199
  uint8_t col0, col1;
  DrawClock drawclock;
  

  public:
  DClock0() {
    name = (char *)"D-Clock0";
  }

  unsigned int playframe() {
    vga.clear(0);
    drawclock.Updatetime(6);
    cl0 = men, cl = 0;
    drawclock.drawdatemssg(5, 6, 9);
    drawclock.drawdigiSS1(575, 80, 4, 6);
    drawclock.drawdigiHHMM1(20, 80, 18, 34);
    drawclock.drawdigiAmPm1(589, 130, 2, 2);
    drawclock.drawTempHumi(325, 7, 10, 3);
    drawclock.drawdrapo(12, 16, 5, 5, 2, 1.60f);
    vga.show();
    return 0;
  }
};

class DClock1 : public Play {
  private:
  #define CEN_X 319
  #define CEN_Y 199
  uint8_t col0, col1;
  DrawClock drawclock;
  

  public:
  DClock1() {
    name = (char *)"D-Clock1";
  }

  unsigned int playframe() {
    vga.clear(0);
    drawclock.Updatetime(6);
    cl0 = men, cl = 0;
    drawclock.drawTempHumi(5, 7, 10, 3);
    drawclock.drawdigiSS1(575, 80, 4, 6);
    drawclock.drawdigiHHMM1(20, 80, 18, 34);
    drawclock.drawdigiAmPm1(589, 130, 2, 2);
    drawclock.drawdatemssg(325, 6, 9);
    drawclock.drawdrapo(12, 16, 5, 5, 2, 1.60f);
    vga.show();
    return 0;
  }
};

class DClock2 : public Play {
  private:
  #define CEN_X 319
  #define CEN_Y 199
  uint8_t col0, col1;
  DrawClock drawclock;
  

  public:
  DClock2() {
    name = (char *)"D-Clock2";
  }

  unsigned int playframe() {
    vga.clear(0);
    drawclock.Updatetime(6);
    cl0 = 0, cl = 0;
    drawclock.drawdigiHHMM1(2, 80, 18, 34);
    drawclock.drawSegmentHMs(sec, 550, 590, 15, 12, 5, Cis);
    drawclock.drawdigiAmPm1(260, 90, 2, 2);
    drawclock.drawdatemssg(325, 6, 9);
    drawclock.drawTempHumi(5, 6, 10, 3);
    drawclock.getSyTemp(550, 95);
    drawclock.drawdrapo(12, 16, 5, 5, 2, 1.60f);
    vga.show();
    return 0;
  }
};

class DClock3 : public Play {
  private:
  #define CEN_X 319
  #define CEN_Y 199
  uint8_t col0, col1;
  DrawClock drawclock;
  

  public:
  DClock3() {
    name = (char *)"D-Clock3";
  }

  unsigned int playframe() {
    vga.clear(0);
    drawclock.Updatetime();
    cl0 = men, cl = 0;
    drawclock.drawdigiSS1(575, 70, 4, 6);
    drawclock.drawdigiAmPm1(589, 120, 2, 2);
    drawclock.drawdigiHHMM1(20, 70, 18, 34);
    drawclock.drawMessage(textmsg, 10, 6, 6, 639);
    (Minflasher) ? drawclock.drawTempHumi(325, 7, 10, 3) : drawclock.drawdatemssg(325, 6, 10);
    drawclock.drawdrapo(12, 16, 5, 5, 2, 1.60f);
    vga.show();
    return 0;
  }
};

class DClock4 : public Play {
  private:
  #define CEN_X 319
  #define CEN_Y 199
  uint8_t col0, col1;
  DrawClock drawclock;
  

  public:
  DClock4() {
    name = (char *)"D-Clock4";
  }

  unsigned int playframe() {
    vga.clear(0);
    drawclock.Updatetime();
    cl0 = men, cl = 0;
    drawclock.drawdigiHHMM1(2, 80, 18, 34);
    drawclock.drawdigiAmPm1(260, 90, 2, 2);
    drawclock.drawSegmentHMs(sec, 550, 590, 15, 12, 5, Cis);
    drawclock.drawMessage(textmsg, 335, 6, 6, 639);
    drawclock.drawTempHumi(5, 7, 10, 3);
    drawclock.getSyTemp(550, 95);
    drawclock.drawdrapo(12, 16, 5, 5, 2, 1.60f);
    vga.show();
    return 0;
  }
};

class SClock0 : public Play {
  private:
  #define CEN_X 319
  #define CEN_Y 199
  uint8_t col0, col1;
  DrawClock drawclock;
  

  public:
  SClock0() {
    name = (char *)"S-Clock0";
  }

  unsigned int playframe() {
    vga.clear(0);
    drawclock.Updatetime(6);
    cl0 = men, cl = 0;
    drawclock.drawSegmentHMs(hor, 30, 180, 100, 50, 18, Cis);
    drawclock.drawSegmentHMs(men, 360, 510, 100, 50, 18, Cis);
    drawclock.drawDotsec(CEN_X, 156, 236, 10, 16, Cis);
    cl0++;
    drawclock.drawSegmentHMs(sec, 550, 590, 15, 12, 5, Cis);
    drawclock.drawdigiAmPm1(306, 90, 2, 2);
    drawclock.drawdatemssg(325, 6, 9);
    drawclock.drawTempHumi(5, 6, 10, 3);
    drawclock.drawdrapo(12, 16, 5, 5, 2, 1.60f);
    vga.show();
    return 0;
  }
};

class SClock1 : public Play {
  private:
  #define CEN_X 319
  #define CEN_Y 199
  uint8_t col0, col1;
  DrawClock drawclock;
  

  public:
  SClock1() {
    name = (char *)"S-Clock1";
  }

  unsigned int playframe() {
    vga.clear(0);
    drawclock.Updatetime(6);
    cl0 = men, cl = 0;
    drawclock.drawSegmentHMs(hor, 30, 180, 100, 50, 18, Cis);
    drawclock.drawSegmentHMs(men, 360, 510, 100, 50, 18, Cis);
    drawclock.drawDotsec(CEN_X, 156, 236, 10, 16, Cis);
    cl0++;
    drawclock.drawSegmentHMs(sec, 550, 590, 340, 12, 5, Cis);
    drawclock.drawdigiAmPm1(306, 90, 2, 2);
    drawclock.drawdatemssg(5, 6, 9);
    drawclock.drawTempHumi(325, 6, 10, 3);
    drawclock.drawdrapo(12, 16, 5, 5, 2, 1.60f);
    vga.show();
    return 0;
  }
};

class SClock2 : public Play {
  private:
  DrawClock drawclock;
  

  public:
  SClock2() {
    name = (char *)"S-Clock2";
  }

  unsigned int playframe() {
    vga.clear(0);
    drawclock.Updatetime(6);
    cl0 = men, cl = 0;
    drawclock.drawSegmentHMs(hor, 20, 150, 120, 40, 18, Cis);
    drawclock.drawSegmentHMs(men, 320, 450, 120, 40, 18, Cis);
    drawclock.drawDotsec(274, 164, 236, 10, 14, Cis);
    cl0++;
    drawclock.drawSegmentHMs(sec, 550, 590, 15, 12, 5, Cis);
    drawclock.drawdigiAmPm1(261, 110, 2, 2);
    drawclock.drawdatemssg(325, 6, 9);
    drawclock.drawTempHumi(5, 6, 10, 3);
    drawclock.getSyTemp(550, 95);
    drawclock.drawdrapo(12, 16, 5, 5, 2, 1.60f);
    vga.show();
    return 0;
  }
};

class MSClock0 : public Play {
  private:
  DrawClock drawclock;
  DrawMusic Drawmusic;
  

  public:
  MSClock0() {
    name = (char *)"Mu-SClock0";
  }

  unsigned int playframe() {
    vga.clear(0);
    drawclock.Updatetime(6);
    cl = 0, cl0 = men;
    drawclock.drawSegmentHMs(hor, 20, 150, 120, 40, 18, Cis);
    drawclock.drawSegmentHMs(men, 320, 450, 120, 40, 18, Cis);
    drawclock.drawDotsec(274, 164, 236, 10, 14, Cis);
    cl0++;
    drawclock.drawSegmentHMs(sec, 550, 590, 15, 12, 5, Cis);
    drawclock.drawdigiAmPm1(261, 110, 2, 2);
    Drawmusic.DrawMode(Cia, 270, 40, 90, 32, 86, 560, 270, 6.00f);
    drawclock.getSyTemp(550, 95);
    (Minflasher) ? drawclock.drawTempHumi(325, 6, 9, 3) : drawclock.drawdatemssg(325, 6, 9) ;
    vga.show();
    return 0;
  }
};

class MSClock1 : public Play {
  private:
  DrawClock drawclock;
  DrawMusic Drawmusic;

  public:
  MSClock1() {
    name = (char *)"Mu-SClock1";
  }

  unsigned int playframe() {
    vga.clear(0);
    drawclock.Updatetime(6);
    cl = 0, cl0 = men;
    drawclock.drawSegmentHMs(hor, 30, 180, 106, 50, 18, Cis);
    drawclock.drawSegmentHMs(men, 360, 510, 106, 50, 18, Cis);
    drawclock.drawDotsec(CEN_X, 162, 242, 10, 16, Cis);
    cl0++;
    drawclock.drawSegmentHMs(sec, 550, 590, 15, 12, 5, Cis);
    drawclock.drawdigiAmPm1(306, 96, 2, 2);
    (Minflasher) ? drawclock.drawTempHumi(330, 6, 9, 3) : drawclock.drawdatemssg(330, 6, 9) ;
    Drawmusic.DrawMode(Cia, 270, 40, 84, 32, 80, 560, 270, 6.00f);
    vga.show();
    return 0;
  }
};

class MSClock2 : public Play {
  private:
  DrawClock drawclock;
  DrawMusic Drawmusic;
  

  public:
  MSClock2() {
    name = (char *)"Mu-SClock2";
  }

  unsigned int playframe() {
    vga.clear(0);
    drawclock.Updatetime(6);
    cl = 0, cl0 = men;
    drawclock.drawSegmentHMs(hor, 20, 150, 120, 40, 18, Cis);
    drawclock.drawSegmentHMs(men, 320, 450, 120, 40, 18, Cis);
    drawclock.drawDotsec(274, 164, 236, 10, 14, Cis);
    cl0++;
    drawclock.drawSegmentHMs(sec, 550, 590, 15, 12, 5, Cis);
    drawclock.drawdigiAmPm1(261, 110, 2, 2);
    drawclock.drawMessage(textmsg, 325, 6, 9, 639);
    drawclock.getSyTemp(550, 95);
    Drawmusic.DrawMode(Cia, 270, 40, 90, 32, 86, 560, 270, 6.00f);
    vga.show();
    return 0;
  }
};

class MSClock3 : public Play {
  private:
  DrawClock drawclock;
  DrawMusic Drawmusic;

  public:
  MSClock3() {
    name = (char *)"Mu-SClock3";
  }

  unsigned int playframe() {
    vga.clear(0);
    drawclock.Updatetime(6);
    cl = 0, cl0 = men;
    drawclock.drawSegmentHMs(hor, 30, 180, 100, 50, 18, Cis);
    drawclock.drawSegmentHMs(men, 360, 510, 100, 50, 18, Cis);
    drawclock.drawDotsec(CEN_X, 162, 242, 10, 16, Cis);
    cl0++;
    drawclock.drawSegmentHMs(sec, 550, 590, 15, 12, 5, Cis);
    drawclock.drawdigiAmPm1(306, 96, 2, 2);
    drawclock.drawMessage(textmsg, 325, 6, 9, 639);
    Drawmusic.DrawMode(Cia, 270, 40, 80, 32, 76, 560, 270, 6.00f);
    vga.show();
    return 0;
  }
};

class MDClock0 : public Play {
  private:
  DrawClock drawclock;
  DrawMusic Drawmusic;

  public:
  MDClock0() {
    name = (char *)"Mu-DClock0";
  }

  unsigned int playframe() {
    vga.clear(0);
    drawclock.Updatetime(6);
    cl = 0, cl0 = men;
    drawclock.drawdigiHHMM1(2, 96, 18, 32);
    drawclock.drawdigiAmPm1(260, 96, 2, 2);
    drawclock.drawSegmentHMs(sec, 550, 590, 15, 12, 5, Cis);
    (Minflasher) ? drawclock.drawTempHumi(325, 6, 9, 3) : drawclock.drawdatemssg(325, 6, 9);
    drawclock.getSyTemp(550, 95);
    Drawmusic.DrawMode(Cia, 270, 40, 90, 32, 86, 560, 270, 6.00f);
    vga.show();
    return 0;
  }
};

class MDClock1 : public Play {
  private:
  DrawClock drawclock;
  DrawMusic Drawmusic;

  public:
  MDClock1() {
    name = (char *)"Mu-DClock1";
  }

  unsigned int playframe() {
    vga.clear(0);
    drawclock.Updatetime(6);
    cl = 0, cl0 = men;
    drawclock.drawdigiSS1(575, 90, 4, 6);
    drawclock.drawdigiAmPm1(589, 140, 2, 2);
    drawclock.drawdigiHHMM1(20, 84, 18, 34);
    (Minflasher) ? drawclock.drawTempHumi(328, 6, 9, 3) : drawclock.drawdatemssg(328, 6, 9);
    Drawmusic.DrawMode(Cia, 270, 50, 80, 32, 76, 580, 270, 6.00f);
    vga.show();
    return 0;
  }
};

class MDClock2 : public Play {
  private:
  DrawClock drawclock;
  DrawMusic Drawmusic;

  public:
  MDClock2() {
    name = (char *)"Mu-DClock2";
  }

  unsigned int playframe() {
    vga.clear(0);
    drawclock.Updatetime(6);
    cl = 0, cl0 = men;
    drawclock.drawSegmentHMs(sec, 550, 590, 15, 12, 5, Cis);
    drawclock.drawdigiAmPm1(260, 96, 2, 2);
    drawclock.drawdigiHHMM1(2, 96, 18, 32);
    drawclock.drawMessage(textmsg, 325, 6, 9, 639);
    drawclock.getSyTemp(550, 95);
    Drawmusic.DrawMode(Cia, 270, 40, 90, 32, 86, 560, 270, 6.00f);
    vga.show();
    return 0;
  }
};

class MDClock3 : public Play {
  private:
  DrawClock drawclock;
  DrawMusic Drawmusic;

  public:
  MDClock3() {
    name = (char *)"Mu-DClock3";
  }

  unsigned int playframe() {
    vga.clear(0);
    drawclock.Updatetime(6);
    cl = 0, cl0 = men;
    drawclock.drawdigiSS1(575, 90, 4, 6);
    drawclock.drawdigiAmPm1(589, 140, 2, 2);
    drawclock.drawdigiHHMM1(20, 84, 18, 34);
    drawclock.drawMessage(textmsg, 325, 6, 9, 639);
    Drawmusic.DrawMode(Cia, 270, 50, 80, 32, 76, 580, 270, 6.00f);
    vga.show();
    return 0;
  }
};

class MAClock0 : public Play {
  private:
  #define CEN_X 319
  #define CEN_Y 199
  uint8_t col0, col1;
  DrawClock drawclock;
  DrawMusic Drawmusic;

  public:
    MAClock0() {
        name = (char *)"Mu-AClock0";
    }

    unsigned int playframe() {
    vga.clear(0);
    drawclock.Updatetime(3);
    Drawmusic.DrawMode(Cia, 319, 109, 320, 28, 106, 639, 250, 6.00f);
    cl = 0, cl0 = men;
    drawclock.drawdigiAmPm1(305, 60, 2, 2);
    (Minflasher) ? drawclock.drawTempHumi(90, 5, 4, 2) : drawclock.drawdatemssg(90, 3, 4);
    drawclock.drawanalog0();
    drawclock.drawdrapo(CEN_X, CEN_Y, 14, 15, 5, 5, 2, 1.60f);
    vga.show();
    return 0;
    }
};

class MAClock1 : public Play {
  private:
  #define CEN_X 319
  #define CEN_Y 199
  DrawClock drawclock;
  DrawMusic Drawmusic;

  public:
    MAClock1() {
        name = (char *)"Mu-AClock1";
    }

    unsigned int playframe() {
    vga.clear(0);
    drawclock.Updatetime(3);
    Drawmusic.DrawMode(Cia, 319, 109, 320, 28, 106, 639, 250, 6.00f);
    cl = 0, cl0 = men;
    drawclock.drawMessage0(textmsg, 100, 5, 4, 500);
    drawclock.drawdigiAmPm1(305, 60, 2, 2);
    drawclock.drawanalog0();
    drawclock.drawdrapo(CEN_X, CEN_Y, 14, 15, 5, 5, 2, 1.60f);
    vga.show();
    return 0;
    }
};

class MAClock2 : public Play {
  private:
  DrawClock drawclock;
  DrawMusic Drawmusic;
  

  public:
    MAClock2() {
        name = (char *)"Mu-AClock2";
    }

    unsigned int playframe() {
    vga.clear(0);
    drawclock.Updatetime(3);
    Drawmusic.DrawMode(Cia, 319, 109, 285, 28, 86, 639, 250, 6.00f);
    cl = 0, cl0 = men;
    drawclock.drawSegmentHMs(hor, 140, 231, 100, 24, 12, Cis);
    drawclock.drawSegmentHMs(men, 359, 450, 100, 24, 12, Cis);
    drawclock.drawDotsec(CEN_X, 130, 166, 8, 12, Cis);
    cl0++;
    drawclock.drawSegmentHMs(sec, 294, 326, 60, 8, 4, Cis);
    drawclock.drawMessage0(textmsg, 295, 5, 4, 480);
    drawclock.drawdigiAmPm1(305, 100, 2, 2);
    drawclock.drawanalog1();
    vga.show();
    return 0;
    }
};

class MAClock3 : public Play {
  private:
  #define CEN_X 319
  #define CEN_Y 199
  uint8_t col0, col1;
  DrawClock drawclock;
  DrawMusic Drawmusic;
  
  public:
    MAClock3() {
        name = (char *)"Mu-AClock3";
    }

    unsigned int playframe() {
    vga.clear(0);
    drawclock.Updatetime(3);
    Drawmusic.DrawMode(Cia, 319, 109, 285, 28, 86, 639, 250, 6.00f);
    cl = 0, cl0 = men;
    drawclock.drawSegmentHMs(hor, 140, 231, 100, 24, 12, Cis);
    drawclock.drawSegmentHMs(men, 359, 450, 100, 24, 12, Cis);
    drawclock.drawDotsec(CEN_X, 130, 166, 8, 12, Cis);
    cl0++;
    drawclock.drawSegmentHMs(sec, 294, 326, 60, 8, 4, Cis);
    drawclock.drawdigiAmPm1(305, 100, 2, 2);
    (Minflasher) ? drawclock.drawTempHumi(295, 4, 4, 2) : drawclock.drawdatemssg(295, 3, 5);
    drawclock.drawanalog1();
    vga.show();
    return 0;
    }
};

class Music0 : public Play {
  private:
  #define CEN_X 319
  #define CEN_Y 199
  DrawMusic drawmusic;

  public:
  Music0() {
    name = (char *)"Music0";
  }

  unsigned int playframe() {
    vga.clear(0);
    drawmusic.Updatetime();
    drawmusic.DrawMode(Cia, CEN_X, 55, 399, 32, 398, 590, 272, 6.00f);
    vga.show();
    return 0;
  }
};

#endif
