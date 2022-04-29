main: main.o Node.o list.o stack.o
	g++ -o main main.o Node.o list.o stack.o

tests: tests.o Node.o list.o stack.o
	g++ -o tests tests.o Node.o list.o stack.o

main.o: main.cpp stack.h

tests.o: tests.cpp stack.h doctest.h

stack.o: stack.cpp stack.h list.h

Node.o: Node.cpp Node.h

list.o: list.cpp list.h Node.h

clean:
	rm -f *o