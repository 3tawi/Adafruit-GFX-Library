
/*
 * Written by 3tawi
- Lien vidéo: https://youtu.be/zPvuzV2fqaA
*/

#ifndef Command_H
#define Command_H


class Command {
protected:

private:
  #define EndBand    0xA0
  #define EndTime    0xA1
  #define EndMesg    0xA2
  #define EndStting  0xA3

public:

void Setup() {
}

void ReadBand() {
  uint8_t valFreq[(numBands+1)];
  if (Serial.read() != DataBand)
       return;
  Serial.readBytes(valFreq, (numBands+1));
  if (Serial.read() != EndBand)
       return;
  
  memcpy(valBand, valFreq, numBands);
  if (ModeSmv) return;
  hue = valFreq[numBands];
  for(int x=0; x<numBands; x++)
    ColorFreq[x] = map(valBand[15-x], 0, 255, 0, 10);
}
void ReadMesg() {
  if (Serial.read() != DataMesg)
       return;
  String Mesge = Serial.readStringUntil('\n');
  if (Serial.read() != EndMesg)
       return;
  Message = Mesge;
  xmesg = 640, textmsg = Message;
  mesg = 1;
}
void ReadTime() {
  if (Serial.read() != DataTime)
       return;
  long timeEpo = Serial.readStringUntil('\n').toInt();
  if (Serial.read() != EndTime)
       return;
  rtc.setTime(timeEpo);
  RTCm = 60;
}
void ReadStting() {
  if (Serial.read() != DataStting)
       return;
  String Mesge = Serial.readStringUntil('\n');
  if (Serial.read() != EndStting)
       return;
  readLine(Mesge);
}
void ReadComand() {
  if (Serial.read() != DataCommand)
       return;
  uint8_t Comd = Serial.read();
  if (Serial.read() != EndCommand)
       return;
  SetComand(Comd);
}
void SendStting(String sendtex, int seval) {
  String strtex  =  sendtex;
         strtex +=  seval;
  Serial.write(DataStting);
  Serial.println(strtex);
  Serial.write(EndStting);
  delay(2);
}
void SendStting(String sendtex, String seval) {
  String strtex  =  sendtex;
         strtex +=  seval;
  Serial.write(DataStting);
  Serial.println(strtex);
  Serial.write(EndStting);
  delay(2);
}


void setIndex() {
  if(ModeClMu) {
    MCi = mode.getCurrentIndex();
    SendStting("mcindex=", MCi);
    setting.Setup(MCi);
  } else {
    CCi = mode.getCurrentIndex();
    SendStting("ccindex=", CCi);
    setting.Setup(CCi);
  }
}
void setMode() {
  (ModeClMu) ? mode.setMode(MCi) : mode.setMode(CCi);
  setting.Setup(mode.getCurrentIndex());
  RTCm = 60;
}

void SetComand(uint8_t Comd) {
  switch(Comd) {
    case 0xF1:
        ESP.restart();
        break;
    case 0xF2:
        mode.move(1);
        setIndex();
        RTCm = 60;
        break;
    case 0xF3:
        mode.move(-1);
        setIndex();
        RTCm = 60;
        break;
    case 0xF4:
        textmsg = "Hello!", xmesg = 640;
        mesg = 4;
        break;
    case 0xF5:
        textmsg = textip;
        xmesg = 639, mesg = 0;
        break;
    case 0xF6:
        if(ModeSmv) memset(ColorFreq, 0x0, numBands);
        break;
    case 0xF7:
        textmsg  = "Zone Time Update : ";
        textmsg += tmz_str;
        xmesg = 639, mesg = 1;
        RTCm = 60;
        break;
    case 0xF8:
        xmesg = 639, textmsg = "Get Time from NTP....";
        mesg = 1;
        break;
    case 0xF9:
        xmesg = 639, textmsg = "Local Time Update";
        mesg = 1;
        RTCm = 60;
        break;
    case 0xB1:
        xmesg = 639, textmsg = "Manually Time Update";
        mesg = 1;
        RTCm = 60;
        break;
    case 0xB2:
        xmesg = 639, textmsg = "NTP Time Update";
        mesg = 1;
        RTCm = 60;
        break;
  }
}

void readLine(String Line) {
  if (Line.startsWith("mytemp=")) {
    Line = Line.substring(7);
    if (Line.length() > 0) {
      Temp = Line.toFloat();
      setting.setcolTemp();
    }
  }
  else if (Line.startsWith("myhumi=")) {
    Line = Line.substring(7);
    if (Line.length() > 0) {
      Humi = Line.toFloat();
      setting.setcolHumi();
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
  else if (Line.startsWith("modeclmu=")) {
    Line = Line.substring(9);
    if (Line.length() > 0) {
      ModeClMu = Line.toInt();
      setMode();
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
      SetComand(0xF6);
    }
  }
  else if (Line.startsWith("m24h=")) {
    Line = Line.substring(5);
    if (Line.length() > 0) {
      Mode24h = Line.toInt();
      rtc.setmode24(Mode24h);
      RTCm = 60;
    }
  }
  else if (Line.startsWith("rotation=")) {
    Line = Line.substring(9);
    if (Line.length() > 0) {
      rta = Line.toInt();
      gfx.setRotation(rta);
    }
  }
  else if (Line.startsWith("mymsge=")) {
    Line = Line.substring(7);
    if (Line.length() > 0) {
      Message = Line;
    }
  }
  else if (Line.startsWith("mytimstz=")) {
    Line = Line.substring(9);
    if (Line.length() > 0) {
      tmz_str = Line;
    }
  }
  else if (Line.startsWith("myipadd=")) {
    Line = Line.substring(8);
    if (Line.length() > 0) {
      textip = Line;
    }
  }
}


};

#endif
