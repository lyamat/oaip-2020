//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TComboBox *ComboBox;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TEdit *SerialNumberEdit;
	TEdit *FullNameEdit;
	TEdit *HomeAddressEdit;
	TEdit *SearchSerialNumberEdit;
	TEdit *SearchSurnameEdit;
	TButton *AddButton;
	TButton *EditButton;
	TButton *SearchRegistrationDateButton;
	TButton *SearchSerialNumberButton;
	TButton *SearchSurnameButton;
	TMemo *Memo;
	TDateTimePicker *DateSearchPicker;
	TMemo *AwaitingMemo;
	TMemo *CompletedMemo;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TButton *CompletedViewButton;
	TButton *AwaitingViewButton;
	TButton *DeleteRepeatsButton;
	TButton *ViewAllButton;
	TButton *DeleteSerialNumberButton;
	TEdit *DeleteSerialNumberEdit;
	TLabel *Label13;
	TGroupBox *gbOrderStatus;
	TRadioButton *rbCompleted;
	TRadioButton *rbAwaiting;
	TDateTimePicker *DateInputPicker;
	void __fastcall AddButtonClick(TObject *Sender);
	void __fastcall EditButtonClick(TObject *Sender);
	void __fastcall SearchRegistrationDateButtonClick(TObject *Sender);
	void __fastcall SearchSerialNumberButtonClick(TObject *Sender);
	void __fastcall SearchSurnameButtonClick(TObject *Sender);
	void __fastcall ComboBoxChange(TObject *Sender);
	void __fastcall CompletedViewButtonClick(TObject *Sender);
	void __fastcall AwaitingViewButtonClick(TObject *Sender);
	void __fastcall DeleteRepeatsButtonClick(TObject *Sender);
	void __fastcall ViewAllButtonClick(TObject *Sender);
	void __fastcall DeleteSerialNumberButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
