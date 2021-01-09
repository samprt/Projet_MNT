cmake_minimum_required(VERSION 2.6)
project(main)

set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "-std=c++11")
#set(CMAKE_MODULE_PATH "/usr/bin")


file(
	GLOB_RECURSE
	source_files
	src/*.cpp
)

add_executable(
	create_raster
	${source_files}
)

