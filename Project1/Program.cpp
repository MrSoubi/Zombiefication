#include "Company.h"
#include "Employee.h"

#include <time.h>
#include <iostream>
#include <limits>
#include <memory>


void Play() {
	std::unique_ptr<Company> player = std::make_unique<Company>();

	srand(time(NULL));
	int rnd = 0;
	int diceValue = 0;
	int day = 0;
	float totalCost = 0;
	std::string input = "";

	while (day < 28 && player->ZombieCount() < 100) {
		for (int i = 0; i < 100; i++) {
			rnd = rand() % 100;
			player->employees[i].HandleInfection(rnd, player->ZombieCount());
		}

		std::cout << "Day " << day << " | Risk : " << player->ZombieCount() << "%" << std::endl;
		day++;
		totalCost += player->TotalDayCharge();

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Waits for Enter

		diceValue = 2 + rand() % 5;
		diceValue += 2 + rand() % 5;

		std::cout << "Rolled a " << diceValue << "...";

		if (diceValue == 2) {
			// Do nothing
			std::cout << "Nothing happens !" << std::endl;
		}
		else if (diceValue < 7) {
			player->ModifyEmployee(Employee::SANE, Employee::INCUBATING);
			std::cout << "Paul might be infected..." << std::endl;
		}
		else if (diceValue < 12) {
			player->ModifyEmployee(Employee::SANE, Employee::INCUBATING, 2);
			std::cout << "Thomas and Jacques might be infected..." << std::endl;
		}
		else { // diceValue == 12
			player->ModifyEmployee(Employee::SANE, Employee::ZOMBIFIED, 3);
			std::cout << "Oh sh*t ! Philippe, Jean and Judas turned to zombies !" << std::endl;
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

void main() {

	Play();

}

