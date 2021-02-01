
#ifndef PID_H
# define PID_H

#include "main.h"

#define MAX_PID 2
#define MAX_SPEED 75 // out of 100

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
	
	t_motor		*motor;
	int			(*pid_error_function)(void)
}				t_pid;


t_pid			*pids[MAX_PID];

t_pid*			setup_pid(double P, double I, double D, t_motor *motor, int (*pid_error_function)(void));
int				start_pid();
void			pid_cycle();



#endif
