#include "set.h"

set::treenode* set::copynodes(treenode* original) 
{
	treenode* root = new treenode(original->value);

	if (original->left != nullptr) {
		root->left = copynodes(original->left);
	}	

	if (original->right != nullptr) {
		root->right = copynodes(original->right);
	}

	return root;
}

void set::deallocatenodes(treenode* node)
{
	// Check if the subtree is empty
	if (node == nullptr) {
		return;
	}

	deallocatenodes(node->left);
	deallocatenodes(node->right);

	node->left = nullptr;
	node->right = nullptr;
	delete node;
	node = nullptr;

	return;
}

/* Returns true if the value is present in the set,
otherwise returns false */
bool set::contains(int i) const
{
	if (empty()) {
		return false;
	}

	// curr_node is the node whose value
	// is to be checked on equality with i
	treenode* curr_node = this->root;

	while (curr_node) {
		// If the value of curr_node equals i,
		// then the set contains it
		if (curr_node->value == i) {
			return true;
		}
		// If the value of curr_node is greater than i,
		// the search continues in its left subtree
		else if (curr_node->value > i) {
			curr_node = curr_node->left;
		}
		// Otherwise, the value of curr_node is less than i,
		// and the search coontinues in its right subtree
		else {
			curr_node = curr_node->right;
		}
	}

	// If the value was not present where it was expected to be,
	// then the set doesn't contain it
	return false;
}

/* Inserts a new value into the set preserving order if it isn't 
already there and updates the set size. Returns true if the insertion
was successful and false if the value is already present in the set */
bool set::insert(int i)
{	
	if (contains(i)) {
		return false;
	}

	// new_node is the node to insert into the tree
	treenode* new_node = new treenode(i);

	// If the set is empty, i is stored at the root
	if (empty()) {
		this->root = new_node;
		set_size = 1;
		return true;
	}

	// curr_node is the node to which new_node is compared
	treenode* curr_node = this->root;

	while (curr_node) {
		// If i is less than the value on curr_node,
		// it should be inserted in its left subtree;
		// otherwise, in the right subtree
		if (i < curr_node->value) {				
			if (curr_node->left == nullptr) {
				// new_node becomes curr_node's left child
				// if it doesn't have one
				curr_node->left = new_node;
				++set_size;
				return true;
			}
			else {
				// If curr_node has a left child,
				// new_node will be compared to it
				// at the next iteration
				curr_node = curr_node->left;
			}
		}
		else {
			if (curr_node->right == nullptr) {
				// new_node becomes curr_node's right child
				// if it doesn't have one
				curr_node->right = new_node;
				++set_size;
				return true;
			}
			else {
				// If curr_node has a right child,
				// new_node will be compared to it
				// at the next iteration
				curr_node = curr_node->right;
			}
		}
	}
	
	return false;
}

void set::clear()
{
	deallocatenodes(this->root);
	set_size = 0;
	root = nullptr;
}

size_t set::size() const
{
	return set_size;
}

bool set::empty() const
{
	return root == nullptr;
}
