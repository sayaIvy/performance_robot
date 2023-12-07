#pragma once

#include "ServoMotor.h"
#include "Leg.h"

class SimpleLegMovement {
public: 

  SimpleLegMovement();

  ~SimpleLegMovement();

  void RaisedFrontRight();
  void RaisedFrontLeft();
  void RaisedBackRight();
  void RaisedBackLeft();
  void LowerFrontRight();
  void LowerFrontLeft();
  void LowerBackRight();
  void LowerBackLeft();


private:

  Leg leg_front_right;
  Leg leg_front_left;
  Leg leg_back_right;
  Leg leg_back_left;
};