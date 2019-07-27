cmake_minimum_required(VERSION 2.6)
project(GeometryElements3D)

set(CMAKE_BUILD_TYPE "Release")

set(INC_DIR ${PROJECT_SOURCE_DIR}/include)
include_directories(${INC_DIR})
set(INC ${INC_DIR}/BasicElements.h
	${INC_DIR}/Geometry3D.h
	${INC_DIR}/Shape3D.h
	${INC_DIR}/Vector3D.h)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(SRC ${SRC_DIR}/BasicElements.cpp
	${SRC_DIR}/Shape3D.cpp
	${SRC_DIR}/Vector3D.cpp)

add_library(Geometry3D SHARED ${INC} ${SRC})

add_executable(Demo Demo.cpp)

target_link_libraries(Demo Geometry3D)
