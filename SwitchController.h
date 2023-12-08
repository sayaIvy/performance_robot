#pragma once

#include <ArxContainer.h>

#include "SwitchColorStruct.h"
#include "Switch.h"

namespace {
  const Switch switch_red(2);
  const Switch switch_blue(3);
  const Switch switch_yellow(4);
  const Switch switch_orange(5);
  const Switch switch_green(6);
  const Switch switch_brown(7);
  const Switch switch_black(8);
  const Switch switch_white(9);
}

class SwitchController {
public:

  SwitchController();

  ~SwitchController();

  // <summary> 各スイッチのオンオフを読み取り、構造体に記録する
  // <return> オンのスイッチが一つでもあればtrueを返す
  bool ReadSencer(Switches& switches);

  // <summary> 読み取るスイッチを指定してRead


private:

  arx::vector<Switch> switch_arg;


};