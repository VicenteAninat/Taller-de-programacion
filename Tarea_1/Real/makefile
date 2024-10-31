FLAGS = -g
#FLAGS = -O2

all: test_Bidon test_GrupoBidones test_Leer test_OperacionLlenar test_OperacionTrasvasijar test_OperacionVaciar test_JugProb test_Menu
# test_Main  

test_Bidon: Bidon.o test_Bidon.cpp
	g++ ${FLAGS} Bidon.o test_Bidon.cpp -o test_Bidon

test_GrupoBidones: GrupoBidones.o test_GrupoBidones.cpp
	g++ ${FLAGS} GrupoBidones.o test_GrupoBidones.cpp Bidon.o -o test_GrupoBidones

test_Leer: Leer.o test_Leer.cpp
	g++ ${FLAGS} Leer.o test_Leer.cpp GrupoBidones.o Bidon.o -o test_Leer

test_JugProb: JugProb.o test_JugProb.cpp
	g++ ${FLAGS} JugProb.o test_JugProb.cpp OperacionLlenar.o OperacionTrasvasijar.o OperacionVaciar.o GrupoBidones.o Bidon.o -o test_JugProb

test_Menu: Menu.o test_Menu.cpp
	g++ ${FLAGS} Menu.o test_Menu.cpp JugProb.o Leer.o GrupoBidones.o Bidon.o -o test_Menu

test_OperacionLlenar: OperacionLlenar.o test_OperacionLlenar.cpp Operacion.o
	g++ ${FLAGS} OperacionLlenar.o test_OperacionLlenar.cpp Operacion.o GrupoBidones.o Bidon.o -o test_OperacionLlenar

test_OperacionTrasvasijar: OperacionTrasvasijar.o test_OperacionTrasvasijar.cpp Operacion.o
	g++ ${FLAGS} OperacionTrasvasijar.o test_OperacionTrasvasijar.cpp Operacion.o GrupoBidones.o Bidon.o -o test_OperacionTrasvasijar

test_OperacionVaciar: OperacionVaciar.o test_OperacionVaciar.cpp Operacion.o
	g++ ${FLAGS} OperacionVaciar.o test_OperacionVaciar.cpp Operacion.o GrupoBidones.o Bidon.o -o test_OperacionVaciar


Bidon.o : Bidon.cpp Bidon.h
	g++ ${FLAGS} -c Bidon.cpp

GrupoBidones.o : GrupoBidones.cpp GrupoBidones.h
	g++ ${FLAGS} -c GrupoBidones.cpp

Leer.o : Leer.cpp Leer.h
	g++ ${FLAGS} -c Leer.cpp 

JugProb.o : JugProb.cpp JugProb.h
	g++ ${FLAGS} -c JugProb.cpp

Menu.o : Menu.cpp Menu.h
	g++ ${FLAGS} -c Menu.cpp

Operacion: Operacion.cpp Operacion.h
	g++ ${FLAGS} -c Operacion.cpp

OperacionLlenar.o : OperacionLlenar.cpp OperacionLlenar.h 
	g++ ${FLAGS} -c OperacionLlenar.cpp

OperacionTrasvasijar.o : OperacionTrasvasijar.cpp OperacionTrasvasijar.h
	g++ ${FLAGS} -c OperacionTrasvasijar.cpp

OperacionVaciar.o : OperacionVaciar.cpp OperacionVaciar.h
	g++ ${FLAGS} -c OperacionVaciar.cpp

clear:
	rm -f *.o test_Bidon test_GrupoBidones test_JugProb test_Leer test_Main test_Menu test_OperacionLlenar test_OperacionTrasvasijar test_OperacionVaciar