CC := g++ --std=c++11
CCFLAGS := -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer

minigolf.out: main.o rsdl.o ball.o wall.o distance.o utils.o hole.o mgolf.o 
	$(CC) main.o ball.o rsdl.o wall.o distance.o utils.o hole.o mgolf.o $(CCFLAGS) -o minigolf.out
main.o: main.cpp rsdl.hpp ball.hpp wall.hpp distance.hpp area.hpp utils.hpp
	$(CC) $(CCFLAGS) -c main.cpp
mgolf.o:mgolf.cpp mgolf.hpp ball.hpp wall.hpp hole.hpp area.hpp utils.hpp pointholder.hpp rsdl.o
	$(CC) -c mgolf.cpp rsdl.o $(CCFLAGS)
wall.o: wall.cpp wall.hpp ball.hpp utils.hpp rsdl.o
	$(CC) -c wall.cpp rsdl.o $(CCFLAGS)
ball.o: ball.cpp ball.hpp distance.o rsdl.o
	$(CC) -c ball.cpp distance.o rsdl.o $(CCFLAGS)
distance.o: distance.cpp distance.hpp rsdl.o
	$(CC) -c distance.cpp rsdl.o $(CCFLAGS)
hole.o: hole.cpp hole.hpp ball.o rsdl.o
	$(CC) -c hole.cpp rsdl.o $(CCFLAGS)
area.o: area.cpp area.hpp rsdl.o
	$(CC) -c area.cpp rsdl.o $(CCFLAGS)
pointholder.o: pointholder.cpp pointholder.hpp rsdl.o
	$(CC) -c pointholder.cpp rsdl.o $(CCFLAGS)
utils.o: utils.cpp utils.hpp rsdl.o
	$(CC) -c utils.cpp rsdl.o $(CCFLAGS)
rsdl.o: rsdl.cpp rsdl.hpp
	$(CC) -c rsdl.cpp
clean:
	rm -r *.o