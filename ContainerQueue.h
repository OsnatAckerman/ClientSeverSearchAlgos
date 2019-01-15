//
// Created by shira on 1/15/19.
//

#ifndef UNTITLED4_CONTAINERQUEUE_H
#define UNTITLED4_CONTAINERQUEUE_H

using namespace std;

#include <queue>
#include "container.h"
template <class E>
class ContainerQueue : public Container<E>{
    queue<E> queue;
public:
     void pop(){
         this->queue.pop();
     }
     void push(const E& element){
         this->push(element);
     }
     E& look(){
        return this->queue.front();
     }
};


#endif //UNTITLED4_CONTAINERQUEUE_H
