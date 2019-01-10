//
// Created by shira on 1/10/19.
//

#ifndef UNTITLED4_SOLVESEARCH_H
#define UNTITLED4_SOLVESEARCH_H


#include "Solver.h"
#include "Searcher.h"
template <class Solution,class T>
class SolveSearch : public Solver<Solution,Searchable<T>>{
    Searcher<Solution,Searchable<T>> searcher;
public:
    Solution solve(Searchable<T> searchable) override;
};


#endif //UNTITLED4_SOLVESEARCH_H
