#include "Config.hpp"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

Config::Config(const std::string& configPath) {
    std::ifstream f(configPath);
    if (f.is_open()) {
        try {
            json data = json::parse(f);
            if (data.contains("api_key")) {
                apiKey = data["api_key"];
            }
        } catch (const json::parse_error& e) {
            std::cerr << "Config error: Could not parse config file " << configPath << ". " << e.what() << std::endl;
        }
    } else {
        std::cerr << "Config warning: Could not open config file " << configPath << ". Using empty API key." << std::endl;
    }
}

std::string Config::getApiKey() const {
    return apiKey;
}
