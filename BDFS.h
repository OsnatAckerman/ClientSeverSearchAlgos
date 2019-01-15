//
// Created by shira on 1/15/19.
//

#ifndef UNTITLED4_BDFS_H
#define UNTITLED4_BDFS_H

#include "SearcherAbstruct.h"

template <class State,class Con>
class BDFS :public SearcherAbstruct<State>{
public:
    vector<State> traceBack(const Step<cell>& goalState,const vector<Step<State>*>& visited)const{
        vector<State> traceSolution;
        const Step<State>* current = &goalState;
        while(current != nullptr) {
            traceSolution.push_back(current->getState());
            current = current->getParent();
        }
        reverse(traceSolution.begin(), traceSolution.end());
        if(!visited.empty()) {
            for (auto &x: visited) {
                delete x;
            }
        }
        return traceSolution;
    }
    vector<State> search(Searchable<State>* searchable) const{
        vector<Step<State>*> visited;
        Con container;
        container.push(searchable->getInitState());
        while(!container.empty()){
            Step<State> n = container.look();
            //this->numEvaluate++;
            container.pop();
            auto pointerToN = new Step<State>(n);
            visited.push_back(pointerToN);
            if(*pointerToN == searchable->getGoalState()) {
                return traceBack(*pointerToN, visited);
            }
            list<Step<State>> successors = searchable->getSuccessors(*pointerToN);
            for(Step<State>& s: successors) {
                if(find(visited.begin(), visited.end(), &s) != visited.end()){
                    container.push(s);
                    visited.push_back(new Step<State>(s));
                }
            }
        }
    }

};
#endif //UNTITLED4_BDFS_H
