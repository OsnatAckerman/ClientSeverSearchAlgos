//
// Created by shira on 1/16/19.
//

#ifndef UNTITLED4_ASTAR_H
#define UNTITLED4_ASTAR_H

#include <utility>
#include <bits/stdc++.h>
#include "SearcherAbstruct.h"
#include "MatrixSearchable.h"
#include <vector>
#include<iterator>
using namespace std;

template <class State>
class Astar : public  SearcherAbstruct<State> {
    vector<State> traceBack(const Step<State>& goalState, const unordered_set<Step<State>*>& closed) const{
        vector<State> traceSolution;
        const Step<State>* current = &goalState;
        while(current != nullptr) {
            traceSolution.push_back(current->getState());
            current = current->getParent();
        }
        reverse(traceSolution.begin(), traceSolution.end());
        if(!closed.empty()) {
            for (auto &x: closed) {
                delete x;
            }
        }
        return traceSolution;
    }
public:
    struct CompState {
        bool operator()(Step<State>& first, Step<State>& second) {
            return (first.getFHeuristics() > second.getFHeuristics());
        }
    }Com;

    vector<State> search(Searchable<State>* searchable) const {
        unordered_set<Step<State>*> closed ;
        vector<Step<State>> openList;
        auto f = searchable->getInitState();
        f.setHeuristic(0);
        openList.push_back(f);
        while(openList.amountOfElement() > 0) {
            Step<State> n = openList.back();
            //this->numEvaluate++;
            openList.pop_back();
            auto pointerToN = new Step<State>(n);
            closed.insert(pointerToN);
            if(*pointerToN == searchable->getGoalState()) {
                return traceBack(*pointerToN, closed);
            }
            list<Step<State>> successors = searchable->getSuccessors(*pointerToN);
            calFHeuristics(successors,searchable->getGoalState());
            for(Step<State>& s: successors) {
                if(closed.find(&s) != closed.end()){
                    continue;
                } else if(Step<State>* spos = openList.find(s)){
                    if( s.getHeuristic() < spos->getHeuristic()) {
                        updatePriority(s, openList);
                    }
                } else {
                    openList.push_back(s);
                    sort(openList.begin(),openList.end(),Com);
                }
            }

        }
        vector<Step<State>> NoSolution = {};
        return NoSolution;
    }

    void updatePriority(Step<State>& s, vector<Step<State>> openList) const{
        Step<State>* findS = openList.find(s);
        findS->setParent(*s.getParent());
        findS->setCost(s.getCost());
        findS->setHeuristic(s.getHeuristic());
        sort(openList.begin(),openList.end(),Com);
    }

    void calFHeuristics(list<Step<State>> successors,Step<State>& goalState) {
        for(auto& s : successors){
            double f, h, g;
            h = abs(s->getState().first - goalState->getState().first) +
                abs(s->getState().second - goalState->getState().second);
            s.setHeuristic(h);
        }
    }


};
#endif //UNTITLED4_ASTAR_H
