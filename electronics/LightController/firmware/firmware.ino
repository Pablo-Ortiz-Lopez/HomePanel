#define CLK 3
#define PULSE 4
#define BUTTON 5
#define TX 2

#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();

bool pulseALast = 0;
bool buttonWasPressed = 0;
uint8_t messageID = 0;

void signMessage(const char* message, char* result) {
  uint8_t index = 0;
  for (int i = 2; i >= 0; i--) {
    if (bitRead(messageID, i)) {
      result[index] = '1';
      index++;
    } else {
      result[index]= '0';
      index++;
    }
  }
  
  // Copy the characters from str2 to result
  while (*message) {
    result[index] = *message;
    message++;
    index++;
  }
}

void sendState(bool clockwise, bool buttonPressed){
  const char message[13] = {'0','0','0','0','0','0','0','0','0','0','0','0','0'};
  if(buttonPressed){
    //Serial.println("Button");
    signMessage("0001011001", message);
  }else if(clockwise){
    //Serial.println("Clockwise");
    signMessage("0001100110", message);
  }else{
    //Serial.println("Counterclockwise");
    signMessage("0001110011", message);
  }
  //Serial.print("SIGNED: ");
  //Serial.println(message);
  //Serial.print("ID: ");
  //Serial.println(messageID);

  mySwitch.send(message);
  messageID = (messageID + 1) % 8;
  delay(11);

}

void setup() {
  //Serial.begin(115200);
  pinMode(CLK,INPUT);
  pinMode(PULSE,INPUT);
  pinMode(BUTTON, INPUT);
  
  mySwitch.enableTransmit(TX);
  mySwitch.setRepeatTransmit (4);
}

void loop() {
  const bool pulseARead = digitalRead(CLK);
  const bool pulseBRead = digitalRead(PULSE);
  const bool buttonRead = digitalRead(BUTTON);
  if(!pulseARead && pulseALast){
    if(pulseBRead){
      sendState(true, false); // Clockwise
    }else{
      sendState(false, false); // Counter-Clockwise
    }
  }
  if(!buttonRead && !buttonWasPressed){
    sendState(false, true); // Button Press
  }
  buttonWasPressed = !buttonRead;
  pulseALast = pulseARead;
}
