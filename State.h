#ifndef PROJECT2_STATE_H
#define PROJECT2_STATE_H

#include <string>
using namespace std;
template <class T> class State {
T state;
double cost;
State<T> cameFrom;
public:
    State(T state, double cost) {
        this->state = state;
        this->cost = cost;
    }
    bool equals(State<T> s) {
        return this->state.equals(s.state);
    }
    T getState() {
        return this->state;
    }
    double getCost() {
        return this->cost;
    }
    State <T> getCameFrom() {
        return this->cameFrom;
    }
};

#endif
