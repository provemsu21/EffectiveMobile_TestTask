cmake_minimum_required(VERSION 3.16)
project(EM_Test CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -Wpedantic)

set(SOURCES
    main.cpp
    parser/parser.cpp
    ListCreator/ListCreator.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
