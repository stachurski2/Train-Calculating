object Form7: TForm7
  Left = 573
  Top = 112
  Width = 626
  Height = 447
  Caption = 'Form7'
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
    Left = 464
    Top = 18
    Width = 71
    Height = 13
    Caption = 'Rozk'#322'ad jazdy '
  end
  object Label2: TLabel
    Left = 39
    Top = 294
    Width = 90
    Height = 13
    Caption = 'Godzina wiod'#261'ca : '
  end
  object Label3: TLabel
    Left = 47
    Top = 308
    Width = 11
    Height = 13
    Caption = 'hh'
  end
  object Label4: TLabel
    Left = 87
    Top = 308
    Width = 15
    Height = 13
    Caption = 'mm'
  end
  object Label6: TLabel
    Left = 48
    Top = 18
    Width = 97
    Height = 13
    Caption = 'Punkty Rozk'#322'adowe'
  end
  object Label7: TLabel
    Left = 240
    Top = 18
    Width = 23
    Height = 13
    Caption = 'Czas'
  end
  object Label5: TLabel
    Left = 328
    Top = 18
    Width = 35
    Height = 13
    Caption = 'Postoje'
  end
  object Edit1: TEdit
    Left = 39
    Top = 324
    Width = 32
    Height = 21
    TabOrder = 0
    Text = '00'
  end
  object Edit2: TEdit
    Left = 79
    Top = 324
    Width = 32
    Height = 21
    TabOrder = 1
    Text = '00'
  end
  object ListBox2: TListBox
    Left = 24
    Top = 36
    Width = 176
    Height = 241
    ItemHeight = 13
    TabOrder = 2
  end
  object ListBox3: TListBox
    Left = 215
    Top = 36
    Width = 81
    Height = 241
    ItemHeight = 13
    TabOrder = 3
  end
  object ListBox1: TListBox
    Left = 312
    Top = 34
    Width = 65
    Height = 241
    ItemHeight = 13
    TabOrder = 4
  end
  object ListBox4: TListBox
    Left = 392
    Top = 34
    Width = 201
    Height = 241
    ItemHeight = 13
    TabOrder = 5
  end
  object Button1: TButton
    Left = 384
    Top = 352
    Width = 89
    Height = 33
    Caption = 'Button1'
    TabOrder = 6
  end
  object Button2: TButton
    Left = 504
    Top = 352
    Width = 89
    Height = 33
    Caption = 'Button2'
    TabOrder = 7
  end
  object Button3: TButton
    Left = 128
    Top = 321
    Width = 128
    Height = 25
    Caption = 'Zmien godz. wiod'#261'c'#261
    TabOrder = 8
    OnClick = Button3Click
  end
end
