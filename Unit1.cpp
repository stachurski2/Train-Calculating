//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CGAUGES"
#pragma link "CGRID"
#pragma link "Unit3"
#pragma resource "*.dfm"
int a;
TForm1 *Form1;
TStringList *dane = new TStringList;
TStringList *dane2= new TStringList;
TStringList *loco= new TStringList;

bool RouteOpen=0;
bool VehicleOpen=0;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{


}

void __fastcall TForm1::ZaladujLinie1Click(TObject *Sender)
{

        try
        {       char myPath[_MAX_PATH+1];
                GetModuleFileName(NULL,myPath,_MAX_PATH);
                String path = AnsiString(myPath);
                 path = path.SubString(0,path.Length()-7)+"\\Routes\\";
                OpenDialog1->InitialDir = path;
                if(OpenDialog1->Execute())
                {
                        OpenDialog1->Title = "�adowanie linii kolejowej";
                        dane  -> LoadFromFile(OpenDialog1->FileName);
                        if(RouteOpen==0)
                        {
                                Linia = new Route(dane);
                                RouteOpen=1;
                         }
                        else
                        {
                                Linia -> ~Route();
                                Linia = new Route(dane);
                        }
                        Form4->Caption=OpenDialog1->FileName;
                        if(Linia->ShowLength()==0){throw 20;}
                        Label33->Caption="Zaladowano linie o dlugosci "+CurrToStr(Linia->ShowLength())+" m.";
                        Form1->EdytujLinie1->Enabled="TRUE";
                        Form1->W1->Enabled="TRUE";
                        Form4->Wykres2=0;
                        profilstatyczny.erase(profilstatyczny.begin(),profilstatyczny.end());
                        jazda.erase(jazda.begin(),jazda.end());
                }
        }
        catch(...)
        {
                Application->MessageBoxA("Nie udalo sie otworzyc pliku","B��d",MB_ICONWARNING);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EdytujLinie1Click(TObject *Sender)
{
if(Form2->Visible==0)
{
         Form2->ListBox1->Clear();
        for(int i=0; i<Linia->Size(); i++){
                AnsiString s=Linia->ShowSection(i);
                Form2->ListBox1->Items->Add(s);}
        Form2->ListBox2->Clear();
        for(int i=0; i<Linia->DescriptionCount(); i++){
                AnsiString s=Linia->ShowDescribe(i);
                Form2->ListBox2->Items->Add(s);}
        if(Linia->DescriptionCount()==0){Form2->ListBox2->Items->Add("      ");}
        Form2->Visible="TRUE";
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::W1Click(TObject *Sender)
{
        Form4->RouteLength=Linia->ShowLength();
        Form4->Visible="TRUE";
        Form4->SetWindowSize(Linia->TheHighestSpeed());
        profilstatyczny=staticprofile(Linia,NULL);
        Form4->SetScale(Linia->ShowLength());
        Form4->RysujWykres(profilstatyczny,Form4->start,Form4->skala,0,Linia->TheHighestSpeed());


}

//---------------------------------------------------------------------------



void __fastcall TForm1::NowaLinia1Click(TObject *Sender)
{
        if(RouteOpen==0)
        {
                Linia = new Route(dane,1);
                RouteOpen=1;
        }
        else
        {
                Linia -> ~Route();
                Linia = new Route(dane,1);
        }
        Form1->EdytujLinie1->Enabled="TRUE";
        Form1->W1->Enabled="TRUE";
}
//---------------------------------------------------------------------------





void __fastcall TForm1::ZaladujPojazd1Click(TObject *Sender)
{
try
{
         char myPath[_MAX_PATH+1];
         GetModuleFileName(NULL,myPath,_MAX_PATH);
         String path = AnsiString(myPath);
         path = path.SubString(0,path.Length()-7)+"\\Vehicles\\";
         OpenDialog2->InitialDir = path;
        if(OpenDialog2->Execute())
        {
                if(VehicleOpen==1){
                Pojazd -> ~Vehicle();
                }
                else {VehicleOpen=1;}
                dane2  -> LoadFromFile(OpenDialog2->FileName);
                Pojazd = new Vehicle(dane2);
                Form1-> E1 -> Enabled = "TRUE";
                Form1->Label1->Caption = "Za�adowano pojazd z pliku: "+OpenDialog2->FileName;
                VehicleOpen=1;
                Edit2->Text = Pojazd ->ShowName();
                Edit3->Text = Pojazd ->ShowLength();
                Edit6->Text = Pojazd ->ShowWeight();
                Edit10->Text = Pojazd ->ShowWheels();
                Edit13->Text = CurrToStr(Pojazd -> Vmax());
                Edit7->Text = "100";
                GroupBox1->Enabled="TRUE";
                StatusBar1->Panels->Items[0]->Text="Karta poci�gu odblokowana";
                Form4->Wykres2=0;
        }
}
catch(...)
{
        ShowMessage("Nie udalo sie otworzyc pliku");
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::E1Click(TObject *Sender)
{
        Form3->Show();
        Form3->Edit1->Text = Pojazd->ShowName();
        Form3->Edit2->Text = Pojazd->ShowWheels();
        Form3->Edit3->Text = Pojazd->ShowWeight();
        Form3->Edit4->Text = Pojazd->ShowLength();
        for (int i=0; i<Pojazd->CharSize(); i++){ Form3->ListBox1->Items->Add(Pojazd->ShowChar(i,0));}
        Form3->RysujWykres();
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Nowy1Click(TObject *Sender)
{

        GroupBox1->Enabled="TRUE";
        StatusBar1->Panels->Items[0]->Text="Karta poci�gu odblokowana";
        if(VehicleOpen==1){
                int msgboxID = Application->MessageBox("Czy chcesz utworzyc nowy pojazd trakcyjny?","UWAGA!",MB_YESNO | MB_ICONWARNING);
                if(msgboxID == IDYES){
                        Pojazd -> ~Vehicle();
                        TStringList *empty = new TStringList;
                        Pojazd = new Vehicle(empty);
                        Form1-> E1 -> Enabled = "TRUE";
                        Form3-> Visible = "TRUE";
                        Form3-> RysujWykres();
                        Form1-> Label1 -> Caption ="Utworzono nowy pojazd trakcyjny";
           }
        }
        else {
                VehicleOpen=1;
                TStringList *empty = new TStringList;
                Pojazd = new Vehicle(empty);
                Form1-> E1 -> Enabled = "TRUE";
                Form3-> Visible = "TRUE";
                Form3-> RysujWykres();
                Form1-> Label1 -> Caption ="Utworzono nowy pojazd trakcyjny";
        }
}
//---------------------------------------------------------------------------



void __fastcall TForm1::GroupBox1Click(TObject *Sender)
{
Edit2->Text = Pojazd -> ShowName();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        locomotives=1;
        ComboBox1->Items->Add("1");
        ComboBox1->Items->Add("2");
        ComboBox1->Items->Add("3");
        hamulce = new TStringList;
        StatusBar1->Panels->Add();
        StatusBar1->Panels->Items[0]->Text="Karta poci�gu zablokowana";
        StatusBar1->Panels->Items[0]->Alignment=2;
        try {
                  hamulce->LoadFromFile("hamowanie.dat");
                  Hamulec = new Brake(hamulce);
            }
        catch(...){
                Application->MessageBox("Brak pliku z krzywymi hamowania","B��D",MB_ICONERROR);
                Application->Terminate();
        }


}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button2Click(TObject *Sender)
{
        if(Pojazd->ReadyToGo()==1){
                try{
                        Pociag = new Train(Pojazd,locomotives,atoi(Edit11->Text.c_str()),atof(Edit8->Text.c_str()),atoi(Edit4->Text.c_str()),atoi(Edit7->Text.c_str()),atoi(Edit13->Text.c_str()));
                        Edit5->Text=CurrToStr(Pociag->TrainLength());
                        Edit9->Text=CurrToStr(Pociag->TrainWeight());
                        Edit12->Text=CurrToStr(Pociag->LWheels() + Pociag->CWheels() );

                        if(atoi(Edit7->Text.c_str())<30){ Application->MessageBoxA("Minimalny % masy hamuj�cej wynosi 30%","Masa hamuj�ca",MB_ICONWARNING);}
                        else if(atoi(Edit13->Text.c_str())>Pojazd->Vmax()){ Application->MessageBoxA(("Maksymalna pr�dkosc pociagu wynosi "+CurrToStr(Pojazd->Vmax())+" km/h. \n Wpisz nizsza wartosc").c_str(),"Pr�dkosc",MB_ICONWARNING);}
                        else {
                        jazda = trainride(Pociag,Linia,Hamulec);
                        Form4->SetWindowSize(atoi(Form1->Edit13->Text.c_str()));
                        Form4->Label5->Caption = "Pocz�tek wykresu: 0";
                        Form4->Label6->Caption = "Maksymalna pr�dkosc: "+ CurrToStr(Form1->Linia->Vmax(0,Pociag->TrainLength(),atoi(Form1->Edit13->Text.c_str())));
                        Form4->Show();
                        Form4->Refresh();
                        Form4->Wykres2=1;
                        Form4->SetScale(Linia->ShowLength());
                        Form4->start=0;
                        Form4->RysujWykres(profilstatyczny,Form4->start,Form4->skala,Pociag->TrainLength(),atoi(Form1->Edit13->Text.c_str()));
                        Form4->RysujWykres2(jazda,Form4->skala,Pociag->TrainMaxSpeed(),Form4->start);
                        Form4->TrainMaxSpeed=atoi(Form1->Edit13->Text.c_str());
                        Form4->RouteLength=Linia->ShowLength();
                        }
                }
                catch(...)
                {
                        Application->MessageBoxA("Nieprawid�owe dane wejsciowe","B��d procedury",MB_ICONERROR);
                }
        }
        else { Application->MessageBoxA("Niekompletne dane pojazdu trakcynego","Pojazd trakcyjny",MB_ICONWARNING);}





}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
locomotives=atoi(ComboBox1->Text.c_str());
Form4->Wykres2=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{

        Pociag = new Train(Pojazd,locomotives,atoi(Edit11->Text.c_str()),atof(Edit8->Text.c_str()),atoi(Edit4->Text.c_str()),atoi(Edit7->Text.c_str()),atoi(Edit13->Text.c_str()));
        Edit5->Text=CurrToStr(Pociag->TrainLength());
        Edit9->Text=CurrToStr(Pociag->TrainWeight());
        Edit12->Text=CurrToStr(Pociag->LWheels() + Pociag->CWheels() );

        if(atoi(Edit7->Text.c_str())<30){
        Application->MessageBoxA("Minimalny % masy hamuj�cej wynosi 30%","Masa hamuj�ca",MB_ICONWARNING);

        }
        else if(atoi(Edit13->Text.c_str())>Pojazd->Vmax()){
          Application->MessageBoxA(("Maksymalna pr�dkosc pociagu wynosi "+CurrToStr(Pojazd->Vmax())+" km/h. \n Wpisz nizsza wartosc").c_str(),"Pr�dkosc",MB_ICONWARNING);

        }
       // Form4->Visible="TRUE";
          Form4->Show();
        Form4->RouteLength=Linia->ShowLength();
        Form4->TrainLength=Pociag->TrainLength();
        Form4->SetWindowSize(atoi(Form1->Edit13->Text.c_str()));
        profilstatyczny=staticprofile(Linia,Pociag);
        Form4->SetScale(Linia->ShowLength());
        Form4->RysujWykres(profilstatyczny,Form4->start,Form4->skala,Pociag->TrainLength(),atoi(Form1->Edit13->Text.c_str()));
        Form4->Label5->Caption = "Pocz�tek wykresu: 0";
        Form4->Label6->Caption = "Maksymalna pr�dkosc: "+ CurrToStr(Form1->Linia->Vmax(0,Pociag->TrainLength(),atoi(Form1->Edit13->Text.c_str())));
       // Form4->Label7->Caption = "Nastepna predkosc (obnizenie): "+ CurrToStr(Form1->Linia->NextSpeed(0,Pociag->TrainLength(),atoi(Form1->Edit13->Text.c_str())));
       // Form4->Label8->Caption = "Dystans do obnizenia predkosci: "+ CurrToStr(Form1->Linia->DistanceToSpeedChange(0,Pociag->TrainLength(),atoi(Form1->Edit13->Text.c_str())));
       // Form4->Label9->Caption = "Droga hamowania: "+ CurrToStr(Form1->Hamulec->DistanceOfBraking(Form1->Linia->Vmax(0,Pociag->TrainLength(),atoi(Form1->Edit13->Text.c_str())),Form1->Linia->NextSpeed(0,Pociag->TrainLength(),atoi(Form1->Edit13->Text.c_str())),atoi(Edit7->Text.c_str())));
       // Form4->Label10->Caption = "Najblizszy pkt hamowania: "+CurrToStr(Form1->Hamulec->BrakeLaunch(0,Form1->Linia,Form1->Pociag));
        }
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit13Change(TObject *Sender)
{
        Form4->Wykres2=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit7Change(TObject *Sender)
{
Form4->Wykres2=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit4Change(TObject *Sender)
{
Form4->Wykres2=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit8Change(TObject *Sender)
{
Form4->Wykres2=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit11Change(TObject *Sender)
{
Form4->Wykres2=0;
}
//---------------------------------------------------------------------------





void __fastcall TForm1::Zakocz1Click(TObject *Sender)
{
        int ID = Application->MessageBoxA("Czy chcesz zako�czyc program?","Koniec",MB_YESNO | MB_ICONQUESTION);
        if(ID==IDYES){
                Application->Terminate();
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Oprogramie2Click(TObject *Sender)
{
Form5->Visible="TRUE";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Zaadujodcinek1Click(TObject *Sender)
{
ZaladujLinie1Click(Sender);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Zaadujpojazd1Click(TObject *Sender)
{
ZaladujPojazd1Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{

        if(Form4->Wykres2==1){
         
                //std::map<int,int> TimeTable = GetTimetable(jazda);
                 Rozklad = new TimeTable(jazda,Linia,*Pociag);


                Form7->Show();
                Form7->CreateTemplate(Rozklad);
                Form7->ShowTimeTable(Rozklad,Form7->pt);
                    Form7->ComboBox2->Items->Add("Przyjazd");
                       Form7->ComboBox2->Items->Add("Odjazd");
                       Form7->ComboBox2->Enabled=0;

                Form7->ComboBox1->ItemIndex=0;
                Form7->ComboBox2->ItemIndex=1;

               // ShowMessage("Rozmiar = "+CurrToStr(Rozklad.CountSection()));


        }
        else {
                Application->MessageBoxA("Brak profilu dynamicznego","B��d",MB_ICONERROR);
        }
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


