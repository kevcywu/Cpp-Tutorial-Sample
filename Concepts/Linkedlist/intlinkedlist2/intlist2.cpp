#include "stdafx.h"
#include "intlist2.h"
#include <iostream>

IntList2::Node::Node(int n): data(n), next(nullptr) {}

IntList2::IntList2() : head(nullptr), tail(nullptr), len(0) {}

IntList2::~IntList2() {
	clear(); // Free up the space held by the nodes in the list
}

void IntList2::insert(int n) {
	IntList2::Node *new_node = new Node(n);
	if (tail) {
		tail->next = new_node;
		tail = new_node;
	}
	else {
		head = tail = new_node;
	}
	len++;
}

void IntList2::print() const {
	for (auto cursor = head; cursor; cursor = cursor->next)
		std::cout << cursor->data << ' ';
	std::cout << '\n';
}

int IntList2::length() const {
	return len;
}

void IntList2::clear() {
	auto cursor = head;
	while (cursor) {
		auto temp = cursor;
		cursor = cursor->next;
		delete temp;
	}
	head = tail = nullptr;
	len = 0;
}
