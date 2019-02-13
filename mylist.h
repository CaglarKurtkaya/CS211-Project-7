#ifndef PROJECT6_MYLIST_H
#define PROJECT6_MYLIST_H
#include <iostream>
#include "mynode.h"

class MyList{
private:
    MyNode* phead;
    int Listlength; // bookkeeping for length

public:
   
    MyList();
    ~MyList();
    MyNode* getHead();
    int getLength();
    int getNthNode(int index);
    void setHead();
    void pushNode(int ID);
    // added for proj7
    void addToFrontOfList(int ID);
    int getValueAtFrontOfList();
    void removeValueFromFrontOfList();
	bool isListEmpty();
	//
    void popNode(int key);
    bool contains(int x);
    void printList();
    
    
}; 
#endif
