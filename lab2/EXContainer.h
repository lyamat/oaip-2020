#ifndef EXContainerH
#define EXContainerH
//---------------------------------------------------------------------------
#endif

#include <vector>
#include <string>
#include <vcl.h>
#include <stdlib.h>

using std::vector;
using std::string;

class Order
{
	public:

	UnicodeString OrderNumber;
	UnicodeString TableNumber;
	UnicodeString DishName;
	UnicodeString DishCost;
	UnicodeString NumberOfServings;
	UnicodeString OrderInvoice;

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

	UnicodeString GetNumberOfServings()
	{
		return NumberOfServings;
	}

	UnicodeString GetOrderNumber()
	{
		return OrderNumber;
	}

	virtual UnicodeString ToString()
	{
		UnicodeString str = OrderNumber + "\n" + TableNumber + "\n" + DishName + "\n"
							+ DishCost + "\n" + NumberOfServings + "\n"
							+ "=================";
		return str;
	}

} ;

//////////////////////////////////////////////////

class EXContainer
{
	public:
	vector<Order> Orders;

	public:
	void Size(int n)
	{
		Orders.resize(n);
	}

	void SortAllByOrderInvoice ()
	{
		if (!Orders.size())
		{
			return;
		}

		for (vector<Order>::iterator i = Orders.begin(); i != Orders.end(); i++)
		{
			for(vector<Order>::iterator j = i; (j != Orders.begin()) && ((*(j-1)).OrderInvoiceCalc() < (*j).OrderInvoiceCalc()); j--)
			{
				Order temp = *j;
				*j = *(j-1);
				*(j-1) = temp;
			}
		}
	}

	void SortAllBySeOrderNumber ()
	{
		if (!Orders.size())
		{
			return;
		}

		for (vector<Order>::iterator i = Orders.begin(); i != Orders.end(); i++)
		{
			for(vector<Order>::iterator j = i; (j != Orders.begin()) && ((*(j-1)).GetOrderNumber() > (*j).GetOrderNumber()); j--)
			{
				Order temp = *j;
				*j = *(j-1);
				*(j-1) = temp;
			}
		}
	}

	void TopTwoDishes()
	{
		if (!Orders.size())
		{
			return;
		}

		for (vector<Order>::iterator i = Orders.begin(); i != Orders.end(); i++)
		{
			for(vector<Order>::iterator j = i; (j != Orders.begin()) && ((*(j-1)).GetNumberOfServings() < (*j).GetNumberOfServings()); j--)
			{
				Order temp = *j;
				*j = *(j-1);
				*(j-1) = temp;
			}
		}
	}

};
