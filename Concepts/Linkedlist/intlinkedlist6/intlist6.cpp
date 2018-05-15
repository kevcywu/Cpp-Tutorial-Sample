#include "stdafx.h"
#include "intlist6.h"

#include <iostream>
#include <utility>
/*
 *	shared_ptr hides new or delete operators
 *	automatic resource management
 */


// Private IntList6 operations

// Node constructor
IntList6::Node::Node(int n) : data(n), next(nullptr) {
	std::cout << "Creating node " << data
		<< " (" << reinterpret_cast<uintptr_t>(this) << ")\n";
}

IntList6::Node::~Node() {
	std::cout << "Destroying node " << data
		<< " (" << reinterpret_cast<uintptr_t>(this) << ")\n";
}

IntList6::IntList6() : head(nullptr), tail(nullptr), len(0) {}

// Copy constructor makes a copy of the other object's list
IntList6::IntList6(const IntList6& other) : IntList6() {
	// Walk through other's list inserting each of its elements
	// into this list
	for (auto cursor = other.head; cursor; cursor = cursor->next)
		insert(cursor->data);
}

// Move constructor talkes possession of the temporary's list
IntList6::IntList6(IntList6&& temp) : IntList6() {
	std::swap(head, temp.head);
	std::swap(tail, temp.tail);
	std::swap(len, temp.len);
}

// Assignment operator
IntList6& IntList6::operator=(const IntList6& other) {
	// Make a local ,tempory copy of other
	IntList6 temp{ other };
	std::swap(head, temp.head);
	std::swap(tail, temp.tail);
	std::swap(len, temp.len);
	return *this;
}

// Move assignment operator
IntList6& IntList6::operator=(IntList6&& temp) {
	std::swap(head, temp.head);
	std::swap(tail, temp.tail);
	std::swap(len, temp.len);
	// The temporary list now points to this list's original contents,
	// and this list now points to the temporary's list
	// The temporary list will be estroyed since it is a temporary
	return *this;
}

// The destructor deallocates the memory held by the list
IntList6::~IntList6() { clear(); }

void IntList6::insert(int n) {
	// Make a node for the new element n
	std::shared_ptr<IntList6::Node> new_node = std::make_shared<Node>(n);
	if (tail) { // Is tail empty?
		tail->next = new_node;
		tail = new_node;
	}
	else
		head = tail = new_node;
	len++;
}

void IntList6::print() const {
	for (auto cursor = head; cursor; cursor = cursor->next)
		std::cout << cursor->data << ' ';
	std::cout << '\n';
}

int IntList6::length() const{
	return len;
}

void IntList6::clear() {
	auto cursor = head;
	while (cursor) {
		auto temp = cursor;			// Remember where we are
		cursor = cursor->next;		// Move next node
		temp->next = nullptr;		// Sever link from previous node
	}
	head = tail = nullptr;
	len = 0;
}

// Removes the first occurence of n from the list.
// Returns true if successful (found n and removed it)
// Returns false if n is not originally present in the list. 
bool IntList6::remove(int n) {
	auto cursor = head,		// Start at head of list
		prev = head;		// Keep track of previous node seen

	// Loop until we run off the end of the list or find n,
	// whichever comes first
	while (cursor && cursor->data != n) {
		prev = cursor;					// Remember previous node
		cursor = cursor->next;			// move to next node
	}

	if (!cursor)						// Did we run off the end of the list?
		return false;					// Indicate we did not find n
	
	// Found n; cursor is pointing at the node containing n
	if (head == tail)					// n was the only element in the list
		head = tail = nullptr;			// cursor still points to node with n
	else if (cursor == head)			// Is n the first element in the list?
		head = head->next;				// Redirect head around n
	else								// n is not the first element
		prev->next = cursor->next;		// redirect previous node around n

	if (cursor = tail)					// was n the last element in the list
		tail = prev;					// Update tail to new last element

	// No delete is necessary
	len--;								// List size decreased by 1
	return true;						// We found n and deleted its node
}