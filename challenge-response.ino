#include "BluetoothSerial.h" //Header File for Serial Bluetooth
#define MAX_NBR 5 // max number digits in input
const unsigned int MAX_INPUT = 16;
int LED_PIN = 13;
bool connected = false;
bool disconnected = false;
BluetoothSerial ESP_BT; //Object for Bluetooth
char i=0;
char data[16];

void setup() {
  Serial.begin(115200);
  pinMode (LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  if(!ESP_BT.begin("PIA")) // You will connect to this device
    Serial.println("An error occurred initializing Bluetooth");
  else
    Serial.println("Bluetooth initialized");
} // setup()

void callback(esp_spp_cb_event_t event, esp_spp_cb_param_t *param) {
  if(event == ESP_SPP_SRV_OPEN_EVT){
    Serial.println("Client Connected");
  connected = true;
  }
  if(event == ESP_SPP_CLOSE_EVT ){
    Serial.println("Client disconnected");
    connected = false;
  }
} // callback
// Check received message and control output accordingly

void process_data (const char * data) {
  Serial.println (data);
  if (!strcmp(data, "on"))
    digitalWrite(LED_PIN, HIGH);
  if (!strcmp(data, "off"))
    digitalWrite(LED_PIN, LOW);
  //process X=NNNN&Y=MMMM, variable nr. of digits
  const char str_x[3]="X=";
  const char str_y[3]="Y=";
  char *str2; // will hold temp results
  unsigned long int X=0, Y=0;
  if(strncmp(data, str_x, 2) == 0) { // check if first 2 chars are X=
    str2=strstr(data,str_y); // look for substring beginning with Y=
    if(str2) { // nonzero means it is found
      Y=atoi(str2+2); // get over first 2 characters Y=
    }
    i=2; // process X, get over first 2 characters X=
    while((data[i] != '&') && (i < MAX_NBR+2)) { \\ wait for & separator
      if (!isdigit(data[i])) { \\ isdigit() looks for 0..9
        X=0;
        break;
      }
    X=10*X+(data[i++] - '0'); // convert from ASCII code by substracting code of "0"
   }
  }
  if(X != 0 && Y != 0) {
    sprintf(str2, "%d", X+Y);
    i = 0;
    while(str2[i])
      ESP_BT.write(str2[i++]); // send back string one char at a time
    ESP_BT.write('\n'); // newline ends string
  }
  if (!strcmp(data, "disc")) {
    ESP_BT.flush();
    ESP_BT.disconnect();
    ESP_BT.end();
    disconnected = true;
    delay(100);
  }
} // process_data
// create null-terminated string from individual bytes [2]

void processIncomingByte (const byte inByte) {
  static char input_line [MAX_INPUT];
  static unsigned int input_pos = 0;
  switch (inByte)
  {
    case '\n': // end of text
          input_line [input_pos] = 0; // terminating null byte
          // terminator reached! process input_line here ...
          process_data (input_line);
          // reset buffer for next time
          input_pos = 0;
          break;
    case '\r': // discard carriage return
          break;
    default:
          // keep adding if not full ... allow for terminating null byte
    if (input_pos < (MAX_INPUT - 1))
      input_line [input_pos++] = inByte;
    break;
  } //switch
} // processIncomingByte

void loop() {
  ESP_BT.register_callback(callback); // for connect/disconnect detection
  if (ESP_BT.available())
  processIncomingByte(ESP_BT.read() );
  if(disconnected) {
    Serial.println("Trying to reconnect");
    ESP_BT.begin("PIA");
    disconnected = false;
    delay(100);
  }
}
