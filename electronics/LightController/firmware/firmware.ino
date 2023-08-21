#define CLK 3
#define PULSE 4
#define BUTTON 5
#define TX 2

#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();

void sendData(bool clockwise, bool buttonPressed){
  if(buttonPressed){
    Serial.println("Button");
    mySwitch.send("0001001101");
  }else if(clockwise){
    Serial.println("Clockwise");
    mySwitch.send("0001010101");
  }else{
    Serial.println("Counterclockwise");
    mySwitch.send("0001011101");
  }
  delay(11);
}
bool pulseALast = 0;
bool buttonWasPressed = 0;

void setup() {
  Serial.begin(115200);
  pinMode(CLK,INPUT);
  pinMode(PULSE,INPUT);
  pinMode(BUTTON, INPUT);
  
  mySwitch.enableTransmit(TX);
  mySwitch.setRepeatTransmit (3);
}

void loop() {
  const bool pulseARead = digitalRead(CLK);
  const bool pulseBRead = digitalRead(PULSE);
  const bool buttonRead = digitalRead(BUTTON);
  if(!pulseARead && pulseALast){
    if(pulseBRead){
      sendData(true, false);
    }else{
      sendData(false, false);
    }
  }
  if(!buttonRead && !buttonWasPressed){
    sendData(false, true);
    buttonWasPressed = 1;
  }else if(buttonRead){
    buttonWasPressed = 0;
  }
  pulseALast = pulseARead;
}
