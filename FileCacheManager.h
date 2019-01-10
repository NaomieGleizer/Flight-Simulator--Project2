#ifndef PROJECT2_FILECACHEMANAGER_H
#define PROJECT2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <unordered_map>
#include <string>
#include <fstream>

using namespace std;
template <typename S, typename P>
class FileCacheManager : public CacheManager<S, P> {
    unordered_map<P, S> ProblemsAndSolutions = {};
public:
    FileCacheManager(string fileName) {
        ifstream read(fileName);
        read >> ProblemsAndSolutions;
        read.close();
    }
    bool search(P problem) {
        if (ProblemsAndSolutions.find(problem) != ProblemsAndSolutions.end()) {
            return true;
        }
        return false;
     }
    S getSol(P problem) {
        return ProblemsAndSolutions[problem];
    }
    void add(P problem, S solution) {
        ProblemsAndSolutions.insert(pair<P, S> (problem, solution));
    }
};

#endif
