//
// Created by shira on 1/10/19.
//

#ifndef UNTITLED4_BESTFIRSTSEARCH_H
#define UNTITLED4_BESTFIRSTSEARCH_H

#include <utility>
#include <bits/stdc++.h>
#include "SearcherAbstruct.h"
using namespace std;
template <class T>
class BestFirstSearch : public  SearcherAbstruct<vector<State<pair<int,int>>>,T>{
    unordered_set<State<pair<int,int>>>* closed = new unordered_set<State<pair<int,int>>>();
    vector<State<pair<int,int>>> traceBack(State<pair<int,int>> goalState);

public:
    vector<State<pair<int,int>>> search(Searchable<T> searchable);
};


#endif //UNTITLED4_BESTFIRSTSEARCH_H
