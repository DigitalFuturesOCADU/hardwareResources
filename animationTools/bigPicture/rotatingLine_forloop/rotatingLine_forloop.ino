/*
 * BiG PICTURE Workshop
 * loop of rotating line with offset start point
 * 
 * https://github.com/olikraus/u8g2/wiki/u8g2reference  shows all of the drawing functions in the library
 * 
 */

//include the libraries
#include <U8g2lib.h>
#include <animationTools.h>

U8G2_SH1106_128X64_NONAME_F_HW_I2C bigPicture(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);


void setup() 
{
  bigPicture.begin();           //start the U8G2 object 

}

void loop() 
{
  long timeStamp = millis();   //grab the time value, used to drive the animations
  bigPicture.clearBuffer();    //this needs to be at the beginning of drawing commands
  int totalObjects = 6;
  int margin = 20;
  for(int x = 1;x<=totalObjects;x++)
  {
  point centerPt = {map(x,1,totalObjects,margin,128-margin),32};
  point endPt = rotatePoint(centerPt.x,centerPt.y,20,0.5,timeStamp,x*40);
  bigPicture.drawLine(centerPt.x,centerPt.y,endPt.x,endPt.y);
  bigPicture.drawBox(endPt.x,endPt.y,12,12);    
  }
  
  bigPicture.sendBuffer();     //this is the bottom of the drawing commands
}
