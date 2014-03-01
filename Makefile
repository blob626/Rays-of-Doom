
CXX=g++

ray: main.cpp *.o
	$(CXX) -o ray main.cpp *.o

.o:
	$(CXX) -c $(.SOURCE)

clean:
	rm -f *.o
