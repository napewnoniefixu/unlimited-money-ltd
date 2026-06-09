#include <iostream>
#include <CLI/CLI.hpp>
#include "Config.hpp"
#include "StockClient.hpp"
#include "DataParser.hpp"
#include "PlotRenderer.hpp"

int main(int argc, char** argv) {
    CLI::App app{"Stock Plotter Tool"};

    std::string symbol = "AAPL";
    int days = 30;
    std::string output = "plot.png";
    std::string configPath = "config.json";
    bool showPlot = false;

    app.add_option("-s,--symbol", symbol, "Stock symbol to fetch (e.g., AAPL)");
    app.add_option("-d,--days", days, "Number of days for historical data");
    app.add_option("-o,--output", output, "Output file name for the plot");
    app.add_option("-c,--config", configPath, "Path to config file");
    app.add_flag("--show", showPlot, "Keep the plot window open until closed manually");

    CLI11_PARSE(app, argc, argv);

    std::cout << "Starting Stock Plotter..." << std::endl;
    std::cout << "Symbol: " << symbol << ", Days: " << days << ", Output: " << output << std::endl;

    Config config(configPath);

    StockClient client;
    std::string rawData = client.fetchStockData(symbol, days);
    
    if (rawData.empty()) {
        std::cerr << "Failed to fetch data. Exiting." << std::endl;
        return 1;
    }

    DataParser parser;
    StockData stockData = parser.parseJson(rawData);
    
    if (stockData.prices.empty()) {
        std::cerr << "Failed to parse data or no data available. Exiting." << std::endl;
        return 1;
    }

    PlotRenderer renderer;
    renderer.renderPlot(stockData, symbol, output, showPlot);

    std::cout << "Process completed successfully." << std::endl;

    return 0;
}
