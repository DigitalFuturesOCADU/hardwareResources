/*
 * BiG PICTURE Workshop
 * keyframe animation of the x/y postion of an object generated randomly
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
int totalKeyframes = 10;
int timeVal;


for( int i = 0; i<totalKeyframes;i++)
{

timeVal += random(600,2000);
  
circleMoveX.timeKey[i] = timeVal;
circleMoveX.valKey[i] = random(0,100);;
circleMoveY.timeKey[i] = timeVal;
circleMoveY.valKey[i] = random(0,60);

}

//you currently must set the total number of keys manually
circleMoveX.totalKeys = totalKeyframes;
circleMoveY.totalKeys = totalKeyframes;

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
