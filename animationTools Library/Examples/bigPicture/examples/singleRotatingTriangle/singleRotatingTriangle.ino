/*
 * BiG PICTURE Workshop
 * single rotating triangle oscillating rotation
 * 
 * https://github.com/olikraus/u8g2/wiki/u8g2reference  shows all of the drawing functions in the library
 * 
 */

//include the libraries
#include <U8g2lib.h>
#include <animationTools.h>

point triCenter = {64,32};
tri_angles spinTri= {0,120,240};  //legs of the triangle expressed as angles from the center pt.
valRange spinVals = {0,360};

//define the U8G2 ojbect with the properties that match the screen we are using
U8G2_SH1106_128X64_NONAME_F_HW_I2C bigPicture(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);


void setup() 
{

  bigPicture.begin();           //start the U8G2 object 
}

void loop() 
{
  long timeStamp = millis();

  bigPicture.clearBuffer();    //this needs to be at the beginning of drawing commands


  bigPicture.setDrawColor(1);


  trianglePoints tri1 = rotateTriangle(triCenter.x,triCenter.y,spinTri.leg1,spinTri.leg2,spinTri.leg3,10,0.2,oscillate(spinVals.minVal,spinVals.maxVal,0,0.5,timStamp),0);//rotateTriangle(float centerX, float centerY, int legAngle1, int legAngle2, int legAngle3, float radius, float speedFactor, float rotationInput, int rotOffset)
  bigPicture.drawTriangle(tri1.leg1X,tri1.leg1Y,tri1.leg2X,tri1.leg2Y,tri1.leg3X,tri1.leg3Y);

  bigPicture.sendBuffer();     //this is the bottom of the drawing commands
}
