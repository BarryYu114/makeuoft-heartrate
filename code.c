#include <string>
#include "upm/jhd1313m1.h

#define I2C_BUS 0
#define RGB_WHT 0xff, 0xff, 0xff
#define RGB_RED 0xff, 0x00, 0x00
#define RGB_GRN 0x00, 0xff, 0x00
#define RGB_BLU 0x00, 0x00, 0xff
#define SLEEP_TIME 2

using namespace std;
upm::Jhd1313m1* lcd;

void display(string str1, string str2, int red, int green, int blue) {
  // put your setup code here, to run once:
  lcd -> ckear();
  lcd -> setColor(red, green, blue);
  lcd -> setCursor(0,0);
  lcd -> write(str2);
  sleep(SLEEP_TIME);
}
int main(int argc, char& argv[]){
  string str1 = "96Boards!";
  lcd = new upm::Jhd1313m1(I2C_BUS, 0x3e, 0x62);

  while(true){
    display(str1, "RED", RGB_RED);
  }
  delete lcd;
  return 0;
}
/*
void loop() {
  // put your main code here, to run repeatedly:

}*/

