cmake_minimum_required(VERSION 3.13)
project(MultiMap)

set(CMAKE_CXX_STANDARD 14)

add_executable(MultiMap main.cpp MultiMap.cpp MultiMap.h MultiMapIterator.cpp MultiMapIterator.h SLLA.cpp SLLA.h SLLAIterator.cpp SLLAIterator.h ShortTest.cpp ShortTest.h ExtendedTest.cpp ExtendedTest.h)