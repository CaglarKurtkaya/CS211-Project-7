#ifndef PROJECT6_TRAVELNETWORK_H
#define PROJECT6_TRAVELNETWORK_H
#include <cstring>
#include <string>
#include <iostream>
#include "airport.h"
#include "mylist.h"

class TravelNetwork
{
private:
    int Travelsize;
    Airport* aports;
    MyList* myQueue; // added for prog 7
    MyList* myStack; // added for prog 7
    MyList* fileList;

public:
    TravelNetwork();
    ~TravelNetwork();
    void depthFirstSearchHelper(int s, int t);
    bool dfs (int s, int t);
    void processCommandLoop (FILE* inFile);
    void showCommands();
    void doTravel();
    //
    void doShortestPath();
    MyList* breadthFirstSearch(int x, int y);
    bool bfs(int b);
    //
    void doResize();
    void doInsert();
    void doDelete();
    void doList();
    int countAsciiValues(char* afilename);
    void doFile();
};
#endif
