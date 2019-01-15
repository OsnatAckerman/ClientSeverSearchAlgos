//
// Created by shira on 1/10/19.
//

#ifndef UNTITLED4_BESTFIRSTSEARCH_H
#define UNTITLED4_BESTFIRSTSEARCH_H

#include <utility>
#include <bits/stdc++.h>
#include "SearcherAbstruct.h"
using namespace std;

namespace std {
    template<class State>
    struct equal_to<Step<State>*> {
        bool operator()(const Step<State> *x, const Step<State> *y) const { return *x == *y; }
    };
}

template <class State>
class BestFirstSearch : public  SearcherAbstruct<State>{
    unordered_set<Step<State>*>* closed = new unordered_set<Step<State>*>();

    vector<State> traceBack(const Step<State>& goalState){
        vector<State> traceSolution;
        const Step<State>* current = &goalState;
        while(current != nullptr) {
            traceSolution.push_back(current->getState());
            current = current->getParent();
        }
        reverse(traceSolution.begin(), traceSolution.end());
        return traceSolution;
    }



    void updatePriority(Step<State>& s){
        Step<State>* findS = this->openList->find(s);
        findS->setParent(*s.getParent());
        findS->setCost(s.getCost());
        this->openList->Sort();
    }



public:
    vector<State> search(Searchable<State>* searchable){
        this->openList->push(searchable->getInitState());
        while(this->OpenListSize() > 0) {
            Step<State> n = this->popOpenList();
            auto pointerToN = new Step<State>(n);
            this->closed->insert(pointerToN);
            if(*pointerToN == searchable->getGoalState()) {
                return traceBack(*pointerToN);
            }
            list<Step<State>> successors = searchable->getSuccessors(*pointerToN);
            for(Step<State>& s: successors) {
                if(closed->find(&s) != closed->end()){
                    continue;
                } else if(Step<State>* spos = this->openList->find(s)){
                    if( s.getCost() < spos->getCost()) {
                        this->updatePriority(s);
                    }
                } else {
                    this->openList->push(s);
                }
            }
        }


    }

    ~BestFirstSearch(){
        if(closed) {
            for (auto &x: *closed) {
                delete x;
            }
        }
        delete closed;
    }
};



#endif //UNTITLED4_BESTFIRSTSEARCH_H
