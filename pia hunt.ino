#include "BluetoothSerial.h" //Header File for Serial Bluetooth 
BluetoothSerial ESP_BT; //Object for Bluetooth 
int incoming; 
int LED_PIN = 22; // GPIO ales 
void setup() { 
 Serial.begin(9600); //Start in 9600
ESP_BT.begin("1203"); //Name of your Bluetooth Signal – change it! 
 Serial.println("Bluetooth Device is Ready to Pair"); 
 pinMode (LED_PIN, OUTPUT);//Specify that LED pin is output 
} 
void loop() { 
 
 if (ESP_BT.available()) //Check if we receive anything from Bluetooth 
 { 
 incoming = ESP_BT.read(); //Read what we recevive 
 Serial.print("Received:"); Serial.println(incoming); 
 if (incoming == 49) 
 { 
 digitalWrite(LED_PIN, HIGH); 
 ESP_BT.println("LED turned ON"); 
 } 
 
 if (incoming == 48) 
 { 
 digitalWrite(LED_PIN, LOW); 
 ESP_BT.println("LED turned OFF"); 
 } 
 } 
 delay(20); 
}




void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
}

void row(int x){
  if(x==0){
  digitalWrite(2, HIGH);
  digitalWrite(15, HIGH);
}
  if(x==1){
     digitalWrite(0, HIGH);
  digitalWrite(18, HIGH);
  }
  if(x==2){
     digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  }
  if(x==3){
     digitalWrite(16, HIGH);
  digitalWrite(17, HIGH);
  }
  if(x==4){
     digitalWrite(22, HIGH);
  digitalWrite(23, HIGH);
  }
  if(x==5){
    digitalWrite(2, LOW);
  digitalWrite(15, LOW);
  }
  if(x==6){
    digitalWrite(0, LOW);
  digitalWrite(18, LOW);
  }
  if(x==7){
     digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  }
  if(x==8){
     digitalWrite(16, LOW);
  digitalWrite(17, LOW);
  }
  if(x==9){
     digitalWrite(22, LOW);
  digitalWrite(23, LOW);
  }
}


void row2(int x){
  if(x==0){
  digitalWrite(2, HIGH);
  
}
  if(x==1){
     digitalWrite(0, HIGH);
 
  }
  if(x==2){
     digitalWrite(4, HIGH);
 
  }
  if(x==3){
     digitalWrite(16, HIGH);

  }
  if(x==4){
      digitalWrite(17, HIGH);
 
  }
  if(x==5){
     digitalWrite(5, HIGH);
 
  }
  if(x==6){
     digitalWrite(18, HIGH);

  }
  if(x==7){
    digitalWrite(15, HIGH);
 
  }
  if(x==8){
    digitalWrite(22, HIGH);
 
  }
  if(x==9){
    digitalWrite(23, HIGH);
 
  }
}
  void row3(int x){
  if(x==0){
  digitalWrite(2, LOW);
  
}
  if(x==1){
     digitalWrite(0, LOW);
 
  }
  if(x==2){
     digitalWrite(4,LOW);
 
  }
  if(x==3){
     digitalWrite(16, LOW);

  }
  if(x==4){
      digitalWrite(17, LOW);
 
  }
  if(x==5){
     digitalWrite(5,LOW);
 
  }
  if(x==6){
     digitalWrite(18, LOW);

  }
  if(x==7){
    digitalWrite(15, LOW);
 
  }
  if(x==8){
    digitalWrite(22, LOW);
 
  }
  if(x==9){
    digitalWrite(23, LOW);
 
  } 
}
void loop() {
  // put your main code here, to run repeatedly:

  
 int counter=0;
 while(counter<4){
  for(int i=0;i<=9;i++){
    row(i);
    delay(200);
  }
  counter++;
  }
  counter=0;
  while(counter<4){
  for(int i=0;i<=9;i++){
    row2(i);
    delay(200);
  }
  for(int i=0;i<=9;i++){
    row3(i);
    delay(200);
  }
  counter++;
  }
  counter=0;
    while(counter<4){
  for(int i=9;i>=0;i--){
    row2(i);
    delay(200);
  }
  for(int i=9;i>=0;i--){
    row3(i);
    delay(200);
  }
  
  counter++;
  }
}
