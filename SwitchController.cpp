#include "SwitchController.h"

SwitchController::SwitchController() {
  switch_arg.clear();
  switch_arg.push_back(switch_red);
  switch_arg.push_back(switch_blue);
  switch_arg.push_back(switch_yellow);
  switch_arg.push_back(switch_orange);
  switch_arg.push_back(switch_green);
  switch_arg.push_back(switch_brown);
  switch_arg.push_back(switch_black);
  switch_arg.push_back(switch_white);
  
  Serial.println("SwitchController Consturactor!");
}

SwitchController::~SwitchController() {
  switch_arg.clear();
  Serial.println("SwitchController desturactor!");
}

bool SwitchController::ReadSencer(Switches& switches) {
  return false;
}