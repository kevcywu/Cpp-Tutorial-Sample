#include "stdafx.h"
#include "intlist6.h"
#include <iostream>

void test() {
	IntList6 list;
	for (int i = 0; i < 10; i++)
		list.insert(i);
	list.print();
}

int main() {
	for (int i = 0; i < 10; i++)
		test();
	return 0;
}