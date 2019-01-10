//
// Created by shira on 1/10/19.
//

#ifndef UNTITLED4_MYPRIORITYQUEUE_H
#define UNTITLED4_MYPRIORITYQUEUE_H


#include "State.h"
#include <queue>
#include <iostream>
#include <climits>
#include <sys/param.h>
#include "HashFuncs.h"

using namespace std;
template <class Q>
class MyPriorityQueue{
    std::queue<Q> queue;
public:
    MyPriorityQueue<Q>(){

    }
    void Sort(){

        for (int i = 1; i <= this->queue.size(); i++)
        {
            int min_index = minIndex(int(queue.size() - i));
            insertMinToRear(min_index);
        }
    }
    void insertMinToRear( int min_index) {
        Q min_val;
        unsigned long int n = queue.size();
        for (int i = 0; i < n; i++) {
            Q curr = queue.front();
            queue.pop();
            if (i != min_index)
                queue.push(curr);
            else
                min_val = curr;
        }
        queue.push(min_val);
    }
    int minIndex(int sortedIndex){
        int min_index = -1;
        Q min_val = queue.pop();
        int n =int( queue.size());
        for (int i=0; i<n; i++)
        {
            Q curr = queue.front();
            queue.pop();  // This is dequeue() in C++ STL
            if (curr <= min_val && i <= sortedIndex)
            {
                min_index = i;
                min_val = curr;
            }
            queue.push(curr);  // This is enqueue() in
            // C++ STL
        }
        return min_index;
    }
    void pop(){
        this->queue.pop();
    }
    void push(Q state){
        queue.push(state);
        this->Sort();
    }
    int amountOfElement(){
        return (int)this->queue.size();
    }

    Q* find(Q q) {
        std::queue<Q> temp = queue;
        for(int i = 0; i < queue.size(); i++) {
            if(queue.front().equals(q)) {
                auto x = queue.front();
                queue = temp;
                return x;
            }
            queue.push(queue.pop());
        }
        queue = temp;
        return nullptr;
    }
};


#endif //UNTITLED4_MYPRIORITYQUEUE_H
