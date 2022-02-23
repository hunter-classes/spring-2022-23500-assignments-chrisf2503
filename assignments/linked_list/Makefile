linkList: linkList.o Node.o
	g++ -o linkList linkList.o Node.o

linkList.o: linkList.cpp Node.h

Node.o: Node.cpp Node.h

clean:
	rm -f *o