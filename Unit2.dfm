object Form2: TForm2
  Left = 597
  Top = 83
  BorderStyle = bsDialog
  Caption = 'Edycja linii'
  ClientHeight = 462
  ClientWidth = 575
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 64
    Top = 0
    Width = 144
    Height = 13
    Caption = 'Wykaz wczytanych predkosci:'
  end
  object Label5: TLabel
    Left = 344
    Top = 0
    Width = 152
    Height = 13
    Caption = 'Wykaz wczytanych  infopoint'#243'w'
  end
  object Button1: TButton
    Left = 177
    Top = 415
    Width = 113
    Height = 33
    Caption = 'Zamknij'
    TabOrder = 0
    OnClick = Button1Click
  end
  object ListBox1: TListBox
    Left = 8
    Top = 16
    Width = 273
    Height = 385
    Style = lbOwnerDrawVariable
    ItemHeight = 13
    ParentShowHint = False
    ShowHint = False
    TabOrder = 1
    OnClick = ListBox1Click
  end
  object ListBox2: TListBox
    Left = 296
    Top = 16
    Width = 273
    Height = 385
    ItemHeight = 13
    TabOrder = 2
    OnClick = ListBox2Click
  end
  object Button6: TButton
    Left = 305
    Top = 417
    Width = 113
    Height = 33
    Caption = 'Zapisz do pliku'
    TabOrder = 3
    OnClick = Button6Click
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = '.xml'
    FileName = 'F:\Kulej\Moje programy\OT\Linie\sdasd'
    Filter = '.xml|*.xml'
    Left = 456
    Top = 536
  end
  object PopupMenu1: TPopupMenu
    Left = 160
    Top = 232
    object blabl1: TMenuItem
      Caption = 'Usu'#324' odcinek'
      OnClick = blabl1Click
    end
    object blele1: TMenuItem
      Caption = 'Zmie'#324' Odcinek'
      OnClick = blele1Click
    end
    object Dodajodcinek1: TMenuItem
      Caption = 'Dodaj odcinek'
      OnClick = Dodajodcinek1Click
    end
  end
  object PopupMenu2: TPopupMenu
    Left = 488
    Top = 280
    object Usupostj1: TMenuItem
      Caption = 'Usu'#324' infopoint'
      OnClick = Usupostj1Click
    end
    object Edytujpostj1: TMenuItem
      Caption = 'Wstaw infopoint'
      OnClick = Edytujpostj1Click
    end
    object Wstawpostj1: TMenuItem
      Caption = 'Wstaw post'#243'j'
      OnClick = Wstawpostj1Click
    end
    object Usupostjje1: TMenuItem
      Caption = 'Usu'#324' post'#243'j'
      Enabled = False
      OnClick = Usupostjje1Click
    end
  end
end
