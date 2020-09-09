int hastighet_1 = 6; //Motor 1 hastighetskontroll
int hastighet_2 = 5; //Motor 2 hastighetskontroll
int rettning_1 = 8; //Motor 1 rettningkontroll
int rettning_2 = 7; //Motor 2 rettningkontroll

void setup() {
  // gjør så at vi kan bruke motor-pinsa
  pinMode(hastighet_1, OUTPUT);
  pinMode(hastighet_2, OUTPUT);
  pinMode(rettning_1, OUTPUT);
  pinMode(rettning_2, OUTPUT);
}

void loop() {
  //kjør belte 1 fremover, full gass
    digitalWrite(rettning_1, LOW); //LOW betyr fremover!
    analogWrite(hastighet_1, 255); //255 er full gass! 100 er slow
    //kjør belte 2 fremover, full gass
    digitalWrite(rettning_2, LOW); //LOW betyr fremover!
    analogWrite(hastighet_2, 255); //255 er full gass! 100 er slow
}
  
