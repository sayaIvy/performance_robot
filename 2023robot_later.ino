#include <Arduino.h>

#include "Switch.h"

#include <ArxContainer.h>

  Switch takt_switch1(2);
  Switch takt_switch2(3);
  Switch takt_switch3(4);
  Switch takt_switch4(5);
  Switch takt_switch5(6);
  Switch takt_switch6(7);
  Switch takt_switch7(8);
  Switch takt_switch8(9);

  arx::vector<Switch> switches;

void setup() {
  switches.push_back(takt_switch1);
  switches.push_back(takt_switch2);
  switches.push_back(takt_switch3);
  switches.push_back(takt_switch4);
  switches.push_back(takt_switch5);
  switches.push_back(takt_switch6);
  switches.push_back(takt_switch7);
  switches.push_back(takt_switch8);
    
  Serial.begin( 115200 );
}

void loop(){
  bool value;

  for (int i = 0; i < 8; i++) {
    value = switches[i].GetValue();
    Serial.print("switch");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(value);
  }    

    delay( 1000 );
}







// #include <Arduino.h>
// #include "SencerStatus.h"


// void setup(){
 
//   Serial.begin(9600);
 
//   // pinMode(US1_echoPin,INPUT);   
//   // pinMode(US1_trigPin,OUTPUT);
//   // pinMode(US2_echoPin,INPUT);
//   // pinMode(US2_trigPin,OUTPUT);
// }


// void loop(){
//   // SencerStatus bs = ball(GetDistanceF(US1_trigPin, US1_echoPin));
//   // if(bs == SencerStatus::Null) {
//   //   Serial.println("Null");
//   // }
//   // else if(bs == SencerStatus::Right) {
//   //   Serial.println("Right");
//   // }
//   // else if(bs == SencerStatus::Left) {
//   //   Serial.println("Left");
//   // }
// }