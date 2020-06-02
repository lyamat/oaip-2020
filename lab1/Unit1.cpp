//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#define Canvas Image1->Canvas

TForm1 *Form1;
Truck MyTruck (150,150,100,40,10,75);

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if (((!CheckBox1->Checked) && (!CheckBox2->Checked)))
	{
		  ShowMessage("Выберите тип передвижения");
		  return;
	}

	Timer3->Enabled=false;
	Timer4->Enabled=false;
	Timer2->Enabled=false;

	if (CheckBox1->Checked)
	{
		if (!Timer1->Enabled)
		{
			Timer1->Enabled = true;
		}
		else
		{
			Timer1->Enabled = false;
		}
	}
	else
	{
		MyTruck.Move(Canvas,0,-100);
	}
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
   if ((!CheckBox1->Checked) && (!CheckBox2->Checked))
	{
		  ShowMessage("Выберите тип передвижения");
          return;
	}

	Timer1->Enabled=false;
	Timer3->Enabled=false;
	Timer4->Enabled=false;

    if (CheckBox1->Checked)
	{
		if (!Timer2->Enabled)
		{
			Timer2->Enabled = true;
		}
		else
		{
			Timer2->Enabled = false;
		}
	}
	else
	{
		MyTruck.Move(Canvas,-100,0);
	}
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	if ((!CheckBox1->Checked) && (!CheckBox2->Checked))
	{
		  ShowMessage("Выберите тип передвижения");
          return;
	}

	Timer1->Enabled=false;
	Timer4->Enabled=false;
	Timer2->Enabled=false;

	if (CheckBox1->Checked)
	{
		if (!Timer3->Enabled)
		{
			Timer3->Enabled = true;
		}
		else
		{
			Timer3->Enabled = false;
		}
	}
	else
	{
		MyTruck.Move(Canvas,0,100);
	}
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	if ((!CheckBox1->Checked) && (!CheckBox2->Checked))
	{
		  ShowMessage("Выберите тип передвижения");
		  return;
	}

	Timer1->Enabled=false;
	Timer3->Enabled=false;
	Timer2->Enabled=false;

	if (CheckBox1->Checked)
	{
		if (!Timer4->Enabled)
		{
			Timer4->Enabled = true;
		}
		else
		{
			Timer4->Enabled = false;
		}
	}
	else
	{
		MyTruck.Move(Canvas,100,0);
	}
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	MyTruck.Move(Canvas,0,-10);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
	MyTruck.Move(Canvas,-10,0);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Timer3Timer(TObject *Sender)
{
	MyTruck.Move(Canvas,0,10);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Timer4Timer(TObject *Sender)
{
	MyTruck.Move(Canvas,10,0);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	Timer1->Enabled=false;
	Timer2->Enabled=false;
	Timer3->Enabled=false;
	Timer4->Enabled=false;

}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{

	Button6->Visible = false;
	TForm1::Button5Click(Sender);

	Image1->Visible = true;
	CheckBox2->Visible = true;
	CheckBox1->Visible = true;
	Button1->Visible = true;
	Button2->Visible = true;
	Button3->Visible = true;
	Button4->Visible = true;
	Button5->Visible = true;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
if ((CheckBox2->Checked))
	{
		CheckBox1->Checked = false;
		Button5->Enabled = false;

		Timer1->Enabled=false;
		Timer3->Enabled=false;
		Timer4->Enabled=false;
		Timer2->Enabled=false;
	}


}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox2Click(TObject *Sender)
{
   if ((CheckBox1->Checked))
	{
		CheckBox2->Checked = false;
			Button5->Enabled = true;
	}
}
//---------------------------------------------------------------------------


