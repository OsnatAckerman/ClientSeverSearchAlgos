//
// Created by shira on 1/10/19.
//

#ifndef UNTITLED4_SEARCHERABSTRUCT_H
#define UNTITLED4_SEARCHERABSTRUCT_H


#include "Searcher.h"
#include "MyPriorityQueue.h"

template <class Solution,class T>
class SearcherAbstruct : public Searcher<Solution,T>{

    int numEvaluate =0;
public:
    virtual Solution search(Searchable<T> s) = 0;
    int getNodEvaluate(){
        return this->numEvaluate;
    }
    int OpenListSize(){
        return this->openList.amountOfElement();
    }
    ~SearcherAbstruct(){
        delete this->openList;
    }
protected:
    MyPriorityQueue<State<T>> openList = new MyPriorityQueue<State<T>>();
    State<T> popOpenList(){
        numEvaluate++;
        this->openList.pop();
    }

};


#endif //UNTITLED4_SEARCHERABSTRUCT_H
