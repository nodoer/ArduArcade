/*
 * Game Data Usage
 * 
 * byteVal1:Element number containing the key currently being revealed to the player
 * byteVal2:Element number containing the key the player currently has to press 
 *  in order for the game to continue.
 * byteVal3:The total number of elements to be displayed to the user. Increments
 *  everytime the player repeats the pattern.
 * byteVal4:Frame counter controlling how log the key is revealed for ant the time
 *  between reveals
 *  
 * byteArray:The complete pattern of 128 keys that the user has to repeat.
 * byteArray2:Unused
 * 
 */

#include "Init.h"
#include "RepeatMe.h"
#include "Controller.h"


RepeatMe::RepeatMe(){
}

void RepeatMe::run(){

  ctrl.clear();

  
 
  switch(ctrl.getGameState()){
    
    case 0:{
      byte leftMargin = drawPad(0);
      ctrl.setCursor(leftMargin,0);
      ctrl.print("Press B");
      ctrl.setCursor(leftMargin,8);
      ctrl.print("to Begin!\n");
        
      if(ctrl.justPressed(B_BUTTON)){
        
        ctrl.activeGameData.byteVal1++;

        //Set the pattern
        randomSeed(millis());
        
        for(byte i=0; i <= 128; i++){
          ctrl.activeGameData.byteArray[i] = random(1,5);
        }

        drawPad(ctrl.activeGameData.byteArray[0]);
        
        ctrl.setGameState(2);
      }
      break;
    }

    case 1:{

        ctrl.setCursor(62,0);
        ctrl.print("Score:");
        ctrl.print(ctrl.activeGameData.byteVal3);

      if(ctrl.activeGameData.byteVal3 == ctrl.activeGameData.byteVal1){
        ctrl.activeGameData.byteVal2 = 0;
        ctrl.activeGameData.byteVal1 = 0;
        ctrl.setGameState(2);
      }

      if(ctrl.activeGameData.byteVal4 == 15){
        drawPad(ctrl.activeGameData.byteArray[ctrl.activeGameData.byteVal1]);
      } else if (ctrl.activeGameData.byteVal4 == 20){
        ctrl.activeGameData.byteVal1++;
        ctrl.activeGameData.byteVal4 = 0;
        drawPad(0);
      } else {
        drawPad(0);
      }

      ctrl.activeGameData.byteVal4++;

      break;
    }

    case 2: {

      ctrl.setCursor(62,0);
      ctrl.print("Score:");
      ctrl.print(ctrl.activeGameData.byteVal3);
      
      drawPad(0);
      
      byte enteredPad = 0;
      if(ctrl.justPressed(LEFT_BUTTON)){
        enteredPad = 1;
        drawPad(1);
      } else if (ctrl.justPressed(UP_BUTTON)) {
        enteredPad = 2;
        drawPad(2);
      } else if (ctrl.justPressed(RIGHT_BUTTON)){
        enteredPad = 3;
        drawPad(3);
      } else if (ctrl.justPressed(DOWN_BUTTON)){
        enteredPad = 4;
        drawPad(4);
      }


      if(ctrl.activeGameData.byteArray[ctrl.activeGameData.byteVal2] == enteredPad){
        ctrl.activeGameData.byteVal2++;
      } else if(enteredPad!=0){
        ctrl.setGameState(4);
      }

      if(ctrl.activeGameData.byteVal2 == ctrl.activeGameData.byteVal3){
        ctrl.activeGameData.byteVal3++;
        ctrl.setGameState(1);
      }
      
      break;
    }

    case 3: {
      ctrl.clear();
      ctrl.print("You Won!\n");
      ctrl.print("B: Play Again\n");
      ctrl.print("A: Return to Menu");

      if(ctrl.justPressed(A_BUTTON)){
        ctrl.setGameMode(0);
      }

      if(ctrl.justPressed(B_BUTTON)){
        ctrl.setGameMode(2);
      }
      
      break;
    }

    case 4: {
      ctrl.clear();
      ctrl.print("Try Again?\n");
      ctrl.print("B: Play Again\n");
      ctrl.print("A: Return to Menu");

      if(ctrl.justPressed(A_BUTTON)){
        ctrl.setGameMode(0);
      }

      if(ctrl.justPressed(B_BUTTON)){
        ctrl.setGameMode(2);
      }
      
      break;
    }

  }

  ctrl.display();
    
}
 
byte RepeatMe::drawPad(byte lightSegment){

  byte squareSize = 20;
  byte xPos = 0;
  byte yPos = squareSize + ((64-(squareSize*3))/2);
  byte toneDur = 200;
  
  ctrl.setRGBled(0,0,0);
  
  if(lightSegment == 1){
    ctrl.fillRect(xPos, yPos, squareSize, squareSize);
    ctrl.sound->tone(1000,toneDur);
    ctrl.setRGBled(1,0,0);
  } else {
    ctrl.drawRect(xPos, yPos, squareSize, squareSize);
  }

  if(lightSegment == 4){
    ctrl.fillRect(xPos+(squareSize), yPos+(squareSize), squareSize, squareSize);
    ctrl.sound->tone(1500,toneDur);
    ctrl.setRGBled(0,1,0);
  } else {
    ctrl.drawRect(xPos+(squareSize), yPos+(squareSize), squareSize, squareSize);
  }

  if(lightSegment == 3){
    ctrl.fillRect(xPos+(squareSize*2), yPos, squareSize, squareSize);
    ctrl.sound->tone(2000,toneDur);
    ctrl.setRGBled(0,0,1);
  } else {
    ctrl.drawRect(xPos+(squareSize*2), yPos, squareSize, squareSize);
  }

  if(lightSegment == 2){
    ctrl.fillRect(xPos+(squareSize), yPos-(squareSize), squareSize, squareSize);
    ctrl.sound->tone(2500,toneDur);
    ctrl.setRGBled(1,1,1);
  } else {
    ctrl.drawRect(xPos+(squareSize), yPos-(squareSize), squareSize, squareSize);
  }

  return squareSize*3+2;

  
}
  


