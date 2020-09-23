Flags = -Wreturn-type -pedantic -pedantic-errors -Wundef -std=c++17 -O5 -flto
	CPP = g++

main : Makefile main.o queue.o
	$(CPP) $(Flags) -o main main.o queue.o

main.o : Makefile main.cpp queue.h
	$(CPP) -c $(Flags) main.cpp -o main.o

queue.o : Makefile queue.cpp queue.h
	$(CPP) -c $(Flags) queue.cpp -o queue.o