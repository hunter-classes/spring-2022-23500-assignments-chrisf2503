main: main.o BSTree.o Node.o
	g++ -o main main.o BSTree.o Node.o

tests: tests.o BSTree.o Node.o
	g++ -o tests tests.o BSTree.o Node.o

main.o: main.cpp BSTree.h Node.h

tests.o: tests.cpp doctest.h BSTree.h Node.h

BSTree.o: BSTree.cpp BSTree.h Node.h

Node.o: Node.cpp Node.h

clean:
	rm -f *o;