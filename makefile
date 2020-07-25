# makefile
CC=g++
CFLAGS=-std=c++1z -Wall

main.out: grVec2.o grCvPoly2.o
	$(CC) $(CFLAGS) -o main.out grVec2.o grCvPoly2.o tests/main.cpp

grCvPoly2.o: math/grCvPoly2.cpp math/grCvPoly2.h
	$(CC) $(CFLAGS) -c math/grCvPoly2.cpp

grVec2.o: math/grVec2.cpp math/grVec2.h
	$(CC) $(CFLAGS) -c math/grVec2.cpp

clean:
	rm main.out grVec2.o grCvPoly2.o

