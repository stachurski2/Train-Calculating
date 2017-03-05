//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit7.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm7::Button3Click(TObject *Sender)
{
        Form1->Rozklad->ChangeStartTime(atof(Edit1->Text.c_str()),atof(Edit2->Text.c_str()));;
                 Form7->ListBox4->Clear();
                for(int i=0;i<Form1->Rozklad->CountSection();i++){
                         Form7->ListBox4->Items->Add(Form1->Rozklad->ShowSchedule(i));

                }
}
//---------------------------------------------------------------------------

