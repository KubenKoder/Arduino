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

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

// Let the ESP8266 know which network it should connect to
#ifndef STASSID
#define STASSID "skriv in dit trådløse nett navn her" //Wifi ID
#define STAPSK  "passord for trådløst nett" // Wifi Password
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

ESP8266WebServer server(80);

const int led = 16;

void handleRoot() {
  //digitalWrite(led, 1);
  server.send(200, "text/html", "<a href=\"/led\">Turn led off</a>");
  digitalWrite(led, 0);
   Serial.println("Led on");
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

void setup(void) {
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);

  server.on("/led", []() {
    server.send(200, "text/html", "<a href=\"/\">Turn LED on</a>");
     digitalWrite(led, 1);
      Serial.println("Led off");
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
  MDNS.update();
}
