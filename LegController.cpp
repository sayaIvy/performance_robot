#include "LegController.h"

LegController::LegController() {
  legs.clear();
  legs.push_back(leg0);
  legs.push_back(leg1);
  legs.push_back(leg2);
  legs.push_back(leg3);

  Serial.println("leg constructor!");
}

LegController::~LegController() {
  legs.clear();
  Serial.println("leg destructor!");
}

void LegController::setup() {  
  for(int i = 0; i < legs.size(); i++) {
    servo_control.move(legs[i].base_pin, legs[i].base_front_angle);
    delay(100);
    servo_control.move(legs[i].sub_pin, legs[i].sub_down_angle);
    delay(100);
  }
}

void LegController::walk() {
  // 足上げる
  servo_control.move(legs[0].sub_pin, legs[0].sub_center_angle);
  servo_control.move(legs[2].sub_pin, legs[2].sub_center_angle);
  delay(time_sleep_leg);
  servo_control.move(legs[0].base_pin, legs[0].base_front_angle);
  servo_control.move(legs[2].base_pin, legs[2].base_front_angle);
  servo_control.move(legs[1].base_pin, legs[1].base_back_angle);
  servo_control.move(legs[3].base_pin, legs[3].base_back_angle);
  delay(time_sleep_leg);
  // 足下げる
  servo_control.move(legs[0].sub_pin, legs[0].sub_down_angle);
  servo_control.move(legs[2].sub_pin, legs[2].sub_down_angle);
  delay(time_sleep_leg);
  // 足上げる
  servo_control.move(legs[1].sub_pin, legs[1].sub_center_angle);
  servo_control.move(legs[3].sub_pin, legs[3].sub_center_angle);
  delay(time_sleep_leg);
  servo_control.move(legs[0].base_pin, legs[0].base_back_angle);
  servo_control.move(legs[2].base_pin, legs[2].base_back_angle);
  servo_control.move(legs[1].base_pin, legs[1].base_front_angle);
  servo_control.move(legs[3].base_pin, legs[3].base_front_angle);
  delay(time_sleep_leg);
  // 足下げる
  servo_control.move(legs[1].sub_pin, legs[1].sub_down_angle);
  servo_control.move(legs[3].sub_pin, legs[3].sub_down_angle);
  delay(time_sleep_leg);
}

void LegController::walk2() {
  // 足上げる 右前
  int leg_num = 3;
  servo_control.move(legs[leg_num].base_pin, legs[leg_num].base_back_angle);
  servo_control.move(legs[leg_num].sub_pin, legs[leg_num].sub_down_angle);
  delay(time_sleep_leg);
  servo_control.move(legs[leg_num].base_pin, legs[leg_num].base_front_angle);
  delay(time_sleep_leg);
  servo_control.move(legs[leg_num].sub_pin, legs[leg_num].sub_up_angle);
  delay(time_sleep_leg);

  // 足上げる 左後ろ
  leg_num = 0;
  servo_control.move(legs[leg_num].base_pin, legs[leg_num].base_back_angle);
  servo_control.move(legs[leg_num].sub_pin, legs[leg_num].sub_down_angle);
  delay(time_sleep_leg);
  servo_control.move(legs[leg_num].base_pin, legs[leg_num].base_front_angle);
  delay(time_sleep_leg);
  servo_control.move(legs[leg_num].sub_pin, legs[leg_num].sub_up_angle);
  delay(time_sleep_leg);

  // 足上げる 左前
  leg_num = 2;
  servo_control.move(legs[leg_num].base_pin, legs[leg_num].base_back_angle);
  servo_control.move(legs[leg_num].sub_pin, legs[leg_num].sub_down_angle);
  delay(time_sleep_leg);
  servo_control.move(legs[leg_num].base_pin, legs[leg_num].base_front_angle);
  delay(time_sleep_leg);
  servo_control.move(legs[leg_num].sub_pin, legs[leg_num].sub_up_angle);
  delay(time_sleep_leg);

  // 足上げる 右後ろ
  leg_num = 1;
  servo_control.move(legs[leg_num].base_pin, legs[leg_num].base_back_angle);
  servo_control.move(legs[leg_num].sub_pin, legs[leg_num].sub_down_angle);
  delay(time_sleep_leg);
  servo_control.move(legs[leg_num].base_pin, legs[leg_num].base_front_angle);
  delay(time_sleep_leg);
  servo_control.move(legs[leg_num].sub_pin, legs[leg_num].sub_up_angle);
  delay(time_sleep_leg);

  for(int i = 0; i < legs.size(); i++) {
    servo_control.move(legs[i].base_pin, legs[i].base_back_angle);
  }
}



void LegController::Rotate(RotateType direction) {
  Leg tmp;
  switch (direction) {
    case rightward: // leg0 → leg1 右足
      // tmp = legs[0];

      // for(int i = 0; i < legs.size() - 1; i++) {
      //   legs[i] = legs[i+1];
      // }
      // legs[legs.size() - 1] = tmp;

      legs.clear();
      legs.push_back(leg1);
      legs.push_back(leg2);
      legs.push_back(leg3);
      legs.push_back(leg0);


      break;
    case leftward: // leg0 → leg3 右足
      tmp = legs[legs.size() - 1];

      for(int i = legs.size() - 1; i > 0; i++) {
        legs[i] = legs[i-1];
      }
      legs[0] = tmp;
      break;
    case backward:
      //
      break;
  }
}


void LegController::Test() {
  for(int i = 0; i < legs.size(); i++) {
    servo_control.move(legs[i].base_pin, legs[i].base_front_angle);
  }
  delay(time_sleep_leg);
  for(int i = 0; i < legs.size(); i++) {
    servo_control.move(legs[i].base_pin, legs[i].base_back_angle);
  }
  delay(time_sleep_leg);

  for(int i = 0; i < legs.size(); i++) {
    servo_control.move(legs[i].sub_pin, legs[i].sub_center_angle);
  }
  delay(time_sleep_leg);
  for(int i = 0; i < legs.size(); i++) {
    servo_control.move(legs[i].sub_pin, legs[i].sub_down_angle);
  }
  delay(time_sleep_leg);
  // for(int i = 0; i < legs.size(); i++) {
  //   servo_control.move(legs[i].sub_pin, legs[i].sub_center_angle);
  // }
  // delay(time_sleep_leg);
  
}

void LegController::Test2() {
  for(int i = 0; i < legs.size(); i++) {
    servo_control.move(legs[i].base_pin, 90);
    servo_control.move(legs[i].sub_pin, 90);
  }
  delay(time_sleep_leg);
}