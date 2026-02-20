cmake_minimum_required(VERSION 3.10)
project(DataStructures)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set build type
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Add source files
file(GLOB SOURCES
    "${CMAKE_SOURCE_DIR}/*.cpp"
)

# Add executable
add_executable(DataStructures ${SOURCES} "02-SinglyLinkedList/SinglyLinkedList.h" "Sorting Algorthims/Sorting.h")

# Include current directory for headers
target_include_directories(DataStructures PRIVATE ${CMAKE_SOURCE_DIR})