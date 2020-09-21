
//Spare rover motor-pin-nummer i variabler med navn vi husker
int hastighet_1 = 6; //Motor 1 hastighetskontroll
int hastighet_2 = 5; //Motor 2 hastighetskontroll
int rettning_1 = 8; //Motor 1 rettningkontroll
int rettning_2 = 7; //Motor 2 rettningkontroll
//Hvis rettningen ikke stemmer for deg, så kan du snu plass på kablerne til den motor som går feil vei eller endre LOW til HIGH i koden nederst.

// define pins for a HC-SR04, an Ultrasonic range finder sensor
const int trigPin = 2;
const int echoPin = 3;

//Pin 1 (TX) og 2 (RX) blir brukt til serikommunikasjon

void setup() {
  // gjør så at vi kan bruke motor-pinsa
  pinMode(hastighet_1, OUTPUT);
  pinMode(hastighet_2, OUTPUT);
  pinMode(rettning_1, OUTPUT);
  pinMode(rettning_2, OUTPUT);
  //Gjør så vi kan bruke pins koblet til sensorn
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  // Starter seriekommunikajon via USB på pin 1 og 0
  Serial.begin(9600); //Husk BAUD 9600 på serial monitor, det er hastiheten på antall tegn i sekundet
}


void loop() {

  //MÅL AVSTAND med sensor
  // Pulses the trigPin; HIGH state for 10 micro seconds then LOW, this triggers the sound pulse.
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long  duration = pulseIn(echoPin, HIGH);  // Reads the echoPin and measures the time until it detects an echo, returns the sound wave travel time in microseconds
  int distance = duration * 0.034 / 2; // Calculating the distance from the time it took the soundwave to go back and forth: (duration * 0.034 cm/microsecond)/2
  // Prints the distance in cm on the Serial Monitor, for our amusement :)
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  //SLUTT PÅ SENSORKODE, nå har vi en oppdatert måling under variable-navn: distance

  if (distance < 10) { //If the distance is measured to be less than 10 cm, do this.
    Serial.println("Nå har vi kjørt inn i en vegg");
    bakover(); //Kjører all kode i funksjonen som heter bakover(), se nederst.
    delay(1000); //rygge i 1 sekund innen neste måling og kursendring
  }

  if (distance > 20) { //If the distance is measured to be more than 20 cm, do this.
    Serial.println("Kursen er klar!");
    fremover(); //Kjører all kode i funksjonen som heter fremover(), se nederst.
    delay(100); //vent 0.1 sekund innen neste måling og kursendring
  }
  else { //If the distance is measured to be less than 20 cm, do this.
    Serial.println("Hindring funnen!");
    sving_venster(); //Kjører all kode i funksjonen som heter sving_venster(), se nederst.
    delay(2000); //forstett å svinge i to sekunder innen neste endring
  }


} //Her slutter loopen


//HER KAN DU LAGE EGNE FUNKSJONER, kopier en å endre på inneholdet

void fremover() {
  Serial.println("nå prøver jeg å kjøre fremover");
  //kjør belte 1 fremover, full gass
  digitalWrite(rettning_1, LOW); //LOW betyr fremover!
  analogWrite(hastighet_1, 255); //255 er full gass! 100 er slow
  //kjør belte 2 fremover, full gass
  digitalWrite(rettning_2, LOW); //LOW betyr fremover!
  analogWrite(hastighet_2, 255); //255 er full gass! 100 er slow
}

void bakover() {
  Serial.println("nå prøver jeg å rygge!");
  //kjør belte 1 bakover, full gass
  digitalWrite(rettning_1, HIGH); //HIGH betyr bakover!
  analogWrite(hastighet_1, 255); //255 er full gass! 100 er slow
  //kjør belte 2 bakover, full gass
  digitalWrite(rettning_2, HIGH); //HIGH betyr bakover!
  analogWrite(hastighet_2, 255); //255 er full gass! 100 er slow
}

void sving_venster() {
  Serial.println("nå prøver jeg å svinge venster!");
  //kjør belte 1 bakover, full gass
  digitalWrite(rettning_1, HIGH); //HIGH betyr bakover!
  analogWrite(hastighet_1, 255); //255 er full gass! 100 er slow
  //kjør belte 2 fremover, full gass
  digitalWrite(rettning_2, LOW); //LOW betyr fremover!
  analogWrite(hastighet_2, 255); //255 er full gass! 100 er slow
}
