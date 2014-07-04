/*******************************************************************************************
  Easing equations for Arduino v0.1
  
  These functions were quickly mashed together and the code could probably need some 
  tidying up e.g. in terms of memory management (all variables are floats).
  
  All functions are put in the namespace "Easing".
  
  July 27, 2009
  Translated by Tobias Toft
  hello@tobiastoft.dk

  Based on the work by Robert Penner.

  ******************************************************************************************

  Easing Equations v1.5
  May 1, 2003
  (c) 2003 Robert Penner, all rights reserved. 
  This work is subject to the terms in http://www.robertpenner.com/easing_terms_of_use.html.  
  
  These tweening functions provide different flavors of 
  math-based motion under a consistent API. 
  
  Types of easing:
  
	  Linear
	  Quadratic
	  Cubic
	  Quartic
	  Quintic
	  Sinusoidal
	  Exponential
	  Circular
	  Elastic
	  Elastic (four parameter version) <-- for passing functions as parameters to other functions
	  Back
	  Back (four parameter version) <-- for passing functions as parameters to other functions
	  Bounce

  Discussed in Chapter 7 of 
  Robert Penner's Programming Macromedia Flash MX
  (including graphs of the easing equations)
  
  http://www.robertpenner.com/profmx
  http://www.amazon.com/exec/obidos/ASIN/0072223561/robertpennerc-20
*******************************************************************************************/

#ifndef Easing_h
#define Easing_h

//class Easing {
//public:
	//Easing();
namespace Easing{	
	float linearTween (float t, float b, float c, float d);
	float easeInQuad (float t, float b, float c, float d);
	float easeOutQuad (float t, float b, float c, float d);
	float easeInOutQuad (float t, float b, float c, float d);
	float easeInCubic (float t, float b, float c, float d);
	float easeOutCubic (float t, float b, float c, float d);
	float easeInOutCubic (float t, float b, float c, float d);
	float easeInQuart (float t, float b, float c, float d);
	float easeOutQuart (float t, float b, float c, float d);
	float easeInOutQuart (float t, float b, float c, float d);
	float easeInQuint (float t, float b, float c, float d);
	float easeOutQuint (float t, float b, float c, float d);
	float easeInOutQuint (float t, float b, float c, float d);
	float easeInSine (float t, float b, float c, float d);
	float easeOutSine (float t, float b, float c, float d);
	float easeInOutSine (float t, float b, float c, float d);
	float easeInExpo (float t, float b, float c, float d);
	float easeOutExpo (float t, float b, float c, float d);
	float easeInOutExpo (float t, float b, float c, float d);
	float easeInCirc (float t, float b, float c, float d);
	float easeOutCirc (float t, float b, float c, float d);
	float easeInOutCirc (float t, float b, float c, float d);
	float easeInElastic (float t, float b, float c, float d, float a=0, float p=0);
	float easeOutElastic (float t, float b, float c, float d, float a=0, float p=0);
	float easeInOutElastic (float t, float b, float c, float d, float a=0, float p=0);
	float easeInElastic (float t, float b, float c, float d);
	float easeOutElastic (float t, float b, float c, float d);
	float easeInOutElastic (float t, float b, float c, float d);
	float easeInBack (float t, float b, float c, float d, float s=1.70158);
	float easeOutBack (float t, float b, float c, float d, float s=1.70158);
	float easeInOutBack (float t, float b, float c, float d, float s=1.70158);
	float easeInBack (float t, float b, float c, float d);
	float easeOutBack (float t, float b, float c, float d);
	float easeInOutBack (float t, float b, float c, float d);
	float easeInBounce (float t, float b, float c, float d);
	float easeOutBounce (float t, float b, float c, float d);
	float easeInOutBounce (float t, float b, float c, float d);
}
//};

#endif






