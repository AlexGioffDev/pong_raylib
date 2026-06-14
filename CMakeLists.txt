cmake_minimum_required(VERSION 3.10)
project(mio_progetto CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(raylib REQUIRED)

# Raccoglie tutti i .cpp dentro library/
file(GLOB LIBRARY_SOURCES "${CMAKE_SOURCE_DIR}/src/library/*.cpp")

add_executable(mio_progetto
    src/main.cpp
    ${LIBRARY_SOURCES}
)

target_include_directories(mio_progetto PRIVATE
    ${CMAKE_SOURCE_DIR}/src/library
)

target_link_libraries(mio_progetto raylib)