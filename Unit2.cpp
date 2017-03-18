//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Unit1.h"
#include <vector>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
bool d=0;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
 ListBox1->Items->Clear();
 ListBox2->Items->Clear();
Form2->Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button3Click(TObject *Sender)
{

if(Form1->Linia->Size()>0){
        Form1->Linia->DeleteSection();
        ListBox1->Items->Clear();
        for(int i=0; i<Form1->Linia->Size(); i++){
                AnsiString s= Form1->Linia->ShowSection(i);
                Form2->ListBox1->Items->Add(s);}

        Form1->Linia->DeleteDescribe(-1);
        Form1->Linia->DeleteDescribes(Form1->Linia->ShowLength());
        if(Form1->Linia->ShowLength()!=0){ Form1->Linia->AddDescribe(Form1->Linia->ShowLength(),"End"); }
         ListBox2->Items->Clear();
        for(int i=0; i<Form1->Linia->DescriptionCount(); i++){
                AnsiString s=Form1->Linia->ShowDescribe(i);
                Form2->ListBox2->Items->Add(s);}


}



}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button2Click(TObject *Sender)
{
        double a,b;
        int c;
        a=atof((Edit1->Text).c_str());
        if(Form1->Linia->Size()==0){
                b=0;
        }
        else {
                b=Form1->Linia->ShowLength(); }
        c=atoi((Edit2->Text).c_str());


        if(a<=b){
                ShowMessage("Podaj wartosc wyzsza niz "+CurrToStr(Form1->Linia->ShowLength()));
                }
        else    {
                if(d==1){
                        //ShowMessage("1");
                        Form1->Linia->AddSection(b,a,c,1);
                        }
                else    {
                        // ShowMessage("0");
                        Form1->Linia->AddSection(b,a,c,0);
                        }
                }
        Form1->Linia->DeleteDescribe(-1);
        Form1->Linia->AddDescribe(a,"End");
        ListBox1->Items->Clear();
        for(int i=0; i<Form1->Linia->Size(); i++){
        AnsiString s= Form1->Linia->ShowSection(i);
        Form2->ListBox1->Items->Add(s);}
        ListBox2->Items->Clear();
        for(int i=0; i<Form1->Linia->DescriptionCount(); i++){
                AnsiString s=Form1->Linia->ShowDescribe(i);
                Form2->ListBox2->Items->Add(s);}


}
//---------------------------------------------------------------------------



void __fastcall TForm2::ListBox2Click(TObject *Sender)
{
        if(Form1->Linia->DescriptionCount()>0){
                Form2->Usupostj1->Enabled=1;
                int a = ListBox2->ItemIndex;
                int b = Form1->Linia->DescribeLocation(a);
                if(Form1->Linia->Vmax(b)==0 && b<Form1->Linia->ShowLength()){Form2->Usupostjje1->Enabled=1;}
                else{Form2->Usupostjje1->Enabled=0;}
         }
         else {
               Form2->Usupostj1->Enabled=0;

         }
                POINT p;
                GetCursorPos(&p);
                PopupMenu2->Popup(p.x,p.y);

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button4Click(TObject *Sender)
{


if(Form1->Linia->DescriptionCount()>0){
        int a= ListBox2->ItemIndex;
        if(a<0 || a>(Form1->Linia->DescriptionCount())-1){
                a=Form1->Linia->DescriptionCount()-1;
        }
        Form1->Linia->DeleteDescribe(a);
        ListBox2->Items->Clear();
        for(int i=0; i<Form1->Linia->DescriptionCount(); i++){
                AnsiString s=Form1->Linia->ShowDescribe(i);
                Form2->ListBox2->Items->Add(s);}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button5Click(TObject *Sender)
{
if(Edit4->Text!="" && Edit4->Text!=" " && atof((Edit3->Text).c_str())<=Form1->Linia->ShowLength()){
String nazwa = Edit4->Text;
double polozenie = atof((Edit3->Text).c_str());
Form1->Linia->AddDescribe(polozenie,nazwa);
ListBox2->Items->Clear();
if(Form1->Linia->ShowDescribe(0)!="0 - Start\0"){
Form1->Linia->AddDescribe(0,"Start");
}

if(Form1->Linia->ShowDescribe(Form1->Linia->DescriptionCount()-1)!=CurrToStr(Form1->Linia->ShowLength())+" - End\0"){
//ShowMessage("hahaha \n"+Form1->Linia->ShowDescribe(Form1->Linia->DescriptionCount()-1));
Form1->Linia->AddDescribe(Form1->Linia->ShowLength(),"End");

}

for(int i=0; i<Form1->Linia->DescriptionCount(); i++){
AnsiString s=Form1->Linia->ShowDescribe(i);
Form2->ListBox2->Items->Add(s);}
}
}
//---------------------------------------------------------------------------




void __fastcall TForm2::CheckBox1Click(TObject *Sender)
{
        if(d==0){d=1;}
        else {d=0;}


}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button6Click(TObject *Sender)
{

        try{
                if(SaveDialog1->Execute()){
                TStringList *wynik =  new TStringList;
                wynik = Form1 -> Linia -> SaveToFile();
                wynik -> SaveToFile(SaveDialog1->FileName);
                }
        }
        catch (...){

        }

}
//---------------------------------------------------------------------------


void __fastcall TForm2::ListBox1Click(TObject *Sender)
{
        POINT p;
        GetCursorPos(&p);
       PopupMenu1->Popup(p.x,p.y);
       /*

       */
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button7Click(TObject *Sender)
{
        Form6->Visible="TRUE";
        Form6->Button2->Visible=1;
        Form6->Button1->Visible=0;
        Form6->Caption="Definiowanie ograniczenia";
        Form6->CheckBox2->Visible=0;
        Form6->Label6->Visible=0;
}
//---------------------------------------------------------------------------



void __fastcall TForm2::blele1Click(TObject *Sender)
{
 Form6->number_of_section=ListBox1->ItemIndex;
        Form6->Visible="TRUE";
        Form6->Show();
        Form6->Button2->Visible=0;
        Form6->Button1->Visible=1;
        Form6->CheckBox2->Visible=1;
        Form6->CheckBox3->Visible=0;
        Form6->Label1->Visible=0;
        Form6->Label6->Visible=1;
        Form6->Caption="W³asciwosci odcinka nr "+CurrToStr(ListBox1->ItemIndex);
        Form6->Edit1->Text = Form1->Linia->ShowStart(ListBox1->ItemIndex);
        Form6->Edit2->Text = Form1->Linia->ShowEnd(ListBox1->ItemIndex);
        Form6->Edit3->Text = Form1->Linia->ShowSpeed(ListBox1->ItemIndex);
        if(Form1->Linia->ShowSpot(ListBox1->ItemIndex)==1){
                Form6->CheckBox1->Checked="TRUE";
        }
        else if(Form1->Linia->ShowSpot(ListBox1->ItemIndex)==0)
        {
                Form6->CheckBox1->Checked=0;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::blabl1Click(TObject *Sender)
{
   Form1->Linia->ChangeSection(1,ListBox1->ItemIndex,0,0,0,0);
   Form2->ListBox1->Items->Clear();
   for(int i=0; i<Form1->Linia->Size(); i++){
                        AnsiString s= Form1->Linia->ShowSection(i);
                        Form2->ListBox1->Items->Add(s);}
   Form2->ListBox2->Items->Clear();
   for(int i=0; i<Form1->Linia->DescriptionCount(); i++){
                        AnsiString s=Form1->Linia->ShowDescribe(i);
                        Form2->ListBox2->Items->Add(s);}
   if(Form1->Linia->DescriptionCount()==0){Form2->ListBox2->Items->Add("      ");}

}
//---------------------------------------------------------------------------

void __fastcall TForm2::ListBox3Click(TObject *Sender)
{

        POINT p;
        GetCursorPos(&p);
       PopupMenu2->Popup(p.x,p.y);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Wstawpostj1Click(TObject *Sender)
{

Form8->Show();
Form8->Label1->Caption="Lokalizacja postoju";
Form8->Button1->Visible=1;
Form8->Button2->Visible=0;
}
//---------------------------------------------------------------------------


void __fastcall TForm2::FormCreate(TObject *Sender)
{
//if( ListBox3->Items->Count==0) {ListBox3->Items->Add("   ");}
}
//---------------------------------------------------------------------------



void __fastcall TForm2::Usupostj1Click(TObject *Sender)
{

if(Form1->Linia->DescriptionCount()>0){
        int a= ListBox2->ItemIndex;
        if(a<0 || a>(Form1->Linia->DescriptionCount())-1){
                a=Form1->Linia->DescriptionCount()-1;
        }
        Form1->Linia->DeleteDescribe(a);
        ListBox2->Items->Clear();
        for(int i=0; i<Form1->Linia->DescriptionCount(); i++){
                AnsiString s=Form1->Linia->ShowDescribe(i);
                Form2->ListBox2->Items->Add(s);}
        if(Form1->Linia->DescriptionCount()==0){Form2->ListBox2->Items->Add("      ");}
}
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Usupostjje1Click(TObject *Sender)
{
       int a = ListBox2->ItemIndex;
       int b = Form1->Linia->DescribeLocation(a);

        ShowMessage(CurrToStr(Form1->Linia->FindSection(b))+"//"+CurrToStr(Form1->Linia->Size()));
        Form1->Linia->DeleteDescribe(a);
        Form1->Linia->ChangeSection(1,Form1->Linia->FindSection(b),0,0,0,0);
        Form2->ListBox1->Items->Clear();
        for(int i=0; i<Form1->Linia->Size(); i++){
                        AnsiString s= Form1->Linia->ShowSection(i);
                        Form2->ListBox1->Items->Add(s);}
        Form2->ListBox2->Items->Clear();
        for(int i=0; i<Form1->Linia->DescriptionCount(); i++){
                        AnsiString s=Form1->Linia->ShowDescribe(i);
                        Form2->ListBox2->Items->Add(s);}
        if(Form1->Linia->DescriptionCount()==0){Form2->ListBox2->Items->Add("      ");}

}
//---------------------------------------------------------------------------




void __fastcall TForm2::Dodajodcinek1Click(TObject *Sender)
{
         Form6->Visible="TRUE";
         Form6->Show();
         Form6->CheckBox3->Visible=1;
          Form6->CheckBox3->Checked=0;
        Form6->Label1->Visible=1;
        Form6->Button2->Visible=1;
        Form6->Button1->Visible=0;
        Form6->Edit1->Enabled=1;
         Form6->Edit2->Enabled=1;
          Form6->Edit3->Enabled=1;
           Form6->CheckBox1->Enabled=1;
        Form6->Caption="Definiowanie ograniczenia";
        Form6->CheckBox2->Visible=0;
        Form6->Label6->Visible=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edytujpostj1Click(TObject *Sender)
{
        Form8->Show();
        Form8->Label1->Caption="Lokalizacja punktu rozk³adowego";
        Form8->Button2->Visible=1;
        Form8->Button1->Visible=0;
}
//---------------------------------------------------------------------------

