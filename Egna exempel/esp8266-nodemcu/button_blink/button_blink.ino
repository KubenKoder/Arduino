#define firstLED 2 //This LED is connected to the pin marked D0 
#define flashButton 0 //This button is connected to the pin marked D3 

boolean buttonState = LOW;    // variable for reading the pushbutton status

void setup() {
  pinMode(firstLED, OUTPUT);
   pinMode(flashButton, INPUT);
}
void loop() {

  buttonState = digitalRead(flashButton); //Read the pin, 0V = LOW, 3.3V = HIGH

// check if the pushbutton is pressed. If it is, the buttonState is LOW:
  if (buttonState == LOW) {
    // turn LED on:
    digitalWrite(firstLED, LOW); // LOW = LED ON
  } else {
    // turn LED on:
    digitalWrite(firstLED, HIGH); //HIGH = LED OFF
  }

}
