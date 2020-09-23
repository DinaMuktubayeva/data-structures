#include "stack.h"
#include <iostream>

void output(stack st) {
	std::cout << st.size() << " " << st.empty() << std::endl;
	std::cout << st << std::endl;
	std::cout << "" << std::endl;
}

// This is a minimal testing file.... we will use something more complete
// for grading!!!
int main() {

	stack st1;
	output(st1);

	for (int i = 11; i < 100; i = i + 11) {
		st1.push(i);
	}
	output(st1);

	for (int i = 100; i < 1000; i = i + 100) {
		st1.push(i);
	}
	output(st1);

	stack st2 = st1;
	stack st3 = {123, 234, 345, 456, 567, 678, 789};
	stack st4(st3);

	output(st2);
	output(st3);
	output(st4);

	st1.clear();

	for (int i = 0; i < 5; i++) {
		std::cout << st2.peek() << " ";
		st3.push(st2.peek());
		st2.pop();
	}
	std::cout << std::endl;

	output(st1);
	output(st2);
	output(st3);
	output(st4);

	stack st;
}



