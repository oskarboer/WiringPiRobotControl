#include "main.h"


int64_t timespecDiff(struct timespec *timeA_p, struct timespec *timeB_p)
{
  return ((timeA_p->tv_sec * 1000000000) + timeA_p->tv_nsec) -
           ((timeB_p->tv_sec * 1000000000) + timeB_p->tv_nsec);
}

//void sighadle(int sig)
//{
    //set_speed(motorR, 0);
	//set_speed(motorL, 0);
	//delay(1000);
	//printf("Exiting...\n");
//}

double		pid_error_function(t_pid *pid)
{
	// ATTEMP to count time
	//struct timespec end;
	//clock_gettime(CLOCK_MONOTONIC, &end);
	//int64_t time = timespecDiff(&end, &pid->acceced);
	//double speed = steps / time;
	//pid->acceced = end;
	//printf("%i\n", steps);
	
	
	double steps = (double)(pid->motor->encoder->value - pid->motor->encoder->last_value);
	steps = steps / TICKS_PER_REVOLUTION * (SECOND_IN_MICROSECONDS/PID_UPDATE_INTERVAL) / TICKS_PER_REVOLUTION;
	
	pid->motor->encoder->last_value = pid->motor->encoder->value;
	return steps;

	
	
	//return pid->motor->encoder->value;
}


int		main (void)
{
	//(void) signal(SIGINT, sighadle);
	
	wiringPiSetup ();
	double P = 0.30;
	double I = 0.005;
	double D = 0.2;

	//pinMode (0, OUTPUT);
	
	struct encoder *encoderR = setupencoder(26, 27);
	struct encoder *encoderL = setupencoder(22, 23);

	t_motor *motorR = setup_motor(29, 28, encoderR);
	t_motor *motorL = setup_motor(24, 25, encoderL);
	

	// Set speed 0 to calm the motors:
	set_speed(motorR, 0);
	set_speed(motorL, 0);
	delay(1000);
	
	
	t_pid *pidR = setup_pid(P, I, D, motorR, pid_error_function);
	t_pid *pidL = setup_pid(P, I, D, motorL, pid_error_function);
	
	if (pidR == NULL || pidL == NULL)
		return 1;
	
	
	start_pid();
	
	pidR->aim_output = 100;
	pidL->aim_output = 100;

	
	for (;;)
	{
		//printf("%i\n", pidR->output);
		//delay(100);
	}
	
	return 0;
}
