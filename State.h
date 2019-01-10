//
// Created by osnat on 1/10/19.
//

#ifndef UNTITLED4_STATE_H
#define UNTITLED4_STATE_H

template<class T>
class State {
    T state;
    double cost = 0;
    State<T> comeFrom = nullptr;
public:
    State<T>(T state);
    bool equals(State<T> s);
    void setParent(State<T>& p);
};


#endif //UNTITLED4_STATE_H
