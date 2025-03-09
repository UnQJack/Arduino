void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT); // GPIO2 used for LED as Output
  Serial.begin(115200); // baud rate = 115200 bps
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2, LOW); // turn off LED
  Serial.println("LED is off");
  delay(1000); // wait 1 second
  digitalWrite(2, HIGH); // turn on LED
  Serial.println("LED is on");
  delay(1000); // wait 1 second
}
