class IntList3 {
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
	IntList3();
	~IntList3();
	void insert(int n);
	void print() const;
	int length() const;
	void clear();
};