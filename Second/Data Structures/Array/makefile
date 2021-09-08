test_array: main.o Array.o
	g++ -o test_array main.o Array.o
main.o: main.cpp Array.h ../List/List.h
	g++ -c main.cpp
Array.o: Array.cpp Array.h ../List/List.h
	g++ -c Array.cpp

