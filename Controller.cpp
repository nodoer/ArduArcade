#include "Arduino.h"
#include "Controller.h"
#include <Arduboy2.h>

Controller::Controller(){

  this->gameMode = 0;

}

byte Controller::frameInit(){

  if (!(this->nextFrame())) return;
  this->pollButtons();

  
}

