#pragma once

#include <ArxContainer.h>
#include <Arduino.h>

#include "ServoMotor.h"
#include "SimpleLegMovement.h"

#include "SwitchController.h"


namespace {
  static const Leg leg0 = { 8, 9, 135, 92, 190, 90, 50 };
  static const Leg leg1 = { 12, 13, 90, 45, 20, 90, 130 };
  static const Leg leg2 = { 1, 0, 90, 130, 20, 90, 130 }; //hidariusiro
  static const Leg leg3 = { 5, 4, 30, 84, 190, 90, 50 }; // hidarimae
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

    float delay_time = 250;

    arx::vector<Leg> legs;

    ServoMotor servo_control;

    SimpleLegMovement simple_leg_movement;
};