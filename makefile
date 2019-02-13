proj7: Ckurtk2Proj7.o airport.o travelnetwork.o mylist.o mynode.o
	g++ -o proj7 Ckurtk2Proj7.o airport.o travelnetwork.o mylist.o mynode.o

Ckurtk2Proj7.o: Ckurtk2Proj7.cpp airport.h travelnetwork.h mylist.h mynode.h
	g++ -c Ckurtk2Proj7.cpp 

airport.o: airport.cpp airport.h travelnetwork.h mylist.h mynode.h
	g++ -c airport.cpp

travelnetwork.o: travelnetwork.cpp airport.h travelnetwork.h mylist.h mynode.h
	g++ -c travelnetwork.cpp

mylist.o: mylist.cpp airport.h travelnetwork.h mylist.h mynode.h
	g++ -c mylist.cpp

mynode.o: mynode.cpp airport.h travelnetwork.h mylist.h mynode.h
	g++ -c mynode.cpp

clean: Ckurtk2Proj7.o airport.o travelnetwork.o mylist.o mynode.o
	rm *.o && rm proj7
