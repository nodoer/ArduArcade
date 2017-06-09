#ifndef Menu_h
#define Menu_h

#include "Arduino.h"
#include "Controller.h"

class Menu
{
  public:
    Menu();
    void start(Controller arduboy);
    void nextFrame();

};

#endif
