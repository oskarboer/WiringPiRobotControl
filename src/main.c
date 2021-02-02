#include "main.h"

double		pid_error_function(t_pid *pid)
{

	double steps = (double)(pid->motor->encoder->value - pid->motor->encoder->last_value);
	steps = steps / TICKS_PER_REVOLUTION * (SECOND_IN_MICROSECONDS/PID_UPDATE_INTERVAL) / TICKS_PER_REVOLUTION;
	
	pid->motor->encoder->last_value = pid->motor->encoder->value;
	return steps;
}


int		main (void)
{
	(void)signal(SIGINT, exithandle);
	
	wiringPiSetup ();
	double P = 0.30;
	double I = 0.005;
	double D = 0.2;

	
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
	
	robot = setup_robot(encoderR, encoderL, motorR, motorL);

	
	if (pidR == NULL || pidL == NULL)
		return 1;
	
	
	start_pid();
	
	pidR->aim_output = 100;
	pidL->aim_output = 100;

	
	for (;;)
	{
		
	}
	
	return 0;
}
