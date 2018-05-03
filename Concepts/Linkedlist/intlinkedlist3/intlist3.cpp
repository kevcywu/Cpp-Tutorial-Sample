#include "stdafx.h"
#include "intlist3.h"
#include <iostream>

IntList3::Node::Node(int n): data(n), next(nullptr) {
	std::cout << "Creating node " << data << " (" << reinterpret_cast<uintptr_t>(this) << ")\n";
}

IntList3::Node::~Node() {
	std::cout << "Destroying node " << data << " (" << reinterpret_cast<uintptr_t>(this) << ")\n";
}

IntList3::IntList3() : head(nullptr), tail(nullptr), len(0) {

}

IntList3::~IntList3() {
	clear();
}


void IntList3::insert(int n) {
	IntList3::Node *new_node = new Node(n);
	if (tail) {
		tail->next = new_node;
		tail = new_node;
	}
	else {
		head = tail = new_node;
	}
	len++;
}

void IntList3::print() const {
	for (auto cursor = head; cursor; cursor = cursor->next)
		std::cout << cursor->data << ' ';
	std::cout << '\n';
}

int IntList3::length() const {
	return len;
}

void IntList3::clear() {
	auto cursor = head;
	while (cursor) {
		auto temp = cursor;
		cursor = cursor->next;
		delete temp;
	}
	head = tail = nullptr;
	len = 0;
}
