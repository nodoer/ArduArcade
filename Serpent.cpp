/* Grid 32*48 
*
*Game Data Usage
*
* byteVal1:Length of the snake
* byteVal2:Last direction 1-Left, 2-Up, 3-Right 4-Down
* byteVal3:
* byteVal4:Frame counter for delaying movement of the snake
*  
* byteArray:X grid position of snake segment
* byteArray2:Y grid position of snake segment
* 
* bool1: 1 if a button was pressed betwwen segment draws
*/

#include "Init.h"
#include "Serpent.h"
#include "Controller.h"


Serpent::Serpent(){
}

void Serpent::run(){

  ctrl.clear();
 
  switch(ctrl.getGameState()){
    
    case 0:{
      drawPlayfield();
      ctrl.print("Press B to Begin!");
      if(ctrl.justPressed(B_BUTTON)){

        ctrl.activeGameData.byteArray[0] = 1;
        ctrl.activeGameData.byteArray2[0] = 1;

        ctrl.setGameState(1);
        
      }
      break;
    }

    case 1:{

      byte newX;
      byte newY;

      newX = ctrl.activeGameData.byteArray[ctrl.activeGameData.byteVal1];
      newY = ctrl.activeGameData.byteArray2[ctrl.activeGameData.byteVal1];

      //Snake stops growing @ 128 segments
      if(ctrl.activeGameData.byteVal1 != 128){
        ctrl.activeGameData.byteVal1++;
      } else {
        ctrl.activeGameData.byteVal1 = 127;
      }

      //Shift positions of the snake down the array to make space for
      //the new direction
      for(byte i = ctrl.activeGameData.byteVal1; i=1; i--){
        ctrl.activeGameData.byteArray[i+1] = ctrl.activeGameData.byteArray[i];
        ctrl.activeGameData.byteArray2[i+1] = ctrl.activeGameData.byteArray2[i];
      }
      

      if(ctrl.justPressed(LEFT_BUTTON) &&
          ctrl.activeGameData.byteVal2 != 3)
      {
          newX--;
          ctrl.activeGameData.bool1 = 1;
      }

      if(ctrl.justPressed(UP_BUTTON) &&
          ctrl.activeGameData.byteVal2 != 4)
      {
          newX++;
          ctrl.activeGameData.bool1 = 1;
      }

      if(ctrl.justPressed(RIGHT_BUTTON) &&
          ctrl.activeGameData.byteVal2 != 1)
      {
          newX++;
          ctrl.activeGameData.bool1 = 1;
      }

      if(ctrl.justPressed(DOWN_BUTTON) &&
          ctrl.activeGameData.byteVal2 != 2)
      {
          newX++;
          ctrl.activeGameData.bool1 = 1;
      }
      
      break;
    }

    case 2: {
      break;
    }

    case 3: {
      break;
    }

    case 4: {
      break;
    }

  }

  ctrl.display();
    
}
 
void Serpent::drawPlayfield(){

  ctrl.drawRect(0,0,96,64);
  
}
  
