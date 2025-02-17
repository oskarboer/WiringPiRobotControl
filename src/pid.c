#include "main.h"

int num_of_pids = 0;

t_pid*	setup_pid(double P, double I, double D, t_motor *motor, double (*pid_error_function)(t_pid *pid))
{
	if (num_of_pids >= MAX_PID)
		return NULL;
	t_pid *pid = (t_pid *)malloc(sizeof(t_pid));
	if (pid == NULL)
		return NULL;
	
	pid->P = P;
	pid->I = I;
	pid->D = D;
	
	pid->derivative = 0;
	pid->integral = 0;
	pid->error = 0;
	pid->error_old = 0;
	pid->output = 0;
	pid->max_output = MAX_SPEED;
	pid->aim_output = 0;
	pid->motor = motor;
	
	pids[num_of_pids] = pid;
	num_of_pids++;
	pid->ticks_per_revolution = TICKS_PER_REVOLUTION;
	
	pid->pid_error_function = pid_error_function;

	return pid;
}


int		start_pid()
{
	signal(SIGALRM, pid_cycle);
	ualarm(5000, PID_UPDATE_INTERVAL);
	printf("Alarm set\n");
}

void	pid_cycle()
{
	for (int i = 0; i < 2; i++)
	{
		
		//pids[i]->error = pids[i]->aim_output - pids[i]->motor->encoder->value;
		pids[i]->error = pids[i]->aim_output - pids[i]->pid_error_function(pids[i]);
		
		pids[i]->integral += pids[i]->error;
		pids[i]->integral = max(min(pids[i]->integral, 1000), -1000);
		pids[i]->derivative = pids[i]->error - pids[i]->error_old;
		
		pids[i]->output = (int)(pids[i]->error * pids[i]->P + pids[i]->derivative * pids[i]->D + pids[i]->integral * pids[i]->I);
		
		pids[i]->output = max(min(pids[i]->output, pids[i]->max_output), -pids[i]->max_output);
		
		set_speed(pids[i]->motor, pids[i]->output);
		
		pids[i]->error_old = pids[i]->error;
		//printf("%d\n", pids[i]->output);
	}
}
