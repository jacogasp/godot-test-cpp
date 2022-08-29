cmake_minimum_required(VERSION 3.16.3)
project(CoreGame)

set(CMAKE_CXX_STANDARD 17)

set(ARCH "x64")
set(DEFAULT_BUILD_TYPE "Debug")

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${DEFAULT_BUILD_TYPE}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${DEFAULT_BUILD_TYPE}")
endif()

if (APPLE)
  set(PLATFORM "macOS")
elseif(UNIX AND NOT APPLE)
  set(PLATFORM "Linux")
elseif(MSVC)
  set(PLATFORM "Windows")
endif()

if (MSVC)
  set(BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}\\dist\\${PLATFORM}\\${ARCH}\\${CMAKE_BUILD_TYPE}")
else()
  set(BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dist/${PLATFORM}/${ARCH}/${CMAKE_BUILD_TYPE}")
endif()

add_subdirectory(godot-cpp)
add_subdirectory(CoreGame)