//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <string>
#include <vcl.h>
#include <stdlib.h>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *OrderNumberLabel;
	TLabel *TableNumberLabel;
	TLabel *DishNameLabel;
	TLabel *NumberOfServingsLabel;
	TLabel *OrderInvoiceLabel;
    TLabel *DishCostLabel;
	TLabel *SearchLabel;
	TLabel *Label;

	TButton *AddButton;
	TButton *EditButton;
	TButton *GetDateButton;
	TButton *SortButton;
	TButton *SearchButton;
	TButton *TopDishesButton;
	TButton *SaveDataButton;
	TButton *ViewAllButton;

	TFileOpenDialog *FileOpenDialog;
	TSaveDialog *SaveDialog;

	TComboBox *ComboBox;

	TEdit *SearchEdit;
	TEdit *OrderNumberEdit;
	TEdit *TableNumberEdit;
	TEdit *DishNameEdit;
	TEdit *NumberOfServingsEdit;
	TEdit *OrderInvoiceEdit;
	TEdit *DishCostEdit;

	TMemo *Memo1;
	TMemo *Memo;

	void __fastcall GetDateButtonClick(TObject *Sender);
	void __fastcall AddButtonClick(TObject *Sender);
	void __fastcall ComboBoxChange(TObject *Sender);
	void __fastcall EditButtonClick(TObject *Sender);
	void __fastcall SearchButtonClick(TObject *Sender);
	void __fastcall SaveDataButtonClick(TObject *Sender);
	void __fastcall SortButtonClick(TObject *Sender);
	void __fastcall TopDishesButtonClick(TObject *Sender);
	void __fastcall ViewAllButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------

#endif
