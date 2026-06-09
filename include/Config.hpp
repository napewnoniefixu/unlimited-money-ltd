#pragma once
#include <string>

class Config {
public:
    Config(const std::string& configPath);
    std::string getApiKey() const;

private:
    std::string apiKey;
};
