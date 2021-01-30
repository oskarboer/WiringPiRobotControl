
#ifndef MOTOR_H
# define MOTOR_H_H

typedef struct	s_motor{
	int			pin_a;
	int			pin_b;
	int			speed;
}				t_motor;

t_motor*		setup_motor(int pin_a, int pin_b);

void			set_speed(t_motor *motor, int speed);


#endif
