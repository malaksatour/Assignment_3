# Name: Malak Satour
# ID: 900241965

CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic

DEMO := assignment_3_demo
SOURCES := main.cpp Code/Graph.cpp

.PHONY: all demo run clean

all: demo

demo: $(DEMO)

$(DEMO): $(SOURCES) Code/Graph.h
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(DEMO)

run: demo
	./$(DEMO)

clean:
	rm -f $(DEMO)
	rm -rf build
