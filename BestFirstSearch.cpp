//
// Created by shira on 1/10/19.
//

#include "BestFirstSearch.h"
template <class T>
vector<State<pair<int,int>>> BestFirstSearch<T>::search(Searchable<T> s){

}
template <class T>
vector<State<pair<int,int>>> BestFirstSearch<T>::traceBack(State<pair<int,int>> goalState){
    vector<State<pair<int,int>>> traceSolution;
    auto current = goalState;
    while(current.getParent()!= nullptr) {
        traceSolution.push_back(current);
        current = *current.getParent();
    }
    return traceSolution;
}