//
// Created by osnat on 1/10/19.
//

#ifndef UNTITLED4_STATE_H
#define UNTITLED4_STATE_H

template<class T>
class State {
    T state;
    double cost = 0;
    State<T>* comeFrom = nullptr;
public:
    bool equals(State<T> s) {
        if(this->state == s.state){
            return true;
        }
        return false;
    }

    void setParent(State<T>* p){
        this->comeFrom = p;
    }

    explicit State<T>(T state) {
        this->state = state;
    }

    void setCost(double cost) {
        this->cost = cost;
    }
};




#endif //UNTITLED4_STATE_H
