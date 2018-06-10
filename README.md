# Animation Tools

The animation tools library is a small set of helper functions and data structures for Arduino that use basic tools and methods of time-based animation to control various actuators.  The tools have been used to control LEDs, stepper motors, servos, and piezo buzzers.  The core of the library is based around 2 basic functions – oscillation & timeline– that can be layered onto eachother for more complex behaviours.The library also contains tools for drawing animation to OLED screens using the [U8G](https://github.com/olikraus/u8g2/wiki) library. These functions are all based on timers, so they do not block any other input/output functions used in a sketch.

## Basic Functions:

### Oscillation
This function uses a simple sin wave to drive a continuous fade between 2 values and returns an integer.

The function has 5 inputs that can be changed dynamically
```arduino
oscillate(int minVal, int maxVal, int offset, float multiplier, long timeInput)

minVal //starting value of the oscillation
maxVal //end value of the oscillation
offset //moves initial start of the oscillation sequence. 
multiplier //used to change the speed of the oscillation (typically < 1, smaller number = slower)
timeInput//value used to step across the sin wave (typically millis())
```

#### Examples:

```arduino 
//oscillate between 0 -255 with a multiplier speed of 0.2
int ledBrightness = oscillate(0,255,0,0.2,millis());

//oscillate between 20 – 150 with a multiplier speed of 0.5 
int servoRotation = oscillate(20,150,0,0.5,millis()); 
```


Note: oscillate is designed to function as a very simple fade mechanism. If you require more precise or complex controls over values, use Timeline.


### Timeline
This function creates a method for using keyframe values in time as a means of controlling outputs in Arduino.  It consists of two parts: the Timeline structure and the getTimelineValue function.  The timeline of keyframe values can be set at the beginning of the sketch or changed dynamically at runtime. The function uses only linear interpolation between the values/time. Note: This is still an early version of the code. It has some quirks.

All timelines have the following parameters. Where X is the index of the array
```
.timeKey[X]  
.valKey{X]
```
These 2 parameters are typically defined together in the same manner you would input this type of data into an animation interface.  Define a value at a time.   The index should start at 0 and must be the same for the timeKey and valKey.
```
.totalKeys
```
At this point, you must manually define the total number of keyframes that you have created.  The maximum number of values is 10, but can be changed. (This will be fixed in a future version of the library)
```
.timelineLoop
```
This is True by default, but if you want the timeline to stop when it reaches the end it can be set to False.
```
.startupDelay
```
This typically isn’t needed. Primarily it is helpful when using a motor shield as they take a few seconds to initialize, thus throwing off the timing.  This corrects that by capturing the time at the bottom of the setup() function.


To use the function you must create an instance of a Timeline object, define it’s parameters.

#### Example:

```arduino

Timeline rotationValues:  //define a new Timeline object called rotationValues


//inside setup define the parameters of the Timeline
void setup()
{
rotationValues.timeKey[0] = 0;   //set a rotation of 10 at time 0
rotationValue.valKey[0] = 10;

rotationValues.timeKey[1] = 100;   //set a rotation of 100 at 1 second
rotationValue.valKey[1] = 1000;

rotationValues.timeKey[2] = 100;   //stay at 100 for 1 more second
rotationValue.valKey[2] = 2000;

rotationValues.timeKey[3] = 50;   //move to 50 over 500 milliseconds
rotationValue.valKey[3] = 2500;

rotationValues.timeKey[4] = 170;   //set a rotation of 170
rotationValue.valKey[4] = 3500;

rotationValues.timeKey[5] = 0;   //set rotation back to 0
rotationValue.valKey[5] = 4000;

rotationValues.totalKeys = 6;   //manually tell it how many keyframes

}

void loop()
{
int currentRotation = getTimelineValue(rotationValues); //to return the current value pass the object in the getTimelineValue function

} 
```

## OLED Animation functions
These functions and data structures build on the Timeline and Oscillation tools to create methods for creating animations that can be output to a small OLED screen.  These tools are built around the [U8G](https://github.com/olikraus/u8g2/wiki) Library which handles all of the drawing functions for the screen. These tools provide methods for animating those drawings

### Data Structures

Point
This new variable type has a .x and .y parameter. This is helpful for organizing coordinates

```arduino
point circlePoint;

circlePoint.x = 10;
circlePoint.y = 30;

//you can also assign directly at creation

point circlePoint2 = {10,20};

u8g.drawCircle(circlePoint2.x,circlePoint2.y,5);

```



