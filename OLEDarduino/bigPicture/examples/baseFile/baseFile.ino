/*
 * BiG PICTURE Workshop
 * This is the base file we will work from that loads U8G2 library and the basic animationTools
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

  bigPicture.clearBuffer();    //this needs to be at the beginning of drawing commands


  bigPicture.sendBuffer();     //this is the bottom of the drawing commands

  

}
