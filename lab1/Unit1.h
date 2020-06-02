//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <vcl.h>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TTimer *Timer1;
	TTimer *Timer2;
	TTimer *Timer3;
	TTimer *Timer4;
	TButton *Button5;
	TButton *Button6;
	TImage *Image1;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall Timer3Timer(TObject *Sender);
	void __fastcall Timer4Timer(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall CheckBox2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------

class MyRect
{
	private:
	int x, y, w, h ;

	public:
	MyRect (int x0, int y0, int width, int height)
	{
		x = x0;
		y = y0;
		h = height;
		w = width;
	}

	void Move(TCanvas* Canvas, int x, int y)
	{
		this->x += x;
		this->y += y;

		Show(Canvas);
	}

	void Show(TCanvas* Canvas)
	{
		Canvas->Pen->Color=clBlack;
		Canvas->Brush->Color=clBlue;
		Canvas->Rectangle(x, y, x + w, y + h);
	}

	void Hide (TCanvas * Canvas)
	{
		Canvas->Pen->Color = Form1->Color;
		Canvas->Brush->Color = Form1->Color;

		Canvas->Rectangle(x,y,x+w,y+h);
	}

	~MyRect(){};
};

////////////////////////////////////////////////////////////////////////////////////

class Wheels
{
    private:
	int x, y, r, d;

	protected:
	Wheels (int x0, int y0, int radius, int distanceAlongX)
	{
		x = x0;
		y = y0;
		r = radius;
		d = distanceAlongX;
	}

    void Show(TCanvas * Canvas)
	{
		Canvas->Pen->Color=clNavy;
		Canvas->Brush->Color=clLime;

		Canvas->Ellipse(x-r, y+r, x+r, y-r);
        Canvas->Ellipse(x-r + d, y+r, x+r + d, y-r);
	}

	void Move(TCanvas* Canvas, int x, int y)
	{
		this->x += x;
		this->y += y;

		Show(Canvas);
	}

	void Hide (TCanvas* Canvas)
	{
		Canvas->Pen->Color = Form1->Color;
		Canvas->Brush->Color = Form1->Color;

		Canvas->Ellipse(x-r, y-r, x+r, y+r);
		Canvas->Ellipse(x-r + d, y-r, x+r + d, y+r);
	}

	~Wheels(){};
};

////////////////////////////////////////////////////////////////////////////////////

class Truck: Wheels,MyRect
{
	private:
	int x, y, r;

	public:
	Truck(int x0, int y0, int width, int height, int radius, int distanceAlongX):
	MyRect(x0,y0,width,height),
	Wheels(x0 + 5, y0 + height, radius, width-10) {}


	void Hide(TCanvas* Canvas)
	{
		MyRect::Hide(Canvas);
		Wheels::Hide(Canvas);
	}

	void Show(TCanvas* Canvas)
	{
		MyRect::Show(Canvas);
		Wheels::Show(Canvas);
	}

	void Move(TCanvas* Canvas, int xNew, int yNew)
	{
		MyRect::Hide(Canvas);
		Wheels::Hide(Canvas);

		MyRect::Move(Canvas, xNew, yNew);
		Wheels::Move(Canvas, xNew, yNew);
	}

	~Truck(){};

};


#endif

