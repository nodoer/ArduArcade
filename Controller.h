#ifndef Controller_h
#define Controller_h

#include "Arduino.h"
#include <Arduboy2.h>

class Controller : public Arduboy2
{
  public:
    Controller();
    byte frameInit();
    byte gameMode;
};

#endif

