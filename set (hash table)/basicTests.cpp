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

/*	set pets;
	pets.insert("Cat");
	pets.insert("Dog");
	
	std::cout << "before removal\n";
	std::cout << pets << "\n";
	pets.remove("dog");
	std::cout << "after removal\n";
	std::cout << pets << "\n";
	std::cout << "Pets contains cat: "<<pets.contains("cat")<<std::endl;
	std::cout << "Pets contains dog: "<<pets.contains("dog")<<std::endl;

	pets.insert("Fox");
	pets.insert("Parrot");
	pets.insert("Snake");
	pets.insert("Hamster");
	pets.insert("Tiger");
	std::cout << pets<<std::endl;
//	pets.clear();
//	std::cout<<pets<<std::endl;

	auto animals = pets;

	std::cout << "Animals\n";
	std::cout << animals << std::endl;
	std::cout <<"Pets\n";
	std::cout << pets << std::endl;

	pets.insert("Turtle");

	animals = pets;

	std::cout << "Animals\n";
	std::cout << animals << std::endl;
	std::cout <<"Pets\n";
	std::cout << pets << std::endl;

	return 0;
}*/
	set pets = {"Dog", "Cat", "Turtle", "Fish", "Fox"};

	set kaz;

	kaz.insert("aqtobe");
	kaz.insert("atyrau");

	std::cout << kaz.contains("Aqtobe") << "\n";
	std::cout << kaz.contains("AqToBe") << "\n";
	// Or not to be, that's the question.

	kaz.insert("SHYMKENT");
	std::cout << kaz.contains("szymkent") << "\n";

	kaz.insert("Almaty");
	kaz.insert("Taraz");
	kaz.insert("Qaraghandy");
	kaz.insert("Qostanay");
	kaz.insert("Kokshetau");

	std::cout << "before removal\n";
	std::cout << kaz << "\n";
	kaz.remove("qostanay");
	std::cout << "after removal\n";

	std::cout << kaz << "\n";
	std::cout << kaz.size() << "\n";

	// If the numbers differ much, the tree is badly balanced.

	auto kaz2 = kaz; // Copy constructor.
	std::cout << kaz2 << "\n";
	std::cout << kaz2.size() << "\n";
	kaz2 = kaz;      // Assignment.
	kaz = kaz;       // Self assignment.

	std::cout << kaz.loadfactor() << " " << kaz.standarddev() << std::endl;

	set someset1;
	set someset2;

	for (size_t k = 0; k != 8000; ++k) {
		someset1.insert(create("aa", rand()));
		someset2.insert(create("bb", rand()));
	}

	//auto someset2 = someset1;
	//std::cout << someset1 << std::endl;
	std::cout << someset1.loadfactor() << "	" << someset1.standarddev() << std::endl;
	std::cout << someset2.loadfactor() << "	" << someset2.standarddev() << std::endl;


/*
	return 0;
}

	set test;
	std::vector<std::string> testlist = {"ww","wx","wy","wz","xw","xx","xy","xz","yw","yx","yy","yz","uy","iu","ry","ey","wg"};

	for(size_t i=1; i<testlist.size(); ++i){
		test.insert(testlist[i-1]);
		std::cout<<i<<"	  "<<test.size()<<"	"<<test.loadfactor()<<"	  "<<test.standarddev()<<std::endl;
	}
	test.remove("ww");
		std::cout<<"	  "<<test.size()<<"	"<<test.loadfactor()<<"	  "<<test.standarddev()<<std::endl;
	test.remove("a");
		std::cout<<"	  "<<test.size()<<"	"<<test.loadfactor()<<"	  "<<test.standarddev()<<std::endl;
	
	for(std::string s: testlist){
		test.insert(s);
		std::cout << test <<std::endl;
		std::cout << test.loadfactor() << " "<< test.standarddev() << " " << test.size() << std::endl;		
	}*/

	return 0;
}
