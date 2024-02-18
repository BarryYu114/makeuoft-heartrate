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

  if(rateValue)  {
    sevseg.setNumber(rateValue,2);
    sevseg.refreshDisplay();
    Serial.println(rateValue);
    for(int i = 0; i < 3; i++){
        digitOn(i);
        delay(10);
    }
  }
  else{
    delay(30);
  }
}


//BMI calculator
float calculateBMI(float weight, float height) {
  // Convert height from centimeters to meters
  float heightInMeters = height / 100.0;

  // Calculate BMI using the formula: weight / (height * height)
  float bmi = weight / (heightInMeters * heightInMeters);

  return bmi;
}
