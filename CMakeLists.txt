cmake_minimum_required(VERSION 4.3.1)

project(cpp-oop-review LANGUAGES CXX)

# Require CMake 4.3.1 or newer
if (CMAKE_VERSION VERSION_LESS "4.3.1")
    message(FATAL_ERROR "CMake version 4.3.1 or higher is required.")
endif()

# Source files
set(SOURCES
        main.cpp
)

# Define the executable target
add_executable(cpp-oop-review ${SOURCES})

# Require C++26
set_target_properties(cpp-oop-review PROPERTIES
        CXX_STANDARD 26
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
)

# Include directory
target_include_directories(cpp-oop-review PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

# Toolchain validation target
add_custom_target(validate-upgrade
        COMMAND ${CMAKE_COMMAND} -E echo
        "Validated toolchain: CMake ${CMAKE_VERSION} / ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION} / C++26"
        VERBATIM
)