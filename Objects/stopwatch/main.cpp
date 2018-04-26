#include "stdafx.h"

#include <iostream>
#include "Stopwatch.h"

int main() {
	Stopwatch timer;

	std::cout << "Enter something.. ";
	timer.start();
	std::cin.get();
	timer.stop();

	std::cout << "Time elapsed: " << timer.elapsed()<< " seconds\n";
	timer.reset();

	std::cout << "Enter something.. ";
	timer.start();
	std::cin.get();
	timer.stop();
	std::cout << "Time elapsed: " << timer.elapsed() << " seconds\n";
	timer.reset();
	
	return 0;
}