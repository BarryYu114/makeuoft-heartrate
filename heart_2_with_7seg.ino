#include "DFRobot_Heartrate.h"
#include "SevSeg.h"
#define heartratePin A1

DFRobot_Heartrate heartrate(DIGITAL_MODE);   // ANALOG_MODE or DIGITAL_MODE

SevSeg sevseg;

void setup() {
  Serial.begin(115200);
   byte numDigits = 3;
    byte digitPins[] = {2, 3, 4};
    byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12};
    bool resistorsOnSegments = true;

    byte hardwareConfig = COMMON_CATHODE; 
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(10);
}

void loop() {
   uint8_t rateValue;
  heartrate.getValue(heartratePin);   // A1 foot sampled values
  rateValue = heartrate.getRate();   // Get heart rate value 
  char rateChar[4];
  sprintf(rateChar, "%03d", rateValue);
  sevseg.setChars(rateChar);
    sevseg.refreshDisplay();
  delay(1100);
}