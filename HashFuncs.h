//
// Created by osnat on 1/10/19.
//

#ifndef UNTITLED4_HASHFUNCS_H
#define UNTITLED4_HASHFUNCS_H

#include <cstddef>
#include "State.h"
#include <string>
#include "To_String.h"

namespace std
{
/*    template <>
    struct hash<State<pair<int,int>>>
    {
        size_t operator()(const State<pair<int,int>>& s) const{
            string concat = to_string(s.getState().first) + to_string(s.getState().second) +
                    to_string(s.getCost()) + to_string(s.getParent());
            return hash<string>()(concat);
        }
    };*/

    template <class T>
    struct hash<State<T>>
    {
        size_t operator()(const State<T>& s) const{
            string concat = to_string(s.getState())  +
                            to_string(s.getCost());
            if(s.getParent() != nullptr) {
               concat += to_string(s.getParent());
            }
            return hash<string>()(concat);
        }
    };
}


#endif //UNTITLED4_HASHFUNCS_H
