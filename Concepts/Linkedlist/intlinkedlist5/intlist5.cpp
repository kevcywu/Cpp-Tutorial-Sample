#include "stdafx.h"
#include "IntList5.h"
#include <iostream>

IntList5::Node::Node(int n) : data(n), next(nullptr) {
	std::cout << "Creating node " << data << " (" << reinterpret_cast<uintptr_t>(this) << ")\n";
}

IntList5::Node::~Node() {
	std::cout << "Destroying node " << data << " (" << reinterpret_cast<uintptr_t>(this) << ")\n";
}

IntList5::IntList5() : head(nullptr), tail(nullptr), len(0) {}

// Copy constructor
IntList5::IntList5(const IntList5& other) {
	for (auto cursor = other.head; cursor; cursor = cursor->next)
		insert(cursor->data);
}

// Move constructor takes possession of the temporary's list
IntList5::IntList5(IntList5&& temp) : IntList5() {
	// swap contents with the temprary
	std::swap(head, temp.head);
	std::swap(tail, temp.tail);
	std::swap(len, temp.len);
}

// Assignment operator
IntList5& IntList5::operator=(const IntList5& other) {
	// Make a local temporyary copy of other
	IntList5 temp{ other };
	// Exchange the head and tail pointers and len from this list
	// with those of the new, temporary list
	std::swap(head, temp.head);
	std::swap(tail, temp.tail);
	std::swap(len, temp.len);
	// The temporary list now points to this list's original contents,
	// and this list now points to the copy of other's list
	return *this;
}


// Move Assignment operator
IntList5& IntList5::operator=(IntList5&& temp) {
	// Exchange the head and tail pointers and len from this list
	// with those of the new, temporary list
	std::swap(head, temp.head);
	std::swap(tail, temp.tail);
	std::swap(len, temp.len);
	// The temporary list now points to this list's original contents,
	// and this list now points to the temp's list
	// The temporary list will be destroyed since it is a temporary
	return *this;
}

IntList5::~IntList5() {
	clear();
}

void IntList5::insert(int n) {
	IntList5::Node *new_node = new Node(n);
	if (tail) {
		tail->next = new_node;
		tail = new_node;
	}
	else {
		head = tail = new_node;
	}
	len++;
}

void IntList5::print() const {
	for (auto cursor = head; cursor; cursor = cursor->next)
		std::cout << cursor->data << ' ';
	std::cout << '\n';
}

int IntList5::length() const {
	return len;
}

void IntList5::clear() {
	auto cursor = head;
	while (cursor) {
		auto temp = cursor;
		cursor = cursor->next;
		delete temp;
	}
	head = tail = nullptr;
	len = 0;
}
