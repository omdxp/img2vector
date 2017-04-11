cmake_minimum_required(VERSION 3.0)
project(openann)

set(CMAKE_BUILD_TYPE          Debug)
set(CMAKE_CXX_FLAGS           "${CMAKE_CXX_FLAGS} -std=c++14")

find_package(OpenCV REQUIRED)

# main app
add_executable(
  img2vector
  main.cpp
)

target_link_libraries(img2vector ${OpenCV_LIBS})

install(TARGETS img2vector RUNTIME DESTINATION bin) 
