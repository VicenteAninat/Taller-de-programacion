FLAGS = -g


all: TestEdge TestDinic TestRead TestMenu main


TestEdge: TestEdge.o Edge.o
	g++ ${FLAGS} TestEdge.o Edge.o -o TestEdge

TestDinic: TestDinic.o Dinic.o Edge.o GrafoBase.o
	g++ ${FLAGS} TestDinic.o Dinic.o Edge.o GrafoBase.o -o TestDinic

TestRead: TestRead.o Edge.o GrafoBase.o Read.o Dinic.o
	g++ ${FLAGS} TestRead.o Edge.o GrafoBase.o Read.o Dinic.o -o TestRead

TestMenu:

main: main.o Edge.o Read.o Dinic.o GrafoBase.o Menu.o
	g++ ${FLAGS} main.o Edge.o Read.o Dinic.o GrafoBase.o Menu.o -o main


Edge.o: Edge.cpp Edge.h
	g++ ${FLAGS} -c Edge.cpp

Read.o: Read.cpp Read.h
	g++ ${FLAGS} -c Read.cpp

Dinic.o: Dinic.cpp Dinic.h
	g++ ${FLAGS} -c Dinic.cpp

GrafoBase.o: GrafoBase.cpp GrafoBase.h
	g++ ${FLAGS} -c GrafoBase.cpp

Menu.o: Menu.cpp Menu.h Read.h Edge.h Dinic.h GrafoBase.h
	g++ ${FLAGS} -c Menu.cpp

main.o: main.cpp Edge.h Read.h Dinic.h GrafoBase.h Menu.h
	g++ ${FLAGS} -c main.cpp


TestEdge.o: TestEdge.cpp Edge.h
	g++ ${FLAGS} -c TestEdge.cpp

TestDinic.o: TestDinic.cpp Dinic.h Edge.h
	g++ ${FLAGS} -c TestDinic.cpp

TestRead.o: TestRead.cpp Read.h Edge.h Dinic.h GrafoBase.h
	g++ ${FLAGS} -c TestRead.cpp

TestMenu.o: TestMenu.cpp Menu.h Read.h Edge.h Dinic.h GrafoBase.h
	g++ ${FLAGS} -c TestMenu.cpp


clean:
	rm -f *.o TestEdge TestDinic TestRead