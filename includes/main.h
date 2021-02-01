#ifndef MAIN_H
# define MAIN_H

#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>
#include <stdint.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

#include "motor.h"
#include "rotaryencoder.h"
#include "pid.h"


#define PID_UPDATE_INTERVAL 10000 //microseconds
#define SECOND_IN_MICROSECONDS 1000000 //microseconds

typedef struct		s_robot{
	struct encoder	*encoderR;
	struct encoder	*encoderL;
	
	t_motor			*motorR;
	t_motor			*motorL;
}					t_robot;


#define max(a,b) \
({ __typeof__ (a) _a = (a); \
   __typeof__ (b) _b = (b); \
 _a > _b ? _a : _b; })
 
#define min(a,b) \
({ __typeof__ (a) _a = (a); \
   __typeof__ (b) _b = (b); \
 _a < _b ? _a : _b; })
     
#endif
