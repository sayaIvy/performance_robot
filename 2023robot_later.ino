#include <Arduino.h>

#include "LegController.h"


void setup() {
  LegController Legs;
    
  Serial.begin( 115200 );
}

void loop(){
  LegController Legs;
  Legs.Walk();
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