# Set the minimum version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(MyProject VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Find all .cpp files in the src directory
file(GLOB SRC_FILES src/*.cpp)

# Add executable
add_executable(my_executable ${SRC_FILES} main.cpp)

# Optionally, you can specify additional compile options
target_compile_options(my_executable PRIVATE -Wall -Wextra)

# Link libraries (if any)
# target_link_libraries(my_executable some_library)
