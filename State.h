//
// Created by osnat on 1/10/19.
//

#ifndef UNTITLED4_STATE_H
#define UNTITLED4_STATE_H

#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;

template<class T>
class State {
    T state;
    double cost = 0;
    State<T>* comeFrom = nullptr;
public:

    explicit State<T>(T state) {
        this->state = state;
    }

    bool equals(State<T> s) {
        if(this->state == s.state){
            return true;
        }
        return false;
    }

    void setParent(State<T>* p){
        this->comeFrom = p;
    }


    void setCost(double cost) {
        this->cost = cost;
    }

    T getState() const{
        return this->state;
    }

    double getCost() const{
        return this->cost;
    }

    State<T>* getParent() const{
        return this->comeFrom;
    }

    bool operator<(State<T> const& s) const{
        return (this->cost < s.cost) ? true:false;
    }
    bool operator>(State<T> const& s) const{
        return (this->cost > s.cost) ? true:false;
    }
    bool operator<=(State<T> const& s) const{
        return (this->cost <= s.cost) ? true:false;
    }
    bool operator>=(State<T> const& s) const{
        return (this->cost >= s.cost) ? true:false;
    }

    bool operator==(State<T> const& s) const{
        return (s.getCost() == this->cost && this->state == s.getState() &&
            this->comeFrom== s.getParent()) ? true: false;
    }


};






#endif //UNTITLED4_STATE_H
