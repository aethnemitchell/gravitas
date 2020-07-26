# makefile
CC=g++
CFLAGS=-std=c++11 -Wall -Wextra -pedantic-errors

demo: grVec2.o grCvPoly2.o demo.o
	$(CC) $(CFLAGS) demo.o -o demo grVec2.o grCvPoly2.o -lsfml-graphics -lsfml-window -lsfml-system

demo.o: demos/grDemo.cpp
	$(CC) $(CFLAGS) -c -o demo.o demos/grDemo.cpp

main: grVec2.o grCvPoly2.o
	$(CC) $(CFLAGS) -o main grVec2.o grCvPoly2.o tests/main.cpp

grCvPoly2.o: math/grCvPoly2.cpp math/grCvPoly2.h
	$(CC) $(CFLAGS) -c math/grCvPoly2.cpp

grVec2.o: math/grVec2.cpp math/grVec2.h
	$(CC) $(CFLAGS) -c math/grVec2.cpp

clean:
	rm -f main grVec2.o grCvPoly2.o demo.o demo

