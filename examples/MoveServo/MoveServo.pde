/*
 * Easing
 * Tobias Toft <hello@tobiastoft.dk>
 * July 27, 2009
 *
 * Moves a servo motor back and forth between 0 and 140 degrees
 * when a button is pressed.
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
  myServo.write(0);  //put servo at 0 degrees
  pinMode(buttonPin, INPUT); //set up button
  digitalWrite(buttonPin, HIGH); //activate internal pull-up resistor (then we don't have to put one in our circuit)
}

void loop(){
  boolean buttonPressed = digitalRead(buttonPin); //read button, LOW==activated
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