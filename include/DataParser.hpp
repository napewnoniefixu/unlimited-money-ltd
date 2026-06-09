#pragma once
#include <string>
#include <vector>

struct StockData {
    std::vector<double> prices;
    std::vector<std::string> dates;
};

class DataParser {
public:
    StockData parseJson(const std::string& jsonData);
};
