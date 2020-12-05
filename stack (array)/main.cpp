#include "stack.h"
#include <iostream>

void output(stack st) {
	std::cout << st.size() << " " << st.empty() << std::endl;
	std::cout << st << std::endl;
	std::cout << "" << std::endl;
}

int main() {

	std::cout << "Initializing a stack\n" << std::endl;
	stack st1;
	output(st1);

	std::cout << "Pushing items into the stack\n" << std::endl;
	for (int i = 11; i < 100; i = i + 11)
		st1.push(i);
	
	output(st1);

	std::cout << "Pushing more items into the stack\n" << std::endl;
	for (int i = 100; i < 1000; i = i + 100)
		st1.push(i);
	
	output(st1);
	
	std::cout << "Initializing a stack as a copy\n" << std::endl;
	stack st2 = st1;
	output(st2);
	
	std::cout << "Declaring a stack with initial values\n" << std::endl;	
	stack st3 = {123, 234, 345, 456, 567, 678, 789};
	output(st3);
	
	std::cout << "Initializing a stack as a copy\n" << std::endl;
	stack st4(st3);
	output(st4);	
	
	std::cout << "Clearing a stack\n" << std::endl;
	st1.clear();
	output(st1);
	
	std::cout << "Peek, push and pop\n" << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << st2.peek() << " ";
		st3.push(st2.peek());
		st2.pop();
	}
	std::cout << std::endl;
	
	output(st2);
	output(st3);
	output(st4);
}
