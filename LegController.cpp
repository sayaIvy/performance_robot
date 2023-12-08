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

void LegController::Walk() {
  // 足上げる 右前
  int leg_num = 1;
  servo_control.move(legs[leg_num].base_pin, legs[leg_num].base_back_angle);
  servo_control.move(legs[leg_num].sub_pin, legs[leg_num].sub_up_angle);
  delay(delay_time);
  servo_control.move(legs[leg_num].base_pin, legs[leg_num].base_front_angle);
  delay(delay_time);
  servo_control.move(legs[leg_num].sub_pin, legs[leg_num].sub_down_angle);
  delay(delay_time);

  for(int i = 0; i < legs.size(); i++) {
    servo_control.move(legs[i].base_pin, legs[i].base_back_angle);
  }

  leg_num = 3; // 上げる左後ろ
  servo_control.move(legs[leg_num].base_pin, legs[leg_num].base_back_angle);
  servo_control.move(legs[leg_num].sub_pin, legs[leg_num].sub_up_angle);
  delay(delay_time);
  servo_control.move(legs[leg_num].base_pin, legs[leg_num].base_front_angle);
  delay(delay_time);
  servo_control.move(legs[leg_num].sub_pin, legs[leg_num].sub_down_angle);
  delay(delay_time);

  leg_num = 2; // 上げる左前
  servo_control.move(legs[leg_num].base_pin, legs[leg_num].base_back_angle);
  servo_control.move(legs[leg_num].sub_pin, legs[leg_num].sub_up_angle);
  delay(delay_time);
  servo_control.move(legs[leg_num].base_pin, legs[leg_num].base_front_angle);
  delay(delay_time);
  servo_control.move(legs[leg_num].sub_pin, legs[leg_num].sub_down_angle);
  delay(delay_time);

  for(int i = 0; i < legs.size(); i++) {
    servo_control.move(legs[i].base_pin, legs[i].base_back_angle);
  }

  leg_num = 0; // 上げる左前
  servo_control.move(legs[leg_num].base_pin, legs[leg_num].base_back_angle);
  servo_control.move(legs[leg_num].sub_pin, legs[leg_num].sub_up_angle);
  delay(delay_time);
  servo_control.move(legs[leg_num].base_pin, legs[leg_num].base_front_angle);
  delay(delay_time);
  servo_control.move(legs[leg_num].sub_pin, legs[leg_num].sub_down_angle);
  delay(delay_time);

}

void LegController::RadioController() {
  
}



void LegController::Test() {
  for(int i = 0; i < legs.size(); i++) {
    servo_control.move(legs[i].base_pin, legs[i].base_front_angle);
  }
  delay(delay_time);
  for(int i = 0; i < legs.size(); i++) {
    servo_control.move(legs[i].base_pin, legs[i].base_back_angle);
  }
  delay(delay_time);

  for(int i = 0; i < legs.size(); i++) {
    servo_control.move(legs[i].sub_pin, legs[i].sub_center_angle);
  }
  delay(delay_time);
  for(int i = 0; i < legs.size(); i++) {
    servo_control.move(legs[i].sub_pin, legs[i].sub_down_angle);
  }
  delay(delay_time);
  // for(int i = 0; i < legs.size(); i++) {
  //   servo_control.move(legs[i].sub_pin, legs[i].sub_center_angle);
  // }
  // delay(delay_time);
  
}

void LegController::Test2() {
  for(int i = 0; i < legs.size(); i++) {
    // servo_control.move(legs[i].base_pin, );
    // servo_control.move(legs[i].sub_pin, 10);
  }
  servo_control.move(0, 10);
  servo_control.move(13, 10);
  servo_control.move(4, 190);
  servo_control.move(9, 190);
  delay(delay_time);
}