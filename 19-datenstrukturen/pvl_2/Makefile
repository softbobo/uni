# Makefile for second assignment for data structures

CPPFLAGS= g++ -g -Wall -Wextra -pedantic -std=c++11
OBJECTS= pvl_2-main.cpp pvl_2-students.cpp pvl_2-menu.cpp

all: $(OBJECTS)
	$(CPPFLAGS) -o pvl_2 $(OBJECTS)

pvl_2-students.o: pvl_2-students.cpp
	$(CPPFLAGS) -c pvl_2-students.cpp

pvl_2-menu.o: pvl_2-menu.cpp
	$(CPPFLAGS) -c pvl_2-menu.cpp