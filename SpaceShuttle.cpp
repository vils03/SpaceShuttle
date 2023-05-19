#include "SpaceShuttle.h"

size_t SpaceShuttle::stringToNum(std::string str)
{

    std::stringstream sstream(str);
    size_t result;
    sstream >> result;
    return result;

}

void SpaceShuttle::getInfoFromFile(std::ifstream& file)
{
    size_t counter = 0;
    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> tokens;
        std::stringstream ss(line);
        std::string token;

        while (std::getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (counter == 0) {
            counter++;
            for (const auto& t : tokens)
                day.push_back(stringToNum(t));
        }
        else if (counter == 1) {
            counter++;
            for (const auto& t : tokens)
                temperature.push_back(stringToNum(t));
        }
        else if (counter == 2) {
            counter++;
            for (const auto& t : tokens)
                wind.push_back(stringToNum(t));
        }
        else if (counter == 3) {
            counter++;
            for (const auto& t : tokens)
                humidity.push_back(stringToNum(t));
        }
        else if (counter == 4) {
            counter++;
            for (const auto& t : tokens)
                precipitation.push_back(stringToNum(t));
        }
        else if (counter == 5) {
            counter++;
            for (const auto& t : tokens)
                lightning.push_back(stringToNum(t));
        }
        else if (counter == 6) {
            counter++;
            for (const auto& t : tokens)
                clouds.push_back(t);
        }
    }
}