# makefile
CC=g++
CFLAGS=-std=c++1z -Wall

main.out: main.o grVec2.o
	$(CC) $(CFLAGS) -o main.out main.o grVec2.o

main.o: tests/main.cpp
	$(CC) $(CFLAGS) -c tests/main.cpp

grVec2.o: math/grVec2.cpp math/grVec2.h
	$(CC) $(CFLAGS) -c math/grVec2.cpp

