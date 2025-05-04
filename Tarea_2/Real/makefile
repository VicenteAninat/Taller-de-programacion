all: main TestGraph TestState TestRead TestColoringOperation

main: main.o Read.o ColoringOperation.o Graph.o State.o
	g++ main.cpp Read.o ColoringOperation.o Graph.o State.o -o main

TestGraph: TestGraph.o Graph.o
	g++ TestGraph.cpp Graph.o -o TestGraph

TestState: TestState.o State.o Graph.o
	g++ TestState.cpp State.o Graph.o -o TestState

TestRead: TestRead.o Read.o Graph.o State.o
	g++ TestRead.cpp Read.o Graph.o State.o -o TestRead

TestColoringOperation: TestColoringOperation.o ColoringOperation.o Graph.o State.o
	g++ TestColoringOperation.cpp ColoringOperation.o Graph.o State.o -o TestColoringOperation

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

TestGraph.o: TestGraph.cpp Graph.cpp
	g++ -c TestGraph.cpp

TestState.o: TestState.cpp State.cpp Graph.cpp
	g++ -c TestState.cpp

TestRead.o: TestRead.cpp Read.cpp Graph.cpp State.cpp
	g++ -c TestRead.cpp

TestColoringOperation.o: TestColoringOperation.cpp ColoringOperation.cpp Graph.cpp State.cpp
	g++ -c TestColoringOperation.cpp

clean:
	rm -f *.o main Read ColoringOperation Graph State TestGraph TestState TestRead TestColoringOperation