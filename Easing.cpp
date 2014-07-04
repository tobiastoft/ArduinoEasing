/*******************************************************************************************
  Easing equations for Arduino v0.1
  
  These functions were quickly mashed together and the code needs to be
  tidied up e.g. in terms of memory management (all variables are floats).
  
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
	  Back
	  Bounce

  Discussed in Chapter 7 of 
  Robert Penner's Programming Macromedia Flash MX
  (including graphs of the easing equations)
  
  http://www.robertpenner.com/profmx
  http://www.amazon.com/exec/obidos/ASIN/0072223561/robertpennerc-20
*******************************************************************************************/

#include "Easing.h"
#include <math.h>


// simple linear tweening - no easing
// t: current time, b: beginning value, c: change in value, d: duration
float Easing::linearTween (float t, float b, float c, float d) {
	return c*t/d + b;
}


 ///////////// QUADRATIC EASING: t^2 ///////////////////

// quadratic easing in - accelerating from zero velocity
// t: current time, b: beginning value, c: change in value, d: duration
// t and d can be in frames or seconds/milliseconds
float Easing::easeInQuad (float t, float b, float c, float d) {
	return c*(t/=d)*t + b;
}

// quadratic easing out - decelerating to zero velocity
float Easing::easeOutQuad (float t, float b, float c, float d) {
	return -c *(t/=d)*(t-2) + b;
}

// quadratic easing in/out - acceleration until halfway, then deceleration
float Easing::easeInOutQuad (float t, float b, float c, float d) {
	if ((t/=d/2) < 1) return c/2*t*t + b;
	return -c/2 * ((--t)*(t-2) - 1) + b;
}


 ///////////// CUBIC EASING: t^3 ///////////////////////

// cubic easing in - accelerating from zero velocity
// t: current time, b: beginning value, c: change in value, d: duration
// t and d can be frames or seconds/milliseconds
float Easing::easeInCubic (float t, float b, float c, float d) {
	return c*(t/=d)*t*t + b;
}

// cubic easing out - decelerating to zero velocity
float Easing::easeOutCubic (float t, float b, float c, float d) {
	return c*((t=t/d-1)*t*t + 1) + b;
}

// cubic easing in/out - acceleration until halfway, then deceleration
float Easing::easeInOutCubic (float t, float b, float c, float d) {
	if ((t/=d/2) < 1) return c/2*t*t*t + b;
	return c/2*((t-=2)*t*t + 2) + b;
}


 ///////////// QUARTIC EASING: t^4 /////////////////////

// quartic easing in - accelerating from zero velocity
// t: current time, b: beginning value, c: change in value, d: duration
// t and d can be frames or seconds/milliseconds
float Easing::easeInQuart (float t, float b, float c, float d) {
	return c*(t/=d)*t*t*t + b;
}

// quartic easing out - decelerating to zero velocity
float Easing::easeOutQuart (float t, float b, float c, float d) {
	return -c * ((t=t/d-1)*t*t*t - 1) + b;
}

// quartic easing in/out - acceleration until halfway, then deceleration
float Easing::easeInOutQuart (float t, float b, float c, float d) {
	if ((t/=d/2) < 1) return c/2*t*t*t*t + b;
	return -c/2 * ((t-=2)*t*t*t - 2) + b;
}


 ///////////// QUINTIC EASING: t^5  ////////////////////

// quintic easing in - accelerating from zero velocity
// t: current time, b: beginning value, c: change in value, d: duration
// t and d can be frames or seconds/milliseconds
float Easing::easeInQuint (float t, float b, float c, float d) {
	return c*(t/=d)*t*t*t*t + b;
}

// quintic easing out - decelerating to zero velocity
float Easing::easeOutQuint (float t, float b, float c, float d) {
	return c*((t=t/d-1)*t*t*t*t + 1) + b;
}

// quintic easing in/out - acceleration until halfway, then deceleration
float Easing::easeInOutQuint (float t, float b, float c, float d) {
	if ((t/=d/2) < 1) return c/2*t*t*t*t*t + b;
	return c/2*((t-=2)*t*t*t*t + 2) + b;
}



 ///////////// SINUSOIDAL EASING: sin(t) ///////////////

// sinusoidal easing in - accelerating from zero velocity
// t: current time, b: beginning value, c: change in position, d: duration
float Easing::easeInSine (float t, float b, float c, float d) {
	return -c * cos(t/d * (M_PI/2)) + c + b;
}

// sinusoidal easing out - decelerating to zero velocity
float Easing::easeOutSine (float t, float b, float c, float d) {
	return c * sin(t/d * (M_PI/2)) + b;
}

// sinusoidal easing in/out - accelerating until halfway, then decelerating
float Easing::easeInOutSine (float t, float b, float c, float d) {
	return -c/2 * (cos(M_PI*t/d) - 1) + b;
}


 ///////////// EXPONENTIAL EASING: 2^t /////////////////

// exponential easing in - accelerating from zero velocity
// t: current time, b: beginning value, c: change in position, d: duration
float Easing::easeInExpo (float t, float b, float c, float d) {
	return (t==0) ? b : c * pow(2, 10 * (t/d - 1)) + b;
}

// exponential easing out - decelerating to zero velocity
float Easing::easeOutExpo (float t, float b, float c, float d) {
	return (t==d) ? b+c : c * (-pow(2, -10 * t/d) + 1) + b;
}

// exponential easing in/out - accelerating until halfway, then decelerating
float Easing::easeInOutExpo (float t, float b, float c, float d) {
	if (t==0) return b;
	if (t==d) return b+c;
	if ((t/=d/2) < 1) return c/2 * pow(2, 10 * (t - 1)) + b;
	return c/2 * (-pow(2, -10 * --t) + 2) + b;
}


 /////////// CIRCULAR EASING: sqrt(1-t^2) //////////////

// circular easing in - accelerating from zero velocity
// t: current time, b: beginning value, c: change in position, d: duration
float Easing::easeInCirc (float t, float b, float c, float d) {
	return -c * (sqrt(1 - (t/=d)*t) - 1) + b;
}

// circular easing out - decelerating to zero velocity
float Easing::easeOutCirc (float t, float b, float c, float d) {
	return c * sqrt(1 - (t=t/d-1)*t) + b;
}

// circular easing in/out - acceleration until halfway, then deceleration
float Easing::easeInOutCirc (float t, float b, float c, float d) {
	if ((t/=d/2) < 1) return -c/2 * (sqrt(1 - t*t) - 1) + b;
	return c/2 * (sqrt(1 - (t-=2)*t) + 1) + b;
}


 /////////// ELASTIC EASING: exponentially decaying sine wave  //////////////

// t: current time, b: beginning value, c: change in value, d: duration, a: amplitude (optional), p: period (optional)
// t and d can be in frames or seconds/milliseconds

float Easing::easeInElastic (float t, float b, float c, float d, float a, float p) {
	float s;
	if (t==0) return b;  if ((t/=d)==1) return b+c;  if (!p) p=d*.3;
	if (a < fabs(c)) { a=c; s=p/4; }
	else s = p/(2*M_PI) * asin (c/a);
	return -(a*pow(2,10*(t-=1)) * sin( (t*d-s)*(2*M_PI)/p )) + b;
}

float Easing::easeOutElastic (float t, float b, float c, float d, float a, float p) {
	float s;
	if (t==0) return b;  if ((t/=d)==1) return b+c;  if (!p) p=d*.3;
	if (a < fabs(c)) { a=c; s=p/4; }
	else s = p/(2*M_PI) * asin (c/a);
	return a*pow(2,-10*t) * sin( (t*d-s)*(2*M_PI)/p ) + c + b;
}

float Easing::easeInOutElastic (float t, float b, float c, float d, float a, float p) {
	float s;
	if (t==0) return b;  if ((t/=d/2)==2) return b+c;  if (!p) p=d*(.3*1.5);
	if (a < fabs(c)) { a=c; s=p/4; }
	else s = p/(2*M_PI) * asin (c/a);
	if (t < 1) return -.5*(a*pow(2,10*(t-=1)) * sin( (t*d-s)*(2*M_PI)/p )) + b;
	return a*pow(2,-10*(t-=1)) * sin( (t*d-s)*(2*M_PI)/p )*.5 + c + b;
}


//Four parameter versions
float Easing::easeInElastic (float t, float b, float c, float d) {
	float s;
	float a=0.0;
	float p=0.0;
	if (t==0) return b;  if ((t/=d)==1) return b+c;  if (!p) p=d*.3;
	if (a < fabs(c)) { a=c; s=p/4; }
	else s = p/(2*M_PI) * asin (c/a);
	return -(a*pow(2,10*(t-=1)) * sin( (t*d-s)*(2*M_PI)/p )) + b;
}

float Easing::easeOutElastic (float t, float b, float c, float d) {
	float s;
	float a=0.0;
	float p=0.0;
	if (t==0) return b;  if ((t/=d)==1) return b+c;  if (!p) p=d*.3;
	if (a < fabs(c)) { a=c; s=p/4; }
	else s = p/(2*M_PI) * asin (c/a);
	return a*pow(2,-10*t) * sin( (t*d-s)*(2*M_PI)/p ) + c + b;
}

float Easing::easeInOutElastic (float t, float b, float c, float d) {
	float s;
	float a=0.0;
	float p=0.0;
	if (t==0) return b;  if ((t/=d/2)==2) return b+c;  if (!p) p=d*(.3*1.5);
	if (a < fabs(c)) { a=c; s=p/4; }
	else s = p/(2*M_PI) * asin (c/a);
	if (t < 1) return -.5*(a*pow(2,10*(t-=1)) * sin( (t*d-s)*(2*M_PI)/p )) + b;
	return a*pow(2,-10*(t-=1)) * sin( (t*d-s)*(2*M_PI)/p )*.5 + c + b;
}

 /////////// BACK EASING: overshooting cubic easing: (s+1)*t^3 - s*t^2  //////////////

// back easing in - backtracking slightly, then reversing direction and moving to target
// t: current time, b: beginning value, c: change in value, d: duration, s: overshoot amount (optional)
// t and d can be in frames or seconds/milliseconds
// s controls the amount of overshoot: higher s means greater overshoot
// s has a default value of 1.70158, which produces an overshoot of 10 percent
// s==0 produces cubic easing with no overshoot
float Easing::easeInBack (float t, float b, float c, float d, float s) {
	return c*(t/=d)*t*((s+1)*t - s) + b;
}

// back easing out - moving towards target, overshooting it slightly, then reversing and coming back to target
float Easing::easeOutBack (float t, float b, float c, float d, float s) {
	return c*((t=t/d-1)*t*((s+1)*t + s) + 1) + b;
}

// back easing in/out - backtracking slightly, then reversing direction and moving to target,
// then overshooting target, reversing, and finally coming back to target
float Easing::easeInOutBack (float t, float b, float c, float d, float s) {
	if ((t/=d/2) < 1) return c/2*(t*t*(((s*=(1.525))+1)*t - s)) + b;
	return c/2*((t-=2)*t*(((s*=(1.525))+1)*t + s) + 2) + b;
}


//Four parameter versions
float Easing::easeInBack (float t, float b, float c, float d) {
	float s=1.70158;
	return c*(t/=d)*t*((s+1)*t - s) + b;
}

float Easing::easeOutBack (float t, float b, float c, float d) {
	float s=1.70158;
	return c*((t=t/d-1)*t*((s+1)*t + s) + 1) + b;
}

float Easing::easeInOutBack (float t, float b, float c, float d) {
	float s=1.70158;
	if ((t/=d/2) < 1) return c/2*(t*t*(((s*=(1.525))+1)*t - s)) + b;
	return c/2*((t-=2)*t*(((s*=(1.525))+1)*t + s) + 2) + b;
}

 /////////// BOUNCE EASING: exponentially decaying parabolic bounce  //////////////

// bounce easing in
// t: current time, b: beginning value, c: change in position, d: duration
float Easing::easeInBounce (float t, float b, float c, float d) {
	return c - easeOutBounce (d-t, 0, c, d) + b;
}

// bounce easing out
float Easing::easeOutBounce (float t, float b, float c, float d) {
	if ((t/=d) < (1/2.75)) {
		return c*(7.5625*t*t) + b;
	} else if (t < (2/2.75)) {
		return c*(7.5625*(t-=(1.5/2.75))*t + .75) + b;
	} else if (t < (2.5/2.75)) {
		return c*(7.5625*(t-=(2.25/2.75))*t + .9375) + b;
	} else {
		return c*(7.5625*(t-=(2.625/2.75))*t + .984375) + b;
	}
}

// bounce easing in/out
float Easing::easeInOutBounce (float t, float b, float c, float d) {
	if (t < d/2) return easeInBounce (t*2, 0, c, d) * .5 + b;
	return easeOutBounce (t*2-d, 0, c, d) * .5 + c*.5 + b;
}
