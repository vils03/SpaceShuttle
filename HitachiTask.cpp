
#include "SpaceShuttle.h"

int main()
{
	std::cout << "Weather conditions for SPACE shuttle launch" << std::endl;
	std::cout << "Enter file name: ";
	std::string fileName;
	std::cin >> fileName;
	std::ifstream file(fileName);
	if (!file.is_open())
		throw std::exception("Error opening file!");
	SpaceShuttle test;
	test.getInfoFromFile(file);
	test.getBestData();
	test.writeToFile();
	
}

