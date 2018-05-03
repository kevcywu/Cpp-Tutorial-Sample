class IntList2 {
private:
	struct Node {
		int data;
		Node *next;
		Node(int d);

	};
	Node *head;
	Node *tail;

	int len;

public:
	IntList2();
	~IntList2();
	void insert(int n);
	void print() const;
	int length() const;
	void clear();
};