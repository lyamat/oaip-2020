//---------------------------------------------------------------------------

#pragma hdrstop

#include "HTable.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)


int HTable::GetHashCode(int key)
{
	return key % size;
}

Stack* HTable::FindStack(int key)
{
	Stack* stack = &table[GetHashCode(key)];
	return stack;
}

void HTable::Add(int key)
{
	Stack* stack = FindStack(key);
	stack->push(key);
}

void HTable::DeleteNode(int key)
{
	Stack* stack = FindStack(key);
	if(!stack->isEmpty())
	{
		while(!stack->isEmpty() && stack->top()->key == key)
		{
			stack->pop();
		}
		if(stack->isEmpty())
		{
			return;
		}
		Item* prev = stack->top();
		Item* cur = prev->pNext;
        while(cur)
		{
			if(cur->key == key)
			{
				prev->pNext = cur->pNext;
				free(cur);
				cur = prev->pNext;
			}
			else
			{
				prev = cur;
				cur = cur->pNext;
			}
		}
	}
}
