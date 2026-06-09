#include "PlotRenderer.hpp"
#include <matplot/matplot.h>
#include <iostream>
#include <vector>
#include <numeric>

void PlotRenderer::renderPlot(const StockData& data, const std::string& symbol, const std::string& outputPath, bool showPlot) {
    if (data.prices.empty()) {
        std::cerr << "Renderer error: No data to plot for " << symbol << std::endl;
        return;
    }

    using namespace matplot;

    auto plt = plot(data.prices);
    plt->line_width(2);
    
    title("Stock Price for " + symbol);
    xlabel("Date");
    ylabel("Price (USD)");

    // Handle X-axis labels (dates)
    if (data.dates.size() > 1) {
        std::vector<double> ticks;
        std::vector<std::string> labels;
        
        size_t n = data.dates.size();
        size_t num_ticks = 5; // We want roughly 5 labels
        if (n < num_ticks) num_ticks = n;

        for (size_t i = 0; i < num_ticks; ++i) {
            size_t idx = i * (n - 1) / (num_ticks - 1);
            ticks.push_back(idx + 1); // matplot++ uses 1-based indexing for plot(y)
            labels.push_back(data.dates[idx]);
        }
        
        xticks(ticks);
        xticklabels(labels);
    }

    grid(on);
    save(outputPath);
    std::cout << "Plot saved to: " << outputPath << std::endl;

    if (showPlot) {
        std::cout << "Displaying plot... Close the window to exit." << std::endl;
        show();
    }
}
