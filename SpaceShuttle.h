#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
class SpaceShuttle
{

	std::vector<size_t> day;
	std::vector<size_t> temperature;
	std::vector<size_t> wind;
	std::vector<size_t> humidity;
	std::vector<size_t> precipitation;
	std::vector<std::string> lightning;
	std::vector<std::string> clouds;
	
	std::vector<size_t> best;
	size_t stringToNum(std::string str);
public:
	SpaceShuttle() = default;
	void getInfoFromFile(std::ifstream& file);
	void getBestData();
	void writeToFile();
	std::vector<double> calculate(std::vector<size_t>);
	double getMedian(std::vector<size_t>);
};

