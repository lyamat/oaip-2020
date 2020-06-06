//---------------------------------------------------------------------------

#pragma hdrstop

#include "InheritanceTable.h"
#include "string"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void InheritanceTable::Print(TMemo* Memo)
{
	for(int i = 0; i < this->size; i++)
	{
		AnsiString str = IntToStr(i) + "#   ";
		if (!table[i].isEmpty())
		{
			Item* temp = table[i].top();
			while(temp)
			{
				str += "[" + IntToStr(temp->key) + "] ";
				temp = temp->pNext;
			}
		}
		Memo->Lines->Add(str);
	}
}

void InheritanceTable::SpacingDelete(int k1, int k2)
{
	for(int i = 0; i < this->size; i++)
	{
		if (!table[i].isEmpty())
		{
			Item* temp = table[i].top();
			while(temp)
			{
				if (k1 < temp->key && temp->key < k2)
				{
					DeleteNode(temp->key);
				}
				temp = temp->pNext;
			}
		}
	}
}
