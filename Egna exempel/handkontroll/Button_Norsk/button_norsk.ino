// Dette programmet er "02. Digital > Button" eksempelet, med mange kommentarer.
// Tekst som er bak disse to tegnene ( // ) er kommentarer og påvirker ikke koden sin funksjon.
// TIPS: Husk å ende hver linje med kode med et semikolon ( ; ) tegn.
// TIPS: Noter deg fargeforskjellen på funksjoner og kode. Funksjonene er farget og de er selve kommandoen som får noe til å skje.

// Først lager vi tre variable sånn at vi kan gi dem verdier. Vi setter disse variablene før hoved-funskjonen.

int pinneKnappenErKobletTil = 2; // Denne linjen lager en variabel som lagrer pin nummeret til knappen som er koblet til.
int pinneMedLED =  13;           // Denne linjen lager en variabel som lagrer pin nummeret til LEDen som er koblet til.
int knappenErTrykketNed = 0;     // Denne linjen lager en variabel der vi skal lagre informasjon som forteller oss om knappen er trykket ned eller ikke.
// Verdien til denne variablen kommer til å forandre seg mens programmet kjører.

// Her skriver vi koden som skal kjøres en gang av Arduinoen.

// Her åpner vi funksjonen med en åpen bracket. ( { )
void setup() {
  // Alt som er inni { og } tegnene er inni en funksjon som heter setup.
  pinMode(pinneMedLED, OUTPUT);            // Dette gjør slik at vi kan sende et digitalt signal til pinne 13.
  pinMode(pinneKnappenErKobletTil, INPUT); // Dette gjær slik at vi kan lese signaler av pinne 2.

  // Hvis det er andre ting vi må gjøre når vi starter programmet bør vi legge dem til her.

} // Denne funksjonen ender her med en lukkende bracket ( } )

// Her er hoved-funksjonen eller "loopen". Funksjonen åpnes med en {
void loop() {
  
  // Det første vi gjør er å sjekke om knappen er trykket ned.
  // Dette gjør vi ved å lese av den digitale verdien til pinnen knappen er koblet til.
  knappenErTrykketNed = digitalRead(pinneKnappenErKobletTil); // Denne linjen måler og forteller oss om knappen er trykken ned (1) eller ikke (0) 
  
  // Nå vil vi gjøre noe med informasjonen vi fikk fra å lese av knappen.
  // Vi vil skru på LEDen vår hvis knappen er trykket ned og skru den av hvis knappen ikke er trykket ned.
   // "if" blokken er en viktig operasjon i kode. Den sjekker hvis noe er sant, og utfører kode hvis det som ble sjekket var sant.
  if (knappenErTrykketNed == 1)  // I denne "if" blokken sjekker vi om variabelen vår "knappenErTrykketNed" er lik 1. 
  { // Vi åpner "if" blokken sin scope med en {
    // All koden som er inne i mellom { og } blir utført hvis "if" blokken sitt kontrollspørsmål var sant.
    
    digitalWrite(pinneMedLED, HIGH); // Denne linja skrur på LED lyset. Det blir gjørt ved å sette verdien på pinnen til LEDen til HIGH.

    // Her kan man plasserere annen kode man vil kjøre om knappen er trykket ned.

   } // Denne }'en markerer at "if" blokken vår ender.
  // "else" blokken er den andre halvdelen av "if" blokken som blir kjørt om kontrollspørsmålet i "if" blokken var usann.
  else
  { // Vi åpner "else" blokken sin scope med en {
    // All koden som er inne i mellom { og } blir utført hvis "if" blokken sitt kontrollspørsmåø var usant.
    
    digitalWrite(pinneMedLED, LOW); // Denne linja skrur av LED lyset. Det blir gjort ved å sette veriden på pinnen til LEDen til LOW.
    
    // Her kan man plassere annen kode man vil kjøre når knappen ikke er trykket ned.

  } // Denne }'en markerer at "else" blokken vår ender.

} // Loopen slutter her ved denne }'en

// Koden som du skriver under her blir ikke kjørt inne i loopen.
// Vil du at mer skal skje inne i loopen må du legge til mer kode tidligere i programmet.
