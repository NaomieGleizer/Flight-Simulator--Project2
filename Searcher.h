#ifndef PROJECT2_SEARCHER_H
#define PROJECT2_SEARCHER_H

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