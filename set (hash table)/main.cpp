#include <random>
#include <iostream>
#include <sstream>

#include "set.h"

std::string create(std::string str, int x) {

	std::stringstream ss;
	ss << str << x;
	return ss.str();
}

int main(int argc, char* argv[]) {

	set pets = {"Dog", "Cat", "Turtle", "Fish", "Fox"};

	set pets;

	pets.insert("cat");
	pets.insert("dog");

	std::cout << pets.contains("Cat") << "\n";
	std::cout << pets.contains("Dog") << "\n";

	pets.insert("GOLDFISH");
	std::cout << pets.contains("coldfish") << "\n";

	pets.insert("Turtle");
	pets.insert("Parrot");
	pets.insert("Humster");
	pets.insert("Mouse");
	pets.insert("Rabbit");

	std::cout << "Before removal\n";
	std::cout << pets << "\n";
	kaz.remove("rabbit");
	std::cout << "After removal\n";

	std::cout << "Set: " << pets << "\n";
	std::cout << "Set size: " << pets.size() << "\n";

	// If the numbers differ much, the tree is badly balanced.

	std::cout << "Initializing a set as a copy\n";
	auto pets2 = pets; // Copy constructor.
	std::cout << "Set: " << pets2 << "\n";
	std::cout << "Set size: " << pets2.size() << "\n";
	
	std::cout << "Checking assignment\n";
	pets2 = pets;
	
	std::cout << "Checking self-assignment\n";
	pets = pets;

	std::cout << "Load factor: " << pets.loadfactor() << std::endl; 
	std::cout << "Stdev: " << pets.standarddev() << std::endl;

	std::cout << "Initializing 2 sets and putting random values into them" << std::endl;
	set someset1;
	set someset2;

	for (size_t k = 0; k != 8000; ++k) {
		someset1.insert(create("aa", rand()));
		someset2.insert(create("bb", rand()));
	}

	std::cout << "Load factor of the 1st set: " << someset1.loadfactor() << std::endl; 
	std::cout << "Stdev of the 1st set: " << someset1.standarddev() << std::endl;
	std::cout << std::endl;
	std::cout << "Load factor of the 2nd set: " << someset2.loadfactor() << std::endl; 
	std::cout << "Stdev of the 2nd set: " << someset2.standarddev() << std::endl;	
	std::cout << std::endl;

	set test;
	std::vector<std::string> testlist = {"ww","wx","wy","wz","xw","xx","xy","xz","yw","yx","yy","yz","uy","iu","ry","ey","wg"};

	for (size_t i = 1; i < testlist.size(); ++i){
		test.insert(testlist[i-1]);
		std::cout<< i <<"	  "<< test.size() <<"	"<< test.loadfactor() <<"	  "<< test.standarddev() << std::endl;
	}
	
	test.remove("ww");
	std::cout<<"	  "<< test.size() <<"	"<< test.loadfactor() <<"	  "<< test.standarddev() << std::endl;
	test.remove("a");
	std::cout<<"	  "<< test.size() <<"	"<< test.loadfactor() <<"	  "<< test.standarddev() << std::endl;
	
	for(std::string s: testlist){
		test.insert(s);
		std::cout << test << std::endl;
		std::cout << test.loadfactor() << " "<< test.standarddev() << " " << test.size() << std::endl;		
	}

	return 0;
}
