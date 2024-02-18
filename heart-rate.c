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

/*
// Define segment pins
const int SEGMENT_PINS[] = {2, 3, 4, 5, 6, 7, 8, 9}; // a, b, c, d, e, f, g, DP
// Define digit pins
const int DIGIT_PINS[] = {10, 11, 12, 13}; // D1, D2, D3, D4

// Define digit patterns
const byte DIGIT_PATTERNS[10] = {
  B11111100, // 0
  B01100000, // 1
  B11011010, // 2
  B11110010, // 3
  B01100110, // 4
  B10110110, // 5
  B10111110, // 6
  B11100000, // 7
  B11111110, // 8
  B11110110  // 9
};

void setup() {
  // Set pin modes
  for (int i = 0; i < 8; i++) {
    pinMode(SEGMENT_PINS[i], OUTPUT);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(DIGIT_PINS[i], OUTPUT);
  }
}

void loop() {
  int number = 123; // Your 3-digit number
  displayNumber(number);
  delay(1000); // Display for 1 second
}

void displayNumber(int num) {
  for (int i = 0; i < 3; i++) {
    int digit = num % 10; // Get the least significant digit
    num /= 10; // Move to the next digit
    displayDigit(i, digit);
    delay(5); // Delay for stability (adjust as needed)
  }
}

void displayDigit(int digitNum, int digit) {
  digitalWrite(DIGIT_PINS[digitNum], LOW); // Activate the digit
  for (int i = 0; i < 8; i++) {
    digitalWrite(SEGMENT_PINS[i], (DIGIT_PATTERNS[digit] >> i) & 1);
  }
  delay(2); // Delay for stability (adjust as needed)
  digitalWrite(DIGIT_PINS[digitNum], HIGH); // Deactivate the digit
}
*/
