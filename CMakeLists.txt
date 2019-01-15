cmake_minimum_required(VERSION 3.13)
project(untitled4)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled4 main.cpp BestFirstSearch.h CacheManager.h FileCachManager.h FileCachManager.cpp HashFuncs.h MatrixSearchable.h MatrixSearchable.cpp MyPriorityQueue.h MySerialServer.h Searcher.h SearcherAbstruct.h Solver.h SearchSolver.h Step.h Step.cpp StreamOverload.h To_String.h Searchable.h MyMatrixClientHandler.cpp MyMatrixClientHandler.h MyParallServer.h MyParallServer.cpp DataStructure.h Server.h ClientHandler.h)