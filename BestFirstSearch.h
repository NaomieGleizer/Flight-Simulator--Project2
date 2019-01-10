#ifndef PROJECT2_BESTFIRSTSEARCH_H
#define PROJECT2_BESTFIRSTSEARCH_H

#include "Searcher.h"
#include <queue>
using namespace std;
template<class T> class BestFirstSearch: public Searcher<T> {

    bool isInVector(State<T> element, vector<State<T>> v) {
        for (typename std::vector<State<T>>::iterator it = v.begin();
             it != v.end(); it++) {
            if (element.equals(*it)) {
                return true;
            }
        }
        return false;
    }

    vector<T> search(Searchable<T> searchable) {
        this->openList.AddToQueue(searchable.getInitialState());
        vector<State<T>> closed = {};
        vector<T> path;
        list<State<T>> successors;
        while (!this->openList.getQueue().empty()) {
            State<T> n = this->openList.pop();
            closed.push_back(n);
            if (n.equals(searchable.getGoalState())) {
                while(!n.equals(searchable.getInitialState())) {
                    path.push_back(n.getState());
                    n = n.getCameFrom();
                }
                return path;
            }
            successors = searchable.getAllPossibleStates(n);
            for (typename std::list<State<T>>::iterator it = successors.begin();
            it != successors.end(); it++) {
                if(!isInVector(*it, closed) && this->openList.isElementInQueue(*it)) {
                    it->setCameFrom(n);
                    this->openList.AddToQueue(*it);
                }
                else if (it->) {

                }
            }
        }
    }
    int getNumberOfNodesEvaluated();

};

#endif
