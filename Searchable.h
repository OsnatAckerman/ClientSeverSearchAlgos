//
// Created by osnat on 1/10/19.
//

#ifndef UNTITLED4_SEARCHABLE_H
#define UNTITLED4_SEARCHABLE_H

#include <list>
#include "State.h"

using namespace std;

template<class T>
class Searchable {
public:
    virtual State<T> getInitState() = 0;
    virtual State<T> getGoalState() = 0;
    virtual list<State<T>> getSuccessors(State<T> n) = 0;

};

#endif //UNTITLED4_SEARCHABLE_H
