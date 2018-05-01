#include "stdafx.h"
#include "intlist1.h"
#include <iostream>

IntList1::Node::Node(int n): data(n), next(nullptr) {}

int IntList1::length(IntList1::Node *p) const{
	if (p)
		return 1 + length(p->next);
	else
		return 0;
}

void IntList1::dispose(IntList1::Node *p) {
	if (p) {
		dispose(p->next);
		delete p;
	}
}

IntList1::IntList1() : head(nullptr), tail(nullptr) {}

void IntList1::insert(int n) {
	IntList1::Node *new_node = new Node(n);
	if (tail) {
		tail->next = new_node;
		tail = new_node;
	}
	else {
		head = tail = new_node;
	}
}

void IntList1::print() const {
	for (auto cursor = head; cursor; cursor = cursor->next)
		std::cout << cursor->data << ' ';
	std::cout << '\n';
}

int IntList1::length() const {
	return length(head);
}

void IntList1::clear() {
	dispose(head);
	head = tail = nullptr;
}
