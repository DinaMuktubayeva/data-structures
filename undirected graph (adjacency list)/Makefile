Flags = -Wreturn-type -pedantic -pedantic-errors -Wundef -std=c++17 -O5 -flto
	CPP = g++

main : Makefile main.o graph.o
	$(CPP) $(Flags) -o main main.o graph.o

main.o : Makefile main.cpp graph.h
	$(CPP) -c $(Flags) main.cpp -o main.o

graph.o : Makefile graph.cpp graph.h
	$(CPP) -c $(Flags) graph.cpp -o graph.o