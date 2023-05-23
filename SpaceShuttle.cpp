#include "SpaceShuttle.h"

size_t SpaceShuttle::stringToNum(std::string str)
{

    std::stringstream sstream(str);
    size_t result;
    sstream >> result;
    return result;

}
std::vector<double> SpaceShuttle::calculate(std::vector<size_t> values) {
    std::vector<double> res;
    double avTemp = 0;
    int maxTemp = INT_MIN;
    int minTemp = INT_MAX;

    for (auto& el : values) {
        if (el < minTemp)
            minTemp = el;
        if (int(el) > maxTemp)
            maxTemp = el;
        avTemp += el;
    }
    avTemp /= best.size();

    double med = getMedian(values);
    res.push_back(maxTemp);
    res.push_back(minTemp);
    res.push_back(avTemp);
    res.push_back(med);
    return res;
}
void SpaceShuttle::getBestData() const
{
}
void SpaceShuttle::writeToFile() {
    std::ofstream ofs("WeatherReport.csv");
    std::vector<size_t> bestTemp;
    std::vector<size_t> bestWind;
    std::vector<size_t> bestHumidity;
    for (auto& t : best) {
        bestTemp.push_back(temperature[t]);
        bestWind.push_back(wind[t]);
        bestHumidity.push_back(humidity[t]);
    }
    std::vector<double> tempData = calculate(bestTemp);
    std::vector<double> windData = calculate(bestWind);
    std::vector<double> humidityData = calculate(bestHumidity);
    ofs << "Parameter," << "Max value," << "Min value," << "Average," << "Median," << std::endl;
     ofs << "Temperature(C)," << tempData[0] << "," << tempData[1] << "," << tempData[2] << "," << tempData[3] << std::endl;
     ofs << "Wind(m/s)," << windData[0] << "," << windData[1] << "," << windData[2] << "," << windData[3] << std::endl;
     ofs << "Humidity(%)," << humidityData[0] << "," << humidityData[1] << "," << humidityData[2] << "," << humidityData[3] << std::endl;
     ofs << "Precipitation(%)," << "0," << "0," << "0," << "0," << std::endl;
     ofs << "Lightning," << "-," << "-," << "-," << "-," << std::endl;
     ofs << "Clouds," << "-," << "-," << "-," << "-," << std::endl;
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
                lightning.push_back(t);
        }
        else if (counter == 6) {
            counter++;
            for (const auto& t : tokens)
                clouds.push_back(t);
        }
    }
}


double SpaceShuttle::getMedian(std::vector<size_t> nums)
{
    std::priority_queue<size_t> left;
    std::priority_queue <size_t, std::vector<size_t>, std::greater<size_t>> right;
    std::vector<double> results;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (!right.empty() && nums[i] > right.top())
            right.push(nums[i]);
        else
            left.push(nums[i]);
        size_t leftSize = left.size();
        size_t rightSize = right.size();
        int check = leftSize - rightSize;
        if (check > 1)
        {
            right.push(left.top());
            left.pop();
        }
        else if (check != 0 && check < 1) {
            left.push(right.top());
            right.pop();
        }

    }
    if (left.size() > right.size())
        return (double(left.top()));
    else if (left.size() < right.size())
        return (double(right.top()));
    else
        return ((double(left.top()) + double(right.top())) / 2.0);
}

void SpaceShuttle::getBestData()
{
    size_t vecSize = day.size();
    for (size_t i = 2; i < vecSize; ++i) {
        if (2 <= temperature[i] && temperature[i] <= 31 && wind[i] <= 10 && humidity[i] < 60 && precipitation[i] == 0 && lightning[i] == "No" && clouds[i] != "Cumulus" && clouds[i] != "Nimbus")
        {
            best.push_back(i);
        }
    }
    std::cout << "Best launch day is" << best[0];
}
