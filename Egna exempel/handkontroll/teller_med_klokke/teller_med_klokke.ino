//Variabler
int klokken = 0;
int forrigeSekunder = 0;
int teller = 60;

//Instillninger
void setup() {
  Serial.begin(9600); //Starter seriell kommunikasjon
}

//Programmets hoved loop
void loop() {
klokken = millis()/1000;//Vi sparer hva klokke er i sekunder
if (klokken > forrigeSekunder){//Er vi inne i en ny sekund?
forrigeSekunder = klokken;  //Lagre ny klokkeslett
teller= teller -1; //Telle opp(+) eller ned(-)

//Skriver ut hva klokken er på serial
Serial.print("Teller er nå "); 
Serial.println(teller);
}

} //loop slutter her
