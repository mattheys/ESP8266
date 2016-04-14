#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char *ssid = "ESPGreatness";
const char *password = "password";

ESP8266WebServer server ( 80 );

void setup() {
  WiFi.begin ( ssid, password );
  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
  }
  if ( MDNS.begin ( "esp8266" ) ) {
  }

  server.on ( "/", handleRoot );
  server.on ( "/raphael-2.1.4.min.js", handleRaphael );
  server.on ( "/justgage.js", handleJustGauge );
  server.onNotFound ( handleNotFound );
  server.begin();
  
}

void loop() {
  server.handleClient();
}


