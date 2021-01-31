
#ifndef MOTOR_H
# define MOTOR_H

#include "main.h"

typedef struct	s_motor{
	int			pin_a;
	int			pin_b;
	int			speed;
	struct encoder		*encoder;
	
}				t_motor;

t_motor*		setup_motor(int pin_a, int pin_b, struct encoder *encoder);

void			set_speed(t_motor *motor, int speed);


#endif
