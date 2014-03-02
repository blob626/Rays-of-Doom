
CXX=g++
CXXFLAGS= -std=c++11
OBJ=vector3.o image.o camera.o ray.o triangle.o colour.o mesh.o

ray: main.cpp $(OBJ)
	$(CXX) $(CXXFLAGS) -o ray main.cpp $(OBJ)

.o:
	$(CXX) $(CXXFLAGS) -c $(.SOURCE)

clean:
	rm -f *.o
