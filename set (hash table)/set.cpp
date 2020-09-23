#include "set.h"
#include <iostream>
#include <list>

bool equal(const std::string &s1, const std::string &s2) {

	if (s1.size() != s2.size()) {

		return false;

	} else {

		// Comparing the lowercase of every character pair
		for (auto iterator_s1 = s1.begin(), iterator_s2 = s2.begin();
			iterator_s1 != s1.end(), iterator_s2 != s2.end();
			++iterator_s1, ++iterator_s2) {
			
			if (tolower(*iterator_s1) != tolower(*iterator_s2)) {
				return false;
			}
		}

		return true;
	}
}

/* The hash function is going to implement the
polynomial rolling hash function according to the equation:
hash(s) = (s[0] * x^(n-1) + s[1]*x^(n-2) + ... + s[n-1]) mod m,
where s is the string, s[i] is a string character,
x is a prime constant, and m is a large prime number.
This function only returns the sum; the cardinality fix -
the mod operation by the table size - should be done
at a function call */
size_t hash(const std::string &s) {
	// bucket_index stores the sum
	// x is the prime constant
	// m is the large prime constant
	size_t bucket_index = 0, x = 31, m = 1e9 + 9;

	// The summation is computed in reverse order
	// to simplify the computation of x^(n-i)

	// string_char is an iterator pointing to a character in the given string
	for (auto string_char = s.rbegin(); string_char != s.rend(); ++string_char) {
		
		bucket_index = (bucket_index * x + tolower(*string_char)) % m;
	}

	return bucket_index;
}

set::set(const set &s) : 
	bucket_array(new std::list<std::string>[s.bucket_array_size]),
    bucket_array_size(s.bucket_array_size), set_size(0) 
{
	for (size_t i = 0; i < s.bucket_array_size; ++i) {
		for (std::string val : s.bucket_array[i]) {
    		// Inserting a copy of every element from the set s
    		insert(val);
    	}
  	}
}

set::set(std::initializer_list<std::string> ilist) :
	bucket_array(new std::list<std::string>[ilist.size()]),
    bucket_array_size(ilist.size()), set_size(0) 
{
	for (std::string item : ilist) {
    	insert(item);
	}
}

set &set::operator=(const set &s) {

	if (this != &s) {

    	clear();

    	for (size_t i = 0; i < s.bucket_array_size; ++i) {
    		for (std::string item : s.bucket_array[i]) {
				// Inserting every element from the given set
        		insert(item);
      		}
    	}
  	}

  	return *this;
}

/* Adds a new item to the set. If adding the item
makes the load factor reach its limit, all the elements
in the set are re-hashed and inserted into the new array
twice as big as the original */
bool set::insert(std::string val) {

	if (!contains(val)) {

    	size_t bucket_index;
		// set_size will have that value (after the increment) at return
		// set_size should not be modified later in this function
		++set_size;

		if (loadfactor() >= max_load_factor) {

			// Creating new array twice as big
			size_t new_bucket_array_size = 2 * bucket_array_size;
			std::list<std::string> *new_bucket_array = new std::list<std::string>[new_bucket_array_size];
			size_t new_set_size = set_size;

			for (size_t i = 0; i < bucket_array_size; ++i) {
				// Recomputing hash value for each element
				// and inserting it into the newly created array
				for (auto bucket_element = bucket_array[i].begin();
					bucket_element != bucket_array[i].end(); ++bucket_element) {

					bucket_index = hash(*bucket_element) % new_bucket_array_size;
					new_bucket_array[bucket_index].push_back(*bucket_element);
				}
			}

			// Deallocating of the old array and assigning the
			// pointer bucket_array to the new one
			// Note that clear() resets set_size
			// (for that reason, new_set_seize was created)
			clear();
			delete[] bucket_array;
			bucket_array = new_bucket_array;
			bucket_array_size = new_bucket_array_size;
			set_size = new_set_size;
    	}

		// Adding a new element to the set
		bucket_index = hash(val) % bucket_array_size;
		bucket_array[bucket_index].push_back(val);

		return true;
  	}

  	return false;
}

bool set::contains(std::string val) const {

	if (!empty()) {

		size_t bucket_index = hash(val) % bucket_array_size;

		for (std::string item : bucket_array[bucket_index]) {

			if (equal(item, val)) {
				return true;
			}
		}
	}

  	return false;
}

bool set::remove(std::string val) {

	if (contains(val)) {

		size_t bucket_index = hash(val) % bucket_array_size;

		for (auto bucket_element = bucket_array[bucket_index].begin();
			bucket_element != bucket_array[bucket_index].end(); ++bucket_element) {

			if (equal(*bucket_element, val)) {
				
				bucket_element = bucket_array[bucket_index].erase(bucket_element);
				--set_size;
				return true;
			}
		}
	}

  	return false;
}

void set::clear() {

	if (!empty()) {

		for (size_t i = 0; i < bucket_array_size; ++i) {
			bucket_array[i].clear();
		}

		set_size = 0;
	}
}

size_t set::size() const { 
	
	return set_size; 
}

bool set::empty() const { 
	
	return set_size == 0; 
}

set::~set() {

	clear();
	delete[] bucket_array;
	bucket_array_size = 0;
}
