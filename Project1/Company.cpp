#include "Company.h"
#include <list>

Company::Company()
{
	for (int i = 0; i < 100; i++) {
		Employee *currentEmployee = new Employee(i);
		employees.push_back(*currentEmployee);
	}

	employees[0].SetNewZombificationState(Employee::ZOMBIFIED);
}

int Company::zombieCount()
{
	int zombies = 0;

	for (int i = 0; i < employees.size(); i++) {
		if (employees[i].IsZombified()) {
			zombies++;
		}
	}
	return zombies;
}
