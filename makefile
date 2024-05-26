CXX= clang++
CXXFLAGS=-Wall -g

all: demo test


test: Test.o TestCounter.o
	$(CXX) $(CXXFLAGS) -o test Test.o TestCounter.o Graph.o Algorithms.o


demo: demo.o Graph.o Algorithms.o
	$(CXX) $(CXXFLAGS) -o demo demo.o Graph.o Algorithms.o


demo.o: demo.cpp
	$(CXX) $(CXXFLAGS) -c demo.cpp -o demo.o


Test.o: Test.cpp doctest.h Graph.hpp Algorithms.hpp
	$(CXX) $(CXXFLAGS) -c Test.cpp -o Test.o

TestCounter.o: TestCounter.cpp doctest.h
	$(CXX) $(CXXFLAGS) -c TestCounter.cpp -o TestCounter.o


Graph.o: Graph.cpp Graph.hpp
	$(CXX) $(CXXFLAGS) -c Graph.cpp -o Graph.o

Algorithms.o: Algorithms.cpp Algorithms.hpp
	$(CXX) $(CXXFLAGS) -c Algorithms.cpp -o Algorithms.o


clean:
	rm -f *.o demo test
