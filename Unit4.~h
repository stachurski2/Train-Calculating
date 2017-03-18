//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
        TShape *Shape22;
        TShape *Shape24;
        TLabel *Label22;
        TLabel *Label24;
        TShape *Shape25;
        TShape *Shape26;
        TLabel *Label25;
        TShape *Shape27;
        TShape *Shape28;
        TLabel *Label26;
        TShape *Shape29;
        TLabel *Label27;
        TLabel *Label28;
        TShape *Shape1;
        TLabel *Label1;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TShape *Shape2;
        TLabel *Label11;
        TShape *Shape3;
        TLabel *Label12;
        TShape *Shape4;
        TShape *Shape5;
        TLabel *Label13;
        TButton *Button3;
        TButton *Button4;
        TScrollBar *ScrollBar1;
        //void __fastcall Button1Click(TObject *Sender);
        //void __fastcall Button2Click(TObject *Sender);
        //void __fastcall Edit1Change(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall ScrollBar1Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm4(TComponent* Owner);
        int TrainLength;
        int TrainMaxSpeed;
        int start;
        int StartPoint;
        int RouteLength;
        void RysujWykres(std::map<int,int>,int=0,double=1000,int=0,int=0); //profil statyczny
        void RysujWykres2(std::map<int,int>,double,int,int=0); //profil dynamiczny
        void SetWindowSize(int);
        void SetScale(int);
        void UpScale();
        void DownScale();
        void ShowSrollbar();
        double skala;
        bool Wykres2;

};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
