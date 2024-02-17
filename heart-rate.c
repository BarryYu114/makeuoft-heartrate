#define heartratePin A1
#include "DFRobot_Heartrate.h"

DFRobot_Heartrate heartrate(DIGITAL_MODE); ///< ANALOG_MODE or DIGITAL_MODE

// define pin number and segment numbers 
int D1 = 2;
int D2 = 3;
int D3 = 4;
int D4 = 5;

int A = 6;
int B = 7;
int C = 8;
int D = 9;
int E =  10;
int F = 11;
int G = 12;
int DP = 13;

void setup() {
  Serial.begin(115200);
}

void loop() {
  uint8_t rateValue;
  heartrate.getValue(heartratePin); ///< A1 foot sampled values
  rateValue = heartrate.getRate(); ///< Get heart rate value 
  if(rateValue)  {
    Serial.println(rateValue);
  }
  delay(20);
}
