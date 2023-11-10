#pragma once

#include <Arduino.h>

class Switch {
public:

  Swich();

  // <param> デジタルピンの番号
  Swich(int digit_pin);

  ~Swich();

  bool GetValue();


private:

  int digit_pin_;
  bool value_;

}