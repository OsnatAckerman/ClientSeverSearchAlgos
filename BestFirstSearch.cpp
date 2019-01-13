//
// Created by shira on 1/10/19.
//

#include "BestFirstSearch.h"
template <class T>
vector<State<pair<int,int>>> BestFirstSearch<T>::search(Searchable<T> searchable){
    this->openList.push(searchable.getInitState());
    while(this->openList.size() > 0) {
        State<pair<int,int>> n = this->popOpenList();
        this->closed->insert(n);
        if(n.equals(searchable.getGoalState())) {
            return traceBack(n);
        }
        list<State<pair<int,int>>> successors = searchable.getSuccessors(n);
        for(State<pair<int,int>> s: successors) {
            State<pair<int,int>>* spos = this->openList.find(s);
            if((closed->find(s) != closed->end()) && !spos){
                this->openList.push(s);
            } else if(spos){
                if(spos->getCost() > s.getCost()) {
                    this->updatePriority(s);
                } else {
                    this->openList.push(s);
                }
            }
        }
    }


}
template <class T>
void BestFirstSearch<T>:: updatePriority(State<pair<int,int>> s){
    for(int i = 0; i<this->OpenListSize(); i++){
        if(s.equals(this->openList.front())) {
            this->openList.pop();
            this->openList.push(s);
            return;
        }
        this->openList.push(this->openList.front());
        this->openList.pop();
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