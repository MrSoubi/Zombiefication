#pragma once

class Employee
{
public:
	enum State {
		SANE, INCUBATING, ZOMBIFIED
	};

	int id;

	Employee(int id);

	bool IsZombified();
	void HandleInfection(int rnd, int zombieCount);
	void SetNewZombificationState(State s);

private:
	int daysSinceInfection;
	State state;
};

