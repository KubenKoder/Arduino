// Detta program er "02. Digital > Button"-exemplet, fast på svorsk 

// Variabler och startverdier
int pinneKnappenErKobletTil = 2;
int pinneMedLED =  13;           
int knappenErTrykketNed = 0;     

// Instillninger
void setup() { 
  pinMode(pinneMedLED, OUTPUT);
  pinMode(pinneKnappenErKobletTil, INPUT); 
} // Slut på setup


// Huvudprogrammet
void loop(){
 
  knappenErTrykketNed = digitalRead(pinneKnappenErKobletTil); // Check om knappen er trykket ned

  // Gør ulike ting beroende på knappen
  if (knappenErTrykketNed == 1)  
  { 
    // Gør detta når knappen er trykket ned
    digitalWrite(pinneMedLED, HIGH); 
   } 
  else
  { 
    // Gør detta når knappen er sluppet opp
    digitalWrite(pinneMedLED, LOW); 
  }
  
} // Slut på loop
