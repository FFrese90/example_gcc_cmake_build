################################################################################
# CMake Projekt
################################################################################

# set test name
set(PROJECT_NAME Test_Project)

# Project Setup
cmake_minimum_required(VERSION 3.10)
project(${PROJECT_NAME})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../abs")

# Setup Language
set(CMAKE_C_STANDARD 99)
set(CMAKE_VERBOSE_MAKEFILE ON) # debug output from makefiles

# Setup Debug Symbols
#set(CMAKE_BUILD_TYPE Debug)

# Add Defines
add_definitions(-DCMAKE_TEST_DEFINE)

# Include Directories
include_directories(modul)

# Subdirectories
##add_subdirectory(none)

# set test sources
file(GLOB PROJECT_SOURCES
  modul/*.c
  system/*.c
)


# Main
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

# Link Libs
#target_link_libraries (${PROJECT_NAME} none)