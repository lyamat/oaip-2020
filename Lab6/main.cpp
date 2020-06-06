//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------

TForm1 *Form1;

InheritanceTable* HTable = new InheritanceTable(10);

//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}

//---------------------------------------------------------------------------

void __fastcall TForm1::RandomFillingButtonClick(TObject *Sender)
{
	int i = 0;
	while(i <= 21 )
	{
		HTable->Add(1 + rand() % 100);
		i++;
	}
	RefreshMemo(Sender);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::AddButtonClick(TObject *Sender)
{
	HTable->Add(KeyEdit->Text.ToInt());
	RefreshMemo(Sender);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::DeleteButtonClick(TObject *Sender)
{
	HTable->DeleteNode(KeyEdit->Text.ToInt());
	RefreshMemo(Sender);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::SpacingDeleteButtonClick(TObject *Sender)
{
	SpacingDelete(Sender);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::SpacingDelete(TObject *Sender)
{
	HTable->SpacingDelete(K1Edit->Text.ToInt(), K2Edit->Text.ToInt());
	RefreshMemo(Sender);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::RefreshMemo(TObject *Sender)
{
	Memo->Lines->Clear();
	HTable->Print(Memo);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	RefreshMemo(Sender);
}

//---------------------------------------------------------------------------
