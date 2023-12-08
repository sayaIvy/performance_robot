#pragma once

#include <ArxContainer.h>
#include <Arduino.h>

#include "ServoMotor.h"
#include "SimpleLegMovement.h"

#include "SwitchController.h"


namespace {
  static const Leg leg0 = { 1, 0, 68, 108, 50, 90, 130 }; //hidariusiro
  static const Leg leg1 = { 5, 4, 11, 65, 150, 90, 10 }; // hidarimae
  static const Leg leg2 = { 8, 9, 154, 111, 150, 90, 10 };
  static const Leg leg3 = { 12, 13, 112, 67, 50, 90, 130 };
}

class LegController {
  public:
    LegController();

    ~LegController();

    void setup();

    void Walk();

    void RadioController();

    void Test();

    void Test2();


  private:

    float delay_time = 280;

    arx::vector<Leg> legs;

    ServoMotor servo_control;

    SimpleLegMovement simple_leg_movement;
};