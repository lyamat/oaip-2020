//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TListBox *ListBox1;
	TFileOpenDialog *FileOpenDialog1;
	TSaveDialog *SaveDialog1;
	TButton *OpenFileButton;
	TListBox *ListBox2;
	TButton *ToListButton;
	TButton *ChooseAndDeleteButton;
	TLabel *Label2;
	TButton *ChooseAndInputButton;
	TLabel *Label1;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	void __fastcall OpenFileButtonClick(TObject *Sender);
	void __fastcall ToListButtonClick(TObject *Sender);
	void __fastcall ChooseAndDeleteButtonClick(TObject *Sender);
	void __fastcall ChooseAndInputButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
