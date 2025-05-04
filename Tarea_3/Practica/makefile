all: main TestGraph TestEdge TestVertex TestRead TestFordFulkerson

main: main.o Edge.o Vertex.o Graph.o Read.o FordFulkerson.o
	g++ Edge.o Vertex.o Graph.o Read.o FordFulkerson.o main.cpp -o main

TestGraph: TestGraph.cpp Graph.o Edge.o Vertex.o
	g++ TestGraph.cpp Graph.o Edge.o Vertex.o -o TestGraph

TestEdge: TestEdge.cpp Edge.o Vertex.o
	g++ TestEdge.cpp Edge.o Vertex.o -o TestEdge

TestVertex: TestVertex.cpp Vertex.o Edge.o
	g++ TestVertex.cpp Vertex.o Edge.o -o TestVertex

TestRead: TestRead.cpp Read.o Graph.o Vertex.o Edge.o
	g++ TestRead.cpp Read.o Graph.o Vertex.o Edge.o -o TestRead

TestFordFulkerson: TestFordFulkerson.cpp FordFulkerson.o
	g++ TestFordFulkerson.cpp FordFulkerson.o -o TestFordFulkerson

Edge.o: Edge.cpp Edge.h
	g++ -c Edge.cpp

Vertex.o: Vertex.cpp Vertex.h
	g++ -c Vertex.cpp

Graph.o: Graph.cpp Graph.h
	g++ -c Graph.cpp

Read.o: Read.cpp Read.h
	g++ -c Read.cpp

FordFulkerson.o: FordFulkerson.cpp FordFulkerson.h
	g++ -c FordFulkerson.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -f *.o main TestGraph TestEdge TestVertex TestRead TestFordFulkerson