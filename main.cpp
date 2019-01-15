#include <iostream>
#include <vector>
#include "MatrixSearchable.h"
#include "Searcher.h"
#include "Solver.h"
#include "SearchSolver.h"
#include "BestFirstSearch.h"
#include "StreamOverload.h"
#include "MyMatrixClientHandler.h"
#include "CacheManager.h"
#include "MyParallelServer.h"
#include "Server.h"


using namespace std;
using cell = pair<int,int>;
int main() {

    CacheManager<MatrixSearchable, vector<cell>>* cm =
            new FileCacheManager<MatrixSearchable, vector<cell>>("cachFile.txt");

    Searcher<cell>* bfs = new BestFirstSearch<cell>();

    ClientHandler* clientHandler = new MyMatrixClientHandler(bfs, cm);

    server_side::Server* server = new MyParallelServer();
    server->open(5400, clientHandler);
    server->stop();
    return 0;
}