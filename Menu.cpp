#include "Init.h"
#include "Menu.h"
#include "Controller.h"
#include <ArduboyTones.h>


Menu::Menu(){
}

void Menu::run(){
 
  byte numTitles = 3;
  byte cursorY = 0;
  byte lineHeight = 8;  
  char* titles[] = {"Serpent","Repeat Me","Space Rocks","Cave"};

  updateInput(numTitles);
 
  ctrl.clear();

  ctrl.setCursor(35,cursorY);
  ctrl.print("ArduArcade");

  cursorY += lineHeight*2;
  
  for(int i = 0; i <= numTitles; i++)
  {

    ctrl.setCursor(1,cursorY);
    if(ctrl.activeGameData.byteVal1 == i){
      ctrl.print(">");
    } else {
      ctrl.print(" ");
    }
    
    ctrl.print(titles[i]);

    cursorY += lineHeight;
     
  }

  ctrl.display();
 
  
}

void Menu::updateInput(byte numTitles){

  if(ctrl.justPressed(DOWN_BUTTON)){
    ctrl.activeGameData.byteVal1++;
    ctrl.sound->tone(3000,100);
  } else if (ctrl.justPressed(UP_BUTTON)){
    ctrl.activeGameData.byteVal1--;
    ctrl.sound->tone(3100,100);
  }

  if(ctrl.justPressed(B_BUTTON)||ctrl.justPressed(A_BUTTON)){
    ctrl.setGameMode(ctrl.activeGameData.byteVal1+1);
    ctrl.sound->tones(sfx[0]);
  }

  if(ctrl.activeGameData.byteVal1 > numTitles){
    ctrl.activeGameData.byteVal1=0;
    ctrl.sound->tones(sfx[1]);
  } 

 
  
}

