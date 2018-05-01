class IntList1 {
private:
	struct Node {
		int data;
		Node *next;
		Node(int d);

	};
	Node *head;
	Node *tail;

	int length(Node *p) const;
	void dispose(Node *p);

public:
	IntList1();
	void insert(int n);
	void print() const;
	int length() const;
	void clear();
};