# Simple easing library for Arduino
I wrote this library as a part of the code I wrote my final project "Synthesising Personality", but I thought maybe other people could use it too. It will be on Github very, very soon.

It's an implementation of Robert Penner's easing functions (all credits should go to him). I've kept them generic (basically easing from one floating point value to another), but the only thing I have used them for is controlling servo motors and a little bit of playing around with LEDs.

The code is not very well written; it was just something I put together because I needed the functionality, but hey - at least it works :)

The functions are in the namespace "Easing". I wrote a small example for moving a servo, it's included in the library zip. It's installed like any other Arduino library.

##  Example code
Please note that this example is the most basic way of using the library – which also means that it will lock up the Arduino while the servo is moving, so if you need to perform other operations simultaneously with the movement (e.g. move other servos, fade light, etc.), consider stepping up to using the main loop, `millis()` for timing and a global counter for controlling the servo position instead of using the `moveServo()` function.

```c
/*
* Easing
* Tobias Toft 
* July 27, 2009
*
* Moves a servo motor back and forth between 
* 0 and 140 degrees when a button is pressed.
*
* This example is using the Servo.h library that comes
* with the Arduino IDE.
*
* Easing functions based on Robert Penner's work,
* for more info see Easing.h or Easing.cpp
*/

#include <Easing.h>
#include <Servo.h>

Servo myServo; //create servo object
const int buttonPin = 11; //we have a push button on pin 11

void setup(){
  myServo.attach(9); //attach servo at pin 9
  myServo.write(0); //put servo at 0 degrees
  pinMode(buttonPin, INPUT); //set up button
  digitalWrite(buttonPin, HIGH); //activate internal pull-up 
}

void loop(){
  //read button, LOW==activated
  boolean buttonPressed = digitalRead(buttonPin); 
  if (buttonPressed==LOW){
    moveServo();
  }
}

void moveServo(){
  int dur = 100; //duration is 100 loops
  for (int pos=0; pos<dur; pos++){
    //move servo from 0 and 140 degrees forward
    myServo.write(Easing::easeInOutCubic(pos, 0, 140, dur));
    delay(15); //wait for the servo to move
  }

  delay(1000); //wait a second, then move back using "bounce" easing

  for (int pos=0; pos<dur; pos++){
    //move servo -140 degrees from position 140 (back to 0)
    myServo.write(Easing::easeOutBounce(pos, 140, -140, dur));
    delay(15);
  }
}
```
