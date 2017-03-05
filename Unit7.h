//---------------------------------------------------------------------------

#ifndef Unit7H
#define Unit7H
#include "Unit1.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm7 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TEdit *Edit1;
        TEdit *Edit2;
        TLabel *Label3;
        TLabel *Label4;
        TListBox *ListBox2;
        TListBox *ListBox3;
        TLabel *Label6;
        TLabel *Label7;
        TListBox *ListBox1;
        TLabel *Label5;
        TListBox *ListBox4;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm7(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm7 *Form7;
//---------------------------------------------------------------------------
#endif
