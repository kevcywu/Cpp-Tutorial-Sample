#include "stdafx.h"
#include "IntList4.h"
#include <iostream>

IntList4::Node::Node(int n): data(n), next(nullptr) {
	std::cout << "Creating node " << data << " (" << reinterpret_cast<uintptr_t>(this) << ")\n";
}

IntList4::Node::~Node() {
	std::cout << "Destroying node " << data << " (" << reinterpret_cast<uintptr_t>(this) << ")\n";
}

IntList4::IntList4() : head(nullptr), tail(nullptr), len(0) {}

IntList4::~IntList4() {
	clear();
}

// Copy constructor
IntList4::IntList4(const IntList4& other) {
	for (auto cursor = other.head; cursor; cursor = cursor->next)
		insert(cursor->data);
}
// Assignment operator
IntList4& IntList4::operator=(const IntList4& other) {
	// Make a local temporyary copy of other
	IntList4 temp{ other };
	// Exchange the head and tail pointers and len from this list
	// with those of the new, temporary list
	std::swap(head, temp.head);
	std::swap(tail, temp.tail);
	std::swap(len, temp.len);
	// The temporary list now points to this list's original contents,
	// and this list now points to the copy of other's list
	return *this;
}
void IntList4::insert(int n) {
	IntList4::Node *new_node = new Node(n);
	if (tail) {
		tail->next = new_node;
		tail = new_node;
	}
	else {
		head = tail = new_node;
	}
	len++;
}

void IntList4::print() const {
	for (auto cursor = head; cursor; cursor = cursor->next)
		std::cout << cursor->data << ' ';
	std::cout << '\n';
}

int IntList4::length() const {
	return len;
}

void IntList4::clear() {
	auto cursor = head;
	while (cursor) {
		auto temp = cursor;
		cursor = cursor->next;
		delete temp;
	}
	head = tail = nullptr;
	len = 0;
}
