
#include "mylist.h"
#include <iostream>
using namespace std;
   // Constructor
MyList::MyList(){
        phead = NULL;
        Listlength = 0;

    }

    //Destructor
MyList::~MyList(){
        if(phead == NULL){
            return;
        }
        MyNode* temp = NULL;
        // free the whole list
        while (phead != NULL) {
            temp = phead;
            phead = phead->getNext();
            delete temp;
        }
        
        delete phead; // free memory
        
    }

    //get member functions
    //==================================================

MyNode* MyList::getHead(){
        return phead;
    }

int MyList::getLength(){
        return Listlength;
    }

int MyList::getNthNode(int index){
        // set temp to phead
        MyNode* temp = phead;

        //counter
        int count = 0;

        //iterate the list to find the index
        while(temp != NULL){
            // return the id stored in the index
            if(count ==index){
                return temp->getId();
            }
            // increment the count until index is found
            count++;
            // check the next node
            temp = temp->getNext();
        }


        //if we get here caller asking non-existent element
        return -999;
    }
    //==================================================

void MyList::setHead(){
    phead = NULL;
}

    //insert node
void MyList::pushNode(int ID){
        MyNode* temp = phead;
        MyNode* addNode = new MyNode(ID);
        Listlength++; // bookkeping for length;

        //base case head is null
        if(phead == NULL){
            phead = addNode;
            return;
        }
        //List is not empty add node at the end
        else{
            while (temp->getNext() != NULL) {
                temp = temp->getNext();
            }
            //when we get here we are pointing the last node at the end
            // connect the addNode to the end of the list
            temp->setNext(addNode);
            return;
        }
    }
    
void MyList::addToFrontOfList(int ID){
	MyNode* temp = phead;
	MyNode* addNode = new MyNode(ID);
	Listlength++; // bookkeping for length;
	
	addNode->setNext(phead);
	phead = addNode;
	
}

int MyList::getValueAtFrontOfList(){
	return phead->getId();
}


void MyList::removeValueFromFrontOfList( ){
	
	if(phead != NULL){
		MyNode* temp = phead->getNext();
		delete phead;
		phead = temp;
		Listlength--;
	}
	
}

bool MyList::isListEmpty(){
	if(phead == NULL){
		return true;
	}
	else{
		return false;
	}
}
    // delete node
void MyList::popNode(int key){

        // Store head node
        MyNode* temp = phead , *prev;

        // If head node itself holds the key to be deleted
        if (temp != NULL && temp->getId() == key)
        {
            phead = temp->getNext();   // Changed head
            delete temp;               // free old head
            Listlength--;
            return;
        }

        // Search for the key to be deleted, keep track of the
        // previous node as we need to change 'prev->next'
        while (temp != NULL && temp->getId() != key)
        {
            prev = temp;
            temp = temp->getNext();
        }

        // If key was not present in linked list
        if (temp == NULL) return;

        // Unlink the node from linked list
        prev->setNext(temp->getNext());

        delete temp;  // Free memory
        Listlength--;
    }

	// find if given int x is in the list
bool MyList::contains(int x){
        MyNode* temp = phead;
        while (temp != NULL) {
            if(temp->getId() == x){
                return true;
            }
            temp = temp->getNext();
        }
        return false;
    }

  	// iterate the list and print it out
void MyList::printList(){
        if(phead == NULL) return;

        MyNode* temp = phead;
        while (temp != NULL) {
            cout << temp->getId() << "->";
            temp = temp->getNext();
        }
    }





//=============================================================================================


