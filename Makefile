CXX = g++
CXXFLAGS = -Wall -std=c++11

all: prog

prog: main.cpp Matrix.cpp
	$(CXX) $(CXXFLAGS) main.cpp Matrix.cpp -o prog

clean:
	rm -f prog