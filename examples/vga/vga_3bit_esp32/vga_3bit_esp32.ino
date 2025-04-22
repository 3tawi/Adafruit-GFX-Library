
/*
 - vga_3bit_esp32
 * Written by 3tawi
 * Lien vidéo: https://youtu.be/zPvuzV2fqaA
 * REQUIRES the following Arduino libraries:
    * https://github.com/3tawi/ESP32VGA3Bit
    * https://github.com/3tawi/GP_GFX
    * https://github.com/3tawi/EspDHT
    * https://github.com/kosme/arduinoFFT
    * https://github.com/Arduino-IRremote/Arduino-IRremote
 * Find All "Great Projects" Videos : https://www.youtube.com/c/GreatProjects
*/

#include "Setting.h"
Setting setting;
#include "Play.h"
#include "Modeclock.h"
Modeclock mode;
#include "Command.h"
Command setcomd;

void setup() {
  Serial.begin(1500000, SERIAL_8E2);
  delay(2000);
  rtc.setTime();
  vga.setFrameBufferCount(2);
  vga.init(vga.MODE640x400.custom(639, 399), redPin, greenPin, bluePin, hsyncPin, vsyncPin);
  gfx.setTextWrap(false);
  mode.setMode(0);
  setting.Setup(0);
  setting.drawdrapo(150, 190, 5, 5, 2, 1.60f);
  vga.show();
  delay(4000);
  setting.SendCommand(0x5F);
}


//mainloop
void loop() {
  ReadSerial();
  mode.playframe();
}

void ReadSerial() {
  while (Serial.available()) {
    switch (Serial.peek()) {
      case DataBand:
         setcomd.ReadBand();
         break;
      case DataTime:
         setcomd.ReadTime();
         break;
      case DataMesg:
         setcomd.ReadMesg();
         break;
      case DataStting:
         setcomd.ReadStting();
         break;
      case DataCommand:
         setcomd.ReadComand();
         break;
      default:
         Serial.read();
         break;
    }
  }
}

