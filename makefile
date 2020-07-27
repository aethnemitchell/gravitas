# makefile
CC=g++
CFLAGS=-std=c++11 -Wall -Wextra -pedantic-errors

demo: grCvPoly2.o demo.o grEntity.o grWorld.o
	$(CC) $(CFLAGS) demo.o -o demo grVec2.o grCvPoly2.o grRenderC.o grColliderC.o grEntity.o grWorld.o -lsfml-graphics -lsfml-window -lsfml-system

demo.o: demos/grDemo.cpp
	$(CC) $(CFLAGS) -c -o demo.o demos/grDemo.cpp

main: grCvPoly2.o
	$(CC) $(CFLAGS) -o main grVec2.o grCvPoly2.o tests/main.cpp

grEntity.o: grCvPoly2.o grVec2.o grRenderC.o grColliderC.o
	$(CC) $(CFLAGS) -c components/grEntity.cpp

grRenderC.o: grCvPoly2.o
	$(CC) $(CFLAGS) -c components/grRenderC.cpp

grWorld.o: grColliderC.o grCvPoly2.o
	$(CC) $(CFLAGS) -c phys/grWorld.cpp

grColliderC.o: grCvPoly2.o
	$(CC) $(CFLAGS) -c components/grColliderC.cpp

grCvPoly2.o: math/grCvPoly2.cpp math/grCvPoly2.h
	$(CC) $(CFLAGS) -c math/grCvPoly2.cpp

grVec2.o: math/grVec2.cpp math/grVec2.h
	$(CC) $(CFLAGS) -c math/grVec2.cpp

clean:
	rm -f main grVec2.o grCvPoly2.o grEntity.o grRenderC.o demo.o demo grColliderC.o grWorld.o

