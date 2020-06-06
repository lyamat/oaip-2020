//---------------------------------------------------------------------------

#ifndef StackH
#define StackH
//---------------------------------------------------------------------------

class Item
{
	public:
    int key;
	Item* pNext;
	Item(int num) { pNext = NULL; key = num; }
};

class Stack
{
	public:
	Item* pTail;
	Stack() { pTail = NULL; }
	Item* top();
	bool isEmpty();
	void push(int);
	void pop();
};
#endif
