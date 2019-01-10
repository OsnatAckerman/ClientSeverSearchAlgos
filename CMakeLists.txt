cmake_minimum_required(VERSION 3.13)
project(untitled4)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled4 main.cpp ClientHandler.h CachManager.h FileCachManger.cpp FileCachManger.h Solver.h StringReverse.cpp StringReverse.h Searcher.h Searchable.h SolveSearch.cpp SolveSearch.h SearcherAbstruct.cpp SearcherAbstruct.h)