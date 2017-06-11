/*
Screen Size 128*64
*/
#include "Menu.h"
#include "Init.h"


Init game;
Menu menu;


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
    ctrl.clear();
    ctrl.print("Welcome to Serpent!");
    ctrl.display();
    break;
    
  }
  case 2:{
    ctrl.clear();
    ctrl.print("Repeat Me");
    ctrl.display();
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
