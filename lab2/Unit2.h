//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H

#include <string>
#include <vcl.h>
#include <stdlib.h>
//---------------------------------------------------------------------------

class Order
{
	public:

	UnicodeString OrderNumber = "";
	UnicodeString TableNumber = 0;
	UnicodeString DishName = "";
	UnicodeString DishCost = 0;
	UnicodeString NumberOfServings = 0;
	UnicodeString OrderInvoice = 0;

	Order(UnicodeString OrderNumber, UnicodeString TableNumber, UnicodeString DishName,
		  UnicodeString DishCost, UnicodeString NumberOfServings)
	{
		this->OrderNumber = OrderNumber;
		this->TableNumber = TableNumber;
		this->DishName = DishName;
		this->DishCost = DishCost;
		this->NumberOfServings = NumberOfServings;
	}

	Order() {}

	public:

	void ReadOrderNumber(UnicodeString str)
	{
		OrderNumber = str;
	}

	void ReadTableNumber(UnicodeString str)
	{
		TableNumber = str;
	}

	void ReadDishName(UnicodeString str)
	{
		DishName = str;
	}

	void ReadDishCost(UnicodeString str)
	{
		DishCost = str;
	}

	void ReadNumberOfServings(UnicodeString str)
	{
		NumberOfServings = str;
	}

	int OrderInvoiceCalc()
	{
		return DishCost * NumberOfServings;
	}

} ;
#endif
