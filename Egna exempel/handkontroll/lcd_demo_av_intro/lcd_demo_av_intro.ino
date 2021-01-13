#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); 
//0x27 er adressen, man kan ha 128 st på samme arduino pins om de har ulike adress
//16 er antall bokstaver eller tegn per rad, 2 er rader

void setup() {
  // put your setup code here, to run once:
lcd.init();
lcd.backlight(); // <- dette betyr at det er en kommentar og blir ikke med i koden
lcd.setCursor(0,0);  
lcd.print("Loading");



for(int x=0;x<=3;x++){
// Dette er det som jeg ønsker å repetere
lcd.setCursor(7,0);  
delay(500);
lcd.print(".");
delay(500);
lcd.print(".");
delay(500);
lcd.print(".");
delay(500);
lcd.setCursor(7,0);  
lcd.print("   ");
}//slutt på repetisjon
lcd.clear();

}


void loop() {

}
