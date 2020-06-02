//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#endif

#include <vcl.h>
#include <stdlib.h>

class Order
{
	public:

	UnicodeString SerialNumber;
	UnicodeString FullName;
	UnicodeString HomeAddress;
	UnicodeString RegistrationDate;
	bool isAwaiting;
	bool isCompleted;

	Order(UnicodeString SerialNumber, UnicodeString FullName, UnicodeString HomeAddress,
		  UnicodeString RegistrationDate, bool isAwaiting, bool isCompleted)
	{
		this->SerialNumber = SerialNumber;
		this->FullName = FullName;
		this->HomeAddress = HomeAddress;
		this->RegistrationDate = RegistrationDate;
		this->isAwaiting = isAwaiting;
		this->isCompleted = isCompleted;
	}

	Order() {}

	public:



	UnicodeString GetSurname()
	{
		int i = 1;
		const int count = 1;
		while (FullName.SubString(i,count) != ' ')
			{
				i++;
			}
		UnicodeString mystring = FullName.SubString(0, i-1);
		UnicodeString Surname = mystring;

		return Surname;
	}
} ;
