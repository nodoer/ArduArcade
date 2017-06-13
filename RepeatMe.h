#ifndef RepeatMe_h
#define RepeatMe_h

#include "Arduino.h"
#include "Controller.h"

class RepeatMe
{
  public:
    RepeatMe();
    void run();
  private:
    byte drawPad(byte lightSegment);

};

#endif
