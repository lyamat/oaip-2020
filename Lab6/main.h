//---------------------------------------------------------------------------

#ifndef mainH
#define mainH

//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "InheritanceTable.h"

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo;
	TButton *SpacingDeleteButton;
	TButton *AddButton;
	TButton *RandomFillingButton;
	TButton *DeleteButton;
	TEdit *K1Edit;
	TEdit *K2Edit;
	TEdit *KeyEdit;
	TStaticText *StaticText1;
	TStaticText *StaticText2;
	TStaticText *StaticText3;

	void __fastcall RandomFillingButtonClick(TObject *Sender);
	void __fastcall RefreshMemo(TObject *Sender);
	void __fastcall AddButtonClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall DeleteButtonClick(TObject *Sender);
	void __fastcall SpacingDeleteButtonClick(TObject *Sender);
	void __fastcall SpacingDelete(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
