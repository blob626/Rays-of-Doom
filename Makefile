
CC=g++

ray: main.cpp vector3.o
	$(CC) -o ray main.cpp vector3.o

vector3.o: vector3.h vector3.cpp
	$(CC) -c vector3.cpp
