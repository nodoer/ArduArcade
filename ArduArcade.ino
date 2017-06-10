/*
Screen Size 128*64
*/
#include "Menu.h"
#include "Controller.h"


Menu menu;
Controller ctrl;
byte gameMode;


void setup() {

  ctrl.begin();
   
}


void loop() {
 
  ctrl.frameInit();

switch(ctrl.gameMode){

  case 0:menu.run(ctrl);

  case 1:;
  
  
}


  
}
