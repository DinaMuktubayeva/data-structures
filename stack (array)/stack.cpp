#include "stack.h"

stack::stack(const stack& stk) :
		values(new int[stk.array_capacity]),
		stack_size(stk.stack_size),
		array_capacity(stk.array_capacity)
{
    for (size_t i = 0; i < stk.stack_size; ++i)
        values[i] = stk.values[i];
}

stack::stack(std::initializer_list<int> ilist) :
	values(new int[ilist.size()]),
	stack_size(ilist.size()),
	array_capacity(ilist.size())
{
	size_t i = 0;

	for (int val: ilist) {
		values[i] = val;
		++i;
	}
}

stack& stack::operator=(const stack& stk) {

	// If stack sizes of the two objects are different,
	// the array of the object referenced as a parameter
	// is copied into a newly allocated space,
	// the array of the object that is being assigned to
	// is cleared, and its pointer is set to that copy.
	// Otherwise, the values in the array are simply
	// rewritten, to handle the cases of self-assignment
	if (stk.stack_size != stack_size) {

		stack_size = stk.stack_size;
		array_capacity = stk.array_capacity;

		int *new_values = new int[array_capacity];
		
		for (size_t i = 0; i < stack_size; ++i) {
			new_values[i] = stk.values[i];
		}

		delete[] values;

		values = new_values;

	} else {

		for (int i = 0; i < stack_size; ++i) {
			values[i] = stk.values[i];
		}
	}

	return *this;
}

void stack::push(int val) {

	// If the stack size is smaller than the
	// array capacity, the element is simply
	// written to the next place in the array.
	// Otherwise, the stack values are copied
	// to a newly allocated array of double
	// capacity, the element is safely pushed
	// into the copy, the current array is cleared,
	// and its pointer is set to the new array.
	if (stack_size < array_capacity) {		

		values[stack_size] = val;
		++stack_size;

	} else if (stack_size == array_capacity) {

		array_capacity *= 2;

		int* new_values = new int[array_capacity];
		
		for (size_t i = 0; i < stack_size; ++i) {
			new_values[i] = values[i];
		}

		new_values[stack_size] = val;
		++stack_size;

		delete[] values;

		values = new_values;
	}
}

int stack::peek() const {

	if (empty()) {
		throw std::invalid_argument("Cannot peek into an empty stack!");
	}
	return values[stack_size - 1];
}

void stack::pop() {
	
	if (empty()) {
		throw std::invalid_argument("Cannot pop from an empty stack!");
	}
	stack_size--;
}

void stack::clear() {
	stack_size = 0;
}

size_t stack::size() const {
    return stack_size;
}

bool stack::empty() const {
    return (stack_size == 0);
}

stack::~stack() {
    delete[] values;
}