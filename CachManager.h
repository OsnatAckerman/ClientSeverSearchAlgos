//
// Created by shira on 1/6/19.
//

#ifndef UNTITLED4_CACHMANGER_H
#define UNTITLED4_CACHMANGER_H
template <class Solution,class Problem>
class CashManager{
public:
    virtual bool ifExist(Problem p)=0;
    virtual void saveSolution(Problem p)=0;
    virtual void loadSolution() =0;
    virtual Solution getSolution(Problem p)=0;

};
#endif //UNTITLED4_CACHMANGER_H
