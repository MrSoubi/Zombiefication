#pragma once

#include <vector>
#include "Employee.h"

class Company
{
public:
	std::vector<Employee> employees;
	Company();

	int zombieCount();
};

