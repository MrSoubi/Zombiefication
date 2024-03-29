#pragma once

#include <vector>
#include "Employee.h"
#include <memory>

class Company
{
public:
	std::vector<Employee> employees;
	Company();

	int ZombieCount();
	float TotalDayCharge();
	void ModifyEmployee(Employee::State fromState, Employee::State toState, int quantity = 1);
};

