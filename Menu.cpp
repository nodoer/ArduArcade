#include "Arduino.h"
#include "Menu.h"
#include "Controller.h"

Menu::Menu(){


  
}

void Menu::start(Controller controller){
  
  controller.arduboy.clear();
  controller.arduboy.setCursor(1,1);
  controller.arduboy.print("Hello");
  controller.arduboy.display();
  
}

