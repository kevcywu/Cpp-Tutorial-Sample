#include "stdafx.h"
#include "genericcomparer.h"

#include <iostream>
#include <vector>
#include <string>

template <typename T>
void selection_sort(std::vector<T>& a, Comparer<T>& compare) {
	int n = a.size();
	for (int i = 0; i < n - 1; i++) {
		// Note: i, small, and j represent positions within vec.
		// vec[i], vec[small] and a[j] represents the elements at
		// those positions.
		// small is the position of the smallest value we've seen
		// so far; we use it to find the smallest value less
		// than vec[i]
		int small = i;
		// see if a smaller value can be found later in the vector
		for (int j = i + 1; j < n; j++)
			if (compare.compare(a[j], a[small]))
				small = j;		// found a smaller value
								// swap vec[i] and vec[small], if a smaller value was found
		if (i != small)
			compare.swap(a[i], a[small]);		// uses swap from <utility>
	}
}

/*
*	print
*		Prints the contents of a vector
*		a is the vector to print
*		The function does not modify a.
*/
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& a) {
	int n = a.size();
	os << '{';
	if (n > 0) {
		os << a[0];
		for (int i = 1; i < n; i++) {
			std::cout << ',' << a[i];
		}
	}
	os << '}';
	return os;
}

template <typename T>
bool less_than(const T& a, const T& b) {
	return a < b;
}

template <typename T>
bool greater_than(const T& a, const T& b) {
	return a > b;
}

int main() {
	// Make a vector of integers
	std::vector<int> original{ 23,-3,4,215,0,-3,2,23,100,88,-10 };

	// Make a working copy of the original vector
	std::vector<int> working = original;
	std::cout << "Before: ";
	std::cout << working << '\n';
	Comparer<int> lt(less_than<int>), gt(greater_than<int>);
	selection_sort(working, lt);
	std::cout << "Ascending: ";
	std::cout << working << '\n';
	std::cout << " (" << lt.comparisons() << " comparisons, " << lt.swaps() << " swaps)\n";
	std::cout << "---------------------------------------\n";

	// Make another copy of the original vector;
	working = original;
	std::cout << "Before: ";
	std::cout << working << '\n';
	selection_sort(working, gt);
	std::cout << "Descending: ";
	std::cout << working << '\n';
	std::cout << " (" << gt.comparisons() << " comparisons, " << gt.swaps() << " swaps)\n";

	std::cout << "---------------------------------------\n";
	// Make a vector of strings
	std::vector<std::string> str_original{ "tree", "boy", "apple", "girl", "dog", "cat" };
	// Make a working copy of the original vector
	std::vector<std::string> str_working = str_original;
	std::cout << "Before: ";
	std::cout << str_working << '\n';
	Comparer<std::string> str_lt(less_than<std::string>), str_gt(greater_than<std::string>);
	selection_sort(str_working, str_lt);
	std::cout << "Ascending: ";
	std::cout << str_working << '\n';
	std::cout << " (" << str_lt.comparisons() << " comparisons, " << str_lt.swaps() << " swaps)\n";

	std::cout << "---------------------------------------\n";
	str_working = str_original;
	std::cout << "Before: ";
	std::cout << str_working << '\n';
	selection_sort(str_working, str_gt);
	std::cout << "Descending: ";
	std::cout << str_working << '\n';
	std::cout << " (" << str_gt.comparisons() << " comparisons, " << str_gt.swaps() << " swaps)\n";

	return 0;
}