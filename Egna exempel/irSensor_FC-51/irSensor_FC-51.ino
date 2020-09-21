/*
  FC-51 Proximity /obstacle avoidance sensor module
  
  This sketch reads the input signal from the FC-51's output pin (OUT) and prints the value to the serial terminal.
  Output value is stored in a variable and used to steer a LED.

  The code is commented in norwegian.
  
  The circuit:
  - Vcc connection of the FC-51 attached to +5V
  - GND connection of the FC-51 attached to ground
  - OUT connection of the FC-51 attached to pin 4
  - The built in LED is already connected to pin 13 on all arduinos, you can add external LEDs and resistors if you like.
  
  created 2 sep 2020
  by Colin Vinson
  modified 21.09.2002
  by Jakob Nilsson
*/

//Pins som vi koblet ting til, vi lagrer tallen under variabel-navn så vi slipper huske dem
const int irOut = 4; //Vi bruker pin nr4 for å ta emot signal fra IR-hindringsdetektorn
const int led_pin = 13; //Pin nr 13 har alltid en LED koblet til på arduino-brettet

//Instillninger, kjøres en gang
void setup() { 
  Serial.begin(9600); //Gjør det mulig å sende tekst via USB med en hastighet av 9600 tegn i sekundet
  pinMode(irOut, INPUT); //Sier at vi skall ta emot signaler på denne pin
  pinMode(led_pin, OUTPUT); //sier at vi skall sende ut signaler fra denne pin
}


//Den delen av vårt program som kjører i loop
void loop() {
  
  //Vi måler pin:en som er koblet til IR-hindringsdetektorn og lagrer måleverdien under navnet "irVerdi" for senere bruk
  int irVerdi = digitalRead(irOut);

 //Nå sjekker vi om detektorn ser en hindring og reagerer på det
  if (irVerdi == 0){ //Hvis måleverdien vi lagret er lik null så skall dette skje:
    Serial.println("HINDRING!!!"); //Skriver tekst via USB til Serial monitor på PCn.
    digitalWrite(led_pin, HIGH);  //Slår på LED-lyset på arduino-brettet
    } 
  else{  //Hvis måleverdien vi lagret IKKE er lik null så skall dette skje:
    digitalWrite(led_pin, LOW); //Vi slår av LED-lyset
    Serial.print("Sensor verdi: "); //Vi skriver tekst til serial-monitor over USB men bytter ikke rad. (Noter at det står "print" og ikke "println", ln står for Line.)
    Serial.println(irVerdi); //Vi sender verdien til serial monitor over USB og bytter rad. 
  }
  delay(100); //Vi venter 100 millisekunder innen vi kjører loopen på nytt så at vi rekker å lese hva som står på serial-monitorn på PCn.
} //Her slutter loopen
