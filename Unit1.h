//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include "CGAUGES.h"
#include "CGRID.h"
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <vector>
#include <map>
#include <iterator>
#include <set>
#include "Funkcje.h"
#include "Funkcje.cpp"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit7.h"
#include "Unit8.h"
#include "Unit9.h"
//---------------------------------------------------------------------------


class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TOpenDialog *OpenDialog1;
        TShape *Shape2;
        TLabel *Label33;
        TMainMenu *MainMenu1;
        TMenuItem *L1;
        TMenuItem *ZaladujLinie1;
        TMenuItem *EdytujLinie1;
        TMenuItem *W1;
        TMenuItem *NowaLinia1;
        TMenuItem *Pojazd1;
        TMenuItem *ZaladujPojazd1;
        TMenuItem *E1;
        TOpenDialog *OpenDialog2;
        TLabel *Label1;
        TMenuItem *Nowy1;
        TGroupBox *GroupBox1;
        TComboBox *ComboBox1;
        TLabel *Label2;
        TEdit *Edit2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TEdit *Edit4;
        TEdit *Edit3;
        TLabel *Label6;
        TEdit *Edit5;
        TLabel *Label14;
        TLabel *Label15;
        TEdit *Edit6;
        TEdit *Edit7;
        TLabel *Label7;
        TEdit *Edit8;
        TLabel *Label8;
        TEdit *Edit9;
        TLabel *Label9;
        TEdit *Edit10;
        TLabel *Label10;
        TEdit *Edit11;
        TLabel *Label11;
        TEdit *Edit12;
        TLabel *Label12;
        TEdit *Edit13;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TMenuItem *PL1;
        TMenuItem *Oprogramie1;
        TMenuItem *Oprogramie2;
        TMenuItem *Pomoc1;
        TMenuItem *Zakocz1;
        void __fastcall ZaladujLinie1Click(TObject *Sender);
        void __fastcall EdytujLinie1Click(TObject *Sender);
        void __fastcall W1Click(TObject *Sender);
        void __fastcall NowaLinia1Click(TObject *Sender);
        void __fastcall ZaladujPojazd1Click(TObject *Sender);
        void __fastcall E1Click(TObject *Sender);
        void __fastcall Nowy1Click(TObject *Sender);
        void __fastcall GroupBox1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Edit13Change(TObject *Sender);
        void __fastcall Edit7Change(TObject *Sender);
        void __fastcall Edit4Change(TObject *Sender);
        void __fastcall Edit8Change(TObject *Sender);
        void __fastcall Edit11Change(TObject *Sender);
        void __fastcall Zakocz1Click(TObject *Sender);
        void __fastcall Oprogramie2Click(TObject *Sender);
        void __fastcall Zaadujodcinek1Click(TObject *Sender);
        void __fastcall Zaadujpojazd1Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
 Route *Linia;
 Vehicle *Pojazd;
 Train *Pociag;
 Brake *Hamulec;
 TStringList *hamulce;
 int locomotives;
 std::map<int,int> jazda;
  std::map<int,int> profilstatyczny;
  TimeTable *Rozklad;
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
