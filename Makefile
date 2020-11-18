CXX=g++

#executable name
project=main

all : ${project}

#linking
${project} : Arrete.o Sommet.o Graphe.o main.o
	${CXX} $^ -o ${project}

#compile object files
main.o : main.cpp Graphe.h Sommet.h Arrete.h
Arrete.o: Arrete.cpp Arrete.h
Sommet.o: Sommet.cpp Sommet.h
Graphe.o: Graphe.cpp Graphe.h

clean:
	rm -f *~ *.o ${project}

