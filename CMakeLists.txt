cmake_minimum_required(VERSION 3.28)
project(Verbeal LANGUAGES CXX VERSION 0.1.0.0 DESCRIPTION "Roguelike Word Game" HOMEPAGE_URL "verbeal.com")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Versioning
configure_file("BuildConfig.h.in" "BuildConfig.h")

# Fetch Dependencies
include(FetchContent)

## Fetch spdlog
FetchContent_Declare(spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.12.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL)
FetchContent_MakeAvailable(spdlog)

## Fetch nlohmann/json
FetchContent_Declare(nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.3
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL)
FetchContent_MakeAvailable(nlohmann_json)

## Fetch SFML
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

## Fetch ImGui
FetchContent_Declare(ImGui
    GIT_REPOSITORY https://github.com/ocornut/imgui
    GIT_TAG v1.91.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(ImGui)
FetchContent_GetProperties(ImGui SOURCE_DIR IMGUI_DIR)
set(IMGUI_SFML_FIND_SFML OFF)
FetchContent_Declare(ImGui-SFML
    GIT_REPOSITORY https://github.com/SFML/imgui-sfml
    GIT_TAG v3.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(ImGui-SFML)

# Compiler and Linker
add_executable(Verbeal "src/main.cpp" "src/Application.cpp" "src/Resource.rc" "src/io/SpecialPaths.cpp" "src/io/windows/SpecialFolders.cpp")
target_compile_features(Verbeal PRIVATE cxx_std_17)
target_link_libraries(Verbeal PRIVATE SFML::Graphics spdlog::spdlog ImGui-SFML::ImGui-SFML)
target_include_directories(Verbeal PRIVATE ${PROJECT_BINARY_DIR} ${nlohmann_json_SOURCE_DIR}/include)
