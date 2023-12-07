#pragma once

#include <Arduino.h>

#include "SwitchColorStruct.h"

class Switch {
public:

  Switch();

  // <param> デジタルピンの番号
  Switch(int digit_pin);

  ~Switch();

  // テスト用、後で消す
  bool GetValue();

private:

  int digit_pin_;
  bool value_ = false;

};