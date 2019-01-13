#include "MatrixSearchable.h"

MatrixSearchable::MatrixSearchable(vector<int> matrix, int n, int initialState, int goalState) :
        initialState(State<int>(initialState, matrix[initialState])),
        goalState(State<int>(goalState, matrix[goalState])) {
    this->matrix = matrix;
    this->n = n;

    for (int i = 0; i < this->matrix.size(); i++) {
        this->states.push_back(State<int>(i, matrix[i]));
    }
}

State<int> MatrixSearchable::getInitialState() {
    return this->initialState;
}

State<int> MatrixSearchable::getGoalState() {
    return this->goalState;
}

list<State<int>> MatrixSearchable::getAllPossibleStates(State<int> s) {
    list<State<int>> neighbors;
    int current = s.getState();
    if (current >= n && this->states[current - n].getCost() != -1) { // upper neighbor
        neighbors.push_back(this->states[current - n]);
    }
    if (current < n * n - n && this->states[current + n].getCost()!=-1) { // down neighbor
        neighbors.push_back(this->states[current + n]);
    }
    if (current % n != 0 && this->states[current - 1].getCost()!=-1) { // left neighbor
        neighbors.push_back(this->states[current - 1]);
    }
    if (current % n != n - 1 && this->states[current + 1].getCost()!=-1) { // right neighbor
        neighbors.push_back(this->states[current + 1]);
    }
    return neighbors;
}
