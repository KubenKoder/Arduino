#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

//Connections guide from: https://create.arduino.cc/projecthub/arduino_uno_guy/i2c-liquid-crystal-displays-5b806c
// GND-> ground
// VCC-> +5V
// SDA-> A4
// SCL-> A5



void setup() {
  //starter serie-kommunikasjon mellom arduino og PC med hastighet 9600 tegn per sekund
 Serial.begin(9600); 
//LCD screeen config
  lcd.init();                  // initialize the lcd
  lcd.backlight();             //Turns on the backlight
  lcd.clear();                 //Empties the screen
  lcd.setCursor(3, 0);         // move cursor to the forth position on the first row, 0 is the first.
  lcd.print("Percent");        // print message at the cursor position

 
}

void loop() {
  //måler spenningen på pinne A0 og lagrer den under variabel-navn "verdi"
int verdi = analogRead(A0); 
//Sender grenseverdier og målte verider  til PC over Serial-kommunikasjon
Serial.print("300,700,1023,");
Serial.println(verdi);  

//Er verdien mindre en 300?
if ( verdi < 300 ){
  Serial.print("Revers "); 
}

//Er verdi mellom 300 og 700?
if ( verdi > 300 && verdi < 700) { // for å teste to ting med en gang så kan man bruke "&&" tegn.
  Serial.print("STOP "); 
}

//Er verdien over 700?
if ( verdi > 700 ){
  Serial.print("Forward "); 
}

} //slutt på loop
