#include <iostream>
#include <vector>
#include "MatrixSearchable.h"
#include "Searcher.h"
#include "Solver.h"
#include "SolveSearch.h"
#include "BestFirstSearch.h"
#include "StreamOverload.h"

using namespace std;
using cell = pair<int,int>;
int main() {



    vector<int> vec1 {1,2,3,4,5};
    vector<int> vec2 {7,4,-1,3,1};
    vector<int> vec3 {1,1,2,10,20};
    vector<int> vec4 {1,-1,1,1,10};
    vector<int> vec5 {1,1,-1,1,1};
    vector<vector<int>> matrix {vec1, vec2, vec3, vec4, vec5};
    cell init (make_pair(0,0));
    cell goal (make_pair(4,4));

    MatrixSearchable* m = new MatrixSearchable(matrix, init, goal);

    Searcher<cell>* searcher =new BestFirstSearch<cell>();
    auto searchSolver = new SolveSearch<cell>(searcher);
    vector<cell> answer = searchSolver->solve(m);
    cout<<*m<<endl;
    stringstream ss;
    vector<cell> answer2;
    MatrixSearchable m2;
    ss<<*m;
    ss>>m2;
    cout << m2 << endl;
    delete m;
    delete searcher;
    delete searchSolver;
    return 0;
}