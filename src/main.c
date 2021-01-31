#include "main.h"


int		main (void)
{
	wiringPiSetup ();

	//pinMode (0, OUTPUT);
	
	//softPwmCreate(28, 0, 100);
	//int softPwmCreate (int pin, int initialValue, int pwmRange) ;
	//void softPwmWrite (int pin, int value);
	struct encoder *encoderR = setupencoder(26, 27);
	struct encoder *encoderL = setupencoder(22, 23);

	t_motor *motorR = setup_motor(28, 29, encoderR);
	t_motor *motorL = setup_motor(24, 25, encoderL);

	double P = 0.30;
	double I = 0.005;
	double D = 0.2;
	
	//double derivative;
	//double integral = 0;
	//double error = 0;
	//double error_old = 0;
	//int speed = 0;
	//int max_speed = 75;
	//double aim = 0;
	
	//softPwmWrite (motorR->pin_a, 50);
	
	// Set speed 0 to calm the motors:
	set_speed(motorR, 0);
	set_speed(motorL, 0);
	delay(3000);
	
	
	t_pid *pidR = setup_pid(P, I, D, motorR);
	t_pid *pidL = setup_pid(P, I, D, motorL);
	
	if (pidR == NULL || pidL == NULL)
		return 1;
	
	printf("%f\n", pids[1]->D);
	
	start_pid();
	
	
	for (;;)
	{
		//printf("%i\n", pidR->output);
		//delay(100);
	}
	
	
	//for (;;){
		
		//error = aim - encoderR->value;
		//integral += error;
		//integral = max(min(integral, 1000), -1000);
		//derivative = error - error_old;
		
		//speed = (int)(error * P + derivative * D + integral * I);
		
		//speed = -max(min(speed, max_speed), -max_speed);
		
		//set_speed(motorR, speed);
		//printf("%i\n", speed);
		
		//error_old = error;
		
		//delay(10);
	//}


	

	return 0;
}
