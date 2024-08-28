cmake_minimum_required(VERSION 3.29)
project(data_base_sem1lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(data_base_sem1lab1 main.cpp
        FixedRecord.h
        VariableRecord.h
        Models.h
        Record.h)
