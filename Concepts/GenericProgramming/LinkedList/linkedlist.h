// linkedlist.h
#include <iostream>
#include <utility>		// For std::swap
#include <memory>		// For std::shared_ptr

template <typename T>
class LinkedList
{
private:
	// The nested private Node class
	struct Node {
		T data;									// A data element of the list
		std::shared_ptr<Node> next;				// The node that follows this one
		
		// Constructor
		Node(const T& item): data(item), next(nullptr) {
			std::cout << "Creating node " << data
				<< " (" << reinterpret_cast<uintptr_t>(this) << ")\n";
		}
		// Destructor
		~Node() {
			std::cout << "Destroying node " << data
				<< " (" << reinterpret_cast<uintptr_t>(this) << ")\n";
		}
		Node(const Node&) = default;			// Copy constructor
		Node(Node&&) = default;					// Move constructor
		Node& operator=(const Node&) = default;	// Copy assignment
		Node& operator=(Node&&) = default;		// Move assignment
	};

	std::shared_ptr<Node> head;					// Points to the first item in the list
	std::shared_ptr<Node> tail;					// Points to the last item in the list

	unsigned int len;							// Number of elements in the list

public:
	// The constructor makes an initially empty list.
	// The list is empty is when head and tail are null.
	LinkedList() : head(nullptr), tail(nullptr), len(0) {}

	// Copy constructor makes a copy of the other object's list
	LinkedList(const LinkedList& other) : LinkedList() {
		// Walk through other's list inserting each of its elements
		// into this list
		for (auto cursor = other.head; cursor; cursor = cursor->next) {
			insert(cursor->data);
		}
	}
	
	// Move constructor takes possession of the temporar's list
	LinkedList(const LinkedList&& temp) : LinkedList() {
		// Swap contents with the temporary
		std::swap(head, temp.head);
		std::swap(tail, temp.tail);
		std::swap(len, temp.len);
	}

	// Assignment operator
	LinkedList& operator=(const LinkedList& other) {
		// Make a local ,tempory copy of other
		LinkedList temp{ other };
		std::swap(head, temp.head);
		std::swap(tail, temp.tail);
		std::swap(len, temp.len);
		return *this;
	}

	// Move assignment operator
	LinkedList& operator=(LinkedList&& temp) {
		std::swap(head, temp.head);
		std::swap(tail, temp.tail);
		std::swap(len, temp.len);
		// The temporary list now points to this list's original contents,
		// and this list now points to the temporary's list
		// The temporary list will be estroyed since it is a temporary
		return *this;
	}

	// The destructor that reclaims the list's memory
	~LinkedList() {
		clear();
	}

	// Inserts item onto the back of the list.
	void insert(const T& item) {
		// Make a node for the new element n
		std::shared_ptr<LinkedList::Node> new_node = std::make_shared<Node>(item);
		if (tail) { // Is tail empty?
			tail->next = new_node;
			tail = new_node;
		}
		else
			head = tail = new_node;
		len++;
	}

	// Removes the first occurence of n from the list.
	// Returns true if successful (found n and removed it)
	// Returns false if n is not originally present in the list. 
	bool remove(const T& item) {
		auto cursor = head,		// Start at head of list
			prev = head;		// Keep track of previous node seen

								// Loop until we run off the end of the list or find n,
								// whichever comes first
		while (cursor && cursor->data != item) {
			prev = cursor;					// Remember previous node
			cursor = cursor->next;			// move to next node
		}

		if (!cursor)						// Did we run off the end of the list?
			return false;					// Indicate we did not find n

											// Found n; cursor is pointing at the node containing n
		if (head == tail)					// n was the only element in the list
			head = tail = nullptr;			// cursor still points to node with n
		else if (cursor == head)			// Is n the first element in the list?
			head = head->next;				// Redirect head around n
		else								// n is not the first element
			prev->next = cursor->next;		// redirect previous node around n

		if (cursor = tail)					// was n the last element in the list
			tail = prev;					// Update tail to new last element

											// No delete is necessary
		len--;								// List size decreased by 1
		return true;						// We found n and deleted its node
	}

	void print() const {
		for (auto cursor = head; cursor; cursor = cursor->next)
			std::cout << cursor->data << ' ';
		std::cout << '\n';
	}

	int length() const {
		return len;
	}

	void clear() {
		auto cursor = head;
		while (cursor) {
			auto temp = cursor;			// Remember where we are
			cursor = cursor->next;		// Move next node
			temp->next = nullptr;		// Sever link from previous node
		}
		head = tail = nullptr;
		len = 0;
	}

	template <typename T>
	friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) {
	os << '{';
	if (list.length() > 0) {
		auto cursor = list.head;
		os << cursor->data;
		cursor = cursor->next;
		while (cursor) {
			os << ", " << cursor->data;
			cursor = cursor->next;
		}
	}
	os << '}';
	return os;
}

