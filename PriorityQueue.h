#ifndef PROJECT2_PRIORITYQUEUE_H
#define PROJECT2_PRIORITYQUEUE_H

#include <deque>
#include "State.h"

using  namespace std;

template<class T> class PriorityQueue{
deque<State<T>> queue;
public:
    virtual void AddToQueue(State<T> s);

    virtual bool isElementInQueue(State<T> s){
        for (typename deque<State<T>>::iterator it = queue.begin(); it != queue.end(); it++) {
            if(s.equals(*it)){
                return true;
            }
        }
        return  false;
    }

    virtual deque<State<T>> getQueue(){
        return this->queue;
    }

    virtual State<T> pop(){
        return this->queue.pop_front();
    }

    virtual void adjustPriority(State<T> s){

    }
};

#endif
