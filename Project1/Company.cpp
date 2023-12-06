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

int Company::ZombieCount()
{
	int zombies = 0;

	for (int i = 0; i < employees.size(); i++) {
		if (employees[i].IsZombified()) {
			zombies++;
		}
	}
	return zombies;
}

float Company::TotalDayCharge()
{
	float dayCharge = 0.0f;

	for (int i = 0; i < employees.size(); i++) {
		dayCharge += (employees[i].Cost() / 228.0f);
	}
	return dayCharge;
}

void Company::ModifyEmployee(Employee::State fromState, Employee::State toState, int quantity)
{
	for (int i = 0; i < quantity; i++) {
		int employeeIndex = -1;
		// Get the index of an employee with the corresponding state
		for (int i = 0; i < employees.size(); i++) {
			employeeIndex = i;
		}

		if (employeeIndex != -1) {
			if (employees[employeeIndex].state == fromState) employees[employeeIndex].SetNewZombificationState(toState); // State modification
			if (toState == Employee::INCUBATING) employees[employeeIndex].incubatingTime = 3; // Incubation time set if the employee is set to incubation
		}
	}
}
