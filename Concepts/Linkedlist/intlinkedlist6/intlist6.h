// retool our linked list class to use std::shared_ptr objects instead of raw pointers
#include <memory>	// For std::shared_ptr

class IntList6
{
private:
	// The nested private Node class
	struct Node {
		int data;								// A data element of the list
		std::shared_ptr<Node> next;				// The node that follows this one
		Node(int d);							// Constructor
		Node(const Node&) = default;			// Copy constructor
		Node(Node&&) = default;					// Move constructor
		~Node();								// Destructor
		Node& operator=(const Node&) = default;	// Copy assignment
		Node& operator=(Node&&) = default;		// Move assignment
	};
	
	std::shared_ptr<Node> head;					// Points to the first item in the list
	std::shared_ptr<Node> tail;					// Points to the last item in the list

	unsigned int len;							// Number of elements in the list

public:
	// The constructor makes an initially empty list
	IntList6();
	// The destructor that reclaims the list's memory
	~IntList6();

	IntList6(const IntList6& other);			// Copy constructor
	IntList6(IntList6&& other);					// Move constructor

	IntList6& operator=(const IntList6& other);	// Assignment operator
	IntList6& operator=(IntList6&& other);		// Move assignment operator

	void insert(int n);							// Inserts n onto the back of the list.
	void print() const;							// Print the contents of the linked list of integers.
	int length() const;							// Returns the length of the linked list.
	void clear();								// Removes all the elements in the linked list.
	
	bool remove(int n);
};

