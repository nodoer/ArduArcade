#ifndef Controller_h
#define Controller_h

#include "Arduino.h"
#include <Arduboy2.h>
#include <ArduboyTones.h>

class Controller : public Arduboy2
{
  public:
    Controller();
    ArduboyTones* sound;
    void frameInit();
    void incrementGameMode(boolean up);
    void setGameMode(byte newMode);
    byte getGameMode();
    struct gameData{
      byte byteVal1;
      byte byteVal2;
      byte byteVal3;
      byte byteVal4;
      byte byteArray[128];
      byte byteArray2[128];
      bool bool1;
    } activeGameData;
    byte getGameState();
    void setGameState(byte newGameState);


   private:
    byte _gameMode = 0;
    byte _gameState = 0;
    void resetGameData();
    
};

#endif

