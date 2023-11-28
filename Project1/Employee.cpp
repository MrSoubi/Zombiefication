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
		}
		break;
	case INCUBATING:
		if (daysSinceInfection >= 2) {
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
