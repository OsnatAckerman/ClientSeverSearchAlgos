//
// Created by osnat on 1/12/19.
//

#ifndef UNTITLED4_FILECACHMANAGER_H
#define UNTITLED4_FILECACHMANAGER_H

#include <fstream>
#include <sstream>
#include "CacheManager.h"
#include "To_String.h"

template <class Solution, class Problem>
class FileCachManager: public CacheManager<Solution, Problem> {
    //file format:
    //each line- string of problem:string of solution

    unordered_map<Problem, Solution> map;
    string fileName;
    bool isLoaded = false;
    void loadMap(){
        if(isLoaded) {
            return;
        }
        ifstream readFile;
        readFile.open(this->fileName);
        if(readFile.is_open()) {
            string line;
            while (getline(readFile, line)) {
                string problem, solution;
                problem = line.substr(0, line.find(':'));
                line.erase(0, line.find(':')+1);
                solution = line;
                map[problem] = solution;
            }
        }
        isLoaded = true;
    }
    void saveMap(){
        if(!isLoaded) {
            loadMap();
        }
        ofstream writeToFile;
        writeToFile.open(this->fileName, ios::trunc);
        if(!writeToFile.is_open()) {
            throw "can't open FileCachManager file";
        }
        for(const auto& keyVal: this->map) {
            writeToFile << keyVal.first << ":" << keyVal.second << endl;
        }
    }


public:
    explicit FileCachManager<Solution,Problem>(string file_name) {
        this->fileName = file_name;
    }


    ~FileCachManager(){
        saveMap();
    }


    bool ifExist(const Problem& p) override {
        if(!isLoaded) {
            loadMap();
        }
        if(map.find(p) != map.end()) {
            return true;
        }
        return false;
    }


    void saveSolution(const Problem& p,const Solution& s) override {
        map[p] = s;
    }

    Solution getSolution(const Problem& p) override {
        if(!isLoaded) {
            loadMap();
        }
        return map[p];
    }

};


#endif //UNTITLED4_FILECACHMANAGER_H
