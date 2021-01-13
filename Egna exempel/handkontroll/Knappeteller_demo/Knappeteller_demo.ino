int hvorbraerman = 0; //til å begynne med er denne 0, blir mer etterhvert
int pinneMedKnapp = 3;
int knappenAkkuratDenneTid = 0;
void setup() {
Serial.begin(115200); //gjør instilling så at vi får lov til å sende tekst
pinMode(pinneMedKnapp,OUTPUT);//instilling for at kunne måle om knappen er trykket in
}
void loop() {
knappenAkkuratDenneTid = digitalRead(pinneMedKnapp); //mål om knappen er trykket ned
if (knappenAkkuratDenneTid == HIGH){
hvorbraerman++; //Øke hvorbraerman med +1. Gøy måte at skrive det på.
}
Serial.print("Man er "); //print sender tekst men bytter ikke rad
Serial.print(hvorbraerman); //her sender vi ett tall som er sparet i en variabel, så vi bruker ikke ""
Serial.println(" % bra"); //println sender en melding og bytter rad ln= line = bytt rad
delay(100); //Venter litt før vi måler på nytt så at det ikke telles som mange tast i sekundet
}
