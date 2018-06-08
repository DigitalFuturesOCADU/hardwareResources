/*
 * BiG PICTURE Workshop
 * Rotating Line with oscillating X coordinate of the centerPt
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

  point centerPt = {oscillate(20,80,0,0.1,timeStamp),32};
  point endPt = rotatePoint(centerPt.x,centerPt.y,oscillate(5,25,0,0.2,timeStamp),0.5,timeStamp,0);
  bigPicture.drawLine(centerPt.x,centerPt.y,endPt.x,endPt.y);
  bigPicture.drawBox(endPt.x,endPt.y,oscillate(2,20,0,0.2,timeStamp),oscillate(2,20,0,0.2,timeStamp));

  
  bigPicture.sendBuffer();     //this is the bottom of the drawing commands
}
