//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
void TForm3::RysujWykres(){
        Form3->Canvas->Unlock();
        Form3->Refresh();
        Form3->Canvas->Pen->Color = clBlack;
        Form3->Canvas->Pen->Width = 3;
        //arrow y
        Form3->Canvas->MoveTo(328,16);
        Form3->Canvas->LineTo(325,24);
        Form3->Canvas->LineTo(331,24);
        Form3->Canvas->LineTo(328,16);
        //arrow x
        Form3->Canvas->MoveTo(928,616);
        Form3->Canvas->LineTo(920,619);
        Form3->Canvas->LineTo(920,613);
        Form3->Canvas->LineTo(928,616);

         // y
        Form3->Canvas->Pen->Color = clBlack;
        Form3->Canvas->Pen->Width = 1;
        double  a =  Form1->Pojazd->MaxForce();
        for(int i=0;i<=10;i++){
                Form3->Canvas->TextOut(290,30 + i*58,CurrToStr(a - i*a/10));
                Form3->Canvas->MoveTo(323,36 + i*58);
                Form3->Canvas->LineTo(928,36 + i*58);
        }
        // x
        int b = Form1->Pojazd->Vmax();
        int c= b/10;
        if(Form1->Pojazd->CharSize()>0 && c!=0){
        for(int i=0; i<=c; i++){
                Form3->Canvas->TextOut(900-(i*580/c),622,CurrToStr(c*10-i*10));
                Form3->Canvas->MoveTo(908-(i*580/c),619);
                Form3->Canvas->LineTo(908-(i*580/c),16);
        }
        }
        //belongs
        Form3->Canvas->Pen->Color = clRed;
        Form3->Canvas->Pen->Width = 3;
        if(c!=0){
                Form3->Canvas->MoveTo(328+(Form1->Pojazd->ShowSpeed(0))*580/(c*10),616-(Form1->Pojazd->ShowForce(0))*580/a);



        for(int i=0; i<Form1->Pojazd->CharSize();i++){
                      Form3->Canvas->LineTo(328+(Form1->Pojazd->ShowSpeed(i))*580/(c*10),616-(Form1->Pojazd->ShowForce(i))*580/a);

                  //   Form3->Canvas->LineTo(328+c*10/580*(Form1->Pojazd->ShowSpeed(i)),616-a/580*(Form1->Pojazd->ShowForce(i)));

        }
        }
        else {
        Form3->Canvas->TextOut(350,350,"Brak mozliwosci wygenerowania wykresu, minimalna predkosc maksymalna powinna byc wieksza od 10.");
        }
        Form3->Canvas->Lock();

}




//-----------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender)
{
Form3->ListBox1->Clear();
Form3->Close();
}


//---------------------------------------------------------------------------

void __fastcall TForm3::Edit1Change(TObject *Sender)
{
Form1->Pojazd->ChangeName(Edit1->Text);
Form1->Edit2->Text=Edit1->Text;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Edit2Change(TObject *Sender)
{
Form1->Pojazd->ChangeWheels(Edit2->Text);
Form1->Edit10->Text = Form1->Pojazd->ShowWheels();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Edit3Change(TObject *Sender)
{
Form1->Pojazd->ChangeWeight(Edit3->Text);
Form1->Edit6->Text = Form1->Pojazd ->ShowWeight();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Edit4Change(TObject *Sender)
{
Form1->Pojazd->ChangeLength(Edit4->Text);
Form1->Edit3->Text = Form1->Pojazd ->ShowLength();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{
        if(ListBox1->ItemIndex>=0)
        {
        try
        {
        Form1->Pojazd->DeleteChar(ListBox1->ItemIndex);
        ListBox1->Clear();
        for (int i=0; i<Form1->Pojazd->CharSize(); i++){
                Form3->ListBox1->Items->Add(Form1->Pojazd->ShowChar(i,0));
                }
        RysujWykres();
        Form1->Edit13->Text = CurrToStr(Form1->Pojazd->Vmax());
        }
        catch(...)
        {
        ShowMessage("B³¹d");
        }
        }
        else {
        ShowMessage("Wybierz punkt do usuniecia");

        }

}

//---------------------------------------------------------------------------
void __fastcall TForm3::Button3Click(TObject *Sender)
{
        int Speed = atoi(Form3->Edit5->Text.c_str());
        double Force = atof(Form3->Edit6->Text.c_str());
        Form1 -> Pojazd -> AddChar(Speed,Force);
        ListBox1->Clear();
        for (int i=0; i<Form1->Pojazd->CharSize(); i++){
               Form3->ListBox1->Items->Add(Form1->Pojazd->ShowChar(i,0));}
        RysujWykres();
         Form1->Edit13->Text = CurrToStr(Form1->Pojazd->Vmax());
}
//---------------------------------------------------------------------------



void __fastcall TForm3::Button4Click(TObject *Sender)
{
        try{
                if(SaveDialog1->Execute()){
                TStringList *wynik =  new TStringList;
                wynik = Form1 -> Pojazd -> SaveToFile();
                wynik -> SaveToFile(SaveDialog1->FileName);
                }
        }
        catch (...){

        }
}
//---------------------------------------------------------------------------




