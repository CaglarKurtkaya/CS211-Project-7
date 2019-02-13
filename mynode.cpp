
#include "mynode.h"



//=============================================================================================
    //Constructor
MyNode::MyNode(int ID){
        nodeID = ID;
        pNext = NULL;
    }

    //set member functions
    //==================================================
void MyNode::setNext(MyNode* node){
        pNext = node;

    }


    //get member functions
    //==================================================
int MyNode::getId(){
        return nodeID;
    }

MyNode* MyNode::getNext(){
        return pNext;
    }

//=============================================================================================


