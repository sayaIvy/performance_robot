#include "SencerController.h"

SencerController::SencerController() {
  Serial.println("SencerConroll constructor!");
}

SencerController::~SencerController() {
  Serial.println("SencerConroll destructor!");
}

SencerStatus SencerController::ReadSencer() {
  // Serial.println("Left Sencer");
  if(MeasureDistance(US1_trigPin, US1_echoPin) < upper_distance) {
    return SencerStatus::Left;
  }
  delay(100);

  // Serial.println("Right Sencer");
  if(MeasureDistance(US2_trigPin, US2_echoPin) < upper_distance) {
    return SencerStatus::Right;
  }
  delay(100);

  return SencerStatus::Null;  
}


float SencerController::MeasureDistance(int trigPin_, int echoPin_) {
  float Duration = 0;  // 計測した時間
  float Distance = 0;  // 距離

  digitalWrite(trigPin_,LOW);              // 計測前に一旦トリガーピンをLowに
  delayMicroseconds(2);

  digitalWrite(trigPin_,HIGH);             // トリガーピンを10μsの時間だけHighに
  delayMicroseconds(10);
  digitalWrite(trigPin_,LOW);

  Duration = pulseIn(echoPin_,HIGH);      // エコーピンからの入力
 
  Duration = Duration / 2;               
  Distance = Duration*340*100/1000000;   //単位cm

  if(Distance >= 400 || Distance <= 2){  // センサーの測定範囲外の処理
    // Serial.println("距離 = 測定範囲外");
    return 0;
  }
 
  else{
    // Serial.print("距離 ");               // シリアルモニタに距離を表示させる
    // Serial.print(Distance);
    // Serial.println(" cm");
    return Distance;
  }

}