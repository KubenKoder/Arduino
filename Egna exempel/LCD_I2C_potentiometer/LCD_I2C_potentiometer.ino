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
  lcd.print("Percent");        // print message at the cursor position

//for testin
    Serial.begin(9600);
}

void loop()
{
 // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
    Serial.println(sensorValue);   // print out the value you read to the PC for checking that it works
  //Convert it to a value between 0 and 100
  int percent = map(sensorValue,0,1023,0,100); //map(value, fromLow, fromHigh, toLow, toHigh) 
  //Print the value
  lcd.setCursor(0, 0);         // move cursor to   (0, 0)
  lcd.print("   ");                // print three blank spaces to clear the area
    lcd.setCursor(0, 0);         // move cursor back to   (0, 0)
  lcd.print(percent);                // print message at (0, 0) This overwrites any old message.
  delay(200);                 // wait 200 milliseconds = 0.2 s)
}
