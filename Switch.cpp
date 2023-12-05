#include "Switch.h"

Switch::Switch() 
: digit_pin_(0)
, value_(false) {
  pinMode( digit_pin_, INPUT_PULLUP );
  Serial.println("Swich constructor!");
}

Switch::Switch(int digit_pin)
: value_(false) {
  digit_pin_ = digit_pin;
  pinMode( digit_pin_, INPUT_PULLUP );
  Serial.println("Swich constructor!");
}

Switch::~Switch() {
  int digit_pin_ = 0;
  value_ = false;
  Serial.println("Switch destructor!");
}

bool Switch::GetValue() {
  value_ = !digitalRead( digit_pin_ );
  return value_;
}