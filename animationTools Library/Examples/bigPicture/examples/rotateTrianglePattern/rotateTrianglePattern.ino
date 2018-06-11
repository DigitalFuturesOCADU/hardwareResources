/*
 * BiG PICTURE Workshop
 * Triangle pattern
 * rotation with nested for loops
 * https://github.com/olikraus/u8g2/wiki/u8g2reference  shows all of the drawing functions in the library
 * 
 */

//include the libraries
#include <U8g2lib.h>
#include <animationTools.h>



//define the U8G2 ojbect with the properties that match the screen we are using
U8G2_SH1106_128X64_NONAME_F_HW_I2C bigPicture(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);


void setup() 
{

  bigPicture.begin();           //start the U8G2 object 
}

void loop() 
{
  
  long timeStamp = millis();   //grab the time value, used to drive the animations
  bigPicture.clearBuffer();    //this needs to be at the beginning of drawing commands


  bigPicture.setDrawColor(1);
  bigPicture.drawBox(0,0,128,64);
  bigPicture.setDrawColor(0);
  
  for(int x=1;x<=10;x++)
  {
    for(int y=1;y<=5;y++)
    {
    trianglePoints tri1 = rotateTriangle(map(x,1,10,5,123),map(y,1,5,5,59),0,120,240,10,x*0.01,-timeStamp,x*40);//rotateTriangle(float centerX, float centerY, int legAngle1, int legAngle2, int legAngle3, float radius, float speedFactor, float rotationInput, int rotOffset)
    bigPicture.drawTriangle(tri1.leg1X,tri1.leg1Y,tri1.leg2X,tri1.leg2Y,tri1.leg3X,tri1.leg3Y);   
    }
  }
  
  bigPicture.sendBuffer();     //this is the bottom of the drawing commands
}
