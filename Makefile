FLAGS := -g -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -Wall

ifeq ($(OS),Windows_NT)
$(info Windows n'est pas supporté)
else
	UNAME_S := $(shell uname -s)
$(info Système supporté: $(UNAME_S))
	ifeq ($(UNAME_S),Darwin)
		FLAGS := -g `pkg-config --libs --cflags raylib` -Wall
	endif
endif


all: main

main: main.o math.o sdf.o vec3.o
	gcc main.o math.o sdf.o vec3.o $(FLAGS) -o main

main.o: main.c
	gcc -c main.c $(FLAGS) -o main.o

math.o: math.c
	gcc -c math.c $(FLAGS) -o math.o

sdf.o: sdf.c
	gcc -c sdf.c $(FLAGS) -o sdf.o

vec3.o: vec3.c
	gcc -c vec3.c $(FLAGS) -o vec3.o


clean:
	rm -f *.o
	rm -f main
