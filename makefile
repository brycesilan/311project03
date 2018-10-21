CXX = g++
CXXFLAGS = -c -g -std=c++11 -Wall -W -Werror -pedantic
LDFLAGS =

PROG = minq

$(PROG) : minpriority.o main.cpp
	$(CXX) $(LDFLAGS) minpriority.o -o $(PROG)

minpriority.o : minpriority.cpp minpriority.h
	$(CXX) $(CXXFLAGS) minpriority.cpp

clean :
	rm -f core $(PROG) *.o
