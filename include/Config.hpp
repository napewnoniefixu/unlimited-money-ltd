#pragma once
#include <string>

class Config {
public:
    Config(const std::string& configPath);
    [[nodiscard]] std::string getApiKey() const;

private:
    std::string apiKey;
};
