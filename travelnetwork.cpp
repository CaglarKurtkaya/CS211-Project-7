


#include "travelnetwork.h"


    // Use a constructor to initialize the Data Members for Travel Network
TravelNetwork::TravelNetwork()
    {
        Travelsize = 10;
        fileList = new MyList;
        myQueue =  new MyList;
        myStack = new MyList;
        //Since we ignore the index 0, I will add 1 to macth the size
        aports = new Airport[Travelsize + 1];

        for(int i = 1; i< Travelsize; i++){
            aports[i].setAirId(i);
        }

    }
    
TravelNetwork::~TravelNetwork(){
    	delete [] aports;
    	delete fileList;
        delete myQueue;
        delete myStack;
	}




MyList* TravelNetwork::breadthFirstSearch (int x, int y)
{
    //mark all airports as unvisited (set all previousLocation to -1);

    for(int i = 1; i < Travelsize + 1; i++){
        aports[i].setPrevLoc(-1);
    }


    //set the list AirportQueue to be empty
    myQueue->setHead();

    //add x to the end of the AirportQueue
    myQueue->pushNode(x);

    if(bfs(y) == false){
        cout << "You can NOT get from airport " << x << " to airport " << y << " in one or more flights" << endl;
        return myQueue;
    }
    else{
        cout << "You can get from airport " << x << " to airport " << y << " in one or more flights" << endl;
        //pathList is set to an empty list
        myStack->setHead();
        //set currentAirport to y
        int currrentAirport = y;
        //add currentAirport to front of pathList
        myStack->addToFrontOfList(currrentAirport);

        do{
            currrentAirport = aports[currrentAirport].getPrevLoc();

            //add currentAirport to front of pathList
            myStack->addToFrontOfList(currrentAirport);
        }while(currrentAirport != x);
    }

    return myStack;
}


bool TravelNetwork::bfs(int b){

    while (myQueue->isListEmpty() != true)
    {
        //Set a to be the Airport at the front of the AirportQueue
        int a = myQueue->getValueAtFrontOfList();

        //Remove Airport at the front of the AirportQueue
        myQueue->removeValueFromFrontOfList();

        int size = aports[a].getAdjList()->getLength();

        for(int i = 0; i < size; i++) {

            int c = aports[a].getAdjList()->getNthNode(i);

            //airport c is unvisited (previousLocation is still -1
            if(aports[c].getPrevLoc() == -1){

                //mark airport c as visited (set previousLocation to a);
                aports[c].setPrevLoc(a);
                if(c == b){
                    return true;
                }

                myQueue->pushNode(c);

            }

        }


    }
    return false;
}



void TravelNetwork::depthFirstSearchHelper(int s, int t)
    {
        //mark all airports as unvisited
        for(int i = 1; i < Travelsize + 1; i++){
            aports[i].setNotVisited();
        }
        if (dfs(s, t) == true)
            cout << "You can get from airport " << s << " to airport " << t << " in one or more flights" << endl;
        else
            cout << "You can NOT get from airport " << s << " to airport " << t << " in one or more flights" << endl;
    }

bool TravelNetwork::dfs (int s, int t)
    {
        //get connected airports for source airport
        MyList* tmpList = aports[s].getAdjList();

        for (int i = 0; i < tmpList->getLength(); i++)
        {
            int id = tmpList->getNthNode(i);
            if (id == t)
                return true;
            // check if airport id is unvisited
            if ( aports[id ].isVisited() == false )
            {
                //mark airport id as visited
                aports[id ].setVisted();
                if ( dfs (id, t) == true )
                    return true;
            }
        }
        return false;
    }


    // The main loop for reading in input
void TravelNetwork::processCommandLoop (FILE* inFile)
    {
        char  buffer[300];
        char* input;

        input = fgets ( buffer, 300, inFile );   // get a line of input

        // loop until all lines are read from the input
        while (input != NULL)
        {
            // process each line of input using the strtok functions
            char* command;
            command = strtok (input , " \n\t");

            printf ("*%s*\n", command);

            if ( command == NULL )
                printf ("Blank Line\n");

            else if ( strcmp (command, "q") == 0){
            	this->~TravelNetwork();
                exit(1);
            }

            else if ( strcmp (command, "?") == 0)
                showCommands();

            else if ( strcmp (command, "t") == 0)
                doTravel();

            else if ( strcmp (command, "r") == 0)
                doResize();

            else if ( strcmp (command, "i") == 0)
                doInsert();

            else if ( strcmp (command, "d") == 0)
                doDelete();

            else if ( strcmp (command, "l") == 0)
                doList();

            else if ( strcmp (command, "f") == 0)
                doFile();
            
            else if ( strcmp (command, "s") == 0)
                doShortestPath();

            else if ( strcmp (command, "#") == 0)
                 ;

            else
                printf ("Command is not known: %s\n", command);

            input = fgets ( buffer, 300, inFile );   // get the next line of input

        }
    }

void TravelNetwork::showCommands()
    {
        printf ("The commands for this project are:\n");
        printf ("  q \n");
        printf ("  ? \n");
        printf ("  # \n");
        printf ("  t <int1> <int2> \n");
        printf ("  r <int> \n");
        printf ("  i <int1> <int2> \n");
        printf ("  d <int1> <int2> \n");
        printf ("  l \n");
        printf ("  f <filename> \n");
        printf ("  s <int1> <int2> \n");
        
    }
    
void  TravelNetwork::doShortestPath(){
		int val1 = 0;
        int val2 = 0;

        // get an integer value from the input
        char* next = strtok (NULL, " \n\t");
        if ( next == NULL )
        {
            printf ("Integer value expected\n");
            return;
        }
        val1 = atoi ( next );
        if ( val1 == 0 && strcmp (next, "0") != 0)
        {
            printf ("Integer value expected\n");
            return;
        }

        // get another integer value from the input
        next = strtok (NULL, " \n\t");
        if ( next == NULL )
        {
            printf ("Integer value expected\n");
            return;
        }
        val2 = atoi ( next );
        if ( val2 == 0 && strcmp (next, "0") != 0)
        {
            printf ("Integer value expected\n");
            return;
        }

		
    	if(val1 < 1 || val1 > Travelsize || val2 < 1 || val2 > Travelsize){
       			 cout << "The airport number is not valid. Should be in range from 1 to " << Travelsize << endl;
        		 return;
        	}

        printf ("Performing the Shorthest Path Command from %d to %d\n",
                val1, val2);

        MyList* shortestPath = breadthFirstSearch(val1, val2);
        shortestPath->printList();
        cout << endl;
	
}    

void TravelNetwork::doTravel()
    {
        int val1 = 0;
        int val2 = 0;

        // get an integer value from the input
        char* next = strtok (NULL, " \n\t");
        if ( next == NULL )
        {
            printf ("Integer value expected\n");
            return;
        }
        val1 = atoi ( next );
        if ( val1 == 0 && strcmp (next, "0") != 0)
        {
            printf ("Integer value expected\n");
            return;
        }

        // get another integer value from the input
        next = strtok (NULL, " \n\t");
        if ( next == NULL )
        {
            printf ("Integer value expected\n");
            return;
        }
        val2 = atoi ( next );
        if ( val2 == 0 && strcmp (next, "0") != 0)
        {
            printf ("Integer value expected\n");
            return;
        }

		
    	if(val1 < 1 || val1 > Travelsize || val2 < 1 || val2 > Travelsize){
       			 cout << "The airport number is not valid. Should be in range from 1 to " << Travelsize << endl;
        		 return;
        	}

        printf ("Performing the Travel Command from %d to %d\n",
                val1, val2);

        depthFirstSearchHelper(val1, val2);

    }

void TravelNetwork::doResize()
    {
    	
        int val1 = 0;

		//get user input
        char* next = strtok (NULL, "\n\t");
        if (next == NULL){
            cout << "Integer value expexted" << endl;
            return;
        }

        val1 = atoi(next);

        if(val1 == 0 && strcmp(next, "0") != 0){
            cout << "Integer value expexted" << endl;
            return;
        }
	
		// make sure the user input is valid 
		// then update the new travel network size
        if(val1 >= 1){
            cout << "Performing the Resize Command with " << val1 << endl;
            delete [] aports;
            Travelsize = val1;
            aports = new Airport[Travelsize + 1];

            for(int i = 0; i < Travelsize + 1; i++){
                aports[i].setAirId(i);
            }
            cout << "New Travel Network Size is = " << Travelsize << endl;
        }
		// give error if the user input is not valid
        else{
            cout << "Network size should be at least 1" << endl;
            return;
        }




    }

void TravelNetwork::doInsert()
    {
        int port1= 0 , port2 = 0;
        
		// get port1 from the input
        char* next = strtok (NULL, " \n\t");
            if ( next == NULL )
            {
                printf ("Integer value expected\n");
                return;
            }
            port1 = atoi ( next );
            if ( port1 == 0 && strcmp (next, "0") != 0)
            {
                printf ("Integer value expected\n");
                return;
            }

            // get airport2 from the input
            next = strtok (NULL, " \n\t");
            if ( next == NULL )
            {
                printf ("Integer value expected\n");
                return;
            }
            port2 = atoi ( next );
            if ( port2 == 0 && strcmp (next, "0") != 0)
            {
                printf ("Integer value expected\n");
                return;
            }
            
             if(port1 < 1 || port1 > Travelsize || port2 < 1 || port2 > Travelsize){
       			 cout << "The airport number is not valid. Shoul be in range from 1 to " << Travelsize << endl;
        		 return;
        	}

            cout << "Performing the insert command from " << port1 << " to " << port2 << endl;
            //insert the airport connection
            aports[port1 ].insertAirport(port2);
            


    }

void TravelNetwork::doDelete()
    {
        int port1= 0 , port2 = 0;
		
		// get port1 from the input
        char* next = strtok (NULL, " \n\t");
            if ( next == NULL )
            {
                printf ("Integer value expected\n");
                return;
            }
            port1 = atoi ( next );
            if ( port1 == 0 && strcmp (next, "0") != 0)
            {
                printf ("Integer value expected\n");
                return;
            }

            // get port2 from the input
            next = strtok (NULL, " \n\t");
            if ( next == NULL )
            {
                printf ("Integer value expected\n");
                return;
            }
            port2 = atoi ( next );
            if ( port2 == 0 && strcmp (next, "0") != 0)
            {
                printf ("Integer value expected\n");
                return;
            }

            cout << "Performing the delete command from " << port1 << " to " << port2 << endl;
            // delete the aiport connection
            aports[port1].deleteAirport(port2);

    }

void TravelNetwork::doList()
    {
        cout << "All Aiport Connections" << endl;
		
		// iterate the list and print it out 
        for(int i = 1; i < Travelsize + 1; i++){
            cout << i << "->";
            aports[i].showConnectedAirports();
            cout << endl;
        }

    }

	// sum the ascii values in given string and return it 
int TravelNetwork::countAsciiValues(char* afilename){
        int count = 0;
        for(unsigned int i = 0; i < strlen(afilename); i++){
            count = count + afilename[i];

        } 
        
        return count;
    }

void TravelNetwork::doFile()
    {

        // get a filename from the input
        char* fname = strtok (NULL, " \n\t");
        if ( fname == NULL )
        {
            printf ("Filename expected\n");
            return;
        }

       	//Get the file name and calculate the ascii values of the string 
       	//for example if you add each char's ascii value for proj6data1.txt it is going to be 1354
       	// and add it to the Mylist class. 
       	//It doesn't handle collisons if two strings having same ascii sum for example ad.txt and bc.txt
       	// both have sum of their each char's ascii 596
		// in this case this algorithm fails. But since we have unique txt file names, it will work fine for this project. 
		// A better solution would be a different List class for filenames or implement a template MyList class where we 
		// can handle different types of values(int, string, char*, etc) 
        int value = countAsciiValues(fname);
		
		
		// verify the file is not being used
        if(fileList->contains(value) == true ){       	
            cout << "File is already in use" << endl;
            return;
        }
		
		// open the file
        FILE* inputFile = fopen(fname, "r");
        
		// make sure it is open
        if(inputFile == NULL){
            cout << "Cannot open the file" << endl;
            return;
        }


        printf ("Performing the File command with file: %s\n", fname);

        // next steps:  (if any step fails: print an error message and return )
        //  1. verify the file name is not currently in use
        //  2. open the file using fopen creating a new instance of FILE*
        //  3. recursively call processCommandLoop() with this new instance of FILE* as the parameter
        //  4. close the file when processCommandLoop() returns
        
        //push the file currently open to the linked list 
        fileList->pushNode(value);
        //recursive call for processCommandLoop()
        processCommandLoop(inputFile);
        // cloe the file when processCommandLoop() returns
        fclose(inputFile);
        // pop the file from the linked list
        fileList->popNode(value);
        
        }
    
