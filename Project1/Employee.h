#pragma once

class Employee
{
public:
	enum State {
		SANE, INCUBATING, ZOMBIFIED
	};

	int id;
	int incubatingTime;

	Employee(int id);

	bool IsZombified();
	void HandleInfection(int rnd, int zombieCount);
	void SetNewZombificationState(State s);
	float Cost();
	State state;
private:
	int daysSinceInfection;
};

