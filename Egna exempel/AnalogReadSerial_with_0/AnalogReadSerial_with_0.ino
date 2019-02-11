/*
  AnalogReadSerial

  This example is used to show why you need a pull down/up resistor for your input pins.
  Reads the noise on analog input on pin 0, and prints the result to the Serial Monitor.
  Use the Serial Plotter (Tools > Serial Plotter menu) for a graphical representation.
  Try moving your hand to and from the board while watching the plot of the noise generated from the static electricity.
  
  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.print(0);
  Serial.print(",");
    Serial.print(1023);
Serial.print(",");
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability
}
