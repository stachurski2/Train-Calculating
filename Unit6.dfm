object Form6: TForm6
  Left = 252
  Top = 528
  Width = 323
  Height = 181
  Caption = 'Form6'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 120
    Top = 9
    Width = 50
    Height = 13
    Caption = 'Koniec [m]'
  end
  object Label3: TLabel
    Left = 24
    Top = 9
    Width = 59
    Height = 13
    Caption = 'Pocz'#261'tek[m]'
  end
  object Label4: TLabel
    Left = 200
    Top = 9
    Width = 79
    Height = 13
    Caption = 'Pr'#281'dkosc [km/h]'
  end
  object Label5: TLabel
    Left = 72
    Top = 49
    Width = 109
    Height = 13
    Caption = 'Dotyczy czo'#322'a poci'#261'gu'
  end
  object Label6: TLabel
    Left = 56
    Top = 73
    Width = 158
    Height = 13
    Caption = 'Usu'#324' odcinek (wyd'#322'u'#380' poprzedni)'
  end
  object Label1: TLabel
    Left = 107
    Top = 73
    Width = 74
    Height = 13
    Caption = 'Wyd'#322'u'#380'enie linii'
  end
  object Edit1: TEdit
    Left = 24
    Top = 25
    Width = 65
    Height = 21
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 112
    Top = 25
    Width = 65
    Height = 21
    TabOrder = 1
  end
  object Edit3: TEdit
    Left = 200
    Top = 25
    Width = 73
    Height = 21
    TabOrder = 2
  end
  object Button1: TButton
    Left = 104
    Top = 97
    Width = 97
    Height = 25
    Caption = 'Zmie'#324
    TabOrder = 3
    OnClick = Button1Click
  end
  object CheckBox1: TCheckBox
    Left = 192
    Top = 49
    Width = 17
    Height = 17
    Caption = 'CheckBox1'
    TabOrder = 4
  end
  object CheckBox2: TCheckBox
    Left = 224
    Top = 73
    Width = 17
    Height = 17
    Caption = 'CheckBox2'
    TabOrder = 5
    OnClick = CheckBox2Click
  end
  object Button2: TButton
    Left = 104
    Top = 112
    Width = 97
    Height = 25
    Caption = 'Dodaj odc.'
    TabOrder = 6
    Visible = False
    OnClick = Button2Click
  end
  object CheckBox3: TCheckBox
    Left = 192
    Top = 72
    Width = 17
    Height = 17
    TabOrder = 7
    OnClick = CheckBox3Click
  end
end
