#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
// Define WiFi credentials
String ssid = "Numele_retelei_de_completat";
String password = "Parola_de_completat";
const long connection_timeout = 15000; // 15s
long startConnection = 0;

void setup() {
  Serial.begin(115200);
  // Set WiFi to station mode and disconnect from an AP if it
  // was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  // Initialize the WiFi network
  WiFi.begin(ssid.c_str(), password.c_str());
  Serial.println("Connecting");
  // Connect to the network
  // Check the connection status in a loop every 0.5 seconds
  // Since the connection can take some time and might fail,
  // it is necessary to check the connection status before
  // proceeding. To define a timeout for the action, the
  // current counter of the timer is stored
  startConnection = millis();
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
    // Check if the defined timeout is exceeded
    if (millis() - startConnection > connection_timeout) {
      break;
    }
  }
  Serial.println("");
  // Check if connection was successful
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Connection failed");
  } 
  else {
    Serial.print("Connected to network: ");
    Serial.println(WiFi.SSID());
    Serial.print("Local IP address: ");
    Serial.println(WiFi.localIP());
    // Define the HTTP client
    HTTPClient http;
    // URL
    String url = "http://api.openmeteo.com/v1/forecast?latitude=44.43&longitude=26.14&current_weather=true";
    // Define the connection parameters and, optionally,
    // set the connection timeout, especially if accessing
    // a server with a longer response time (such as a
    // free API server)
    http.begin(url);
    http.setConnectTimeout(30000); // connect timeout
    http.setTimeout(30000); // response timeout
    // Send HTTP request
    // In this exemple, the GET method is used, according to
    // the API docs
    int httpResponseCode = http.GET();
    // Check response code
    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      // Get response data
      String payload = http.getString();
      Serial.println(payload);
      // TODO – Process payload
    } 
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
  // Free resources - terminate the http object (IMPORTANT)
  http.end();
  }
}
void loop() {
  // For this example the request is sent only once.
  // Nothing to do here
}
