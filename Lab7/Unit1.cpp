

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

Node* tree = NULL;

//---------------------------------------------------------------------------

void ViewTree(Node *tree, int count)
{
	if (tree == NULL)
	{
		return;
	}
	if (count == -1)
	{
		Form1->TreeView->Items->AddFirst(NULL, "[" + IntToStr(tree->value) + "] " + tree->str);
	}
	else
	{
		Form1->TreeView->Items->AddChildFirst(Form1->TreeView->Items->Item[count], "[" + IntToStr(tree->value) + "] " + tree->str);
	}
	count++;
	ViewTree(tree->pLeft, count);
	ViewTree(tree->pRight, count);
	count--;
}

//---------------------------------------------------------------------------

void ShowAs(Node* node, int n)
{
	if(node == NULL)
	{
		return;
	}
	switch (n)
	{
		case 0:
		{
			Form1->Memo->Lines->Add("[" + IntToStr(node->value) + "]  " + node->str);
			ShowAs(node->pLeft, n);
			ShowAs(node->pRight, n);
			break;
		}
		case 1:
		{
			ShowAs(node->pRight, n);
			ShowAs(node->pLeft, n);
			Form1->Memo->Lines->Add("[" + IntToStr(node->value) + "]  " + node->str);
			break;
		}
		case 2:
		{
			ShowAs(node->pLeft, n);
			Form1->Memo->Lines->Add("[" + IntToStr(node->value) + "]  " + node->str);
			ShowAs(node->pRight, n);
			break;
		}
		default:
		{
			break;
		}
	}
}

//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	StringGrid->FixedCols=0;

	StringGrid->Cells[0][0]="NUM";	StringGrid->Cells[1][0] = "CITY";

	StringGrid->Cells[0][10]="8"; 	StringGrid->Cells[1][1]="Ottawa";
	StringGrid->Cells[0][11]="3"; 	StringGrid->Cells[1][2]="Santiago";
	StringGrid->Cells[0][12]="4"; 	StringGrid->Cells[1][3]="Prague";
	StringGrid->Cells[0][4]="1"; 	StringGrid->Cells[1][4]="Vilnius";
	StringGrid->Cells[0][5]="2"; 	StringGrid->Cells[1][5]="Majuro";
	StringGrid->Cells[0][1]="5"; 	StringGrid->Cells[1][6]="Palikir";
	StringGrid->Cells[0][2]="9"; 	StringGrid->Cells[1][7]="Tbilisi";
	StringGrid->Cells[0][3]="7"; 	StringGrid->Cells[1][8]="Monaco";
	StringGrid->Cells[0][9]="6"; 	StringGrid->Cells[1][9]="Rabat";
	StringGrid->Cells[0][6]="10"; 	StringGrid->Cells[1][10]="Rome";
	StringGrid->Cells[0][8]="12"; 	StringGrid->Cells[1][11]="Astana";
	StringGrid->Cells[0][7]="11"; 	StringGrid->Cells[1][12]="Riga";

	int num = 12;

	for(int i = 1; i <= num; i++)
	{
		tree = tree->Add(tree, StrToInt(StringGrid->Cells[0][i]), StringGrid->Cells[1][i]);
	}
	ViewTree(tree, -1);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::AddClick(TObject *Sender)
{
    if(NumEdit->Text != "" && CityEdit->Text != "")
	{
		Node* node;
		tree = tree->Add(tree, NumEdit->Text.ToInt(), CityEdit->Text);
		NumEdit->Text = "";
		CityEdit->Text = "";
		TreeView->Items->Clear();
		ViewTree(tree, -1);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FindClick(TObject *Sender)
{
	Node* node = tree->Find(tree, NumEdit->Text.ToInt());
	if (node)
	{
		Memo->Lines->Clear();
		Memo->Lines->Add("[" + IntToStr(node->value) + "] " + node->str);
	}
	else
	{
		Memo->Lines->Clear();
		Memo->Lines->Add("Такого города у нас нет");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DeleteClick(TObject *Sender)
{
    if(NumEdit->Text != "")
	{
		tree = tree->Delete(tree, NumEdit->Text.ToInt());
		NumEdit->Text = "";
		CityEdit->Text = "";
		TreeView->Items->Clear();
		ViewTree(tree, -1);
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::rbStraightClick(TObject *Sender)
{
	Form1->Memo->Lines->Clear();
	::ShowAs(tree, 0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rbReversedClick(TObject *Sender)
{
	Form1->Memo->Lines->Clear();
	::ShowAs(tree, 1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rbSortedClick(TObject *Sender)
{
	Form1->Memo->Lines->Clear();
	::ShowAs(tree, 2);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CountOfRightClick(TObject *Sender)
{
	ShowMessage(IntToStr(Tree::CountOfRight(tree->pRight)) + " узла(ов) в правой ветке дерева");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	/*tree->Balance(tree);
    TreeView->Items->Clear();
	ViewTree(tree, -1);  */
}
//---------------------------------------------------------------------------


