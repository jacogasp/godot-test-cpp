cmake_minimum_required(VERSION 3.17)
project(CoreGame)

set(ARCHITECTURE "x64")
set(default_build_type "Debug")

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${default_build_type}")
endif()

set(default_build_dir "${CMAKE_CURRENT_SOURCE_DIR}/${CMAKE_BUILD_TYPE}")
set(default_runtime_output_dir "${default_build_dir}/${ARCHITECTURE}")

set (CMAKE_BUILD_DIRECTORY "${default_build_dir}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${default_runtime_output_dir}")
message(STATUS "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
set(CMAKE_CXX_STANDARD 17) # Feel free to use whatever standard you want

add_subdirectory(godot-cpp)
add_subdirectory(CoreGame)