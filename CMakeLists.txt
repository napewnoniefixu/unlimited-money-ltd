cmake_minimum_required(VERSION 3.15)
project(stock_plotter VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# CPR (C++ Requests)
FetchContent_Declare(
    cpr
    GIT_REPOSITORY https://github.com/libcpr/cpr.git
    GIT_TAG 1.10.x # Or a specific version
)
FetchContent_MakeAvailable(cpr)

# nlohmann/json
FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.2
)
FetchContent_MakeAvailable(json)

# matplotplusplus
set(MATPLOTPP_BUILD_WITH_PEDANTIC_WARNINGS OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
    matplotplusplus
    GIT_REPOSITORY https://github.com/alandefreitas/matplotplusplus
    GIT_TAG origin/master
)
FetchContent_MakeAvailable(matplotplusplus)

# CLI11
FetchContent_Declare(
    cli11
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.3.2
)
FetchContent_MakeAvailable(cli11)

# Main Executable
add_executable(stock_plotter
    src/main.cpp
    src/Config.cpp
    src/StockClient.cpp
    src/DataParser.cpp
    src/PlotRenderer.cpp
)

target_include_directories(stock_plotter PRIVATE include)

target_link_libraries(stock_plotter
    PRIVATE
    cpr::cpr
    nlohmann_json::nlohmann_json
    Matplot++::matplot++
    CLI11::CLI11
)
