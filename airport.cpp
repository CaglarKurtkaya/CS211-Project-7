

#include "airport.h"
 
   // Constructor
Airport::Airport(int ID){
       airId = ID;
       prevLocation = -1;
       visited = false;
       adjList = new MyList;
   }

Airport::Airport(){
       airId = 0;
       prevLocation = -1;
       visited = false;
       adjList = new MyList;
   }
   // Destructor
Airport::~Airport(){
       airId = 0;
       visited = false;
       delete adjList;
   }

bool Airport::isVisited(){
       return visited;
   }

   // set member functions
   //==================================================
void Airport::setVisted(){
       visited = true;
   }

void Airport::setNotVisited(){
       visited = false;
   }

void Airport::setAirId(int ID){
       airId = ID;
   }

void Airport::setPrevLoc(int l){
    prevLocation = l;
    }

   // get member functions
   //==================================================

int Airport::getAirId(){
       return airId;
   }

MyList* Airport::getAdjList(){
       return adjList;
   }

int Airport::getPrevLoc(){
    return prevLocation;
}

   //insert connected airport
void Airport::insertAirport(int ID){
       adjList->pushNode(ID);
   }

   //delete connected airport
void Airport::deleteAirport(int ID){
       adjList->popNode(ID);
   }

   // print all connected airports
void Airport::showConnectedAirports(){
       adjList->printList();
   }



//=============================================================================================



