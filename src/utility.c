#include "main.h"

void exithandle(int sig)
{
	if (robot != NULL && robot->motorL != NULL && robot->motorR != NULL)
	{
		set_speed(robot->motorR, 0);
		set_speed(robot->motorL, 0);
		delay(3000);
		printf("Motor shutdown\n");
	}
	printf("Exiting...\n");
	exit(0);
}

t_robot *setup_robot(struct encoder *eR, struct encoder *eL, t_motor *mR, t_motor *mL)
{
		t_robot *r = (t_robot *)malloc(sizeof(t_robot));
		r->encoderL = eL;
		r->encoderR = eR;
		r->motorL = mL;
		r->motorR = mR;
		return r;
}
