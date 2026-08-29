cmake_minimum_required(VERSION 4.3.1)
project(cpp-oop-review LANGUAGES CXX)

if (CMAKE_VERSION VERSION_LESS "4.3.1")
    message(FATAL_ERROR "CMake version 4.3.1 or higher is required.")
endif ()

include(CheckCXXSourceCompiles)
set(CMAKE_REQUIRED_FLAGS "{CMAKE_REQUIRED_FLAGS} -std=c++26")
check_cxx_source_compiles("int main() { return 0; }" CXX26_SUPPORTED)
if (NOT CXX26_SUPPORTED)
    message(FATAL_ERROR "C++26 is not supported by the compiler.")
endif ()

# Source files
set(SOURCES
    main.cpp)

# Define the executable target
add_executable(cpp-opp-review ${SOURCES})

set_target_properties(cpp-oop-review PROPERTIES
    CXX_STANDARD 26
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF)

target_include_directories(cpp-opp-review PRIVATE ${PROJECT_SOURCE_DIR}/include)

add_custom_target(valide-upgrade
COMMAND ${CMAKE_COMMAND} -E echo "Validated toolchain: CMake ${CMAKE_VERSION} / ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION} / C++26"
VERBATIM)


set(CMAKE_CXX_STANDARD 26)

add_executable(cpp-oop-review main.cpp)
