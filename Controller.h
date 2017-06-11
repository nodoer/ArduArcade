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
    } activeGameData;

   private:
    byte _gameMode;
    byte _gameState;
    
};

#endif

