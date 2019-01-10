//
// Created by osnat on 1/10/19.
//

#include "MatrixSearchable.h"


MatrixSearchable::MatrixSearchable(vector<vector<int>> matrix, State<pair<int,int>> init, State<pair<int,int>> goal):
    initState(State<pair<int,int>>(make_pair(0,0))), goalState(State<pair<int,int>>(make_pair(0,0))){

    this->goalState = goal;
    this->initState = init;
    this->matrix = matrix;
}

State<pair<int,int>> MatrixSearchable:: getInitState()  {
    return this->initState;
}

State<pair<int,int>> MatrixSearchable:: getGoalState() {
    return this->goalState;
}

/**
 * getSuccessors  - return all 4 neighbors states of n in the matrix only if exist and reachable.
 *                  each state's is set as a sum of the n cost and the walk to the neighbor.
 * @param n - current state
 * @return list<State<pair<int,int>>> successors
 */
list<State<pair<int,int>>> MatrixSearchable::getSuccessors(State<pair<int, int>> n) {
    list<State<pair<int,int>>> successors;
    //if there is upper neighbor
    if(n.getState().first > 0) {
        int up = matrix[n.getState().first - 1][n.getState().second];
        //if neighbor is reachable
        if (up != -1) {
            State<pair<int, int>> s(make_pair(n.getState().first - 1, n.getState().second));
            s.setCost(n.getCost() + up);
            s.setParent(&n);
            successors.push_back(s);
        }
    }
    //if there is lower neighbor
    if(n.getState().first < this->matrix.size()-1) {
        int down = matrix[n.getState().first + 1][n.getState().second];
        if (down != -1) {
            State<pair<int, int>> s(make_pair(n.getState().first + 1, n.getState().second));
            s.setCost(n.getCost() + down);
            s.setParent(&n);
            successors.push_back(s);
        }
    }
    //if there is left neighbor
    if(n.getState().second > 0) {
        int left = matrix[n.getState().first][n.getState().second - 1];
        if (left != -1) {
            State<pair<int, int>> s(make_pair(n.getState().first, n.getState().second - 1));
            s.setCost(n.getCost() + left);
            s.setParent(&n);
            successors.push_back(s);
        }
    }
    //if there is right neighbor
    if(n.getState().second < this->matrix.size()-1) {
        int right = matrix[n.getState().first][n.getState().second + 1];
        if (right != -1) {
            State<pair<int, int>> s(make_pair(n.getState().first, n.getState().second + 1));
            s.setCost(n.getCost() + right);
            s.setParent(&n);
            successors.push_back(s);
        }
    }
    return successors;
}