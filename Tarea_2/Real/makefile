all: main

main: main.o Read.o ColoringOperation.o Graph.o State.o
	g++ main.cpp Read.o ColoringOperation.o Graph.o State.o -o main

Read.o: Read.cpp Read.h
	g++ -c Read.cpp

ColoringOperation.o: ColoringOperation.cpp ColoringOperation.h
	g++ -c ColoringOperation.cpp

Graph.o: Graph.cpp Graph.h
	g++ -c Graph.cpp

State.o: State.cpp State.h
	g++ -c State.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -f *.o main Read ColoringOperation Graph State