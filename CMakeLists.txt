cmake_minimum_required(VERSION 3.28)
project(Verbeal LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)

# Fetch nlohmann/json
FetchContent_Declare(nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.3
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL)
FetchContent_MakeAvailable(nlohmann_json)

# Fetch SFML
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

# Fetch spdlog
FetchContent_Declare(spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.12.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL)
FetchContent_MakeAvailable(spdlog)

add_executable(Verbeal src/main.cpp)
target_compile_features(Verbeal PRIVATE cxx_std_17)
target_link_libraries(Verbeal PRIVATE SFML::Graphics spdlog::spdlog)
target_include_directories(Verbeal PRIVATE ${nlohmann_json_SOURCE_DIR}/include)
