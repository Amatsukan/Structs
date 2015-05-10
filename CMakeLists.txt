cmake_minimum_required(VERSION 3.2)
project(Graphs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Graphs ${SOURCE_FILES} structures/Graph/Node.h structures/List/List.h structures/Array/Vector.h structures/Array/ArrayExceptions.h structures/Array/BooleanArray.h structures/Array/numericVector.h structures/Array/Matrix.h structures/Array/numericVector.cpp structures/Array/numVector3d.cpp structures/Array/numVector3d.h)