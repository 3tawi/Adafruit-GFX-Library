/*
 * Written by 3tawi
- Lien vidéo: https://youtu.be/zPvuzV2fqaA
*/

#ifndef GpTime_H
#define GpTime_H

#include "time.h"
#include <sys/time.h>                   // struct timeval

/*
    get the time as an Arduino String object with the specified format
	format:
		time format 
		http://www.cplusplus.com/reference/ctime/strftime/
*/


class GpTime{
  private:
  struct tm timeinfo; 
  bool flasher;
  bool mode24 = true;

  public:
  
  void readTime() {
    getLocalTime(&timeinfo);
  }
  
  void setTime(int hr, int mn, int sc, int dy, int mt, int yr) {
    struct tm t = {0};        // Initalize to all 0's
    t.tm_year = yr - 1900;    // This is year-1900, so 122 = 2022
    t.tm_mon = mt - 1;
    t.tm_mday = dy;
    t.tm_hour = hr;
    t.tm_min = mn;
    t.tm_sec = sc;
    time_t timeSinceEpoch = mktime(&t);
    setTime(timeSinceEpoch);
  }
  void setTime(long epoch = 1739422800) {
    struct timeval tv;
    tv.tv_sec = epoch;  // epoch time (seconds)
    tv.tv_usec = 0;    // microseconds
    settimeofday(&tv, NULL);
  }
  long getEpoch(){
	  struct timeval tv;
	  gettimeofday(&tv, NULL);
	  return tv.tv_sec;
  }

  String getSTime(const char *format) {
	  char s[60];
    strftime(s, 60, format, &timeinfo);
    return String(s);
  }

  String getflashHrMn() {
	  char s[7];
    flasher = timeinfo.tm_sec & 1;
    if (mode24) (flasher) ? strftime(s, 7, "%R", &timeinfo) : strftime(s, 7, "%H %M", &timeinfo);
      else      (flasher) ? strftime(s, 7, "%I:%M", &timeinfo) : strftime(s, 7, "%I %M", &timeinfo);
    return String(s);
  }
  String getTime() {
	  char s[15];
    if (mode24) strftime(s, 15, "%T", &timeinfo);
      else      strftime(s, 15, "%r", &timeinfo);
    return String(s);
  }
  String getDate(bool lowercase = false) {
	  char s[30];
    if (lowercase) strftime(s, 30, "%A %d %B %Y", &timeinfo);
      else         strftime(s, 30, "%a %d %b %Y", &timeinfo);
    return String(s);
  }
  String getDateTime(bool lowercase = true){
	  char s[50];
    if (lowercase) (mode24) ? strftime(s, 50, "%A, %d %B %Y %T", &timeinfo) : strftime(s, 50, "%A, %d %B %Y %I:%M:%S %p", &timeinfo);
      else         (mode24) ? strftime(s, 50, "%a, %d %b %Y %T", &timeinfo) : strftime(s, 50, "%a, %d %b %Y %r", &timeinfo);
    return String(s);
  }
  String getampm(bool lowercase = true) {
    if (mode24) return "";
	  char s[5];
    if (lowercase) strftime(s, 5, "%p", &timeinfo);
      else         strftime(s, 5, "%P", &timeinfo);
    return String(s);
  }

  bool getflasher() {
    return (timeinfo.tm_sec & 1);
  }
  int getsecond() {
    return timeinfo.tm_sec;
  }
  int getminute() {
    return timeinfo.tm_min;
  }
  int gethour() {
    return timeinfo.tm_hour;
  }
  int getdayOfMonth() {
    return timeinfo.tm_mday;
  }
  int getmonth() {
    return timeinfo.tm_mon;
  }
  int getyear() {
    return timeinfo.tm_year + 1900;
  }
  int getdayOfWeek() {
    return timeinfo.tm_wday;
  }
  int getDayofYear() {
    return timeinfo.tm_yday;
  }

  bool getmode24() {
    return mode24;
  }
  void changemode24() {
    mode24 = !mode24;
  }
  void setmode24(bool mode) {
    mode24 = mode;
  }


};

#endif


