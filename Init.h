
#ifndef Init_h
#define Init_h

#include "Arduino.h"
#include "Controller.h"
#include "Init.h"
#include <ArduboyTonesPitches.h>

extern Controller ctrl;

const uint16_t PROGMEM sfx[3][10] = {
  {NOTE_C6,50,NOTE_E6,100,NOTE_G6,50,TONES_END},
  {2000,100,3000,100,TONES_END},
  {2000,100,3000,100,TONES_END}
};

class Init
{
  public:
    Init();
    start();

};

#endif
