//
// Created by osnat on 1/10/19.
//

#ifndef UNTITLED4_HASHFUNCS_H
#define UNTITLED4_HASHFUNCS_H

#include <cstddef>
#include "Step.h"
#include <string>
#include "To_String.h"

using cell = pair<int,int>;

namespace std {
    template<class State>
    struct hash<Step<State>*> {
        size_t operator()(const Step<State>* s) const {
            return hash<State>()(s->getState());
        }
    };

    template<>
    struct hash<cell> {
        size_t operator()(const cell &c) const {
            string cellString = to_string(c.first) + to_string(c.second);
            return hash<string>()(cellString);
        }
    };
}




#endif //UNTITLED4_HASHFUNCS_H
