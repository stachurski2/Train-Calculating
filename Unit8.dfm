object Form8: TForm8
  Left = 581
  Top = 317
  Width = 352
  Height = 178
  Caption = 'Punkty Rozk'#322'adowe'
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
    Left = 11
    Top = 21
    Width = 102
    Height = 14
    Caption = 'Lokalizacja postoju'
  end
  object Label2: TLabel
    Left = 8
    Top = 56
    Width = 140
    Height = 13
    Caption = 'Nazwa punktu rozk'#322'adowego'
  end
  object Edit1: TEdit
    Left = 168
    Top = 16
    Width = 113
    Height = 21
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 168
    Top = 56
    Width = 113
    Height = 21
    TabOrder = 1
  end
  object Button1: TButton
    Left = 152
    Top = 96
    Width = 137
    Height = 33
    Caption = 'Dodaj post'#243'j'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 152
    Top = 96
    Width = 137
    Height = 33
    Caption = 'Dodaj punkt rozk'#322'adowy'
    TabOrder = 3
    OnClick = Button2Click
  end
end
