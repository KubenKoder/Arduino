/*To control the rover, Copy and paste the code below into the Arduino software*/
int E1 = 6; //M1 Speed Control
int E2 = 5; //M2 Speed Control
int M1 = 8; //M1 Direction Control
int M2 = 7; //M2 Direction Control


// SENSOR-TING
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;
//SLUTT PÅ SENSOR-TING


void setup(void) {
    int i;
    for (i = 5; i <= 8; i++)
        pinMode(i, OUTPUT);
    Serial.begin(9600);
    Serial.println("setup");

// SENSOR-TING
// Ultrasonic sensor setup
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
//SLUTT PÅ SENSOR-TING

}

void loop(void) {
    while (Serial.available() < 1) {
      
      
// SENSOR-TING      
      // Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
//SLUTT PÅ SENSOR-TING

// Reagere på sensor
if(distance <20){
  reverse(120, 120); //Bakke
  delay(2000);
  stop();
}

//Slutt på reaksjon

      
        } // Wait until a character is received

        
    char val = Serial.read();
    int leftspeed = 120; //255 is maximum speed
    int rightspeed = 120;
    int moveTime = 1000;
    switch (val) // Perform an action depending on the command
    {
        case 'w'://Move Forward
        case 'W':
            forward(leftspeed, rightspeed);
            delay(moveTime);
            break;
        case 's'://Move Backwards
        case 'S':
            reverse(leftspeed, rightspeed);
            delay(moveTime);
            break;
        case 'a'://Turn Left
        case 'A':
            left(leftspeed, rightspeed);
            delay(moveTime);
            break;
        case 'd'://Turn Right
        case 'D':
            right(leftspeed, rightspeed);
            delay(moveTime);
            break;
        default:
            stop();
            break;
    }
}

void stop(void) //Stop
{
    digitalWrite(E1, LOW);
    digitalWrite(E2, LOW);
    Serial.println("stop");
}

void forward(char a, char b) {
    analogWrite(E1, a);
    digitalWrite(M1, LOW);
    analogWrite(E2, b);
    digitalWrite(M2, LOW);
    Serial.println("forward");
}

void reverse(char a, char b) {
    analogWrite(E1, a);
    digitalWrite(M1, HIGH);
    analogWrite(E2, b);
    digitalWrite(M2, HIGH);
    Serial.println("reverse");
}

void left(char a, char b) {
    analogWrite(E1, a);
    digitalWrite(M1, HIGH);
    analogWrite(E2, b);
    digitalWrite(M2, LOW);
    Serial.println("left");
}

void right(char a, char b) {
    analogWrite(E1, a);
    digitalWrite(M1, LOW);
    analogWrite(E2, b);
    digitalWrite(M2, HIGH);
    Serial.println("right");
}
