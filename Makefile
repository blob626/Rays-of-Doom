
CXX=g++
OBJ=vector3.o image.o camera.o ray.o triangle.o colour.o

ray: main.cpp $(OBJ)
	$(CXX) -o ray main.cpp $(OBJ)

.o:
	$(CXX) -c $(.SOURCE)

clean:
	rm -f *.o
