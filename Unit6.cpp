//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit6.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TForm6::Button1Click(TObject *Sender)
{
        if(CheckBox2->Checked==1){
                    Form1->Linia->ChangeSection(1,number_of_section,0,0,0,0);
                    }
        else
        {
                if(CheckBox1->Checked==1){
                        Form1->Linia->ChangeSection(0,number_of_section,atof((Form6->Edit1->Text).c_str()),atof((Form6->Edit2->Text).c_str()),atoi((Form6->Edit3->Text).c_str()),1);
                        }
                else if (CheckBox1->Checked==0){
                        Form1->Linia->ChangeSection(0,number_of_section,atof((Form6->Edit1->Text).c_str()),atof((Form6->Edit2->Text).c_str()),atoi((Form6->Edit3->Text).c_str()),0);
                }
        }

                Form2->ListBox1->Items->Clear();
                for(int i=0; i<Form1->Linia->Size(); i++){
                        AnsiString s= Form1->Linia->ShowSection(i);
                        Form2->ListBox1->Items->Add(s);}
                Form2->ListBox2->Items->Clear();
                for(int i=0; i<Form1->Linia->DescriptionCount(); i++){
                        AnsiString s=Form1->Linia->ShowDescribe(i);
                        Form2->ListBox2->Items->Add(s);}
                Form6->Close();



}
//---------------------------------------------------------------------------

void __fastcall TForm6::CheckBox2Click(TObject *Sender)
{
if(Edit1->Enabled==1){
        Edit1->Enabled=0;
        Edit2->Enabled=0;
        Edit3->Enabled=0;
        CheckBox1->Enabled=0;
}
else {
        Edit1->Enabled=1;
        Edit2->Enabled=1;
        Edit3->Enabled=1;
        CheckBox1->Enabled=1;
}

}
//---------------------------------------------------------------------------


void __fastcall TForm6::Button2Click(TObject *Sender)
{

        Form1->Linia->ChangeSection(0,-1,atof((Form6->Edit1->Text).c_str()),atof((Form6->Edit2->Text).c_str()),atoi((Form6->Edit3->Text).c_str()),CheckBox1->Checked);
            Form2->ListBox1->Items->Clear();
                for(int i=0; i<Form1->Linia->Size(); i++){
                        AnsiString s= Form1->Linia->ShowSection(i);
                        Form2->ListBox1->Items->Add(s);}
                Form2->ListBox2->Items->Clear();
                for(int i=0; i<Form1->Linia->DescriptionCount(); i++){
                        AnsiString s=Form1->Linia->ShowDescribe(i);
                        Form2->ListBox2->Items->Add(s);}
                Form6->Close();

}
//---------------------------------------------------------------------------

