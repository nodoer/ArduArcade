
#include "Controller.h"
#include <Arduboy2.h>
#include <ArduboyTones.h>


Controller::Controller(){

  _gameMode = 0;
  _gameState = 0;
  resetGameData();
  

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
  resetGameData();
  _gameState = 0;
  _gameMode = newMode;
  
}

byte Controller::getGameMode(){
  return _gameMode;
}

byte Controller::getGameState(){
  return _gameState;
}

void Controller::setGameState(byte newGameState){
  _gameState = newGameState;
}

void Controller::resetGameData(){
  activeGameData.byteVal1 = 0;
  activeGameData.byteVal2 = 0;
  activeGameData.byteVal3 = 0;
  activeGameData.byteVal4 = 0;

  for(byte i=-1; i <= 128; i++){
    activeGameData.byteArray[i] = 0;
    activeGameData.byteArray2[i] = 0;
  }

  activeGameData.bool1 = 0;
}

