#ifndef PROJECT2_STATE_H
#define PROJECT2_STATE_H

#include <string>
using namespace std;
<<<<<<< HEAD
template <typename T> class State{
    T state;
    double cost;
    State<T>* cameFrom;
=======
template <class T> class State {
T state;
double cost;
State<T> cameFrom;
>>>>>>> dce39a4ff285e4640c053f8b7482cc0e275f9d02
public:
    State(T state, double cost) {
        this->state = state;
        this->cost = cost;
<<<<<<< HEAD
        cameFrom = NULL;
    }
    bool equals(State<T> s) {
        return this->state == s.state;
=======
    }
    bool equals(State<T> s) {
        return this->state.equals(s.state);
>>>>>>> dce39a4ff285e4640c053f8b7482cc0e275f9d02
    }
    T getState() {
        return this->state;
    }
    double getCost() {
        return this->cost;
    }
<<<<<<< HEAD
    State <T>* getCameFrom() {
        return this->cameFrom;
    }
    void setCameFrom(State<T>* s){
        this->cameFrom=s;
    }
};

#endif
=======
    State <T> getCameFrom() {
        return this->cameFrom;
    }
};

#endif
>>>>>>> dce39a4ff285e4640c053f8b7482cc0e275f9d02
