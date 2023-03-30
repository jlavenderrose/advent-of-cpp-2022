# The MiniCppStarter
#
# Build and run by calling: 
# cmake -S. -Bbuild && cmake --build build && ./build/Playground

cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

# ---- Project ----

project(Advent-Of-Code-2022 LANGUAGES CXX)

# ---- Fetch CPM ----

set(CPM_DOWNLOAD_VERSION 0.32.0) 
set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
  message(STATUS "Downloading CPM.cmake v${CPM_DOWNLOAD_VERSION}")
  file(DOWNLOAD https://github.com/cpm-cmake/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake ${CPM_DOWNLOAD_LOCATION})
endif()
include(${CPM_DOWNLOAD_LOCATION})

# ---- Add dependencies via CPM ----
# See https://github.com/TheLartians/CPM.cmake for details and examples

# the ModernCppStarter defines an example project called 'Greeter'
# CPMAddPackage("gh:TheLartians/ModernCppStarter@0.17.2")

# ---- Create executable ----

# add your source files here
add_executable(aoc22 src/main.cpp)
# link to your dependencies' targets here
# target_link_libraries(Playground Greeter::Greeter)
# setup your target's properties
set_target_properties(aoc22 PROPERTIES CXX_STANDARD 17)