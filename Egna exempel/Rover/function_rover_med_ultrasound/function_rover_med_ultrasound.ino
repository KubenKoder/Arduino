
//Spare rover motor-pin-nummer i variabler med navn vi husker
int hastighet_1 = 6; //Motor 1 hastighetskontroll
int hastighet_2 = 5; //Motor 2 hastighetskontroll
int rettning_1 = 8; //Motor 1 rettningkontroll
int rettning_2 = 7; //Motor 2 rettningkontroll

// define pins for two HC-SR04, Ultrasonic range finder sensors
const int trigPin1 = 2;
const int echoPin1 = 3;
const int trigPin2 = 9;
const int echoPin2 = 10;

//Pin 1 (TX) og 2 (RX) blir brukt til serikommunikasjon

void setup() {
  // gjør så at vi kan bruke motor-pinsa
  pinMode(hastighet_1, OUTPUT);
  pinMode(hastighet_2, OUTPUT);
  pinMode(rettning_1, OUTPUT);
  pinMode(rettning_2, OUTPUT);
  //Gjør så vi kan bruke pins koblet til sensorer
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT); // Sets the echoPin as an Input

  // Starter seriekommunikajon via USB på pin 1 og 0
  Serial.begin(9600); //Husk BAUD 9600 på serial monitor, det er hastiheten på antall tegn i sekundet
}


void loop() {

  //Mål avstand med to sensorer med hjelp av en funksjon, se nederst.
  int distance1 = measureDistance(trigPin1, echoPin1);
  int distance2 = measureDistance(trigPin2, echoPin2);
  //nå har vi to oppdaterte målinger under variable-navn: distance1 og distance2

//Her så sjekker vi mange ulike kombinasjoner av de to sensorerne for å bestemme oss for vilken rettning vi ønsker å kjøre roveren
  if (distance1 < 10 || distance2 < 10 ) { //   "||" <- Dette betyr "eller", så om noen maler kort avstand, rygge.
    Serial.println("Nå har vi kjørt inn i en vegg");//Sender tekst til serial monitor
    bakover(); //Kjører all kode i funksjonen som heter bakover(), se nederst.
    delay(1000); //rygge i 1 sekund innen neste måling og kursendring
  }
  else {
    if (distance1 > 40 && distance2 > 40) { //   "&&" <- Dette betyr "også", så om begge maler langt avstand, kjør på
      Serial.println("Kursen er klar!"); //Sender tekst til serial monitor
      fremover(); //Kjører all kode i funksjonen som heter fremover(), se nederst.
      delay(100); //vent 0.1 sekund innen neste måling og kursendring
    }
    else {
      if (distance1 < 40) { //Om den ser en hindring til venster, sving høyre
        Serial.println("Hindring til venster!"); //Sender tekst til serial monitor
        sving_hoyre(); //Kjører all kode i funksjonen som heter sving_hoyre(), se nederst.
        delay(1000); //vent 1 sekund innen neste måling og kursendring
      }
      else {
        if (distance2 < 40) { //Om den ser en hindring til høyre, sving venster
          Serial.println("Hindring til høyre!"); //Sender tekst til serial monitor
          sving_venster(); //Kjører all kode i funksjonen som heter sving_høyre(), se nederst.
          delay(1000); //vent 1 sekund innen neste måling og kursendring
        }
      }
    }
  }
} //Her slutter loopen


//HER KAN DU LAGE EGNE FUNKSJONER, kopier en å endre på inneholdet

void fremover() {
  Serial.println("nå prøver jeg å kjøre fremover");//Sender tekst til serial monitor
  //kjør belte 1 fremover, full gass
  digitalWrite(rettning_1, LOW); //LOW betyr fremover!
  analogWrite(hastighet_1, 255); //255 er full gass! 100 er slow
  //kjør belte 2 fremover, full gass
  digitalWrite(rettning_2, LOW); //LOW betyr fremover!
  analogWrite(hastighet_2, 255); //255 er full gass! 100 er slow
}

void bakover() {
  Serial.println("nå prøver jeg å rygge!");//Sender tekst til serial monitor
  //kjør belte 1 bakover, full gass
  digitalWrite(rettning_1, HIGH); //HIGH betyr bakover!
  analogWrite(hastighet_1, 255); //255 er full gass! 100 er slow
  //kjør belte 2 bakover, full gass
  digitalWrite(rettning_2, HIGH); //HIGH betyr bakover!
  analogWrite(hastighet_2, 255); //255 er full gass! 100 er slow
}

void sving_venster() {
  Serial.println("nå prøver jeg å svinge venster!");//Sender tekst til serial monitor
  //kjør belte 1 bakover, full gass
  digitalWrite(rettning_1, HIGH); //HIGH betyr bakover!
  analogWrite(hastighet_1, 255); //255 er full gass! 100 er slow
  //kjør belte 2 fremover, full gass
  digitalWrite(rettning_2, LOW); //LOW betyr fremover!
  analogWrite(hastighet_2, 255); //255 er full gass! 100 er slow
}

void sving_hoyre() {
  Serial.println("nå prøver jeg å svinge til høyre!");//Sender tekst til serial monitor
  //kjør belte 1 fremover, full gass
  digitalWrite(rettning_1, LOW); //LOW betyr fremover!
  analogWrite(hastighet_1, 255); //255 er full gass! 100 er slow
  //kjør belte 2 bakover, full gass
  digitalWrite(rettning_2, HIGH); //HIGH betyr bakover!
  analogWrite(hastighet_2, 255); //255 er full gass! 100 er slow
}


int measureDistance(int trigPin, int echoPin) {
  //MÅL AVSTAND med en sensor
  // Pulses the trigPin; HIGH state for 10 micro seconds then LOW, this triggers the sound pulse.
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long  duration = pulseIn(echoPin, HIGH);  // Reads the echoPin and measures the time until it detects an echo, returns the sound wave travel time in microseconds
  int distance = duration * 0.034 / 2; // Calculating the distance from the time it took the soundwave to go back and forth: (duration * 0.034 cm/microsecond)/2
  // Prints the distance in cm on the Serial Monitor, for our amusement :)
    Serial.print(distance);//Sender tekst til serial monitor
  Serial.print (" cm ");//Sender tekst til serial monitor
  //SLUTT PÅ SENSORKODE, nå har vi en oppdatert måling under variable-navn: distance
  return distance;
}
