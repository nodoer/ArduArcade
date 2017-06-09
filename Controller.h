#ifndef Controller_h
#define Controller_h

#include "Arduino.h"
#include <Arduboy2.h>

class Controller
{
  public:
    Controller();
    void begin(Arduboy2 arduboy);
    byte pollButtons();
    Arduboy2 arduboy;
};

#endif

