//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>

//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TListBox *ListBox1;
        TLabel *Label1;
        TButton *Button2;
        TButton *Button3;
        TEdit *Edit1;
        TEdit *Edit2;
        TCheckBox *CheckBox1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TListBox *ListBox2;
        TLabel *Label6;
        TButton *Button4;
        TButton *Button5;
        TEdit *Edit3;
        TEdit *Edit4;
        TButton *Button6;
        TSaveDialog *SaveDialog1;
        TButton *Button7;
        TPopupMenu *PopupMenu1;
        TMenuItem *blabl1;
        TMenuItem *blele1;
        TPopupMenu *PopupMenu2;
        TMenuItem *Usupostj1;
        TMenuItem *Edytujpostj1;
        TMenuItem *Wstawpostj1;
        TMenuItem *Usupostjje1;
        TMenuItem *Dodajodcinek1;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall ListBox2Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall CheckBox1Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall ListBox1Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall blele1Click(TObject *Sender);
        void __fastcall blabl1Click(TObject *Sender);
        void __fastcall ListBox3Click(TObject *Sender);
        void __fastcall Wstawpostj1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Usupostj1Click(TObject *Sender);
        void __fastcall Usupostjje1Click(TObject *Sender);
        void __fastcall Dodajodcinek1Click(TObject *Sender);
        void __fastcall Edytujpostj1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
