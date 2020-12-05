#include "queue.h"
#include <iostream>

void output(const queue& q) {
	std::cout << q.size() << " " << q.empty() << " " << q << std::endl;
}

int main() {
	std::cout << "A queue\n";
	queue q1;
	output(q1);

	std::cout << "Empty queue\n";
	queue q2 = {};
	output(q2);

	std::cout << "Initialized copy\n";
	queue q3(q2);
	output(q3);

	std::cout << "Self-assignment\n";
	queue q;
	output(q);
	q = q;
	output(q);
	
	std::cout << "Pushing elements into a queue\n";
	for (int i = 1; i < 10; ++i)
		q2.push(i);
		
	output(q2);



	std::cout << "Peeking and popping from a queue\n";
	for (int x = 0; x < 10; ++x) {
		std::cout << q2.peek() << " ";
		q2.pop();
	}
	std::cout << std::endl;
	
	std::cout << "Copying queue's content\n";
	q1 = q2;
	output(q2);

	std::cout << "Clearing a queue\n";
	q1.clear();

	output(q1); 

	std::cout << "Peeking and popping from a queue until it's empty\n";
	while (!q2.empty()) {
		std::cout << q2.peek() << " ";
		q2.pop();
	}
	
	std::cout << std::endl;
	output(q2);
}
