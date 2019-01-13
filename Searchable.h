#ifndef PROJECT2_SEARCHABLE_H
#define PROJECT2_SEARCHABLE_H

#include "State.h"
#include <list>

using namespace std;

<<<<<<< HEAD
template <typename T> class Searchable {
=======
template <class T> class Searchable {
>>>>>>> dce39a4ff285e4640c053f8b7482cc0e275f9d02
public:
    virtual State<T> getInitialState() = 0;
    virtual State<T> getGoalState() = 0;
    virtual list<State<T>> getAllPossibleStates(State<T> s) = 0;
};

#endif
