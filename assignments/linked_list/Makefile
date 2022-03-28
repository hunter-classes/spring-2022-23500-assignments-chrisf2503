main: main.o Node.o list.o Olist.o
	g++ -o main main.o Node.o list.o Olist.o

tests: tests.o Olist.o Node.o 
	g++ -o tests tests.o Olist.o Node.o
tests.o: tests.cpp doctest.h Olist.h Node.h

main.o: main.cpp Olist.h Node.h

Olist.o: Olist.cpp Olist.h Node.h

Node.o: Node.cpp Node.h

list.o: list.cpp list.h

clean:
	rm -f *o