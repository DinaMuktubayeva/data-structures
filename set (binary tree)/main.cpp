#include "set.h"
#include <iostream>

void output(const set& s) {
	std::cout << s.size() << " " << s.empty() << " " << s << std::endl;
}

// This is a minimal testing file.... we will use something more complete
// for grading!!!
int main() {

	set s1;
	output(s1);

	set s2 = {44, 22, 11, 33, 55};
	output(s2);

	set s3(s2);
	output(s3);

	for (int i = 99; i > 0; i = i - 11) {
		 std::cout << i << " " << s2.insert(i) << " " << s2.contains(i) << "; ";
	}
	std::cout << std::endl;
	output(s2);

	for (int i = 15; i < 100; i = i + 5) {
		 std::cout << i << " " << s2.insert(i) << " " << s2.contains(i) << "; ";
	}
	std::cout << std::endl;
	output(s2);

	output(s3);

	s1 = s2;
	output(s1);

	s1.clear();
	output(s1); output(s2); output(s3);

	s1.insert(123); s1.insert(234); s1.insert(98);
	output(s1);

	std::cout << "Done.";
}
