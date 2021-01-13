#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

//Connections guide from: https://create.arduino.cc/projecthub/arduino_uno_guy/i2c-liquid-crystal-displays-5b806c
// GND-> ground
// VCC-> +5V
// SDA-> A4
// SCL-> A5

void setup()
{
  lcd.init();                  // initialize the lcd
  lcd.backlight();             //Turns on the backlight
  lcd.clear();                 //Empties the screen
  lcd.setCursor(3, 0);         // move cursor to the forth position on the first row, 0 is the first.
  lcd.print("Seconds");        // print message at the cursor position
}

void loop()
{
for(int i=0;i<=60;i++){         //For-loop, this counts up from 0 to 60 and resets for the next loop.
  lcd.setCursor(0, 0);         // move cursor to   (0, 0)
  lcd.print(i);                // print message at (0, 0) This overwrites any old message.
  delay(1000);                 // wait one second (1000 milliseconds = 1 s)
}
}
