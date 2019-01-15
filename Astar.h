#ifndef PROJECT2_ASTAR_H
#define PROJECT2_ASTAR_H

#include "MatrixSearchable.h"
#include "Searcher.h"
#include <map>

class Astar: public Searcher<int>{

    State<int>* nodeWithTheLeastCost(map<State<int>*,int> costs) {
        map<State<int>*,int>::iterator it=costs.begin();
        State<int>* state= it->first;
        int min=it->second;
        it++;
        while(it!=costs.end()){
            if(it->second<min){
                min=it->second;
                state=it->first;
            }
            it++;
        }
        return state;
    }

    vector<int> search(MatrixSearchable* searchable){
        map<int,State<int>*> open;
        map<int,State<int>*> close;
        vector<int> path;
        map<State<int>*, int> costFromStart;
        map<State<int>*, int> costs;

        open[0]=searchable->getInitialState();
        costs[searchable->getInitialState()]= 0;
        State<int>* current;
        list<State<int>*> successors;
        while(!open.empty()){
            current=nodeWithTheLeastCost(costs);
            open.erase(current->getState());
            successors=searchable->getAllPossibleStates(current);
            list<State<int>*>::iterator it=successors.begin();
            while(it!=successors.end()){
                (*it)->setCameFrom(current);

                if((*it)->equals(*searchable->getGoalState())){
                    State<int>* node=(*it);
                    while(!node->equals(*(searchable->getInitialState()))) {
                        path.insert(path.begin(),node->getState());
                        node=node->getCameFrom();
                    }
                    path.insert(path.begin(),node->getState()); // insert the initial state
                    return path;
                }

                costFromStart[*it]=costFromStart[current]+(*it)->getCost();
                costs[*it]=costFromStart[*it]+ distanceToGoal(*it,searchable->getGoalState()
                        , searchable->getNumOfColumns());
                
                it++;
            }


        }
    }

    int distanceToGoal(State<int>* current, State<int>* goal, int numOfColumns){
       int xCurrent=current->getState()/numOfColumns;
       int xGoal= goal->getState()/numOfColumns;
       int yCurrent= current->getState() - xCurrent*numOfColumns;
       int yGoal= goal->getState()- xGoal*numOfColumns;
       return abs(xCurrent-xGoal)+ abs(yCurrent- yGoal);

    }
};
#endif
