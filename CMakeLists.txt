#[[
    @file CMakeLists.txt
    @brief CMake configuration for the cpp-oop-review project.
    @author IoT Solution Development Team
    @date 2026-09-01
    @version 0.1.0
    @license MIT License

    This file sets up the CMake build system for the cpp-oop-review project, ensuring compatibility with CMake
    version 4.3.1 and C++26. It defines the project structure, source files, and compiler settings.
]]

# Minimum required CMake version for the upgraded baseline
cmake_minimum_required(VERSION 4.3.1)

# Project name and language
project(cpp-oop-review LANGUAGES CXX)

# CMake version check
if (CMAKE_VERSION VERSION_LESS "4.3.1")
    message(FATAL_ERROR "CMake version 4.3.1 or higher is required.")
endif()

# Compiler version check and C++26 support check
include(CheckCXXSourceCompiles)
set(CMAKE_REQUIRED_FLAGS "{CMAKE_REQUIRED_FLAGS} -std=c++26")
check_cxx_source_compiles("int main() { return 0; }" CXX26_SUPPORTED)
if(NOT CXX26_SUPPORTED)
    message(FATAL_ERROR "C++26 is not supported by the compiler.")
endif()


# Source files
set(SOURCES
        main.cpp
        src/Resource.cpp)

# Define the executable target
add_executable(cpp-oop-review ${SOURCES})

# Keep language settings and include paths target-scoped
set_target_properties(cpp-oop-review PROPERTIES
        CXX_STANDARD 26
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF)

target_include_directories(cpp-oop-review PRIVATE ${PROJECT_SOURCE_DIR}/include)

add_custom_target(validate-upgrade
        COMMAND ${CMAKE_COMMAND} -E echo "Validated toolchain: CMake ${CMAKE_VERSION} / ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION} / C++26"
        VERBATIM)