#pragma once

#include <Arduino.h>
#include "SencerStatus.h"

// 廃止予定
enum SencerStatus {
  Null,
  Right,
  Left,  
};

namespace {
  int US1_trigPin = 8;
  int US1_echoPin = 9;
  int US2_trigPin = 11;
  int US2_echoPin = 12;

  float upper_distance = 75.0f;
}

class SencerControll {
public:

  SencerControll();

  ~SencerControll();

  SencerStatus ReadSencer();


private:

  float MeasureDistance(int trigPin_, int echoPin_);


};