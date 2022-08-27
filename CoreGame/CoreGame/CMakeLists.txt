project(CoreGame CXX)

add_library(
    CoreGame SHARED
    src/GodotLibrary.cpp
    include/Controller.h
    src/Controller.cpp
)

target_link_libraries(CoreGame PUBLIC godot-cpp)

target_include_directories(
    CoreGame PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)