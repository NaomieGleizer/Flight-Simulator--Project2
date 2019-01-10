#include <iostream>
#include "FileCacheManager.h"
#include <unordered_map>
#include <string>
#include "MatrixSearchable.h"
#include <fstream>
#include "Searcher.h"
#include <vector>
#include "BFS.h"
#include "DFS.h"
using  namespace std;

int main() {
    vector<int> matrix;
    for(int i=0; i<16;i++){
     matrix.push_back(i);
    }

    int a = 15;
    int b = 0;
    Searchable<int>* se = new MatrixSearchable(matrix,4, a, b);
    Searcher<int>* bfs = new BFS<int>();
    vector<int> path1= bfs->search(se);

    Searcher<int>* dfs = new DFS<int>();
    vector<int> path2= dfs->search(se);

    return 0;
}