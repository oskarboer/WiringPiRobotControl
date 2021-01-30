#ifndef MAIN_H
# define MAIN_H

#include <wiringPi.h>
#include <stdio.h>
#include "rotaryencoder.h"
#include <softPwm.h>
#include "motor.h"
#include <stdint.h>
#include <stdlib.h>

#define max(a,b) \
({ __typeof__ (a) _a = (a); \
   __typeof__ (b) _b = (b); \
 _a > _b ? _a : _b; })
 
#define min(a,b) \
({ __typeof__ (a) _a = (a); \
   __typeof__ (b) _b = (b); \
 _a < _b ? _a : _b; })
     
#endif
