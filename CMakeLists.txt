cmake_minimum_required(VERSION 3.5)
project(enumerate_package)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# arenasdk find file dir
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(arena_sdk REQUIRED)

set(target_name enumerate)

add_executable(${target_name} src/enumerate.cpp)
ament_target_dependencies(
  ${target_name}
  rclcpp
  arena_sdk
)

install(TARGETS
  ${target_name}
  DESTINATION lib/${PROJECT_NAME}
)


ament_package()
