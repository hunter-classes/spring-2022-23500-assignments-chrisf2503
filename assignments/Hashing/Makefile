main: main.o list.o Node.o Person.o
	g++ -o main list.o main.o Node.o Person.o 

main.o: main.cpp Node.h Person.h 

list.o: list.cpp list.h Node.h Person.h

Node.o: Node.cpp Node.h Person.h

Person.o: Person.cpp Person.h

clean:
	rm -f *o