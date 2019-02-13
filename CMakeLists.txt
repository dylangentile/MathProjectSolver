cmake_minimum_required(VERSION 3.13)
project(genius)
#set(EXECUTABLE_OUTPUT_PATH ~/etc/etc/usr/etc)

#The includes
include_directories(include)

file(GLOB SOURCES src/*.cpp)

#remove from glob
#list(REMOVE_ITEM SOURCES badcode.cpp)

add_executable(probability ${SOURCES})