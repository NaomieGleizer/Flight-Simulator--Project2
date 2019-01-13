#include "MyClientHandler.h"
#include <string>
#include <string.h>
#include <cstring>
#include "MatrixSearchable.h"
#include "BFS.h"
using namespace std;
MyClientHandler::MyClientHandler(CacheManager<string, string>* cm){
    this->cm = cm;
}
string MyClientHandler::handleClient(string input) {
    // if there is a solution for the given problem, save it to output
    if (this->cm->search(input)) {
        // copy solution to output
        return this->cm->getSol(input);
    }
    else {
        char* temp = new char[input.length()];
        strcpy(temp, (input.c_str()));
        char* token = strtok(temp, "*");
        string lines;
        int n = 0;
        while (token != NULL) {
            lines.append(token);
            n++; // number of lines
            token = (strtok(NULL, "*"));
        }
        n-=3;
        vector<int> matrix = {};
        strcpy(temp, (lines.c_str()));
        char* number = strtok(temp, ",");
        while (number != NULL) {
            matrix.push_back(atoi(number));
            number = (strtok(NULL, ","));
        }
        int goalC = matrix[matrix.size() - 1];
        matrix.pop_back();
        int goalR = matrix[matrix.size() - 1];
        matrix.pop_back();
        int startC = matrix[matrix.size() - 1];
        matrix.pop_back();
        int startR = matrix[matrix.size() - 1];;
        matrix.pop_back();
        int m = matrix.size() / n;

        Searchable<int>* se = new MatrixSearchable(matrix, n, m,
                (startR*n + startC), (goalR*n + goalC));
        Searcher<int>* bfs = new BFS<int>();
        vector<int> path= bfs->search(se);
        int current;
        int next;
        string directions = "";
        for (int i = 0; i <= path.size() - 2; i++) {
            current = path[i];
            next = path[i+1];
            if (next == (current - n)) {
                directions+= "Up,";
            } else if (next == (current + n)) {
                directions+= "Down,";
            } else if(next == current - 1) {
                directions+= "Left,";
            } else if(next == current + 1) {
                directions+= "Right,";
            }
        }
        directions.pop_back();
        this->cm->add(input, directions);
        return directions;
    }
}