#include "main.h"

int num_of_pids = 0;

t_pid*	setup_pid(double P, double I, double D, t_motor *motor)
{
	if (num_of_pids >= MAX_PID)
		return NULL;
	t_pid *pid = (t_pid *)malloc(sizeof(t_pid));
	
	pid->P = P;
	pid->I = I;
	pid->D = D;
	
	pid->derivative = 0;
	pid->integral = 0;
	pid->error = 0;
	pid->error_old = 0;
	pid->output = 0;
	pid->max_output = 75;
	pid->aim_output = 0;
	pid->motor = motor;
	
	pids[num_of_pids] = pid;
	num_of_pids++;

	return pid;
}


int		start_pid()
{
	signal(SIGALRM, pid_cycle);
	ualarm(5000, 10000);
	printf("Alarm set\n");
}

void	pid_cycle()
{
	t_pid *pid_pointer = *pids;
	//for (; pid_pointer < pid_pointer + MAX_PID; pid_pointer++){
		
		pid_pointer->error = pid_pointer->aim_output - pid_pointer->motor->encoder->value;
		
		pid_pointer->integral += pid_pointer->error;
		pid_pointer->integral = max(min(pid_pointer->integral, 1000), -1000);
		pid_pointer->derivative = pid_pointer->error - pid_pointer->error_old;
		
		pid_pointer->output = (int)(pid_pointer->error * pid_pointer->P + pid_pointer->derivative * pid_pointer->D + pid_pointer->integral * pid_pointer->I);
		
		pid_pointer->output = -max(min(pid_pointer->output, pid_pointer->max_output), -pid_pointer->max_output);
		
		set_speed(pid_pointer->motor, pid_pointer->output);
		
		pid_pointer->error_old = pid_pointer->error;
	//}
}
