//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit8.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Button1Click(TObject *Sender)
{
                if( atof((Form8->Edit1->Text).c_str())<Form1->Linia->ShowLength() && atof((Form8->Edit1->Text).c_str())>0)
                {
                        Form1->Linia->AddDescribe(atof((Form8->Edit1->Text).c_str()),Form8->Edit2->Text);
                        Form1->Linia->ChangeSection(0,-1,atof((Form8->Edit1->Text).c_str()),atof((Form8->Edit1->Text).c_str())+1,0,1);
                        Form2->ListBox1->Items->Clear();
                        for(int i=0; i<Form1->Linia->Size(); i++){
                                AnsiString s= Form1->Linia->ShowSection(i);
                                Form2->ListBox1->Items->Add(s);}
                        Form2->ListBox2->Items->Clear();
                        for(int i=0; i<Form1->Linia->DescriptionCount(); i++){
                                AnsiString s=Form1->Linia->ShowDescribe(i);
                                Form2->ListBox2->Items->Add(s);}
                }
                else
                {
                        Application->MessageBoxA("Nie mo¿na wstawic postoju poza zakresem","B³¹d",MB_ICONWARNING);
                }

                                
                Form8->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button2Click(TObject *Sender)
{
        if(Edit1->Text!="" && Edit2->Text!=" " && atof((Edit1->Text).c_str())<=Form1->Linia->ShowLength()){
                String nazwa = Edit2->Text;
                double polozenie = atof((Edit1->Text).c_str());
                Form1->Linia->AddDescribe(polozenie,nazwa);
                Form2->ListBox2->Items->Clear();
                for(int i=0; i<Form1->Linia->DescriptionCount(); i++){
                        AnsiString s=Form1->Linia->ShowDescribe(i);
                        Form2->ListBox2->Items->Add(s);}
                Form8->Close();
        }
        else
        {
                Application->MessageBoxA("Próbujesz wstawic punkt rozk³adowy poza lini¹","B³¹d",MB_ICONWARNING);
        }


}
//---------------------------------------------------------------------------

