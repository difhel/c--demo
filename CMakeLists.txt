cmake_minimum_required(VERSION 3.21)
project(ModuleProject CXX)

# Set C++23 standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Force using Homebrew Clang compiler and its stdlib
set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/bin/clang++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -nostdinc++ -I/opt/homebrew/opt/llvm/include/c++/v1")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L/opt/homebrew/opt/llvm/lib/c++ -Wl,-rpath,/opt/homebrew/opt/llvm/lib/c++")

# Use Homebrew's stdlib
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")

# Use Homebrew's include path
include_directories(SYSTEM "/opt/homebrew/opt/llvm/include")
link_directories("/opt/homebrew/opt/llvm/lib")

# Ensure we're using Ninja generator
if(NOT CMAKE_GENERATOR MATCHES "Ninja")
    message(FATAL_ERROR "You must use Ninja generator for C++ modules support. Please run cmake with -G Ninja")
endif()

# Enable modules support for Clang
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmodules -fbuiltin-module-map -fprebuilt-module-path=${CMAKE_BINARY_DIR}/modules")

# Collect all source files
file(GLOB_RECURSE SOURCES 
    "src/*.cpp"
    "src/*.cppm"
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Create modules directory
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/modules)

# Set module output directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_MODULE_BMI_DIRECTORY "${CMAKE_BINARY_DIR}/modules"
)
