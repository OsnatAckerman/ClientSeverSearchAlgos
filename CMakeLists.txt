cmake_minimum_required(VERSION 3.13)
project(untitled4)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled4 main.cpp ClientHandler.h Solver.h Searchable.h State.cpp State.h Searchable.h Searcher.h SearcherAbstruct.h SolveSearch.cpp SolveSearch.h FileCachManger.cpp FileCachManger.h CachManager.h MyPriorityQueue.h)