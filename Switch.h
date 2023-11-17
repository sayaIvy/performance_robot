#pragma once

#include <Arduino.h>

class Switch {
public:

  Switch();

  // <param> デジタルピンの番号
  Switch(int digit_pin);

  ~Switch();

  bool GetValue();


private:

  int digit_pin_;
  bool value_ = false;

};