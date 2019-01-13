#ifndef PROJECT2_SEARCHER_H
#define PROJECT2_SEARCHER_H

<<<<<<< HEAD
#include "ISearcher.h"
#include "State.h"
#include "MyPriorityQueue.h"
template <typename T> class Searcher : public ISearcher<T> {

public:

    // the search method
     virtual vector<T> search(Searchable<T>* searchable) = 0;

    // get how many nodes were evaluated by the algorithm
     int getNumberOfNodesEvaluated() {
         return this->evaluateNodes;
     }

protected:
    MyPriorityQueue<State<T>> openList;
    int evaluateNodes = 0;
    State<T> popOpenList() {
        evaluateNodes++;
        return openList.pop();
    }


};

#endif
=======
#include "Searchable.h"
#include <vector>

template<class T> class Searcher {

public:
    // the search method
    virtual vector<T> search(Searchable<T> searchable) = 0;

    // get how many nodes were evaluated by the algorithm
    virtual int getNumberOfNodesEvaluated() = 0;

};

#endif
>>>>>>> dce39a4ff285e4640c053f8b7482cc0e275f9d02
