#include <iostream>
#include "SpaceShuttle.h"

int main()
{
	SpaceShuttle test;
	std::ifstream file("weather.csv");
	test.getInfoFromFile(file);
	for (auto f : test.day) {
		std::cout << f << " ";
	}
	std::cout << std::endl;
	for (auto f : test.temperature) {
		std::cout << f << " ";
	}
}

