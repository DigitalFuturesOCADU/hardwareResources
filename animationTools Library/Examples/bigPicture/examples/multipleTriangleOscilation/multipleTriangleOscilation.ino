/*
 * BiG PICTURE Workshop
 * Combines rotations / oscillations of triangles and a loop
 * 
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
  long timeStamp = millis();
  bigPicture.clearBuffer();    //this needs to be at the beginning of drawing commands

  for(int i=1;i<=6;i++)
  {
  bigPicture.setDrawColor(1);  //set the color to ON
  
  trianglePoints tri1 = rotateTriangle(i*20,oscillate(10,50,i*20,0.1*i,timeStamp),0,oscillate(20,120,i*10,0.4,timeStamp),240,oscillate(20,24,i*10,0.4,timeStamp),0.2,timeStamp,i*40); //calculate background triangle
  bigPicture.drawTriangle(tri1.leg1X,tri1.leg1Y,tri1.leg2X,tri1.leg2Y,tri1.leg3X,tri1.leg3Y); //draw the triangle
  
  bigPicture.setDrawColor(0);  //set the color to BLACK
  
  tri1 = rotateTriangle(i*20,oscillate(10,50,i*20,0.1*i,timeStamp),0,oscillate(20,120,i*10,0.4,timeStamp),240,oscillate(5,18,i*10,0.4,timeStamp),0.2,timeStamp,i*40); //calculate front triangle
  bigPicture.drawTriangle(tri1.leg1X,tri1.leg1Y,tri1.leg2X,tri1.leg2Y,tri1.leg3X,tri1.leg3Y); //draw the triangle
  
  }
  bigPicture.sendBuffer();     //this is the bottom of the drawing commands

  

}
