#include "Company.h"
#include "Employee.h"

#include <time.h>
#include <iostream>

void main() {
	Company *player = new Company();

	srand(time(NULL));
	int rnd = 0;
	int diceValue = 0;
	int day = 0;
	float totalCost = 0;

	while (day < 28 && player->ZombieCount() < 100) {
		for (int i = 0; i < 100; i++) {
			rnd = rand() % 100;
			player->employees[i].HandleInfection(rnd, player->ZombieCount());
		}
		std::cout << "Day " << day << " | Risk : " << player->ZombieCount() << "%" << std::endl;
		day++;
		totalCost += player->TotalDayCharge();

		diceValue = rand() % 5;
		diceValue += rand() % 5;

		if (diceValue == 2) {
			// Do nothing
		}
		else if (diceValue < 7) {
			player->ModifyEmployee(Employee::SANE, Employee::INCUBATING);
		}
		else if (diceValue < 12) {
			player->ModifyEmployee(Employee::SANE, Employee::INCUBATING, 2);
		}
		else { // diceValue == 12
			player->ModifyEmployee(Employee::SANE, Employee::ZOMBIFIED, 4);
		}
	}

	// Add some space before final assertion
	std::cout << std::endl << std::endl;


	// All employees are infected
	if (player->ZombieCount() == player->employees.size()) {
		std::cout << "ZOMBIPOCALYPSE IS HERE" << std::endl;
	}
	else { // Not all employees are infected
		std::cout << "It cas just a cold." << std::endl;
	}
	std::cout << "Total cost : " << totalCost << std::endl;
}