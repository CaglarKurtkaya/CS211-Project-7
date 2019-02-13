#ifndef PROJECT6_MYNODE_H
#define PROJECT6_MYNODE_H

#include <cstdlib>
#include <cstdio>

class MyNode{
private:
    int nodeID;
    MyNode* pNext;

public:
    
    MyNode(int ID);
    void setNext(MyNode* node);
    int getId();
    MyNode* getNext();

}; 

#endif 
