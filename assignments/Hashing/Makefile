main: main.o Dictionary.o list.o Node.o Person.o 
	g++ -o main Dictionary.o list.o main.o Node.o Person.o 

tests: tests.o Dictionary.o list.o Node.o Person.o 
	g++ -o tests tests.o Dictionary.o list.o Node.o Person.o

main.o: main.cpp Dictionary.h list.h Node.h Person.h 

tests.o: tests.cpp doctest.h Dictionary.h list.h Node.h Person.h

Dictionary.o: Dictionary.cpp Dictionary.h list.h Person.o

list.o: list.cpp list.h Node.h Person.h

Node.o: Node.cpp Node.h Person.h

Person.o: Person.cpp Person.h

clean:
	rm -f *o