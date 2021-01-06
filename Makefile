prog: main.o executive.o
	g++ -std=c++11 -g -Wall main.o executive.o -o prog

main.o: main.cpp executive.h 
	g++ -std=c++11 -g -Wall -c main.cpp
	
executive.o: executive.h executive.cpp sorts.h sorts.cpp sortTimer.h sortTimer.cpp
	g++ -std=c++11 -g -Wall -c executive.cpp
	
clean:
	rm *.o prog