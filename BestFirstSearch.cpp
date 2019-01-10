//
// Created by shira on 1/10/19.
//

#include "BestFirstSearch.h"
template <class T>
vector<State<pair<int,int>>> BestFirstSearch<T>::search(Searchable<T> searchable){
    this->openList.push(searchable.getInitState());
    while(this->openList.size() > 0) {
        State<pair<int,int>> n = this->openList.pop();
        this->closed->insert(n);
        if(n.equals(searchable.getGoalState())) {
            return traceBack(n);
        }
        list<State<pair<int,int>>> successors = searchable.getSuccessors(n);
        for(State<pair<int,int>> s: successors) {
            if((closed->find(s) != closed->end()) && !this->openList.find(s)){
                this->openList.push(s);
            } else if(closed->find(s) != closed->end()){
                if(*this->openList.find(s) < s) {

                }
            }
        }
    }




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