#include "stdafx.h"

#include <iostream>
#include "Stopwatch.h"

/* Simple inheritance example */
class B {
public: 
	void f();
};

void B::f() {
	std::cout << "In fuction 'f'\n";
}

class D : public B {
public:
	void g();
};

void D::g() {
	std::cout << "In function 'g'\n";	
}

int main() {
	B myB;
	D myD;

	myB.f();
	myD.f();
	myD.g();

	return 0;
}