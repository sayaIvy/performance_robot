#pragma once

#include <ArxContainer.h>
#include <Arduino.h>

#include "ServoMotor.h"
#include "SimpleLegMovement.h"


namespace {
  static const Leg leg0 = { 8, 9, 135, 92, 50, 90, 160 };
  static const Leg leg1 = { 12, 13, 90, 45, 130, 90, 20 };
  static const Leg leg2 = { 1, 0, 90, 130, 130, 90, 20 }; //hidariusiro
  static const Leg leg3 = { 5, 4, 30, 84, 50, 90, 160 }; // hidarimae
}

class LegController {
  public:
    LegController();

    ~LegController();

    void setup();

    void walk();

    void walk2();

    void Test();

    void Test2();


  private:

    float delay_time = 250;

    arx::vector<Leg> legs;

    ServoMotor servo_control;
};