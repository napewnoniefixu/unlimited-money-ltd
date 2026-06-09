#pragma once
#include "DataParser.hpp"
#include <string>

class PlotRenderer {
public:
    void renderPlot(const StockData& data, const std::string& symbol, const std::string& outputPath, bool showPlot = false);
};
