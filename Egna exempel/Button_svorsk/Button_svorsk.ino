// Detta program er "02. Digital > Button"-exemplet, fast med masse kommentarer på svorsk 
// Text bak disse to tegn // er kommentarer och påverkar inte kodens funktion
// TIPS: Husk å avsluta alla koderader med ; tegn
// TIPS: Notera fargeforskell på funktion og øvrig kode. Funktionerna er farget och de er kommandon som får noe å ske.

// Først skaper vi tre variabler så att vi kan lagre verdier. Det sker føre progammet begynner å køre.
int pinneKnappenErKobletTil = 2; // Denna rad lager en variable som lagrer pin nummer som knappen er koblet till
int pinneMedLED =  13;           // Denna rad lager en variable som lagrer pin nummer som LED er koblet till 
int knappenErTrykketNed = 0;     // Denna rad lager en variable der vi ska spare information om knappen blir trykket ned eller ej, 
// Tallet som vi sparer i variablen med namn knappenErTrykketNed kommer att endres under tiden som vi kører programmet.

// Her gør vi instillninger
void setup() { // Instillningerne begynner fra detta { tegn 
  
  pinMode(pinneMedLED, OUTPUT);  // Detta gør instillningen att vill kunna sende eller skriva en digital signal till pinne 13.
  pinMode(pinneKnappenErKobletTil, INPUT); // Detta gør instillningen att vill kunna måle digital signal på pinne 2. 

// Vis vi vill bruke flere pins en disse to som ingang eller utgang så bør vi legge till instillninger før dem her.

} // Instillningerne slutar vid detta } tegn

void loop() { // Huvudprogrammet eller "loopen" begynner fra detta { tegn 
  
  // Det førsta vi gør er å chekke om knappen er trykket ned
  // Det gør vi genom å lese den digitala signalen (som kan vara 1 eller 0) på pinnen som knappen er koblet till 
  knappenErTrykketNed = digitalRead(pinneKnappenErKobletTil); // Denna raden måler och lagrer om knappen er trykket ned (1) eller ej (0). 
  
  // Nu vill vi gøra noe med informationen vi målt om knappen
  // Vi vill slå på en LED vis knappen er trykket ned och vi vill slå LED av om knappen er sluppet opp.
   // if-satsen er ett viktigt kommando i kode. Det sjekker vis noe ær sant eller faskt och kører ulike kode beroende på det
  if (knappenErTrykketNed == 1)  // If-satsen er sann då verdin vi sparat i variablen med namn "knappenErTrykketNed" er lik siffran 1  
  { // All den kode som står nedan fram till neste } tegn vill køres så lenge if-satsen kontrollspørsmål er blir sant. 
    
    digitalWrite(pinneMedLED, HIGH); // Denna rad slår på en LED som er koblet till en pinne, vilken pinne beror på vad du spart i pinneMedLED variablen.

    // HER KAN DU SETTE IN KODE SOM DU VILL SKA KØRES NÅR KNAPPEN ER TRUKKET NED!

   } // Detta markerer sluttet på vad som sker om if-satsen er sann.
  
  else // else er andra halvdelen av if-satsen och innehåller koden som køres om if satsen er usann, feil, null eller falsk. 
  {  // Start på vad som sker når if-satsen er usann
    
    digitalWrite(pinneMedLED, LOW);
    
    // HER KAN DU SETTE IN KODE SOM DU VILL SKA KØRES NÅR KNAPPEN ER SLUPPET OPP!

  } // Detta makerer slut på vad som sker når if-satsen er usann

} // Huvudprogrammet slutar vid detta } tegn och "looper" fra loopens motsvarande start-tegn.

// Her kan vi inte skriva mer siden det er utanfør "setup" och "loop". 
// Vill du att mer ska ske så må du laga nya rader innuti programmet
