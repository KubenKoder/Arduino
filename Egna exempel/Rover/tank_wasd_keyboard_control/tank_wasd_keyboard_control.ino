/*To control the rover, Copy and paste the code below into the Arduino software*/
int E1 = 6; //M1 Speed Control
int E2 = 5; //M2 Speed Control
int M1 = 8; //M1 Direction Control
int M2 = 7; //M2 Direction Control

void setup(void) {
    int i;
    for (i = 5; i <= 8; i++)
        pinMode(i, OUTPUT);
    Serial.begin(9600);
    Serial.println("setup");
}

void loop(void) {
    while (Serial.available() < 1) {} // Wait until a character is received
    char val = Serial.read();
    int leftspeed = 120; //255 is maximum speed
    int rightspeed = 120;
    switch (val) // Perform an action depending on the command
    {
        case 'w'://Move Forward
        case 'W':
            forward(leftspeed, rightspeed);
            break;
        case 's'://Move Backwards
        case 'S':
            reverse(leftspeed, rightspeed);
            break;
        case 'a'://Turn Left
        case 'A':
            left(leftspeed, rightspeed);
            break;
        case 'd'://Turn Right
        case 'D':
            right(leftspeed, rightspeed);
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
