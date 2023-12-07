#pragma once

#include "SwitchColorStruct.h"
#include "Switch.h"

class SwitchController {
public:

  SwitchController();

  ~SwitchController();

  // <summary> 各スイッチのオンオフを読み取り、構造体に記録する
  // <return> オンのスイッチが一つでもあればtrueを返す
  bool ReadSwitch(Switches& switches);

  // <summary> 読み取るスイッチを指定してRead


private:

  Switch RedSwitch(2);
  Switch BlueSwitch(3);
  Switch YellowSwitch(4);
  Switch OrangeSwitch(5);
  Switch GreenSwitch(6);
  Switch BrownSwitch(7);
  Switch BlackSwitch(8);
  Switch WhiteSwitch(9);

};