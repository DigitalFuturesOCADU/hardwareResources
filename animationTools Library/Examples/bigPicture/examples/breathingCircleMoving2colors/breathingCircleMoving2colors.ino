/*
 * BiG PICTURE Workshop
 * Oscillating the size and position of 2 circles
 * 
 * https://github.com/olikraus/u8g2/wiki/u8g2reference  shows all of the drawing functions in the library
 * 
 */

#include <animationTools.h>
#include <U8g2lib.h>



int offset = 10;      //gap between the 2 circles

valRange circlePointRange = {10,84};
valRange circleSize = {2,60};

float radiusSpeedFactor = 0.2;  //rate at which the size animates - smaller=slower
float moveSpeedFactor = 0.07;   //rate at which the movement animates - smaller=slower



U8G2_SH1106_128X64_NONAME_F_HW_I2C bigPicture(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup(void) {
  bigPicture.begin();
}

void loop() 
{
  long timeStamp = millis();
  bigPicture.clearBuffer();          // clear the internal memory
  bigPicture.setDrawColor(1);        //set the color 1 = blue 0 = black
  bigPicture.drawDisc(oscillate(circlePointRange.minVal,circlePointRange.maxVal,0,moveSpeedFactor,timeStamp),32,oscillate(circleSize.minVal,circleSize.maxVal,0,radiusSpeedFactor,timeStamp));//use the oscillate function to animate the radius of the disc
  bigPicture.setDrawColor(0);       //switch the color to black
  bigPicture.drawDisc(oscillate(circlePointRange.minVal,circlePointRange.maxVal,0,moveSpeedFactor,timeStamp),32,oscillate(circleSize.minVal,(circleSize.maxVal-offset),0,radiusSpeedFactor,timeStamp));//use the oscillate function to animate the radius of the disc

  bigPicture.sendBuffer();          //send image to the screen


}





