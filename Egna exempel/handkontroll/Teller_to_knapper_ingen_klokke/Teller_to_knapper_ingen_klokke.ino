//I dette program skall vi teste 2 knapper
//Instillinger for knapper
const int knapp1 = 2;  
const int knapp2 = 3;
//Variabler vi trenger
int teller = 60;

void setup() {
Serial.begin(9600); //starter opp PC kommunikasjon
//Set ingangerne for knappene
pinMode(knapp1,INPUT); 
pinMode(knapp2,INPUT); 
}

void loop() {
  //Mål knappene
boolean knapp1Status = digitalRead(knapp1);
boolean knapp2Status = digitalRead(knapp2);
if(knapp1Status == HIGH){
  teller += 5;
  delay(500);
}
if(knapp2Status == HIGH){
  teller -= 5;
  delay(500);
}
Serial.print(knapp1Status);
Serial.print(" ");
Serial.print(knapp2Status);
Serial.print(" teller  er ");
Serial.println(teller);


}
