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
    byte digitPins[] = {2, 3, 4, 5};
    byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12};
    bool resistorsOnSegments = true;

    byte hardwareConfig = COMMON_CATHODE; 
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);
}

void loop() {
  uint8_t rateValue;
  heartrate.getValue(heartratePin);   // A1 foot sampled values
  rateValue = heartrate.getRate();   // Get heart rate value 
  if(rateValue > 0)  {
    Serial.println(rateValue);

    int hundreds = rateValue/100;
    int tens = (rateValue/10)%10;
    int ones = rateValue % 10;
    // separate rateValue into hundreds, tens and ones
   sevseg.setNumber (hundreds*100+tens*10+ones, 3);


    // display on 7-seg
    sevseg.refreshDisplay();
  }
  delay(20);
}
