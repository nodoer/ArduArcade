/*
Screen Size 128*64
*/
#include "Menu.h"
#include "Controller.h"
#include <Arduboy2.h>



Arduboy2 arduboy;
Menu menu;
Controller controller;
byte gameMode;


void setup() {
  arduboy.begin();
  controller.begin(arduboy);
  
  arduboy.setFrameRate(30);

  menu.start(controller);
   
  gameMode = 0;
   
}


void loop() {
  
arduboy.setRGBled(0,0,10);

  arduboy.setCursor(1,8);
  arduboy.print(gameMode);
  arduboy.display();

switch(gameMode){

  case 1:;
  
  
}


  
}
