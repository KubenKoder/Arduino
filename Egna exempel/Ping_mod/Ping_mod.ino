/*
  Ultrasonic distance sensor

  This sketch reads a ultrasonic rangefinder and returns the distance
  to the closest object in range. To initiate a reading it sends out a
  sound pulse and then listens for the echo of the pulse to return. 
  The time it takes before the echo is registered is proportional to 
  the distance of the object from the sensor.

  The circuit:
	- +V connection of the Sensor attached to +5V
	- GND connection of the Sensor attached to ground
	- SIG connection of the Sensor  attached to digital pin 7 (TRIG and ECHO can be combined)
 

  created 3 Nov 2008
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe
  modified 1 Sept 2018
  by Jakob Nilsson
  
  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Ping
*/

// This constant won't change. It's the arduino pin that communicates with the sensor:
const int pingPin = 7;

// We need to add a timeout for the longes range that the Sensor can sense, so that
// it does not get stuck waiting for an echo that never comes.
// long timeout = 157 / 74 / 2;//Timeout in microseconds for a max range of 157 inches
const long timeout = 400 * 29 * 2; //Timeout in microseconds for a max range of 400 cm

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
}

void loop() {
  // establish variables for duration of the ping, and the distance result
  // in inches and centimeters:
  long duration, inches, cm, mm;

  // The sensor is triggered by a HIGH signal for 10 microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse and 
  // to reset the sensor if it didn't register an echo from the last ping:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(10);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the Sensor: A HIGH pulse
  // whose duration is the time (in microseconds) from the sending of the ping
  // to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH,timeout);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  mm = microsecondsToMillimeters(duration);

  Serial.print(inches);
  Serial.print(" in, ");
  Serial.print(cm);
  Serial.print(" cm, ");
  Serial.print(mm);
  Serial.print(" mm");
  Serial.println();
  
  delay(100); //Recommended minimum cycle time is 50ms so that the echo has time to fade
}

long microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet for the PING))), there are 73.746
  // microseconds per inch (i.e. sound travels at 1130 feet per second).
  // This gives the distance travelled by the ping, outbound and return,
  // so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 343 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}

long microsecondsToMillimeters(long microseconds) {
  // The speed of sound is 343 m/s or 2.9215 microseconds per millimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds * 10000 /29215 / 2;
}
