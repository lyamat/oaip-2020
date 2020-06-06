//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include "Tree.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TTreeView *TreeView;
	TMemo *Memo;
	TButton *CountOfRight;
	TButton *Delete;
	TButton *Find;
	TButton *Add;
	TRadioGroup *RadioGroup1;
	TRadioButton *rbStraight;
	TRadioButton *rbReversed;
	TRadioButton *rbSorted;
	TEdit *NumEdit;
	TEdit *CityEdit;
	TStringGrid *StringGrid;
	void __fastcall AddClick(TObject *Sender);
	void __fastcall FindClick(TObject *Sender);
	void __fastcall DeleteClick(TObject *Sender);
	void __fastcall rbStraightClick(TObject *Sender);
	void __fastcall rbReversedClick(TObject *Sender);
	void __fastcall rbSortedClick(TObject *Sender);
	void __fastcall CountOfRightClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
