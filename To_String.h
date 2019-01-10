//
// Created by osnat on 1/10/19.
//

#ifndef UNTITLED4_TO_STRING_H
#define UNTITLED4_TO_STRING_H

#include <string>
#include "State.h"

namespace std {

    template<class T>
    string to_string(State<T> *state) {
        string concat = to_string(state->getState()) + "," + to_string(state->getCost());
        if(state->getParent() != nullptr) {
            concat += ","+to_string(state->getParent()->getState());
        }
        return concat;
    }

    template <class M, class S>
    string to_string(pair<M, S> pair) {
        return to_string(pair.first) + "," + to_string(pair.second);
    }
}
#endif //UNTITLED4_TO_STRING_H
