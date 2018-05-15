class IntList5 {
private:
	struct Node {
		int data;
		Node *next;
		Node(int d);
		~Node();
	};
	Node *head;
	Node *tail;

	int len;

public:
	IntList5();
	~IntList5();

	// Copy constructor
	IntList5(const IntList5& other);
	// Move constructor
	IntList5(IntList5&& other);
	// Assignment operator
	IntList5& operator=(const IntList5& other);
	// Move Assignment operator
	IntList5& operator=(IntList5&& other);
	void insert(int n);
	void print() const;
	int length() const;
	void clear();
};