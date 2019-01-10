//
// Created by osnat on 1/10/19.
//

#ifndef UNTITLED4_MATRIXSEARCHABLE_H
#define UNTITLED4_MATRIXSEARCHABLE_H


#include <vector>
#include "Searchable.h"
class MatrixSearchable: public Searchable<pair<int,int>> {
    vector<vector<int>> matrix;
    State<pair<int,int>> initState;
    State<pair<int,int>> goalState;

public:
    MatrixSearchable(vector<vector<int>> matrix, State<pair<int,int>> init, State<pair<int,int>> goal);
    State<pair<int,int>> getInitState() override;

    State<pair<int,int>> getGoalState() override;
    list<State<pair<int,int>>> getSuccessors(State<pair<int,int>> n) override;
};


#endif //UNTITLED4_MATRIXSEARCHABLE_H
