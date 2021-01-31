#ifndef MAIN_H
# define MAIN_H

#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>
#include <stdint.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#include "motor.h"
#include "rotaryencoder.h"
#include "pid.h"



#define max(a,b) \
({ __typeof__ (a) _a = (a); \
   __typeof__ (b) _b = (b); \
 _a > _b ? _a : _b; })
 
#define min(a,b) \
({ __typeof__ (a) _a = (a); \
   __typeof__ (b) _b = (b); \
 _a < _b ? _a : _b; })
     
#endif
