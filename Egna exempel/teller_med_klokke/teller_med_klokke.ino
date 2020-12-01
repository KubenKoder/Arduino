int klokken = 0;
int forrigeSekunder = 0;
int teller = 60;
void setup() {
  Serial.begin(9600); //Starter seriell kommunikasjon}
}
void loop() {
klokken = millis()/1000;//Vi sparer hva klokke er i sekunder
if (klokken > 5+forrigeSekunder){//Er vi inne i en ny sekund?
forrigeSekunder = klokken; 
teller= teller +1;
Serial.print("Teller er nå "); //Skriver noe om klokken er mer en 10 sekunde  
Serial.println(teller);
}
}
