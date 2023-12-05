#pragma once

#include <ArxContainer.h>
#include <Arduino.h>
#include "ServoMotor.h"



struct Leg {
  int base_pin;
  int sub_pin;
  int base_front_angle;
  int base_back_angle;
  int sub_down_angle;
  int sub_center_angle;
  int sub_up_angle;
};

enum RotateType {
  rightward,
  leftward,
  backward,
};

namespace {
  static const Leg leg0 = { 8, 9, 135, 92, 50, 90, 160 };
  static const Leg leg1 = { 12, 13, 90, 45, 130, 90, 20 };
  static const Leg leg2 = { 1, 0, 90, 130, 130, 90, 20 }; //hidariusiro
  static const Leg leg3 = { 5, 4, 30, 84, 50, 90, 160 }; // hidarimae
  static const int time_sleep_leg = 250; 
}

class LegController {
  public:
    LegController();

    ~LegController();

    void setup();

    void walk();

    void walk2();

    void Rotate(RotateType direction);

    void Test();

    void Test2();


  private:

    arx::vector<Leg> legs;

    ServoMotor servo_control;
};