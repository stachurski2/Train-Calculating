//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Unit3"
#pragma resource "*.dfm"
TForm4 *Form4;
double skala=1000;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void TForm4::RysujWykres(std::map<int,int> staticprofile,int starta,double skalab, int trainlength, int trainspeed)
{
double skala=skalab;
if(trainspeed<=200)
        {
                StartPoint=215;
                Shape25->Visible=0;
                Shape26->Visible=0;
                Shape27->Visible=0;
                Shape22->Height=200;
                Label13->Caption="200";
                Label12->Caption="160";
                Label11->Caption="120";
                Label28->Caption="80";
                Label27->Caption="40";
                Label26->Caption="0";
                Label25->Visible=0;
                Label24->Visible=0;
                Label22->Visible=0;
                Label3->Top=StartPoint+38;
                Button1->Top=StartPoint+61;
                Button2->Top=StartPoint+61;
                Edit2->Top=StartPoint+36;
                Label4->Top=StartPoint+38;
                Label1->Top=StartPoint+38;
                Edit1->Top=StartPoint+55;
                Label2->Top=StartPoint+55;
                                Label5->Top=StartPoint+38;
                Label7->Top=StartPoint+38;
                Label9->Top=StartPoint+38;
                Label6->Top=StartPoint+55;
                Label8->Top=StartPoint+55;
                Label10->Top=StartPoint+55;
                 Form4->Height=330;

        }
        else
        {
                StartPoint=335;
                Label13->Caption="320";
                Label12->Caption="280";
                Label11->Caption="240";
                Label28->Caption="200";
                Label27->Caption="160";
                Label26->Caption="120";
                Shape25->Visible=1;
                Shape26->Visible=1;
                Shape27->Visible=1;
                Shape22->Height=320;
                Label26->Visible=1;
                Label25->Visible=1;
                Label24->Visible=1;
                Label22->Visible=1;
                Label3->Top=StartPoint+38;
                Button1->Top=StartPoint+61;
                Button2->Top=StartPoint+61;
                Edit2->Top=StartPoint+36;
                Label4->Top=StartPoint+38;
                Label1->Top=StartPoint+38;
                Edit1->Top=StartPoint+55;
                Label2->Top=StartPoint+55;
                                Label5->Top=StartPoint+38;
                Label7->Top=StartPoint+38;
                Label9->Top=StartPoint+38;
                Label6->Top=StartPoint+55;
                Label8->Top=StartPoint+55;
                Label10->Top=StartPoint+55;
                  Form4->Height=450;

        }


     skalab=1000/skalab;
Form4->Refresh();
Form4->Canvas->Pen->Color = clRed;
Form4->Canvas->Pen->Width = 3;
/*
   for(double i=starta;i<Form1->Linia->ShowLength();i++){
        if(i==0){
                Form4->Canvas->MoveTo(30+(i-starta)*skalab,StartPoint-staticprofile[i]);
                }
                else
                {
                Form4->Canvas->MoveTo(30+(i-starta)*skalab,StartPoint-staticprofile[i-1]);
                }
        Form4->Canvas->LineTo(30+(i-starta)*skalab,StartPoint-Form1->Linia->Vmax(i,trainlength,trainspeed));
        }
        */

        int PointOfTrain1 = starta ;
        int PointOfTrain2 = starta;
        Form4->Canvas->MoveTo(30,335-staticprofile[PointOfTrain2]);
        Form4->Canvas->LineTo(30,335-staticprofile[PointOfTrain2]);
        std::map<int,int>::iterator iterator = staticprofile.end();
        std::advance(iterator,-1);
        int koniec = iterator->first;
        for(int i=1;i<1299;i++){
                PointOfTrain1 = start + (i-1)*skalab;
                PointOfTrain2 = start + i*skalab;
                if(PointOfTrain1>koniec){
                        break;
                        }
                        Form4->Canvas->MoveTo(30+i,StartPoint-staticprofile[PointOfTrain1]);
                        Form4->Canvas->LineTo(30+i,StartPoint-staticprofile[PointOfTrain2]);
                        int TemporarySpeed=staticprofile[PointOfTrain1];
                        int TemporaryDistance=PointOfTrain1;
                        while(PointOfTrain1<PointOfTrain2){
                           if(TemporarySpeed!=staticprofile[PointOfTrain1]){
                           Form4->Canvas->MoveTo(30+i,StartPoint-staticprofile[TemporaryDistance]);
                           Form4->Canvas->LineTo(30+i,StartPoint-staticprofile[PointOfTrain1]);
                           TemporarySpeed=staticprofile[PointOfTrain1];
                           TemporaryDistance=PointOfTrain1;
                           }
                         PointOfTrain1++;

                        }

                if(PointOfTrain1>staticprofile.size() &&  PointOfTrain2>staticprofile.size()){
                        break;
                }



        }   


        Form4->Canvas->Pen->Color = clBlack;
        Form4->Canvas->Pen->Width = 2;

        for(double i=starta;i<=Form1->Linia->ShowLength();i++){
        String example = Form1->Linia->Show(i);
        if(example!="null"){
        Form4->Canvas->MoveTo(30+(i-starta)*skala/1000,StartPoint);
        Form4->Canvas->LineTo(30+(i-starta)*skala/1000,61);
        Form4->Canvas->TextOut(30+(i-starta)*skala/1000,46,example);
        }
        }
        Form4->Canvas->Pen->Color = clBlack;
        Form4->Canvas->Pen->Width = 1;
        int kreska=0;
        double podzialka=0;
        // 100000/100000 = 1
        // 100000/10000 = 10
        // 100000/1000 = 100
        // 100000/100 = 1000
        // 100000/10 = 10000
        // 100000/1 = 100000
        skala= 100000/skala;
        while(kreska<1319){

        podzialka=starta+kreska*skalab;
        int kreska2=kreska;
        while(kreska2<kreska+1){
                int x=podzialka/skala;
        double x1=x*skala;
        if(x1==podzialka){
                Form4->Canvas->MoveTo(30+kreska,StartPoint+10);
                Form4->Canvas->LineTo(30+kreska,StartPoint-10);
                if(skalab<=1){
                        Form4->Canvas->TextOut(30+kreska,StartPoint+11,CurrToStr(podzialka)+"m");
                    }
                else {
                         Form4->Canvas->TextOut(30+kreska,StartPoint+11,CurrToStr(podzialka/1000)+"km");

                      }
                }
        podzialka++;
        kreska2= (podzialka-starta)/skalab;
        }

          kreska++;
        }
            // Form4->Canvas->MoveTo(i,StartPoint+10);
                //Form4->Canvas->LineTo(i,StartPoint-10);
                /*
                if(skalab<=1){
                        Form4->Canvas->TextOut(i-12,StartPoint+11,CurrToStr(((((i-30)*skalab))+starta))+"m");
                    }
                else {
                         Form4->Canvas->TextOut(i-12,StartPoint+11,CurrToStr((((i-30)*skalab)/1000+starta/1000))+"km");

                      }



        }
   */
   }


void TForm4::RysujWykres2(std::map<int,int> TrainRide,double skalab,int trainspeed, int start )
{

if(trainspeed<=200)
        {
                StartPoint=215;
                Shape25->Visible=0;
                Shape26->Visible=0;
                Shape27->Visible=0;
                Shape22->Height=200;
                Label13->Caption="200";
                Label12->Caption="160";
                Label11->Caption="120";
                Label28->Caption="80";
                Label27->Caption="40";
                Label26->Caption="0";
                Label25->Visible=0;
                Label24->Visible=0;
                Label22->Visible=0;
                Label3->Top=StartPoint+38;
                Button1->Top=StartPoint+61;
                Button2->Top=StartPoint+61;
                Edit2->Top=StartPoint+36;
                Label4->Top=StartPoint+38;
                Label1->Top=StartPoint+38;
                Edit1->Top=StartPoint+55;
                Label2->Top=StartPoint+55;
                Label5->Top=StartPoint+38;
                Label7->Top=StartPoint+38;
                Label9->Top=StartPoint+38;
                Label6->Top=StartPoint+55;
                Label8->Top=StartPoint+55;
                Label10->Top=StartPoint+55;
                Form4->Height=330;
        }
        else
        {
                StartPoint=335;
                Label13->Caption="320";
                Label12->Caption="280";
                Label11->Caption="240";
                Label28->Caption="200";
                Label27->Caption="160";
                Label26->Caption="120";
                Shape25->Visible=1;
                Shape26->Visible=1;
                Shape27->Visible=1;
                Shape22->Height=320;
                Label26->Visible=1;
                Label25->Visible=1;
                Label24->Visible=1;
                Label22->Visible=1;
                Label3->Top=StartPoint+38;
                Button1->Top=StartPoint+61;
                Button2->Top=StartPoint+61;
                Edit2->Top=StartPoint+36;
                Label4->Top=StartPoint+38;
                Label1->Top=StartPoint+38;
                Edit1->Top=StartPoint+55;
                Label2->Top=StartPoint+55;
                Label5->Top=StartPoint+38;
                Label7->Top=StartPoint+38;
                Label9->Top=StartPoint+38;
                Label6->Top=StartPoint+55;
                Label8->Top=StartPoint+55;
                Label10->Top=StartPoint+55;
                Form4->Height=450;
        }


        skalab=1000/skalab;

        int PointOfTrain1 = start ;
        int PointOfTrain2 = start;
        Form4->Canvas->Pen->Color = clBlue;
        Form4->Canvas->Pen->Width = 3;
        Form4->Canvas->MoveTo(30,335-TrainRide[PointOfTrain2]);
        Form4->Canvas->LineTo(30,335-TrainRide[PointOfTrain2]);
        for(int i=1;i<1299;i++){
                PointOfTrain1 = start + (i-1)*skalab;
                PointOfTrain2 = start + i*skalab;
                Form4->Canvas->MoveTo(30+i,StartPoint-TrainRide[PointOfTrain1]);
                Form4->Canvas->LineTo(30+i,StartPoint-TrainRide[PointOfTrain2]);
                if(PointOfTrain1>TrainRide.size() &&  PointOfTrain2>TrainRide.size()){
                        break;
                }



        }
}

void __fastcall TForm4::Button1Click(TObject *Sender)
{
start=start+atof(Form4->Edit2->Text.c_str());
skala = atof(Form4->Edit1->Text.c_str());
        RysujWykres(Form1->profilstatyczny,start,skala,TrainLength,TrainMaxSpeed);
        Form4->Label5->Caption = "Po�o�enie czo�a poci�gu: "+ CurrToStr(start);
        Form4->Label6->Caption = "Maksymalna pr�dkosc: "+ CurrToStr(Form1->Linia->Vmax(start,TrainLength,TrainMaxSpeed));
        Form4->Label7->Caption = "Nastepna predkosc (obnizenie): "+ CurrToStr(Form1->Linia->NextSpeed(start,TrainLength,TrainMaxSpeed));
        Form4->Label8->Caption = "Dystans do obnizenia predkosci: "+ CurrToStr(Form1->Linia->DistanceToSpeedChange(start,TrainLength,TrainMaxSpeed));
         Form4->Label9->Caption = "Droga hamowania: "+ CurrToStr(Form1->Hamulec->DistanceOfBraking(Form1->Linia->Vmax(start,TrainLength,TrainMaxSpeed),Form1->Linia->NextSpeed(start,TrainLength,TrainMaxSpeed),atoi(Form1->Edit7->Text.c_str())));
if(Wykres2==1){
     RysujWykres2(Form1->jazda,atoi(Form4->Edit1->Text.c_str()),Form1->Pociag->TrainMaxSpeed(),Form4->start);
}
           //Form4->Label10->Caption = "Najblizszy pkt hamowania: "+CurrToStr(Form1->Hamulec->BrakeLaunch(start,Form1->Linia,Form1->Pociag));
        // Form4->Label10->Caption = "Najblizszy pkt hamowania: "+CurrToStr(Form1->Hamulec->BrakeLaunch(Form1->Linia,start,Form1->Pociag->TrainLength(),atoi(Form1->Edit13->Text.c_str()),atoi(Form1->Edit7->Text.c_str())));

}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button2Click(TObject *Sender)
{
        if(start>0){
                start=start-atof(Form4->Edit2->Text.c_str());
        }
        skala = atof(Form4->Edit1->Text.c_str());
           RysujWykres(Form1->profilstatyczny,start,skala,TrainLength,TrainMaxSpeed);
        Form4->Label5->Caption = "Po�o�enie czo�a poci�gu: "+ CurrToStr(start);
        Form4->Label6->Caption = "Maksymalna pr�dkosc: "+ CurrToStr(Form1->Linia->Vmax(start,TrainLength,TrainMaxSpeed));
        Form4->Label7->Caption = "Nastepna predkosc (obnizenie): "+ CurrToStr(Form1->Linia->NextSpeed(start,TrainLength,TrainMaxSpeed));
        Form4->Label8->Caption = "Dystans do obnizenia predkosci: "+ CurrToStr(Form1->Linia->DistanceToSpeedChange(start,TrainLength,TrainMaxSpeed));
        Form4->Label9->Caption = "Droga hamowania: "+ CurrToStr(Form1->Hamulec->DistanceOfBraking(Form1->Linia->Vmax(start,TrainLength,TrainMaxSpeed),Form1->Linia->NextSpeed(start,TrainLength,TrainMaxSpeed),atoi(Form1->Edit7->Text.c_str())));
                //Form4->Label10->Caption = "Najblizszy pkt hamowania: "+CurrToStr(Form1->Hamulec->BrakeLaunch(start,Form1->Linia,Form1->Pociag));
               // Form4->Label10->Caption = "Najblizszy pkt hamowania: "+CurrToStr(Form1->Hamulec->BrakeLaunch(Form1->Linia,start,Form1->Pociag->TrainLength(),atoi(Form1->Edit13->Text.c_str()),atoi(Form1->Edit7->Text.c_str())));

        if(Wykres2==1){
        RysujWykres2(Form1->jazda,atoi(Form4->Edit1->Text.c_str()),Form1->Pociag->TrainMaxSpeed(),Form4->start);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Edit1Change(TObject *Sender)
{
     skala = atof(Form4->Edit1->Text.c_str());
           RysujWykres(Form1->profilstatyczny,start,skala,TrainLength,TrainMaxSpeed);
           Form4->Label5->Caption = "Po�o�enie czo�a poci�gu: "+ CurrToStr(start);
     Form4->Label6->Caption = "Maksymalna pr�dkosc: "+ CurrToStr(Form1->Linia->Vmax(start,TrainLength,TrainMaxSpeed));
     Form4->Label7->Caption = "Nastepna predkosc (obnizenie): "+ CurrToStr(Form1->Linia->NextSpeed(start,TrainLength,TrainMaxSpeed));
     Form4->Label8->Caption = "Dystans do obnizenia predkosci: "+ CurrToStr(Form1->Linia->DistanceToSpeedChange(start,TrainLength,TrainMaxSpeed));
      Form4->Label9->Caption = "Droga hamowania: "+ CurrToStr(Form1->Hamulec->DistanceOfBraking(Form1->Linia->Vmax(start,TrainLength,TrainMaxSpeed),Form1->Linia->NextSpeed(start,TrainLength,TrainMaxSpeed),atoi(Form1->Edit7->Text.c_str())));
        // Form4->Label10->Caption = "Najblizszy pkt hamowania: "+CurrToStr(Form1->Hamulec->BrakeLaunch(start,Form1->Linia,Form1->Pociag));
      //Form4->Label10->Caption = "Najblizszy pkt hamowania: "+CurrToStr(Form1->Hamulec->BrakeLaunch(Form1->Linia,start,Form1->Pociag->TrainLength(),atoi(Form1->Edit13->Text.c_str()),atoi(Form1->Edit7->Text.c_str())));
      if(Wykres2==1){
        RysujWykres2(Form1->jazda,atoi(Form4->Edit1->Text.c_str()),Form1->Pociag->TrainMaxSpeed(),Form4->start);
        }

}
//---------------------------------------------------------------------------







void __fastcall TForm4::FormCreate(TObject *Sender)
{
start=0;
}
//---------------------------------------------------------------------------








