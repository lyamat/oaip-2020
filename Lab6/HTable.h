//---------------------------------------------------------------------------

#include "Stack.h"

#ifndef HTableH
#define HTableH
//---------------------------------------------------------------------------

class HTable
{
public:
	unsigned int size;
	Stack* table;

	HTable(int _size)
	{
		this->size = _size;
		table = new Stack[size];
		for(int i = 0; i < size; i++)
		{
			table[i] = Stack();
        }
	}

	int GetHashCode(int);
	Stack* FindStack(int);
	void Add(int);
	void Print(TMemo*);
	void DeleteNode(int);
};


#endif
