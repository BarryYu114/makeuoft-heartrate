
#include "DFRobot_Heartrate.h"
#define heartratePin A1
#include <Wire.h>
#include "rgb_lcd.h"
#define GREEN_LED_PIN A3
#define RED_LED_PIN A4

DFRobot_Heartrate heartrate(DIGITAL_MODE); // Use DIGITAL_MODE or ANALOG_MODE as needed

// Pins for the segments of the display
int pinA = 6; int pinB = 7; int pinC = 8; int pinD = 9;
int pinE = 10; int pinF = 11; int pinG = 12; int pinDP = 13;

// Pins for the digits of the display
int digits[4] = {2, 3, 4, 5}; // Array to hold digit pins

rgb_lcd lcd;
const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

void setup() {
  Serial.begin(115200);
  // Initialize all the segment and digit pins as OUTPUT
  int segmentPins[] = {pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinDP};
  for (int i = 0; i < sizeof(segmentPins)/sizeof(segmentPins[0]); i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  for (int i = 0; i < sizeof(digits)/sizeof(digits[0]); i++) {
    pinMode(digits[i], OUTPUT);
  }

  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);

  lcd.begin(16, 2);
  lcd.setRGB(255, 255, 255);
  // Print a message to the LCD.
  lcd.setCursor(0,0);
  lcd.print("Hello user!");
  lcd.display();
  delay(1000);
}

void loop() {
  lcd.clear();
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
  lcd.print("Measuring... ");
  lcd.display();

  uint8_t rateValue;
  heartrate.getValue(heartratePin);
  rateValue = heartrate.getRate(); // Get heart rate value
  
  if(rateValue) {
    Serial.println(rateValue);
    lcd.clear();
    displayNumber(rateValue);
    if(rateValue < 30){
      lcd.setRGB(255, 0, 0);
      lcd.setCursor(0,0);
      lcd.print("BAD!");
      lcd.setCursor(0,1);
      lcd.print("BPM: ");
      lcd.print(rateValue);
      digitalWrite(RED_LED_PIN, HIGH); // Red LED on
      digitalWrite(GREEN_LED_PIN, LOW);
    }
    else{
      lcd.setRGB(0,255,0);
      lcd.setCursor(0,0);
      lcd.print("GOOD!");
      lcd.setCursor(0,1);
      lcd.print("BPM: ");
      lcd.print(rateValue);
      digitalWrite(RED_LED_PIN, LOW);
      digitalWrite(GREEN_LED_PIN, HIGH); //Green LED
    }
    delay(1000); // Delay between updates (adjust as needed)
  }
  delay(50);
}

void displayNumber(int number) {
  int displayTime = 1000; // Display time in milliseconds
  int startTime = millis();
  while(millis() - startTime < displayTime) {
    for(int digit = 0; digit < 4; digit++) {
      int digitValue = (number / (int)pow(10, 3-digit)) % 10;
      displayDigit(digitValue);
      // Activate the current digit and deactivate others
      for(int i = 0; i < 4; i++) {
        digitalWrite(digits[i], i == digit ? LOW : HIGH); // Assuming common cathode display
      }
      delay(5); // Short delay for multiplexing visibility
      clearDigits();
    }
  }
  clearDigits();
}


void displayDigit(int digit) {
  // Implement digit display logic here, similar to your `zero`, `one`, etc. functions
  // This function should set the correct segments for the given digit
  // Example for digit 0:
  switch(digit) {
    case 0: zero(); break;
    case 1: one(); break;
    case 2: two(); break;
    case 3: three(); break;
    case 4: four(); break;
    case 5: five(); break;
    case 6: six(); break;
    case 7: seven(); break;
    case 8: eight(); break;
    case 9: nine(); break;
    // Add cases for each digit
  }
  // Ensure you implement zero() through nine() functions to control the segment pins correctly
}

void clearDigits() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(digits[i], HIGH); // Turn off all digit pins
  }
}

void zero(){
digitalWrite(pinA, HIGH);
digitalWrite(pinB, HIGH);
digitalWrite(pinC, HIGH);
digitalWrite(pinD, HIGH);
digitalWrite(pinE, HIGH);
digitalWrite(pinF, HIGH);
digitalWrite(pinG, LOW);
  }

  void one(){
digitalWrite(pinA, LOW);
digitalWrite(pinB, HIGH);
digitalWrite(pinC, HIGH);
digitalWrite(pinD, LOW);
digitalWrite(pinE, LOW);
digitalWrite(pinF, LOW);
digitalWrite(pinG, LOW);
}

void two(){
  digitalWrite(pinA, HIGH);
digitalWrite(pinB, HIGH);
digitalWrite(pinC, LOW);
digitalWrite(pinD, HIGH);
digitalWrite(pinE, HIGH);
digitalWrite(pinF, LOW);
digitalWrite(pinG, HIGH);
  }
  
  void three(){
    digitalWrite(pinA, HIGH);
digitalWrite(pinB, HIGH);
digitalWrite(pinC, HIGH);
digitalWrite(pinD, HIGH);
digitalWrite(pinE, LOW);
digitalWrite(pinF, LOW);
digitalWrite(pinG, HIGH);
    }
    
  void four(){
    digitalWrite(pinA, LOW);
digitalWrite(pinB, HIGH);
digitalWrite(pinC, HIGH);
digitalWrite(pinD, LOW);
digitalWrite(pinE, LOW);
digitalWrite(pinF, HIGH);
digitalWrite(pinG, HIGH);
    }
    
  void five(){
    digitalWrite(pinA, HIGH);
digitalWrite(pinB, LOW);
digitalWrite(pinC, HIGH);
digitalWrite(pinD, HIGH);
digitalWrite(pinE, LOW);
digitalWrite(pinF, HIGH);
digitalWrite(pinG, HIGH);
    }
    
  void six(){
    digitalWrite(pinA, HIGH);
digitalWrite(pinB, LOW);
digitalWrite(pinC, HIGH);
digitalWrite(pinD, HIGH);
digitalWrite(pinE, HIGH);
digitalWrite(pinF, HIGH);
digitalWrite(pinG, HIGH);
    }
    
  void seven(){
    digitalWrite(pinA, HIGH);
digitalWrite(pinB, HIGH);
digitalWrite(pinC, HIGH);
digitalWrite(pinD, LOW);
digitalWrite(pinE, LOW);
digitalWrite(pinF, LOW);
digitalWrite(pinG, LOW);
    }
    
  void eight(){
    digitalWrite(pinA, HIGH);
digitalWrite(pinB, HIGH);
digitalWrite(pinC, HIGH);
digitalWrite(pinD, HIGH);
digitalWrite(pinE, HIGH);
digitalWrite(pinF, HIGH);
digitalWrite(pinG, HIGH);
    }
    
  void nine(){
    digitalWrite(pinA, HIGH);
digitalWrite(pinB, HIGH);
digitalWrite(pinC, HIGH);
digitalWrite(pinD, LOW);
digitalWrite(pinE, LOW);
digitalWrite(pinF, HIGH);
digitalWrite(pinG, HIGH);
    }
