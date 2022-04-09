main: main.o Node.o list.o stack.o
	g++ -o main main.o Node.o list.o stack.o

main.o: main.cpp stack.h

stack.o: stack.cpp stack.h list.h

Node.o: Node.cpp Node.h

list.o: list.cpp list.h

clean:
	rm -f *o