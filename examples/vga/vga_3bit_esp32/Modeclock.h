/*
 * Written by 3tawi
- Lien vidéo: https://youtu.be/zPvuzV2fqaA
*/


#ifndef Modeclock_H
#define Modeclock_H




#include "Clock.h"


class Modeclock : public list {
  private:
    AClock0 Aclock0;
    AClock1 Aclock1;
    AClock2 Aclock2;
    AClock3 Aclock3;
    AClock4 Aclock4;
    DClock0 Dclock0;
    DClock1 Dclock1;
    DClock2 Dclock2;
    DClock3 Dclock3;
    DClock4 Dclock4;
    SClock0 Sclock0;
    SClock1 Sclock1;
    SClock2 Sclock2;
    MSClock0 sclockmusic0;
    MSClock1 sclockmusic1;
    MSClock2 sclockmusic2;
    MSClock3 sclockmusic3;
    MDClock0 dclockmusic0;
    MDClock1 dclockmusic1;
    MDClock2 dclockmusic2;
    MDClock3 dclockmusic3;
    MAClock0 aclockmusic0;
    MAClock1 aclockmusic1;
    MAClock2 aclockmusic2;
    MAClock3 aclockmusic3;
    Music0 dmusic0;


    int currentIndex = 0;
    Play* currentItem;

    static const int Modenm = 26;
    Play* items[Modenm] = {
      &Aclock0,
      &Aclock1,
      &Aclock2,
      &Aclock3,
      &Aclock4,
      &Dclock0,
      &Dclock1,
      &Dclock2,
      &Dclock3,
      &Dclock4,
      &Sclock0,
      &Sclock1,
      &Sclock2,
      &sclockmusic0,
      &sclockmusic1,
      &sclockmusic2,
      &sclockmusic3,
      &dclockmusic0,
      &dclockmusic1,
      &dclockmusic2,
      &dclockmusic3,
      &aclockmusic0,
      &aclockmusic1,
      &aclockmusic2,
      &aclockmusic3,
      &dmusic0
    };
    

  
  public:
    char* Play::name = (char *)"Modeclock";

    int getCurrentIndex() {
      return currentIndex;
    }
    void stop() {
      if (currentItem)
        currentItem->stop();
    }
    void start() {
      if (currentItem)
      currentItem->start();
      }
    void move(int step) {
      currentIndex += step;
      if(ModeClMu) {
        if (currentIndex > Modenm-1) currentIndex = 13;
        if (currentIndex < 13) currentIndex = Modenm-1;
      } else {
        if (currentIndex > 12) currentIndex = 0;
        if (currentIndex < 0) currentIndex = 12;
      }
      moveTo(currentIndex);
    }


    unsigned int playframe() {
      return currentItem->playframe();
    }

    void moveTo(int index) {
      stop();
      currentIndex = index;
      currentItem = items[currentIndex];
      start();
    }  


    bool setMode(int index) {
      if (index >= Modenm || index < 0)
        return false;
      currentIndex = index;
      moveTo(currentIndex);
      return true;
    }
};

#endif
