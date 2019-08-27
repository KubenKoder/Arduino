#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#ifndef STASSID
#define STASSID "Red danger"
#define STAPSK  "struldag"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

ESP8266WebServer server(80);

void handleRoot() {

  server.send(200, "text/html", "<a href=\"/forward\">Forward</a><br><a href=\"/backwards\">Backwards</a><br><a href=\"/left\">Left</a><br><a href=\"/right\">Right</a><br><a href=\"/stop\">STOP</a>");
}

void handleNotFound() {
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
}

void setup(void) {
  Serial.begin(9600);
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

  server.on("/forward", []() {
server.send(200, "text/html", "<a href=\"/forward\">Forward</a><br><a href=\"/backwards\">Backwards</a><br><a href=\"/left\">Left</a><br><a href=\"/right\">Right</a><br><a href=\"/stop\">STOP</a>");

      Serial.println("w");
  });


  server.on("/backwards", []() {
server.send(200, "text/html", "<a href=\"/forward\">Forward</a><br><a href=\"/backwards\">Backwards</a><br><a href=\"/left\">Left</a><br><a href=\"/right\">Right</a><br><a href=\"/stop\">STOP</a>");

      Serial.println("s");
  });

    server.on("/left", []() {
server.send(200, "text/html", "<a href=\"/forward\">Forward</a><br><a href=\"/backwards\">Backwards</a><br><a href=\"/left\">Left</a><br><a href=\"/right\">Right</a><br><a href=\"/stop\">STOP</a>");

      Serial.println("a");
  });

    server.on("/right", []() {
server.send(200, "text/html", "<a href=\"/forward\">Forward</a><br><a href=\"/backwards\">Backwards</a><br><a href=\"/left\">Left</a><br><a href=\"/right\">Right</a><br><a href=\"/stop\">STOP</a>");
      Serial.println("d");
  });

    server.on("/stop", []() {
server.send(200, "text/html", "<a href=\"/forward\">Forward</a><br><a href=\"/backwards\">Backwards</a><br><a href=\"/left\">Left</a><br><a href=\"/right\">Right</a><br><a href=\"/stop\">STOP</a>");
      Serial.println(" ");
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
  MDNS.update();
}
