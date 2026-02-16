cmake_minimum_required(VERSION 3.15)
project(clst-mdl-st-citadel VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find dependencies
find_package(inferos-utils REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)
find_package(PkgConfig REQUIRED)
pkg_check_modules(SODIUM REQUIRED libsodium)
find_package(spdlog REQUIRED)

# Source files
add_executable(citadel
    src/main.cpp
)

# Link libraries
target_link_libraries(citadel PRIVATE
    inferos::utils
    Boost::system
    ${SODIUM_LIBRARIES}
    spdlog::spdlog
)

# Compiler options
target_compile_options(citadel PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    $<$<CONFIG:Debug>:-g>
    $<$<CONFIG:Release>:-O3>
)
