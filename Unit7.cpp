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


void TForm7::ShowData(int i){
        ListBox1->ItemIndex=i;
        ListBox2->ItemIndex=i;
        ListBox3->ItemIndex=i;
        ListBox4->ItemIndex=i;
        ComboBox3->ItemIndex=i;
        Edit7->Text=Form1->Rozklad->ShowNamePoint(i);
        if(!i){
                Edit3->Enabled=0;
                Edit4->Enabled=0;
                Edit3->Text="-";
                Edit4->Text="-";
              }
        else {
                Edit3->Enabled=1;
                Edit4->Enabled=1;
                Edit3->Text=Form1->Rozklad->ShowTime1(i);
                Edit4->Text=Form1->Rozklad->ShowTime2(i);
               }

        if(Form1->Rozklad->ShowStop(i)!="-"){

                Edit5->Enabled=1;
                Edit6->Enabled=1;
                Edit5->Text=Form1->Rozklad->ShowStop1(i);
                Edit6->Text=Form1->Rozklad->ShowStop2(i);
                }
          else   {
                Edit5->Enabled=0;
                Edit6->Enabled=0;
                Edit5->Text="-";
                 Edit6->Text="-";

                }
}

void TForm7::ShowTimeTable(TimeTable* t, TimeTable* pt){
  Form7->ListBox1->Clear();
  Form7->ListBox2->Clear();
  Form7->ListBox3->Clear();
  Form7->ListBox4->Clear();
  Form7->ComboBox1->Clear();
  Form7->ComboBox3->Clear();
  int reserve=0;
  for(int i=0;i<t->CountSection();i++){
        Form7->ListBox2->Items->Add(t->ShowEnd(i));
        Form7->ListBox3->Items->Add(t->ShowTime(i) + "("+pt->ShowTime(i)+")");
        Form7->ListBox1->Items->Add(t->ShowStop(i) + "("+pt->ShowStop(i)+")");
        Form7->ListBox4->Items->Add(t->ShowSchedule(i));
        Form7->ComboBox1->Items->Add(t->ShowEnd(i));
        Form7->ComboBox3->Items->Add(t->ShowEnd(i));
        reserve = reserve + t->ReserveTime(i,pt);
        }
        int mreserve = reserve/60;
        reserve = reserve - mreserve*60;
  Label16->Caption = "Suma rezerw:" + ((mreserve<10)? "0"+CurrToStr(mreserve):CurrToStr(mreserve)) + ":" + ((reserve<10)? "0"+CurrToStr(reserve):CurrToStr(reserve));
}
void TForm7::CreateTemplate(TimeTable *templ){
        pt = new TimeTable(*templ);
       // PrimaryTimeTable = &pt;
}

void __fastcall TForm7::Button3Click(TObject *Sender)
{
      bool deparr;
      if(ComboBox2->ItemIndex==0){deparr=1;}
      else {deparr=0;}
        Form1->Rozklad->ChangeStartTime(atof(Edit1->Text.c_str())*3600 + atof(Edit2->Text.c_str())*60,ComboBox1->ItemIndex,deparr);;
        ShowTimeTable(Form1->Rozklad,pt);
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
 ShowData(ListBox1->ItemIndex);
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
        ShowData(ListBox2->ItemIndex);
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

void __fastcall TForm7::ListBox4Click(TObject*Sender)
{
ShowData(ListBox4->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TForm7::ListBox3Click(TObject *Sender)
{
ShowData(ListBox3->ItemIndex);


}
//---------------------------------------------------------------------------

void __fastcall TForm7::ComboBox3Change(TObject *Sender)
{

ShowData(ComboBox3->ItemIndex);

}
//---------------------------------------------------------------------------







void __fastcall TForm7::Button4Click(TObject *Sender)
{
int nr_section =  ComboBox3->ItemIndex;
int a = Form1->Rozklad->ChangeSection(pt,nr_section,Edit7->Text,atoi(Edit3->Text.c_str())*60+atoi(Edit4->Text.c_str()),atoi(Edit5->Text.c_str())*60+atoi(Edit6->Text.c_str()));
// ShowMessage(pt->ShowTime(2));
 ShowTimeTable(Form1->Rozklad,pt);
  if(a){
        AnsiString aa =  "Oreslony czas przejazdu jest kr�tszy od surowego czasu jazdy: " + pt->ShowTime(nr_section);
        if(a==1){Application->MessageBoxA(aa.c_str(),"B��d", MB_ICONWARNING);}


  }

}
//---------------------------------------------------------------------------



void __fastcall TForm7::Button5Click(TObject *Sender)
{
Form1->Rozklad->RoundTimes();
ShowTimeTable(Form1->Rozklad,pt);
}
//---------------------------------------------------------------------------



void __fastcall TForm7::Button1Click(TObject *Sender)
{
         try{

                char myPath[_MAX_PATH+1];
                GetModuleFileName(NULL,myPath,_MAX_PATH);
                String path = AnsiString(myPath);
                path = path.SubString(0,path.Length()-7)+"\\Reports\\";
                SaveDialog1->InitialDir = path;
                if(SaveDialog1->Execute()){
                TStringList *wynik =  new TStringList;
                wynik = Form1 -> Rozklad -> FinalReport(pt);
                wynik -> SaveToFile(SaveDialog1->FileName);
                }
        }
        catch (...){

        }

}
//---------------------------------------------------------------------------

