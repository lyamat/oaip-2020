//------------------------------------------------------------------------------

#pragma hdrstop
//------------------------------------------------------------------------------
#include "Stack.h"
#pragma package(smart_init)

void Stack::push(int num)
{
	Item* item = new Item(num);
	if(this->isEmpty())
	{
		item->pNext = NULL;
		this->pTail = item;
	}
	else
	{
		item->pNext = this->pTail;
		this->pTail = item;
	}
}

Item* Stack::top()
{
	if(!this->isEmpty())
	{
		return this->pTail;
	}
	else
	{
		throw 13;
    }
}

void Stack::pop()
{
	if(!this->isEmpty())
	{
		Item *temp = this->pTail;
		this->pTail = this->pTail->pNext;
        delete(temp);
	}
	else
	{
		throw 13;
	}
}

bool Stack::isEmpty()
{
	return !this->pTail;
}