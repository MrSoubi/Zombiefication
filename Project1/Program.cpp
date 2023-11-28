#include "Company.h"
#include <time.h>
#include <iostream>

void main() {
	Company *player = new Company();

	srand(time(NULL));
	int rnd = 0;

	int day = 0;

	while (day < 28 && player->zombieCount() < 100) {
		for (int i = 0; i < 100; i++) {
			rnd = rand() % 100;
			player->employees[i].HandleInfection(rnd, player->zombieCount());
		}
		std::cout << "Day " << day << " | Risk : " << player->zombieCount() << "%" << std::endl;
		day++;
	}
}