#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "fivealive";
const char* password = "Jbso2027!";

WebServer server(80); 

const int ledPin = 8;
bool ledState = LOW;


void setup() {
  Serial.begin(115200);
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,ledState);

  WiFi.begin(ssid,password);
  while(WiFi.status()!= WL_CONNECTED){
    delay(1000);
    Serial.println("Connecting to Wifi...");
  }
  Serial.println("Connected to WiFi...");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/",handleRoot);
  server.on("/toggle", handleToggle);
  server.begin();
}

void handleRoot(){
  String html= "<html><body>";
  html += "<h1>Pete's ESP32 LED Control Experiment</h1>";
  html += "<p>Pete's weird LED is " + String(ledState ? "ON" : "OFF") + "</p>";
  html += "<a href='/toggle'><button>Toggle LED</button></a>";
  html += "</body><html>";
  server.send(200, "text/html", html);

}

void handleToggle(){
  ledState = !ledState;
  digitalWrite(ledPin, ledState);
  server.sendHeader("Location","/");
  server.send(303);
}

void loop() {
  server.handleClient();

}
