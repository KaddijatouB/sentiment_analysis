cmake_minimum_required(VERSION 3.21)
project(sentiment_analysis)

set(CMAKE_CXX_STANDARD 14)

add_executable(sentiment_analysis main.cpp database.cpp database.h record.cpp record.h)
