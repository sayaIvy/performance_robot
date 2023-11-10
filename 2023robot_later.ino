// #define trigPin 8  // トリガーピンをD8に
// #define echoPin 9  // エコーピンをD9に

#include "SencerStatus.h"



int US1_trigPin = 8;
int US1_echoPin = 9;
int US2_trigPin = 11;
int US2_echoPin = 12;

float ball_distance = 75.0f;
// float ball_dist_upper = 130.0f




void setup(){
 
  Serial.begin(9600);
 
  pinMode(US1_echoPin,INPUT);   
  pinMode(US1_trigPin,OUTPUT);
  pinMode(US2_echoPin,INPUT);
  pinMode(US2_trigPin,OUTPUT);
}


void loop(){
  SencerStatus bs = ball(GetDistanceF(US1_trigPin, US1_echoPin));
  if(bs == SencerStatus::Null) {
    Serial.println("Null");
  }
  else if(bs == SencerStatus::Right) {
    Serial.println("Right");
  }
  else if(bs == SencerStatus::Left) {
    Serial.println("Left");
  }
}

SencerStatus ball(double distance_) {
  // Serial.println("1つめ");
  if(GetDistanceF(US1_trigPin, US1_echoPin) < ball_distance) {
    return SencerStatus::Left;
  }
  delay(100);

  // Serial.println("2つめ");
  if(GetDistanceF(US2_trigPin, US2_echoPin) < ball_distance) {
    return SencerStatus::Right;
  }
  delay(100);

  return SencerStatus::Null;  
}

float GetDistanceF(int trigPin, int echoPin) {
  float Duration = 0;  // 計測した時間
  float Distance = 0;  // 距離

  digitalWrite(trigPin,LOW);              // 計測前に一旦トリガーピンをLowに
  delayMicroseconds(2);

  digitalWrite(trigPin,HIGH);             // トリガーピンを10μsの時間だけHighに
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  Duration = pulseIn(echoPin,HIGH);      // エコーピンからの入力
 
  Duration = Duration / 2;               // 距離を1/2に
  Distance = Duration*340*100/1000000;   // 音速を掛けて単位をcmに

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