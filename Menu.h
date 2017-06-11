#ifndef Menu_h
#define Menu_h

#include "Arduino.h"
#include "Controller.h"

class Menu
{
  public:
    Menu();
    void run();
  private:
    void updateInput(byte numTitles);

};

#endif
