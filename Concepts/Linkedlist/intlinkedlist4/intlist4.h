class IntList4 {
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
	IntList4();
	~IntList4();
	// Copy constructor
	IntList4(const IntList4& other);
	// Assignment operator
	IntList4& operator=(const IntList4& other);
	void insert(int n);
	void print() const;
	int length() const;
	void clear();
};