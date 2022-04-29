main: main.o Node.o list.o stack.o Queues.o
	g++ -o main main.o Node.o list.o stack.o Queues.o

tests: tests.o Node.o list.o stack.o Queues.o
	g++ -o tests tests.o Node.o list.o stack.o Queues.o

main.o: main.cpp stack.h Queues.h

tests.o: tests.cpp stack.h doctest.h Queues.h

Queues.o: Queues.cpp Queues.h

stack.o: stack.cpp stack.h list.h

Node.o: Node.cpp Node.h

list.o: list.cpp list.h Node.h

clean:
	rm -f *o