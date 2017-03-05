object Form2: TForm2
  Left = 614
  Top = 133
  BorderStyle = bsDialog
  Caption = 'Edycja linii'
  ClientHeight = 571
  ClientWidth = 577
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 64
    Top = 0
    Width = 144
    Height = 13
    Caption = 'Wykaz wczytanych predkosci:'
  end
  object Label2: TLabel
    Left = 8
    Top = 408
    Width = 139
    Height = 13
    Caption = 'Dodawanie nowego odcinka:'
  end
  object Label3: TLabel
    Left = 16
    Top = 432
    Width = 53
    Height = 13
    Caption = 'Koniec [m]:'
  end
  object Label4: TLabel
    Left = 88
    Top = 432
    Width = 79
    Height = 13
    Caption = 'Pr'#281'dkosc [km/h]'
  end
  object Label5: TLabel
    Left = 344
    Top = 0
    Width = 152
    Height = 13
    Caption = 'Wykaz wczytanych  infopoint'#243'w'
  end
  object Label6: TLabel
    Left = 304
    Top = 408
    Width = 114
    Height = 13
    Caption = 'Dodawanie infopoint'#243'w:'
  end
  object Button1: TButton
    Left = 192
    Top = 526
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
  object Button2: TButton
    Left = 16
    Top = 478
    Width = 113
    Height = 33
    Caption = 'Dodaj nowy odcinek'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 152
    Top = 478
    Width = 113
    Height = 33
    Caption = 'Usu'#324' ostatni odcinek'
    TabOrder = 3
    OnClick = Button3Click
  end
  object Edit1: TEdit
    Left = 16
    Top = 446
    Width = 65
    Height = 21
    TabOrder = 4
  end
  object Edit2: TEdit
    Left = 88
    Top = 446
    Width = 65
    Height = 21
    TabOrder = 5
  end
  object CheckBox1: TCheckBox
    Left = 176
    Top = 446
    Width = 113
    Height = 17
    Caption = 'dot. czo'#322'a poci'#261'gu'
    TabOrder = 6
    OnClick = CheckBox1Click
  end
  object ListBox2: TListBox
    Left = 296
    Top = 16
    Width = 273
    Height = 385
    ItemHeight = 13
    TabOrder = 7
    OnClick = ListBox2Click
  end
  object Button4: TButton
    Left = 432
    Top = 480
    Width = 113
    Height = 33
    Caption = 'Usun infopoint'
    TabOrder = 8
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 304
    Top = 480
    Width = 113
    Height = 33
    Caption = 'Dodaj infopoint'
    TabOrder = 9
    OnClick = Button5Click
  end
  object Edit3: TEdit
    Left = 304
    Top = 448
    Width = 65
    Height = 21
    TabOrder = 10
  end
  object Edit4: TEdit
    Left = 384
    Top = 448
    Width = 161
    Height = 21
    TabOrder = 11
  end
  object Button6: TButton
    Left = 320
    Top = 528
    Width = 113
    Height = 33
    Caption = 'Zapisz do pliku'
    TabOrder = 12
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 16
    Top = 526
    Width = 113
    Height = 33
    Caption = 'Definiuj Ograniczenie'
    TabOrder = 13
    OnClick = Button7Click
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = '.xml'
    FileName = 'F:\Kulej\Moje programy\OT\Linie\sdasd'
    Filter = '.xml|*.xml'
    Left = 456
    Top = 536
  end
end
