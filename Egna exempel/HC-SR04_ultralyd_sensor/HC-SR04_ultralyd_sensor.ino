/*
  Ultrasonic Sensor HC-SR04
  
   The circuit for the sensor:
 - Vcc connection of the HC-SR04 attached to +5V
 - GND connection of the HC-SR04 attached to ground
 - Trig connection of the HC-SR04 attached to pin 5
 - Echo connection of the HC-SR04 attached to pin 6

The circuit for two optional indicator LEDs:
- Long leg of Red LED to pin 5
- Short leg of Red LED to a 200-1000 Ohm resistor
- Resistor to ground 
- Long leg of Green LED to pin 10
- Short leg of Green LED to a 200-1000 Ohm resistor
- Resistor to ground 

 created 2 sep 2020
 by Colin Vinson
 modified 21.09.2020
 by Jakob Nilsson
(Added LED circuit instructions and comments)
*/
    // define pins for HC-SR04
    const int trigPin = 5;
    const int echoPin = 6;
    
    // define pins for leds
    const int rLed = 9;
    const int gLed = 10;

    // define variables
    long duration;
    float distance;
    
    void setup(){
      pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
      pinMode(echoPin, INPUT); // Sets the echoPin as an Input
      pinMode(rLed, OUTPUT); //Sets the pin for the red LED as an Output
      pinMode(gLed, OUTPUT); //Sets the pin for the green LED as an Output
     
      Serial.begin(9600); // Starts the serial communication

     
      digitalWrite(trigPin, LOW); // clear the trigPin
    }    
    
    void loop() { 
      // Pulses the trigPin; HIGH state for 10 micro seconds then LOW, this triggers the sound pulse.
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);  // Reads the echoPin and measures the time until it detects an echo, returns the sound wave travel time in microseconds
      distance= duration*0.034/2; // Calculating the distance from the time it took the soundwave to go back and forth: (duration * 0.034 cm/microsecond)/2
      
      // Prints the distance in cm on the Serial Monitor
      Serial.print("Distance: ");
      Serial.print(distance);
      Serial.println(" cm");

      if (distance > 20){ //If the distance is measured to be more than 20 cm, do this.
        digitalWrite(gLed, HIGH); //Turns on the green LED
        digitalWrite(rLed, LOW); //Turns off the red LED
      }
      else{ //If the distance is measured to be less than 20 cm, do this.
        digitalWrite(gLed, LOW);  //Turns off the green LED
        digitalWrite(rLed, HIGH); //Turns on the red LED
        Serial.println("Object!!!!!!!!!!!!!!!!!!!!!!!!"); //Prints the text to the serial monitor
      }
    }
