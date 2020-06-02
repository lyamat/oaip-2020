//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "container.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

Container<Order> list;

	UnicodeString SerialNumber;
	UnicodeString FullName;
	UnicodeString HomeAddress;
	UnicodeString RegistrationDate;
	bool isAwaiting;
	bool isCompleted;

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void RefreshMemo()
{
	Form1->Memo->Lines->Clear();
	Form1->ComboBox->Items->Clear();
	for(int i = 0; i < list.GetSize(); i++)
	{
		Form1->Memo->Lines->Add(list[i].SerialNumber);
		Form1->Memo->Lines->Add(list[i].FullName);
		Form1->Memo->Lines->Add(list[i].HomeAddress);
		Form1->Memo->Lines->Add(list[i].RegistrationDate);
		Form1->Memo->Lines->Add("====================");
		Form1->ComboBox->Items->Add(list[i].SerialNumber);
	}
	Form1->ComboBox->Text = "All orders:";
}

void RefreshCompletedMemo()
{
	Form1->CompletedMemo->Lines->Clear();
	Form1->ComboBox->Items->Clear();
	for(int i = 0; i < list.GetSize(); i++)
	{   if(list[i].isCompleted == true)
		{
		Form1->CompletedMemo->Lines->Add(list[i].SerialNumber);
		Form1->CompletedMemo->Lines->Add(list[i].FullName);
		Form1->CompletedMemo->Lines->Add(list[i].HomeAddress);
		Form1->CompletedMemo->Lines->Add(list[i].RegistrationDate);
		Form1->CompletedMemo->Lines->Add("====================");
		Form1->ComboBox->Items->Add(list[i].SerialNumber);
		}
	}
	Form1->ComboBox->Text = "All completed orders:";
}

void RefreshAwaitingMemo()
{
	Form1->AwaitingMemo->Lines->Clear();
	Form1->ComboBox->Items->Clear();
	for(int i = 0; i < list.GetSize(); i++)
	{
        if(list[i].isAwaiting == true)
		{
		Form1->AwaitingMemo->Lines->Add(list[i].SerialNumber);
		Form1->AwaitingMemo->Lines->Add(list[i].FullName);
		Form1->AwaitingMemo->Lines->Add(list[i].HomeAddress);
		Form1->AwaitingMemo->Lines->Add(list[i].RegistrationDate);
		Form1->AwaitingMemo->Lines->Add("====================");
		Form1->ComboBox->Items->Add(list[i].SerialNumber);
		}
	}
    Form1->ComboBox->Text = "All awaiting orders:";
}

//---------------------------------------------------------------------------

void ShowOrder(int n)
{
	Form1->SerialNumberEdit->Text = list[n].SerialNumber;
	Form1->FullNameEdit->Text = list[n].FullName;
	Form1->HomeAddressEdit->Text = list[n].HomeAddress;
	Form1->DateInputPicker->Date = list[n].RegistrationDate;
	Form1->rbAwaiting->Checked = list[n].isAwaiting;
	Form1->rbCompleted->Checked = list[n].isCompleted;

	Form1->ComboBox->Text = list[n].SerialNumber;
}

//---------------------------------------------------------------------------

void DeleteRepeats()
{
	for (int i = 0 ; i < list.GetSize(); i++)
	{
		for (int j = i+1; j < list.GetSize(); j++)
		{
			if ((list[i].FullName == list[j].FullName) & (list[i].HomeAddress == list[j].HomeAddress))
			{
				list.remove(j);
				j -= 1;
			}
		}
	}
}

//---------------------------------------------------------------------------

void __fastcall TForm1::AddButtonClick(TObject *Sender)
{
	if (SerialNumberEdit->Text == "")
	{
		ShowMessage("Fill serial number");
		return;
	}
	if (FullNameEdit->Text == "")
	{
		ShowMessage("Fill full name");
		return;
	}
	if (HomeAddressEdit->Text == "")
	{
		ShowMessage("Fill home address");
		return;
	}

	for (int i = 0; i != list.GetSize(); i++)
	{
      if (list[i].SerialNumber == SerialNumberEdit->Text)
		{
            ShowMessage("This serial number is already exsits");
			return;
		}
	}

	SerialNumber = SerialNumberEdit->Text;
	FullName = FullNameEdit->Text ;
	HomeAddress = HomeAddressEdit->Text ;
	RegistrationDate = DateInputPicker->Date ;
	isAwaiting = rbAwaiting->Checked;
	isCompleted = rbCompleted->Checked;


	SerialNumberEdit->Clear();
	FullNameEdit->Clear();
	HomeAddressEdit->Clear();
	rbAwaiting->Checked = false;
	rbCompleted->Checked = false;

	list.push_back(Order(SerialNumber, FullName, HomeAddress, RegistrationDate, isAwaiting, isCompleted));

    RefreshCompletedMemo();
	RefreshAwaitingMemo();
	RefreshMemo();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EditButtonClick(TObject *Sender)
{
	if (SerialNumberEdit->Text == "")
	{
		ShowMessage("Fill serial number");
		return;
	}
	if (FullNameEdit->Text == "")
	{
		ShowMessage("Fill full name");
		return;
	}
	if (HomeAddressEdit->Text == "")
	{
		ShowMessage("Fill home address");
		return;
	}

	isAwaiting = rbAwaiting->Checked;
	isCompleted = rbCompleted->Checked;

	bool found = false;
	int tmp = 0;

	for (int i = 0; i != list.GetSize(); i++)
	{
		if (list[i].SerialNumber == ComboBox->Text)
		{
			found = true;
			tmp = i;
			break;
		}
	}

	if (!found)
	{
		ShowMessage("Not found");
		return;
	}

	list[tmp] = Order(SerialNumberEdit->Text, FullNameEdit->Text, HomeAddressEdit->Text,
					  DateInputPicker->Date, isAwaiting, isCompleted);

    SerialNumberEdit->Clear();
	FullNameEdit->Clear();
	HomeAddressEdit->Clear();
    rbAwaiting->Checked = false;
	rbCompleted->Checked = false;

	RefreshCompletedMemo();
	RefreshAwaitingMemo();
	RefreshMemo();
}

//---------------------------------------------------------------------------

void __fastcall TForm1::SearchRegistrationDateButtonClick(TObject *Sender)
{

	bool found = false;
	int tmp = 0;

	for (int i = 0; i != list.GetSize(); i++)
	{
		if (list[i].RegistrationDate == DateSearchPicker->Date)
		{
			found = true;
			tmp = i;
			break;
		}
	}

	if (!found)
	{
		ShowMessage("Not found");
		return;
	}


	ShowOrder(tmp);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SearchSerialNumberButtonClick(TObject *Sender)
{
	bool found = false;
	int tmp = 0;

	for (int i = 0; i != list.GetSize(); i++)
	{
		if (list[i].SerialNumber == SearchSerialNumberEdit->Text)
		{
			found = true;
			tmp = i;
			break;
		}
	}

	SearchSerialNumberEdit->Clear();

	if (!found)
	{
		ShowMessage("Not found");
		return;
	}


	ShowOrder(tmp);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SearchSurnameButtonClick(TObject *Sender)
{

	bool found = false;
	int tmp = 0;

	for (int i = 0; i != list.GetSize(); i++)
	{
		if (list[i].GetSurname() == SearchSurnameEdit->Text)
		{
			found = true;
			tmp = i;
			break;
		}
	}

    SearchSurnameEdit->Clear();

	if (!found)
	{
		ShowMessage("Not found");
		return;
	}


	ShowOrder(tmp);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBoxChange(TObject *Sender)
{
	bool found = false;
	int tmp = 0;


	for (int i = 0; i != list.GetSize(); i++)
	{
		if (list[i].SerialNumber == ComboBox->Text)
		{
			found = true;
			tmp = i;
			break;
		}
	}

	if (!found)
	{
		ShowMessage("Not found");
		return;
	}

	ShowOrder(tmp);
}
//---------------------------------------------------------------------------




void __fastcall TForm1::CompletedViewButtonClick(TObject *Sender)
{
	RefreshCompletedMemo();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AwaitingViewButtonClick(TObject *Sender)
{
	RefreshAwaitingMemo();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DeleteRepeatsButtonClick(TObject *Sender)
{
	DeleteRepeats();
	RefreshCompletedMemo();
	RefreshAwaitingMemo();
	RefreshMemo();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ViewAllButtonClick(TObject *Sender)
{
   RefreshMemo();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DeleteSerialNumberButtonClick(TObject *Sender)
{
    bool found = false;
	int tmp;
	for (int i = 0 ; i < list.GetSize(); i++)
	{
		if (list[i].SerialNumber == DeleteSerialNumberEdit->Text)
		{
			found = true;
			tmp = i;
            break;
		}
	}

    if (!found)
	{
		ShowMessage("Not found");
		return;
	}

	list.remove(tmp);

	DeleteSerialNumberEdit->Clear();

    RefreshCompletedMemo();
	RefreshAwaitingMemo();
	RefreshMemo();
}
//---------------------------------------------------------------------------


