#include "Arduino.h"
#include "Menu.h"
#include "Controller.h"

Menu::Menu(){}

void Menu::run(Controller ctrl){

  

  
  char* titles[2] = {"Surpent","RepeatMe",
  

  ctrl.clear();
  
  ctrl.setCursor(1,1);
  ctrl.print("  1.Game 1");
  ctrl.setCursor(1,9);
  ctrl.print("  2.Game 2");
  ctrl.setCursor(1,17);
  ctrl.print("> 3.Game 3");
  
  ctrl.display();
  
}

