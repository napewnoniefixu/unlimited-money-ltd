#include "StockClient.hpp"
#include <cpr/cpr.h>
#include <chrono>
#include <iostream>

StockClient::StockClient() {}

std::string StockClient::fetchStockData(const std::string& symbol, int days) {
    auto now = std::chrono::system_clock::now();
    auto end_time = std::chrono::system_clock::to_time_t(now);
    auto start_time = std::chrono::system_clock::to_time_t(now - std::chrono::hours(24 * days));

    std::string url = "https://query1.finance.yahoo.com/v8/finance/chart/" + symbol;

    cpr::Response r = cpr::Get(cpr::Url{url},
                               cpr::Parameters{{"period1", std::to_string(start_time)},
                                               {"period2", std::to_string(end_time)},
                                               {"interval", "1d"}},
                               cpr::Header{{"User-Agent", "Mozilla/5.0"}});

    if (r.status_code == 200) {
        return r.text;
    } else {
        std::cerr << "Error fetching data for " << symbol << ": " << r.status_code << " - " << r.error.message << std::endl;
        return "";
    }
}
