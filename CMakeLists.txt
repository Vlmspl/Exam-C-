cmake_minimum_required(VERSION 3.30)
project(ExamProject)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

add_executable(ExamProject ${SOURCES} ${HEADERS})
