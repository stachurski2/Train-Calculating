object Form7: TForm7
  Left = 343
  Top = 180
  Width = 650
  Height = 438
  Caption = 'Form7'
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
    Left = 479
    Top = 2
    Width = 71
    Height = 13
    Caption = 'Rozk'#322'ad jazdy '
  end
  object Label6: TLabel
    Left = 39
    Top = 2
    Width = 97
    Height = 13
    Caption = 'Punkty Rozk'#322'adowe'
  end
  object Label7: TLabel
    Left = 231
    Top = 2
    Width = 23
    Height = 13
    Caption = 'Czas'
  end
  object Label5: TLabel
    Left = 319
    Top = 2
    Width = 35
    Height = 13
    Caption = 'Postoje'
  end
  object ListBox2: TListBox
    Left = 15
    Top = 20
    Width = 176
    Height = 241
    ItemHeight = 13
    TabOrder = 0
    OnClick = ListBox2Click
  end
  object ListBox3: TListBox
    Left = 206
    Top = 20
    Width = 81
    Height = 241
    ItemHeight = 13
    TabOrder = 1
    OnClick = ListBox3Click
  end
  object ListBox1: TListBox
    Left = 303
    Top = 18
    Width = 65
    Height = 241
    ItemHeight = 13
    TabOrder = 2
    OnClick = ListBox1Click
  end
  object ListBox4: TListBox
    Left = 383
    Top = 18
    Width = 242
    Height = 241
    ItemHeight = 13
    TabOrder = 3
    OnClick = ListBox4Click
  end
  object Button1: TButton
    Left = 555
    Top = 279
    Width = 70
    Height = 34
    Caption = 'Button1'
    TabOrder = 4
  end
  object Button2: TButton
    Left = 555
    Top = 319
    Width = 70
    Height = 38
    Caption = 'Button2'
    TabOrder = 5
  end
  object GroupBox1: TGroupBox
    Left = 16
    Top = 264
    Width = 209
    Height = 121
    Caption = 'Godzina Wiod'#261'ca'
    TabOrder = 6
    object Label2: TLabel
      Left = 9
      Top = 59
      Width = 91
      Height = 13
      Caption = 'Godzina wiod'#261'ca : '
    end
    object Label3: TLabel
      Left = 20
      Top = 74
      Width = 12
      Height = 13
      Caption = 'hh'
    end
    object Label4: TLabel
      Left = 60
      Top = 74
      Width = 16
      Height = 13
      Caption = 'mm'
    end
    object Label8: TLabel
      Left = 8
      Top = 16
      Width = 73
      Height = 13
      Caption = 'Punkt wiod'#261'cy:'
    end
    object Button3: TButton
      Left = 96
      Top = 80
      Width = 89
      Height = 33
      Caption = 'Zmie'#324
      TabOrder = 0
      OnClick = Button3Click
    end
    object Edit1: TEdit
      Left = 12
      Top = 90
      Width = 32
      Height = 21
      TabOrder = 1
      Text = '00'
    end
    object Edit2: TEdit
      Left = 52
      Top = 90
      Width = 32
      Height = 21
      TabOrder = 2
      Text = '00'
    end
    object ComboBox1: TComboBox
      Left = 16
      Top = 32
      Width = 161
      Height = 21
      ItemHeight = 13
      TabOrder = 3
      Text = 'ComboBox1'
      OnChange = ComboBox1Change
    end
    object ComboBox2: TComboBox
      Left = 104
      Top = 56
      Width = 73
      Height = 21
      ItemHeight = 13
      TabOrder = 4
      Text = 'ComboBox2'
    end
  end
  object GroupBox2: TGroupBox
    Left = 232
    Top = 266
    Width = 233
    Height = 120
    Caption = 'GroupBox2'
    TabOrder = 7
    object Label9: TLabel
      Left = 154
      Top = 19
      Width = 16
      Height = 13
      Caption = 'mm'
    end
    object Label10: TLabel
      Left = 194
      Top = 19
      Width = 10
      Height = 13
      Caption = 'ss'
    end
    object Label11: TLabel
      Left = 155
      Top = 73
      Width = 16
      Height = 13
      Caption = 'mm'
    end
    object Label12: TLabel
      Left = 194
      Top = 73
      Width = 10
      Height = 13
      Caption = 'ss'
    end
    object Label13: TLabel
      Left = 148
      Top = 61
      Width = 60
      Height = 13
      Caption = 'Czas postoju'
    end
    object Label14: TLabel
      Left = 149
      Top = 8
      Width = 71
      Height = 13
      Caption = 'Czas przejazdu'
    end
    object Label15: TLabel
      Left = 8
      Top = 47
      Width = 73
      Height = 13
      Caption = 'Nazwa Punktu '
    end
    object ComboBox3: TComboBox
      Left = 8
      Top = 24
      Width = 121
      Height = 21
      ItemHeight = 13
      TabOrder = 0
      Text = 'ComboBox3'
    end
    object Edit3: TEdit
      Left = 146
      Top = 35
      Width = 31
      Height = 21
      TabOrder = 1
      Text = '00'
    end
    object Edit4: TEdit
      Left = 186
      Top = 35
      Width = 31
      Height = 21
      TabOrder = 2
      Text = '00'
    end
    object Edit5: TEdit
      Left = 146
      Top = 89
      Width = 30
      Height = 21
      TabOrder = 3
      Text = '00'
    end
    object Edit6: TEdit
      Left = 186
      Top = 89
      Width = 30
      Height = 21
      TabOrder = 4
      Text = '00'
    end
    object Button4: TButton
      Left = 16
      Top = 88
      Width = 89
      Height = 25
      Caption = 'Button4'
      TabOrder = 5
    end
    object Edit7: TEdit
      Left = 8
      Top = 60
      Width = 121
      Height = 21
      TabOrder = 6
    end
  end
  object PopupMenu1: TPopupMenu
    Left = 568
    Top = 216
    object Zmien: TMenuItem
      Caption = 'Zmien Czas'
    end
  end
end
