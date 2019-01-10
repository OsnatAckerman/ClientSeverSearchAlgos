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
    State<T> getInitState();
    State<T> getGoalState();
    list<State<T>> getSuccessors(State<T> n);

};

#endif //UNTITLED4_SEARCHABLE_H
