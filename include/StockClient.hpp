#pragma once
#include <string>

class StockClient {
public:
    StockClient();
    std::string fetchStockData(const std::string& symbol, int days);
};
