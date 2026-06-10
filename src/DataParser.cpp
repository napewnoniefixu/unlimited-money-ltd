#include "DataParser.hpp"
#include <nlohmann/json.hpp>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

using json = nlohmann::json;

StockData DataParser::parseJson(const std::string& jsonData) {
    StockData data;
    try {
        json j = json::parse(jsonData);
        
        if (!j.contains("chart") || !j["chart"].contains("result") || j["chart"]["result"].is_null()) {
            std::cerr << "Parser error: Invalid JSON format or no result found." << std::endl;
            return data;
        }

        auto result = j["chart"]["result"][0];
        
        if (!result.contains("timestamp") || !result.contains("indicators") || 
            !result["indicators"].contains("quote") || result["indicators"]["quote"].empty() ||
            !result["indicators"]["quote"][0].contains("close")) {

            std::cerr << "Parser error: Missing required data fields in JSON." << std::endl;
            return data;
        }

        data.prices.clear();
        data.dates.clear();
        
        auto& closeJ = result["indicators"]["quote"][0]["close"];
        auto& timeJ = result["timestamp"];
        
        for (size_t i = 0; i < timeJ.size() && i < closeJ.size(); ++i) {
            if (!closeJ[i].is_number() || !timeJ[i].is_number()) continue;
            
            double price = closeJ[i].get<double>();
            long ts = timeJ[i].get<long>();
            
            data.prices.push_back(price);
            
            auto t = static_cast<std::time_t>(ts);
            std::tm* tm_ptr = std::gmtime(&t);
            if (!tm_ptr) continue;
            std::stringstream ss;
            ss << std::put_time(tm_ptr, "%Y-%m-%d");
            data.dates.push_back(ss.str());
        }

    } catch (const json::exception& e) {
        std::cerr << "Parser error: " << e.what() << std::endl;
    }

    return data;
}
