/* THIS EXAMPLE LETS YOU CONTROL A LED VIA A WEBPAGE THAT IS AVAILABLE ON A PREEXISTING LOCAL NET
* FOR IT TO WORK YOU NEED TO CONNECT YOUR DEVICE (PC / SMARTPHONE ETC) TO THE SAME WIFI NETWORK AS THE ESP8266
*
*How to use:
*1. Add your wifi network details below
*2. Upload the code to the ESP8266
*3. Check the serial monitor for the IP adress of the ESP8266 local webserver
*4. Connect your PC or smartphone to the same wifi network
*5. Enter the IP adress like a webpage URL
*6. Done!
*/

/* uses code from
 *  /*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

// Let the ESP8266 know which network it should connect to
#ifndef STASSID
#define STASSID "Red danger" //Wifi ID
#define STAPSK  "humphrey" // Wifi Password
#endif

// defines pins numbers
const int trigPin = 4; //D1
const int echoPin = 5; //D2
const int led = 16;
const int ledPWR = 2;
const char* ssid = STASSID;
const char* password = STAPSK;

//Set a limit trigger for the sensor (can set this in a form later?)
const int limit = 100; //in cm

//Create a webserver
ESP8266WebServer server(80);

void setup(void) {
  //Pin setup
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(led, OUTPUT);
  pinMode(ledPWR, OUTPUT);
  digitalWrite(led, 1); //Turn led off to start with
  digitalWrite(ledPWR, 0); //Turn led on to show power is on
  //Start serial and try to connect to the Wifi
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  //When we have connection to the wifi
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

//Setup so that all vaild adresses calls a function
  server.on("/", handleRoot);
  server.on("/distance", distance);
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
  MDNS.update();
}

void distance() {

 //Measure the distance and store the value
    int distanceCM = ping();
    String distanceText = String(ping());
    String withinLimit;
       //Check if it is within a limit
if (distanceCM <= limit) {
    // turn LED on:
    digitalWrite(led, 0);
    withinLimit = "The sensor reading is inside the limit";
  } else {
    // turn LED off:
    digitalWrite(led, 1);
    withinLimit = "The sensor reading is outside the limit";
  }

String htmlString = String("<html>"
    "<head><meta http-equiv=\"refresh\" content=\"1\"></head>"  //This causes the page to auto update every second
    "<body>"
    "<p>The distance to the sensor is " + distanceText + " cm</p>"
    "<p>" + withinLimit + "</p>" 
    "<p><a href=\"/distance\">Check the distance now</a></p>" 
    "</html></body>");
  
//Send the webpage
    server.send(200, "text/html", htmlString);
}

void handleRoot() {
    server.send(200, "text/html", "<p><a href=\"/distance\">Check the distance</a></p>");
}

void handleNotFound() {
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(led, 0);
}


//Ultrasonic sensor code, returns distance in millimeters
int ping() {
  // defines variables
  long duration;
  int distance;
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance in milimeters based on the speed of sound in air and the time it took to get a echo divided in two.
  distance= duration*0.034/2;
  if (distance > 200) distance = 200; // Cap the value to avoid strange values when the signal is lost
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  return distance;
}
