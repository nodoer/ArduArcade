
#include "Controller.h"
#include <Arduboy2.h>
#include <ArduboyTones.h>


Controller::Controller(){

  _gameMode = 0;
  _gameState = 0;
  this->activeGameData.byteVal1 = 0;

  this->sound = new ArduboyTones(this->audio.enabled);


}

void Controller::frameInit(){

  //Hold on to control of the thread until
  //the frame period is over
  do {} while(!nextFrame());
  
  pollButtons();

  //Check if the user wants to return to the menu
  if(pressed(A_BUTTON+B_BUTTON+LEFT_BUTTON)){
    setGameMode(0);
  }
  
}

void Controller::setGameMode(byte newMode){
  _gameState = 0;
  _gameMode = newMode;
}

byte Controller::getGameMode(){
  return _gameMode;
}

