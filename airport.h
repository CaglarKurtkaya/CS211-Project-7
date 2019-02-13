#ifndef PROJECT6_AIRPORT_H
#define PROJECT6_AIRPORT_H

#include "mylist.h"





using namespace std;



class Airport{
private:
   int airId;
   int prevLocation;
   bool visited;
   MyList* adjList;

public:
   Airport(int ID);
   Airport();
   ~Airport();
   bool isVisited();
   void setVisted();
   void setNotVisited();
   void setAirId(int ID);
   void setPrevLoc(int l);
   int getAirId();
   int getPrevLoc();
   MyList* getAdjList();
   void insertAirport(int ID);
   void deleteAirport(int ID);
   void showConnectedAirports();
}; 



#endif


