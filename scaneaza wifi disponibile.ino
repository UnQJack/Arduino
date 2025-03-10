#include <Arduino.h>
#include <WiFi.h>
#define CONNECT_TIMEOUT 15000 // ms
long connectStart = 0;

void setup() {
  Serial.begin(115200);
  // Set WiFi to station mode and disconnect from an AP if it
  // was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}

void loop() {
  // Scan for WiFi networks
  Serial.println("Start scan");
  int networksFound = WiFi.scanNetworks();
  Serial.println("Scan complete");
  if (networksFound == 0) {
    Serial.println("No networks found");
  } 
  else {
    Serial.print(networksFound);
    Serial.println(" networks found");
    // Iterate the network list and display the information for
    // each network
    for (int i = 0; i < networksFound; i++) {
      bool open = (WiFi.encryptionType(i) == WIFI_AUTH_OPEN);
      Serial.print(i + 1);
      Serial.print(". ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print("dB)");
      Serial.print(" - ");
      Serial.println((open) ? "Open" : "Protected");
      delay(10);
    }
  }
  
// Wait 5 seconds
delay(5000);
}
