cmake_minimum_required(VERSION 3.21)
project(lab04)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab04 main.cpp "Square Class/Square.cpp" "Square Class/Square.h" Tests/tests.cpp Tests/tests.h UI/console.cpp UI/console.h UI/operations.cpp UI/operations.h Repo/Repo.cpp Repo/Repo.h)
