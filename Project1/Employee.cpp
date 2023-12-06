#include "Employee.h"

Employee::Employee(int id)
{
	this->id = id;
	this->state = SANE;
	this->daysSinceInfection = 0;
}

bool Employee::IsZombified()
{
	return this->state == ZOMBIFIED;
}

void Employee::HandleInfection(int rnd, int zombieCount)
{
	switch (this->state) {
	case SANE:
		if (rnd <= zombieCount) {
			SetNewZombificationState(INCUBATING);
			incubatingTime = 2 + rnd % 3; // 'rnd' is an int between 0 and 100, so I re-use to get a random incubating time. 
		}
		break;
	case INCUBATING:
		if (daysSinceInfection >= incubatingTime) {
			SetNewZombificationState(ZOMBIFIED);
		}
		else {
			daysSinceInfection++;
		}
		break;
	case ZOMBIFIED:
		// Do nothing
		break;
	}
}

void Employee::SetNewZombificationState(State s)
{
	this->state = s;
}

float Employee::Cost()
{
	if (this->state == SANE || this->state == INCUBATING) {
		return 26000.0f;
	}
	else {
		return 45000.0f;
	}
}
