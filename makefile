#makefile

CXX = g++


combat: main.o startMenu.o character.o vampire.o barbarian.o blueMen.o medusa.o harryPotter.o
	${CXX} -o combat main.o startMenu.o character.o vampire.o barbarian.o blueMen.o medusa.o harryPotter.o

main.o: startMenu.cpp startMenu.hpp main.cpp character.cpp character.hpp vampire.cpp vampire.hpp barbarian.cpp barbarian.hpp blueMen.cpp blueMen.hpp medusa.cpp medusa.hpp harryPotter.cpp harryPotter.hpp
	${CXX} -c main.cpp

startMenu.o: startMenu.hpp startMenu.cpp
	${CXX} -c startMenu.cpp

character.o: character.hpp character.cpp
	${CXX} -c character.cpp

vampire.o: vampire.hpp vampire.cpp character.hpp character.cpp
	${CXX} -c vampire.cpp

barbarian.o: barbarian.hpp barbarian.cpp character.hpp character.cpp
	${CXX} -c barbarian.cpp

blueMen.o: blueMen.hpp blueMen.cpp character.hpp character.cpp
	${CXX} -c blueMen.cpp

medusa.o: medusa.hpp medusa.cpp character.hpp character.cpp
	${CXX} -c medusa.cpp

harryPotter.o: harryPotter.hpp harryPotter.cpp character.hpp character.cpp
	${CXX} -c harryPotter.cpp

clean:
	rm *.o combat
