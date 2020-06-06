//---------------------------------------------------------------------------

#include "HTable.h"

#ifndef InheritanceTableH
#define InheritanceTableH

//---------------------------------------------------------------------------

class InheritanceTable : public HTable
{

public:
	InheritanceTable(int key) : HTable(key){};
	void Print(TMemo*);
	void SpacingDelete(int, int);

};

#endif
