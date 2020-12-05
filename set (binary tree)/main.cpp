#include "set.h"
#include <iostream>

void output(const set& s) {
	std::cout << s.size() << " " << s.empty() << " " << s << std::endl;
}

int main() {
	std::cout << "A set\n";
	set s1;
	output(s1);

	std::cout << "A set with initial value\n";
	set s2 = {44, 22, 11, 33, 55};
	output(s2);

	std::cout << "A set initialized as a copy\n";
	set s3(s2);
	output(s3);

	std::cout << "Inserting values into a set and checking if it contains that value after that\n";
	std::cout << "The value are printed as: Value isInserted Contains\n";	
	std::cout << "The set already contained 44, 22, 11, 33 and 55\n";
	std::cout << "The output line should look like this: 44 0 1\n";	
	for (int i = 99; i > 0; i = i - 11) 
		 std::cout << i << " " << s2.insert(i) << " " << s2.contains(i) << std::endl;
	
	std::cout << "The entire set\n";
	output(s2);

	std::cout << "Inserting values into a set and checking if it contains that value after that\n";
	std::cout << "The value are printed as: Value isInserted Contains\n";
	for (int i = 15; i < 100; i = i + 5) 
		 std::cout << i << " " << s2.insert(i) << " " << s2.contains(i) << std::endl;
	
	std::cout << "The entire set\n";
	output(s2);

	std::cout << "Copying the contents of one set into another\n";
	s1 = s2;
	output(s1);
	output(s2);

	std::cout << "Clearing a set\n";
	s1.clear();
	output(s1);

	std::cout << "Inserting values into the cleared set\n";
	s1.insert(123); 
	s1.insert(234); 
	s1.insert(98);
	output(s1);

	std::cout << "Done\n";
}
