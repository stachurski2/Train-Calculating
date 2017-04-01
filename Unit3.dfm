object Form3: TForm3
  Left = 308
  Top = 177
  Width = 967
  Height = 673
  Caption = 'Charakterystyka pojazdu trakcyjnego'
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
    Left = 24
    Top = 104
    Width = 240
    Height = 13
    Caption = 'Zale'#380'nosc si'#322'y trakcyjnej [ kN]od  predkosci [km/h]'
  end
  object Label2: TLabel
    Left = 16
    Top = 8
    Width = 73
    Height = 13
    Caption = 'Nazwa pojazdu'
  end
  object Label3: TLabel
    Left = 16
    Top = 56
    Width = 47
    Height = 13
    Caption = 'Liczba osi'
  end
  object Label4: TLabel
    Left = 160
    Top = 8
    Width = 87
    Height = 13
    Caption = 'Masa s'#322'u'#380'bowa [t]'
  end
  object Label5: TLabel
    Left = 160
    Top = 56
    Width = 98
    Height = 13
    Caption = 'D'#322'ugosc pojazdu [m]'
  end
  object Label6: TLabel
    Left = 8
    Top = 560
    Width = 32
    Height = 13
    Caption = 'Dla V='
  end
  object Label7: TLabel
    Left = 102
    Top = 560
    Width = 12
    Height = 13
    Caption = 'F='
  end
  object Shape1: TShape
    Left = 328
    Top = 16
    Width = 1
    Height = 600
  end
  object Shape2: TShape
    Left = 328
    Top = 616
    Width = 600
    Height = 1
  end
  object Label8: TLabel
    Left = 840
    Top = 600
    Width = 79
    Height = 13
    Caption = 'Pr'#281'dkosc [km/h]'
  end
  object Label9: TLabel
    Left = 304
    Top = 8
    Width = 42
    Height = 13
    Caption = 'Si'#322'a [kN]'
  end
  object ListBox1: TListBox
    Left = 16
    Top = 120
    Width = 281
    Height = 409
    ItemHeight = 13
    TabOrder = 0
  end
  object Button1: TButton
    Left = 96
    Top = 600
    Width = 81
    Height = 25
    Caption = 'Zamknij'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 16
    Top = 24
    Width = 121
    Height = 21
    TabOrder = 2
    OnChange = Edit1Change
  end
  object Edit2: TEdit
    Left = 16
    Top = 72
    Width = 121
    Height = 21
    TabOrder = 3
    OnChange = Edit2Change
  end
  object Edit3: TEdit
    Left = 160
    Top = 24
    Width = 121
    Height = 21
    TabOrder = 4
    OnChange = Edit3Change
  end
  object Edit4: TEdit
    Left = 160
    Top = 72
    Width = 121
    Height = 21
    TabOrder = 5
    OnChange = Edit4Change
  end
  object Edit5: TEdit
    Left = 48
    Top = 557
    Width = 49
    Height = 21
    TabOrder = 6
  end
  object Edit6: TEdit
    Left = 118
    Top = 557
    Width = 57
    Height = 21
    TabOrder = 7
  end
  object Button2: TButton
    Left = 16
    Top = 600
    Width = 73
    Height = 25
    Caption = 'Usu'#324' punkt'
    TabOrder = 8
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 192
    Top = 552
    Width = 89
    Height = 25
    Caption = 'Dodaj punkt'
    TabOrder = 9
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 192
    Top = 600
    Width = 81
    Height = 25
    Caption = 'Zapisz do pliku'
    TabOrder = 10
    OnClick = Button4Click
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = '.xml'
    Filter = '.xml|*.xml'
    Left = 280
    Top = 592
  end
end
