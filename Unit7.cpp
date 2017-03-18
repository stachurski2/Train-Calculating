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
      bool deparr;
      if(ComboBox2->ItemIndex==0){deparr=1;}
      else {deparr=0;}
        Form1->Rozklad->ChangeStartTime(atof(Edit1->Text.c_str()),atof(Edit2->Text.c_str()),ComboBox1->ItemIndex,deparr);;
                 Form7->ListBox4->Clear();
                for(int i=0;i<Form1->Rozklad->CountSection();i++){
                         Form7->ListBox4->Items->Add(Form1->Rozklad->ShowSchedule(i));

                }
}
//---------------------------------------------------------------------------



void __fastcall TForm7::ListBox1Click(TObject *Sender)
{
/*
        if(ListBox1->Items->operator [](ListBox1->ItemIndex)!="-"){
                POINT p;
                GetCursorPos(&p);
                PopupMenu1->Popup(p.x,p.y);
        }
*/
ListBox1->ItemIndex=ListBox1->ItemIndex;
ListBox2->ItemIndex=ListBox1->ItemIndex;
ListBox3->ItemIndex=ListBox1->ItemIndex;
ComboBox3->ItemIndex=ListBox1->ItemIndex;
Edit7->Text=Form1->Rozklad->ShowNamePoint(ListBox1->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TForm7::ListBox2Click(TObject *Sender)
{
       /* //if(){
                ShowMessage();
                POINT p;
                GetCursorPos(&p);
                PopupMenu1->Popup(p.x,p.y);
        //}
        */
        ListBox3->ItemIndex=ListBox2->ItemIndex;
        ListBox1->ItemIndex=ListBox2->ItemIndex;
        ListBox4->ItemIndex=ListBox2->ItemIndex;
        ComboBox3->ItemIndex=ListBox2->ItemIndex;
        Edit7->Text=Form1->Rozklad->ShowNamePoint(ListBox2->ItemIndex);
}
//---------------------------------------------------------------------------


void __fastcall TForm7::FormCreate(TObject *Sender)
{
        ComboBox1->Clear();

}
//---------------------------------------------------------------------------

void __fastcall TForm7::ComboBox1Change(TObject *Sender)
{
        if(ComboBox1->ItemIndex==0){
                ComboBox2->ItemIndex=1;
                ComboBox2->Enabled=0;
                }
        else if(ComboBox1->ItemIndex==Form1->Rozklad->CountSection()-1){
                ComboBox2->ItemIndex=0;
                ComboBox2->Enabled=0;
        }
        else {
            ComboBox2->Enabled=1;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm7::ListBox4Click(TObject *Sender)
{
ListBox2->ItemIndex=ListBox4->ItemIndex;
ListBox3->ItemIndex=ListBox4->ItemIndex;
ListBox1->ItemIndex=ListBox4->ItemIndex;
ComboBox3->ItemIndex=ListBox4->ItemIndex;
Edit7->Text=Form1->Rozklad->ShowNamePoint(ListBox4->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TForm7::ListBox3Click(TObject *Sender)
{
ListBox1->ItemIndex=ListBox3->ItemIndex;
ListBox2->ItemIndex=ListBox3->ItemIndex;
ListBox4->ItemIndex=ListBox3->ItemIndex;
ComboBox3->ItemIndex=ListBox3->ItemIndex;
Edit7->Text=Form1->Rozklad->ShowNamePoint(ListBox3->ItemIndex);
}
//---------------------------------------------------------------------------

