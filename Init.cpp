#include "Arduino.h"
#include "Init.h"
#include "Controller.h"

Controller ctrl;


Init::Init(){

}

Init::start(){

  ctrl = Controller();

  
}

