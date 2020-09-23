Flags = -Wreturn-type -pedantic -pedantic-errors -Wundef -std=c++17 -O5 -flto
	CPP = g++

basicTests : Makefile basicTests.o set.o
	$(CPP) $(Flags) -o basicTests basicTests.o set.o

basicTests.o : Makefile basicTests.cpp set.h
	$(CPP) -c $(Flags) basicTests.cpp -o basicTests.o

set.o : Makefile set.cpp set.h
	$(CPP) -c $(Flags) set.cpp -o set.o
