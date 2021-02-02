#ifndef PID_H
# define PID_H

#include "main.h"

#define MAX_PID 2
#define MAX_SPEED 75 // out of 100
#define TICKS_PER_REVOLUTION 1430 //for my motors


typedef struct	s_pid{
	double		P;
	double		I;
	double		D;
	
	double		derivative;
	double		integral;
	double		error;
	double		error_old;
	int			output;
	int			max_output;
	double		aim_output;
	int			ticks_per_revolution;
		
	t_motor		*motor;
	double			(*pid_error_function)(struct s_pid *pid);
}				t_pid;


t_pid			*pids[MAX_PID];

t_pid*			setup_pid(double P, double I, double D, t_motor *motor, double (*pid_error_function)(t_pid *pid));
int				start_pid();
void			pid_cycle();



#endif
