
CXX=g++

ray: main.cpp vector3.o colour.o image.o
	$(CXX) -o ray main.cpp vector3.o colour.o image.o

.o:
	$(CXX) -c $(.SOURCE)

clean:
	rm -f *.o
