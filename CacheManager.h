//
// Created by shira on 1/6/19.
//

#ifndef UNTITLED4_CACHMANGER_H
#define UNTITLED4_CACHMANGER_H
template <class Solution,class Problem>
class CacheManager{
public:
    virtual bool ifExist(const Problem& p)=0;
    virtual void saveSolution(const Problem& p, const Solution& s)=0;
    virtual Solution getSolution(const Problem& p)=0;

};
#endif //UNTITLED4_CACHMANGER_H
