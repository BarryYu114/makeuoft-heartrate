#include "DFRobot_Heartrate.h"
#include "SevSeg.h"
#define heartratePin A1

DFRobot_Heartrate heartrate(DIGITAL_MODE);   // ANALOG_MODE or DIGITAL_MODE

// define pin number and segment numbers 
// int D1 = 2;
// int D2 = 3;
// int D3 = 4;
// int D4 = 5;

// int A = 6;
// int B = 7;
// int C = 8;
// int D = 9;
// int E =  10;
// int F = 11;
// int G = 12;
// int DP = 13;

SevSeg sevseg;

void setup() {
  Serial.begin(115200);
   byte numDigits = 3;
    byte digitPins[] = {2, 3, 4};
    byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12};
    bool resistorsOnSegments = true;

    byte hardwareConfig = COMMON_CATHODE; 
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(100);
}

void loop() {
  uint8_t rateValue;
  heartrate.getValue(heartratePin);   // A1 foot sampled values
  rateValue = heartrate.getRate();   // Get heart rate value 
  

    Serial.println(rateValue);

    // separate rateValue into hundreds, tens and ones

   sevseg.setNumber (rateValue, 2);

    // display on 7-seg
    sevseg.refreshDisplay();


}
