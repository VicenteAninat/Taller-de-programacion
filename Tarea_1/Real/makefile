FLAGS = -g
#FLAGS = -O2

all: test_Bidon test_GrupoBidones test_Jugprob test_Leer test_Main test_Menu test_OperacionLlenar test_OperacionTrasvasijar test_OperacionVaciar

test_Bidon: Bidon.o test_Bidon.cpp
	g++ ${FLAGS} Bidon.o test_Bidon.cpp -o test_Bidon

test_GrupoBidones: GrupoBidones.o test_GrupoBidones.cpp
	g++ ${FLAGS} GrupoBidones.o test_GrupoBidones.cpp -o test_GrupoBidones

test_Jugprob:
	g++ ${FLAGS} ? -o test_Jugprob

test_Leer:
	g++ ${FLAGS} ? -o test_Leer

test_Menu:
	g++ ${FLAGS} ? -o test_Menu

test_OperacionLlenar:
	g++ ${FLAGS} ? -o test_OperacionLlenar

test_OperacionTrasvasijar:
	g++ ${FLAGS} ? -o test_OperacionTrasvasijar

test_OperacionVaciar:
	g++ ${FLAGS} ? -o test_OperacionVaciar

Bidon.o : Bidon.cpp Bidon.h
	g++ ${FLAGS} -c Bidon.cpp

GrupoBidones.o : GrupoBidones.cpp GrupoBidones.h
	g++ ${FLAGS} -c GrupoBidones.cpp

Jugprob.o : Jugprob.cpp Jugprob.h
	g++ ${FLAGS} -c Jugprob.cpp

Leer.o : Leer.cpp Leer.h
	g++ ${FLAGS} -c Leer.cpp

Main.o : Main.cpp
	g++ ${FLAGS} -c Main.cpp

Menu.o : Menu.cpp Menu.h
	g++ ${FLAGS} -c Menu.cpp

OperacionLlenar.o : OperacionLlenar.cpp OperacionLlenar.h
	g++ ${FLAGS} -c OperacionLlenar.cpp

OperacionTrasvasijar.o : OperacionTrasvasijar.cpp OperacionTrasvasijar.h
	g++ ${FLAGS} -c OperacionTrasvasijar.cpp

OperacionVaciar.o : OperacionVaciar.cpp OperacionVaciar.h
	g++ ${FLAGS} -c OperacionVaciar.cpp

clean:
	rm -f *.o test_Bidon test_GrupoBidones test_Jugprob test_Leer test_Main test_Menu test_OperacionLlenar test_OperacionTrasvasijar test_OperacionVaciar