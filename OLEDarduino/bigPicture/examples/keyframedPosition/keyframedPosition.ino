/*
 * BiG PICTURE Workshop
 * keyframe animation of the x/y postion of an object
 * 
 * https://github.com/olikraus/u8g2/wiki/u8g2reference  shows all of the drawing functions in the library
 * 
 */

//include the libraries
#include <U8g2lib.h>
#include <animationTools.h>


point circlePosition;  //this variable will hold the currentValues generated from the timelines
Timeline circleMoveX;  //keyframe object for the x values
Timeline circleMoveY;  //keyframe object for the y values



//define the U8G2 ojbect with the properties that match the screen we are using
U8G2_SH1106_128X64_NONAME_F_HW_I2C bigPicture(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);


void setup() 
{

//set the time and value key pairs  
circleMoveX.timeKey[0] = 0;
circleMoveX.valKey[0] = 0;
circleMoveY.timeKey[0] = 0;
circleMoveY.valKey[0] = 20;

circleMoveX.timeKey[1] = 1000;
circleMoveX.valKey[1] = 40;
circleMoveY.timeKey[1] = 1000;
circleMoveY.valKey[1] = 0;
  
circleMoveX.timeKey[2] = 2000;
circleMoveX.valKey[2] = 40;
circleMoveY.timeKey[2] = 2000;
circleMoveY.valKey[2] = 0;

circleMoveX.timeKey[3] = 2500;
circleMoveX.valKey[3] = 100;
circleMoveY.timeKey[3] = 2500;
circleMoveY.valKey[3] = 32;

circleMoveX.timeKey[4] = 5000;
circleMoveX.valKey[4] = 0;
circleMoveY.timeKey[4] = 5000;
circleMoveY.valKey[4] = 20;


//you currently must set the total number of keys manually
circleMoveX.totalKeys = 5;
circleMoveY.totalKeys = 5;

bigPicture.begin();

}

void loop() 
{
circlePosition.x = getTimelineValue(circleMoveX);  //get the current value of the animation
circlePosition.y = getTimelineValue(circleMoveY);

  bigPicture.clearBuffer();          // clear the internal memory
  bigPicture.drawDisc(circlePosition.x,circlePosition.y,10);
  bigPicture.sendBuffer();          //send image to the screen



}
