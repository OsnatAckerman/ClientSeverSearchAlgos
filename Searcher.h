//
// Created by shira on 1/10/19.
//

#ifndef UNTITLED4_SEARCHER_H
#define UNTITLED4_SEARCHER_H

#include "Searchable.h"
using namespace std;

template <class State>
        class Searcher{
public:
    virtual int getNodEvaluate() = 0;
    virtual vector<State> search(Searchable<State>* s) =0;
    virtual ~Searcher() = default;
};
#endif //UNTITLED4_SEARCHER_H
