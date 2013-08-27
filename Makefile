all: source.cpp eatMemory.cpp eatDisk.cpp
	g++ -std=c++0x -c source.cpp -o main.o
	g++ -std=c++0x -c eatMemory.cpp
	g++ -std=c++0x -c eatDisk.cpp
	g++ -std=c++0x eatDisk.o eatMemory.o main.o -o dame

eatDisk: eatDisk.cpp
	g++ -std=c++0x -c eatDisk.cpp

eatMemory: eatMemory.cpp
	g++ -std=c++0x -c eatMemory.cpp

main: source.cpp
	g++ -std=c++0x -c source.cpp -o main.o

compile: eatDisk.o eatMemory.o main.o
	g++ -std=c++0x eatDisk.o eatMemory.o main.o -o dame
clean: 
	rm -rf *.o dame
