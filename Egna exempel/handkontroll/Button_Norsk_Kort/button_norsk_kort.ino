// Dette programmet er "02. Digital > Button"-eksempelet på norsk med få kommentarer.
int pinneKnappenErKobletTil = 2;
int pinneMedLED =  13;           
int knappenErTrykketNed = 0;     

// Setup funksjon
void setup() { 
  pinMode(pinneMedLED, OUTPUT);
  pinMode(pinneKnappenErKobletTil, INPUT); 
} // Slutten av setup funksjon


// Hoved-programmet / loop funksjon start
void loop(){
 
  knappenErTrykketNed = digitalRead(pinneKnappenErKobletTil); // Sjekk om knappen er trykket ned

  // Hvis knapp er trykket ned
  if (knappenErTrykketNed == 1)  
  { 
    // Skru på LED
    digitalWrite(pinneMedLED, HIGH); 
   } 
  // Hvis knapp ikke er trykket ned
  else
  { 
    // Skru av LED
    digitalWrite(pinneMedLED, LOW); 
  }
  
} // Slutten av loop funksjon
