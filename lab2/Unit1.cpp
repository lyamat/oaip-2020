//---------------------------------------------------------------------------

#include <vcl.h>
#include <string.h>

#include "Unit1.h"
#include "EXContainer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


EXContainer container;
#define orders container.Orders

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
	for(int i = 0; i < orders.size(); i++)
	{
		Form1->Memo->Lines->Add(orders[i].OrderNumber);
		Form1->Memo->Lines->Add(orders[i].TableNumber);
		Form1->Memo->Lines->Add(orders[i].DishName);
		Form1->Memo->Lines->Add(orders[i].DishCost);
		Form1->Memo->Lines->Add(orders[i].NumberOfServings);
		Form1->Memo->Lines->Add("====================");
		Form1->ComboBox->Items->Add(orders[i].OrderNumber);
	}
}

void ShowOrder(Order order)
{
	Form1->OrderNumberEdit->Text = (order).OrderNumber;
	Form1->TableNumberEdit->Text = (order).TableNumber;
	Form1->DishNameEdit->Text = (order).DishName;
	Form1->DishCostEdit->Text = (order).DishCost;
	Form1->NumberOfServingsEdit->Text = (order).NumberOfServings;
	Form1->DishCostEdit->Text = (order).DishCost;
	Form1->OrderInvoiceEdit->Text = (order).DishCost * (order).NumberOfServings;

	Form1->ComboBox->Text = order.OrderNumber;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::GetDateButtonClick(TObject *Sender)
{
	FileOpenDialog->Execute();
	Label->Caption=FileOpenDialog->FileName;

    if (FileOpenDialog->FileName == "")
	{
		return;
	}

	TFileStream*tfile = new TFileStream(FileOpenDialog->FileName, fmOpenRead);
	TStringList *SL = new TStringList;

	SL->LoadFromStream(tfile);

	int lines = 0;
	for (; SL->Strings[lines] != ";" ; lines++);

	orders.resize((lines / 6));

	for (int i = 0; i < lines; i+=6)
	{
		int num = i/6;
		orders[num].ReadOrderNumber(SL->Strings[i]);
		orders[num].ReadTableNumber(SL->Strings[i+1]);
		orders[num].ReadDishName(SL->Strings[i+2]);
		orders[num].ReadDishCost(SL->Strings[i+3]);
		orders[num].ReadNumberOfServings(SL->Strings[i+4]);
	}

	delete tfile;
	delete SL;

	RefreshMemo();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::AddButtonClick(TObject *Sender)
{
	vector<Order>::iterator i = orders.begin();
	vector<Order>::iterator j;
	for (j = orders.begin(); j != orders.end(); j++)
	{
			if ((*j).OrderNumber == OrderNumberEdit->Text)
			{
				ShowMessage("This order number is already exists");
				return;
			}
	}

	bool found = false;

	for (i = orders.begin(); i != orders.end(); i++)
	{
		if ((*i).OrderNumber == ComboBox->Text)
		{
			found = true;
			break;
		}
	}
	if (OrderNumberEdit->Text == "")
	{
		ShowMessage("Order number is empty");
		return;
	}
	if (TableNumberEdit->Text == "")
	{
		ShowMessage("Table number is empty");
		return;
	}
	if (DishNameEdit->Text == "")
	{
		ShowMessage("Dish name is empty");
		return;
	}
	if (DishCostEdit->Text == "")
	{
		ShowMessage("Dish cost is empty");
		return;
	}
	if (NumberOfServingsEdit->Text == "")
	{
		ShowMessage("Number of servings is empty");
		return;
	}

	Order* temp = new Order(OrderNumberEdit->Text, TableNumberEdit->Text, DishNameEdit->Text,
							DishCostEdit->Text, NumberOfServingsEdit->Text);
	orders.push_back(*temp);

	RefreshMemo();

	delete temp;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBoxChange(TObject *Sender)
{
	bool found = false;
	vector<Order>::iterator i;

	for (i = orders.begin(); i != orders.end(); i++)
	{
		if ((*i).OrderNumber == ComboBox->Text)
		{
			found = true;
			break;
		}
	}

	if (!found)
	{
		ShowMessage("Not found");
		return;
	}

	ShowOrder(*i);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EditButtonClick(TObject *Sender)
{
	if (OrderNumberEdit->Text == "")
	{
		ShowMessage("Order number is empty");
		return;
	}
	if (TableNumberEdit->Text == "")
	{
		ShowMessage("Table number is empty");
		return;
	}
	if (DishNameEdit->Text == "")
	{
		ShowMessage("Dish name is empty");
		return;
	}
	if (DishCostEdit->Text == "")
	{
		ShowMessage("Dish cost is empty");
		return;
	}
	if (NumberOfServingsEdit->Text == "")
	{
		ShowMessage("Number of servings is empty");
		return;
	}

	bool found = false;
	vector<Order>::iterator i;

	for (i = orders.begin(); i != orders.end(); i++)
	{
		if ((*i).OrderNumber == ComboBox->Text)
		{
			found = true;
			break;
		}
	}

	if (!found)
	{
		ShowMessage("Not found");
		return;
	}

	(*i) = Order(OrderNumberEdit->Text, TableNumberEdit->Text, DishNameEdit->Text,
				 DishCostEdit->Text, NumberOfServingsEdit->Text);

	/////////////////////////////////////////////////

    ShowOrder(*i);

	RefreshMemo();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SearchButtonClick(TObject *Sender)
{
	vector<Order>::iterator i = orders.begin();
	bool found = false;

	for (; i != orders.end(); i++)
	{
		if ((*i).DishName == SearchEdit->Text)
		{
			found = true;
			break;
		}
	}

	if (!found)
	{
		ShowMessage("Not found");
		return;
	}

	ShowOrder(*i);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SaveDataButtonClick(TObject *Sender)
{
	SaveDialog->FileName = Label->Caption;

	if (!SaveDialog->Execute())
	{
		return;
	}

	Label->Caption = SaveDialog->FileName;
	Memo1->Lines->Clear();

	for (vector<Order>::iterator i = orders.begin(); i != orders.end(); i++)
	{
		Memo1->Lines->Add((*i).ToString());
	}

	Memo1->Lines->Add("end");

	Memo1->Lines->SaveToFile(Label->Caption);
	Memo1->Lines->LoadFromFile(Label->Caption);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::SortButtonClick(TObject *Sender)
{
	 container.SortAllByOrderInvoice();
	 RefreshMemo();
}

//---------------------------------------------------------------------------

void __fastcall TForm1::TopDishesButtonClick(TObject *Sender)
{
	container.TopTwoDishes();
	Form1->Memo->Lines->Clear();
	Form1->ComboBox->Items->Clear();
	for(int i = 0; i < 3; i++)
	{
		Form1->Memo->Lines->Add(orders[i].OrderNumber);
		Form1->Memo->Lines->Add(orders[i].TableNumber);
		Form1->Memo->Lines->Add(orders[i].DishName);
		Form1->Memo->Lines->Add(orders[i].DishCost);
		Form1->Memo->Lines->Add(orders[i].NumberOfServings);
		Form1->Memo->Lines->Add("====================");
		Form1->ComboBox->Items->Add(orders[i].OrderNumber);
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ViewAllButtonClick(TObject *Sender)
{
	container.SortAllBySeOrderNumber();
	RefreshMemo();
}

//---------------------------------------------------------------------------

