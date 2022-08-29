project(CoreGame CXX)
set(targetname "CoreGame")
add_library(
    ${targetname} SHARED
    src/GodotLibrary.cpp
    include/Controller.h
    src/Controller.cpp
)

target_link_libraries(CoreGame PUBLIC godot-cpp)

message(STATUS "Build dir: ${BUILD_DIR}")
set_target_properties(CoreGame PROPERTIES LIBRARY_OUTPUT_DIRECTORY_DEBUG "${BUILD_DIR}/")
set_target_properties(CoreGame PROPERTIES LIBRARY_OUTPUT_DIRECTORY_RELEASE "${BUILD_DIR}/")

target_include_directories(
    ${targetname} PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)