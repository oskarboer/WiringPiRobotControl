#include "main.h"


t_motor*	setup_motor(int pin_a, int pin_b, struct encoder *encoder)
{
	t_motor *motor = (t_motor *)malloc(sizeof(t_motor));
	motor->pin_a = pin_a;
	motor->pin_b = pin_b;
	motor->speed = 0;
	motor->encoder = encoder;

	softPwmCreate(pin_a, 0, 100);
	softPwmCreate(pin_b, 0, 100);

	return motor;
}


void		set_speed(t_motor *motor, int speed)
{
	if (speed < -100 || speed > 100 || motor == NULL)
		return;
	if (speed >= 0)
	{
		softPwmWrite (motor->pin_a, speed);
		softPwmWrite (motor->pin_b, 0);
	}
	if (speed < 0)
	{
		softPwmWrite (motor->pin_a, 0);
		softPwmWrite (motor->pin_b, -speed);
	}
}
	
