# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall -Iinc
LSFMFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
#mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
#current_dir := $(notdir $(patsubst %/,%,$(dir $(mkfile_path))))
current_dir := ${CURDIR}
# The build target 

TG = make_obj_dir Particle
all: $(TG)

make_obj_dir:
	mkdir -p obj

Particle: main.o Particle.o Vector.o
	$(CC) $(CFLAGS) $(LSFMFLAGS) -o Particle ./obj/main.o ./obj/Particle.o ./obj/Vector.o
	
# The main.o target can be written more simply
main.o: ./src/main.cpp ./inc/Vector.h ./inc/Particle.h
	$(CC) $(CFLAGS) -c ./src/main.cpp -o ./obj/main.o

Vector.o: ./src/Vector.cpp ./inc/Vector.h
	$(CC) $(CFLAGS) -c ./src/Vector.cpp -o ./obj/Vector.o

Particle.o: ./src/Particle.cpp ./inc/Particle.h ./inc/Vector.h
	$(CC) $(CFLAGS)  -c ./src/Particle.cpp -o ./obj/Particle.o

clean: 
	@echo " "
	@echo "** Clean ... "
	cd $(current_dir); \
	rm -r obj; \
	rm Particle 

go:
	./Particle 
