#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>



namespace globalConstants {
	const size_t DAYS_COUNT = 16;
}

class SpaceShuttle
{
public:
	std::vector<size_t> day{ globalConstants::DAYS_COUNT };
	std::vector<size_t> temperature{ globalConstants::DAYS_COUNT };
	std::vector<size_t> wind{ globalConstants::DAYS_COUNT };
	std::vector<size_t> humidity{ globalConstants::DAYS_COUNT };
	std::vector<size_t> precipitation{ globalConstants::DAYS_COUNT };
	std::vector<size_t> lightning{ globalConstants::DAYS_COUNT };
	std::vector<std::string> clouds{ globalConstants::DAYS_COUNT };

	size_t stringToNum(std::string str);
	SpaceShuttle() = default;
	void getInfoFromFile(std::ifstream& file);
	void writeToFile(const char* fileName);
};

