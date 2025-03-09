#define DIGIT1 15 
#define DIGIT2 2 
#define MAX_TIME 10 
void setup() { 
 
 pinMode (DIGIT1, OUTPUT); // catod comun 1 
 pinMode (DIGIT2, OUTPUT); 
 pinMode (4, OUTPUT);
 pinMode (16, OUTPUT);
 pinMode (17, OUTPUT);
 pinMode (5, OUTPUT);
 pinMode (18, OUTPUT);  
 pinMode (19, OUTPUT);
 pinMode (21, OUTPUT);
 pinMode(22, OUTPUT);
 
 #define A 4 
 #define B 16
 #define C 17
 #define D 5
 #define E 18
 #define F 19
 #define G 21
 #define RDP 22
 
 Serial.begin(115200); 
 } 


void loop(){
//96
  for(int i=0;i<500;i++){
     digitalWrite(A, 1);
     digitalWrite(B, 1);
     digitalWrite(C, 1);
     digitalWrite(D, 1);
     digitalWrite(E, 0);
     digitalWrite(F, 1);
     digitalWrite(G, 1);
     digitalWrite(DIGIT2, 1);
     digitalWrite(RDP, 1);
     delay(1);
     digitalWrite(A, 0);
     digitalWrite(B, 0);
     digitalWrite(C, 0);
     digitalWrite(D, 0);
     digitalWrite(E, 0);
     digitalWrite(F, 0);
     digitalWrite(G, 0);
     digitalWrite(DIGIT2, 0);
     digitalWrite(RDP, 0);
     delay(1);
     digitalWrite(A, 1);
     digitalWrite(B, 0);
     digitalWrite(C, 1);
     digitalWrite(D, 1);
     digitalWrite(E, 1);
     digitalWrite(F, 1);
     digitalWrite(G, 1);
     digitalWrite(DIGIT1, 1);
     digitalWrite(RDP, 1);
     delay(1);
     digitalWrite(A, 0);
     digitalWrite(B, 0);
     digitalWrite(C, 0);
     digitalWrite(D, 0);
     digitalWrite(E, 0);
     digitalWrite(F, 0);
     digitalWrite(G, 0);
     digitalWrite(DIGIT1, 0);
     digitalWrite(RDP, 0);
     delay(1);
}
//03
  for(int i=0;i<500;i++){
    digitalWrite(A, 1);
    digitalWrite(B, 1);
    digitalWrite(C, 1);
    digitalWrite(D, 1);
    digitalWrite(E, 1);
    digitalWrite(F, 1);
    digitalWrite(G, 0);
    digitalWrite(DIGIT2, 1);
    digitalWrite(RDP, 1);
    delay(1);
    digitalWrite(A, 0);
    digitalWrite(B, 0);
    digitalWrite(C, 0);
    digitalWrite(D, 0);
    digitalWrite(E, 0);
    digitalWrite(F, 0);
    digitalWrite(G, 0);
    digitalWrite(DIGIT2, 0);
    digitalWrite(RDP, 0);
    delay(1);
    digitalWrite(A, 1);
    digitalWrite(B, 1);
    digitalWrite(C, 1);
    digitalWrite(D, 1);
    digitalWrite(E, 0);
    digitalWrite(F, 0);
    digitalWrite(G, 1);
    digitalWrite(DIGIT1, 1);
    digitalWrite(RDP, 1);
    delay(1);
    digitalWrite(A, 0);
    digitalWrite(B, 0);
    digitalWrite(C, 0);
    digitalWrite(D, 0);
    digitalWrite(E, 0);
    digitalWrite(F, 0);
    digitalWrite(G, 0);
    digitalWrite(DIGIT1, 0);
    digitalWrite(RDP, 0);
    delay(1);
}
//12
  for(int i=0;i<500;i++){
    digitalWrite(A, 0);
    digitalWrite(B, 1);
    digitalWrite(C, 1);
    digitalWrite(D, 0);
    digitalWrite(E, 0);
    digitalWrite(F, 0);
    digitalWrite(G, 0);
    digitalWrite(DIGIT2, 1);
    digitalWrite(RDP, 1);
    delay(1);
    digitalWrite(A, 0);
    digitalWrite(B, 0);
    digitalWrite(C, 0);
    digitalWrite(D, 0);
    digitalWrite(E, 0);
    digitalWrite(F, 0);
    digitalWrite(G, 0);
    digitalWrite(DIGIT2, 0);
    digitalWrite(RDP, 0);
    delay(1);
    digitalWrite(A, 1);
    digitalWrite(B, 1);
    digitalWrite(C, 0);
    digitalWrite(D, 1);
    digitalWrite(E, 1);
    digitalWrite(F, 0);
    digitalWrite(G, 1);
    digitalWrite(DIGIT1, 1);
    digitalWrite(RDP, 1);
    delay(1);
    digitalWrite(A, 0);
    digitalWrite(B, 0);
    digitalWrite(C, 0);
    digitalWrite(D, 0);
    digitalWrite(E, 0);
    digitalWrite(F, 0);
    digitalWrite(G, 0);
    digitalWrite(DIGIT1, 0);
    digitalWrite(RDP, 0);
    delay(1);
}
}
