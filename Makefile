all: iCopy

iCopy: main.o
	g++ main.o -o iCopy

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *o iCopy
