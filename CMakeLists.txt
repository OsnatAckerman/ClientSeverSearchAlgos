cmake_minimum_required(VERSION 3.13)
project(untitled4)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled4 main.cpp Searchable.h State.cpp Searcher.h SolveSearch.cpp SolveSearch.h CachManager.h MyPriorityQueue.h MatrixSearchable.cpp MatrixSearchable.h Solver.h SearcherAbstruct.h SolveSearch.h SolveSearch.cpp BestFirstSearch.cpp BestFirstSearch.h HashFuncs.h To_String.h Server.h ClientHandle.cpp ClientHandle.h MyParallServer.cpp MyParallServer.h DataStructure.h)