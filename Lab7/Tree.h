//---------------------------------------------------------------------------
//#include <string.h>

//using namespace std;

#ifndef TreeH
#define TreeH

//---------------------------------------------------------------------------

//using std::string;

class Node
{
	public:
	unsigned char height;
	int value;
	String str;
	Node* pLeft;
	Node* pRight;

	Node() { height = 1; }

	Node(int key, String str)
	{
		height = 1;
		this->value = key;
		this->str = str;
	};

	~Node(){};
	Node* Add(Node*, int, String);
	Node* Balance(Node*);
    Node* Find(Node*, int);
	Node* Delete(Node*, int);
	unsigned char Height(Node*);
	int BalanceFactor(Node*);
	void FixHeight(Node*);

	Node* RotateRight(Node*);
	Node* RotateLeft(Node*);

	private:
	Node* MinValue(Node*);
};

class Tree : public Node
{
	public:
	Tree() : Node(){};
	Tree(int key, String str) : Node(key, str){};
	static int CountOfRight(Node*);
};

#endif

