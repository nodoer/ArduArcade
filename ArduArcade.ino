/*
Screen Size 128*64
*/
#include "Menu.h"
#include "RepeatMe.h"
#include "Serpent.h"
#include "Init.h"


Init game;
Menu menu;
RepeatMe repeatMe;
Serpent serpent;


void setup() {
  game.start();
  ctrl.begin();
  ctrl.setFrameRate(30);
}


void loop() {
  
  ctrl.frameInit();
  
  switch(ctrl.getGameMode()){

  case 0:{
    menu.run();
    break;
  }

  case 1:{
    serpent.run();
    break;
    
  }
  case 2:{
    repeatMe.run();
    break;
    
  }
  case 3:
  case 4:{
    ctrl.clear();
    ctrl.print("Entered Game ");
    ctrl.print(ctrl.getGameMode());
    ctrl.display();
  };
  
  
}


  
}
