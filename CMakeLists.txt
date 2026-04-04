cmake_minimum_required(VERSION 3.10)
project(DataStructures)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set build type
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Install path
if(NOT DEFINED CMAKE_INSTALL_PREFIX OR CMAKE_INSTALL_PREFIX STREQUAL "")
  set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/out/install/${CMAKE_BUILD_TYPE}" CACHE PATH "Install path")
endif()

# Add source files
file(GLOB SOURCES
    "${CMAKE_SOURCE_DIR}/*.cpp"
)

# Add executable
add_executable(DataStructures ${SOURCES} "02-SinglyLinkedList/SinglyLinkedList.h" "Sorting Algorthims/Sorting.h" "03-stack/stack.h" "common/Node.h" "DoublyLinkedList/DoublyLinkedList.h")

# Include current directory for headers
target_include_directories(DataStructures PRIVATE ${CMAKE_SOURCE_DIR})