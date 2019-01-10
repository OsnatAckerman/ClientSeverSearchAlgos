//
// Created by shira on 1/10/19.
//

#ifndef UNTITLED4_SEARCHER_H
#define UNTITLED4_SEARCHER_H

#include "Searchable.h"

template <class Solution,class T>
        class Searcher{
public:
    virtual int getNodEvaluate() = 0;
    virtual Solution search(Searchable<T> s) =0;
};
#endif //UNTITLED4_SEARCHER_H
