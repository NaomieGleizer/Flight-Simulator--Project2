#ifndef PROJECT2_MYSEARCHEBLE_H
#define PROJECT2_MYSEARCHEBLE_H

#include "Searchable.h"
#include <vector>
#include "State.h"

using namespace std;

class MatrixSearchable : public Searchable<int> {
    int n;
    vector<int> matrix;
    vector<State<int>> states;
    State<int> initialState;
    State<int> goalState;
public:
    MatrixSearchable(vector<int> matrix,int n, int initialState, int goalState);
    State<int> getInitialState();
    State<int> getGoalState();
    list<State<int>> getAllPossibleStates(State<int> s);
};

#endif
