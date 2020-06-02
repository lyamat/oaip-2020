//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"

#include <stdlib.h>
#include <vcl.h>
#include <cstdlib>
#include <map>

List list;

Mstack<UnicodeString> op_stack;
Mstack<int> pos_stack;

using std::string;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------

std::map <int,int> operands = {
};


__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm1::OpenFileButtonClick(TObject *Sender)
{
	FileOpenDialog1 -> Execute();

	if (FileOpenDialog1->FileName == "")
	{
		return;
	}

	TFileStream*tfile = new TFileStream(FileOpenDialog1->FileName, fmOpenRead);
	TStringList *SL = new TStringList;

	SL->LoadFromStream(tfile);

	int lines = 0;
	for (; SL->Strings[lines] != ";" ; lines++);


	for (int i = 0; i < lines; i++)
	{
		ListBox1->Items->Add(SL->Strings[i]);
		//list.Add(StringToUS(SL->Strings[i]));
		list.Add(SL->Strings[i]);
	}

	delete tfile;
	delete SL;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ToListButtonClick(TObject *Sender)
{
	for (int i = 1; i < list.GetCount()+1; i++)
	{
		ListBox2->Items->Add(list.GetElemData(i));
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ChooseAndDeleteButtonClick(TObject *Sender)
{
	if (op_stack.Size() == 0)
	{
		int numOfSelect = 1;
		int check = 0;

		for (int i = 0; i < list.GetCount(); i++)
		{
			if (ListBox2->Selected[i])
			{
				op_stack.push(list.GetElemData(i+1));
				pos_stack.push(i);

				/*operands.insert( {numOfSelect+10, i} );*/
				numOfSelect++;
				ListBox2->Selected[i] = false;
				check++;

			}
		}

		if (check == list.GetCount())
		{
			for (int i = numOfSelect-1; i > 0; i--)
			{
				pos_stack.pop();
				check--;
			}
			ShowMessage("Оставьте строку(и) для вставки");
		}
		else
		{
			for (int i = numOfSelect-1; i > 0; i--)
				{
					ListBox2->Items->Delete(pos_stack.top());
					pos_stack.pop();
				}
		}

		Label2->Caption = numOfSelect - 1;

        if (check == 0)
		{
			ShowMessage("Выберите строку(и) для вставки");
		}
	}
	else
	{
		ShowMessage("Строки уже выбраны, теперь к строке вставки\n");
	}

}

//---------------------------------------------------------------------------

void __fastcall TForm1::ChooseAndInputButtonClick(TObject *Sender)
{
	int numOfSelect = StrToInt(Label2->Caption);
	int i = 0;
	int pos = 0;

	for (; i < list.GetCount() - numOfSelect; i++)
	{
		 if (ListBox2->Selected[i])
		 {
			pos++;
			break;
		 }
	}
	if (pos == 0)
	{
		ShowMessage("Вы не выбрали строку(и), перед которой вставлять");
	}
	else
	{
        if (op_stack.Size() == 0)
		{
			ShowMessage("Вы не выбрали строки для вставки, кнопка выше");
		}
		else
		{
			for (int j = 0; j < numOfSelect ; j++)
			{
				ListBox2->Items->Insert(i, op_stack.top());
				op_stack.pop();
			}

			int countInList = list.GetCount();
			list.DelAll();

			for (i = 0; i < countInList; i++)
			{
				list.Add(ListBox2->Items->Strings[i]);
			}
		}
    }
}

//---------------------------------------------------------------------------

