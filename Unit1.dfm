object Form1: TForm1
  Left = 613
  Top = 73
  BorderStyle = bsToolWindow
  Caption = 'EVC microsimulator 0.1'
  ClientHeight = 302
  ClientWidth = 502
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Shape2: TShape
    Left = 32
    Top = 265
    Width = 713
    Height = 0
    Visible = False
  end
  object Label33: TLabel
    Left = 8
    Top = 8
    Width = 144
    Height = 13
    Caption = 'Brak odcink'#243'w do przeliczania'
  end
  object Label1: TLabel
    Left = 8
    Top = 32
    Width = 203
    Height = 13
    Caption = 'Brak  za'#322'adowanych pojazd'#243'w trakcyjnych'
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 61
    Width = 489
    Height = 228
    Caption = 'Karta Poci'#261'gu'
    Enabled = False
    TabOrder = 0
    OnClick = GroupBox1Click
    object Label2: TLabel
      Left = 24
      Top = 24
      Width = 86
      Height = 13
      Caption = #346'rodek Trakcyjny:'
    end
    object Label3: TLabel
      Left = 175
      Top = 24
      Width = 187
      Height = 13
      Caption = 'Liczba  czynnych pojazd'#243'w trakcyjnych'
    end
    object Label4: TLabel
      Left = 16
      Top = 56
      Width = 102
      Height = 13
      Caption = 'D'#322'ugosc lokomotywy:'
    end
    object Label5: TLabel
      Left = 175
      Top = 56
      Width = 96
      Height = 13
      Caption = 'D'#322'ugosc wagon'#243'w: '
    end
    object Label6: TLabel
      Left = 339
      Top = 56
      Width = 82
      Height = 13
      Caption = 'D'#322'ugosc poci'#261'gu'
    end
    object Label14: TLabel
      Left = 30
      Top = 83
      Width = 84
      Height = 13
      Caption = 'Masa lokomotywy'
    end
    object Label15: TLabel
      Left = 245
      Top = 148
      Width = 181
      Height = 13
      Caption = 'Rzeczywisty procent masy hamuj'#261'cej: '
    end
    object Label7: TLabel
      Left = 185
      Top = 83
      Width = 78
      Height = 13
      Caption = 'Masa wagon'#243'w:'
    end
    object Label8: TLabel
      Left = 347
      Top = 85
      Width = 67
      Height = 13
      Caption = 'Masa poci'#261'gu'
    end
    object Label9: TLabel
      Left = 43
      Top = 115
      Width = 67
      Height = 13
      Caption = 'Liczba osi lok.'
    end
    object Label10: TLabel
      Left = 186
      Top = 115
      Width = 73
      Height = 13
      Caption = 'Liczba osi wag.'
    end
    object Label11: TLabel
      Left = 333
      Top = 115
      Width = 88
      Height = 13
      Caption = 'Liczba osi poci'#261'gu'
    end
    object Label12: TLabel
      Left = 40
      Top = 144
      Width = 106
      Height = 13
      Caption = 'Pr'#281'dkosc maksymalna'
    end
    object ComboBox1: TComboBox
      Left = 370
      Top = 21
      Width = 38
      Height = 21
      ItemHeight = 13
      TabOrder = 0
      Text = '1'
      OnChange = ComboBox1Change
    end
    object Edit2: TEdit
      Left = 121
      Top = 21
      Width = 49
      Height = 21
      Color = cl3DLight
      Enabled = False
      TabOrder = 1
    end
    object Edit3: TEdit
      Left = 121
      Top = 53
      Width = 49
      Height = 21
      Color = cl3DLight
      Enabled = False
      TabOrder = 2
    end
    object Edit4: TEdit
      Left = 273
      Top = 50
      Width = 49
      Height = 21
      TabOrder = 3
      OnChange = Edit4Change
    end
    object Edit5: TEdit
      Left = 429
      Top = 53
      Width = 48
      Height = 21
      Color = cl3DLight
      Enabled = False
      TabOrder = 4
    end
    object Edit6: TEdit
      Left = 120
      Top = 82
      Width = 50
      Height = 21
      Color = cl3DLight
      Enabled = False
      TabOrder = 5
    end
    object Edit7: TEdit
      Left = 427
      Top = 146
      Width = 48
      Height = 21
      TabOrder = 6
      OnChange = Edit7Change
    end
    object Edit8: TEdit
      Left = 273
      Top = 81
      Width = 49
      Height = 21
      TabOrder = 7
      OnChange = Edit8Change
    end
    object Edit9: TEdit
      Left = 428
      Top = 83
      Width = 48
      Height = 21
      Color = cl3DLight
      Enabled = False
      TabOrder = 8
    end
    object Edit10: TEdit
      Left = 119
      Top = 112
      Width = 50
      Height = 21
      Color = cl3DLight
      Enabled = False
      TabOrder = 9
    end
    object Edit11: TEdit
      Left = 272
      Top = 113
      Width = 49
      Height = 21
      TabOrder = 10
      OnChange = Edit11Change
    end
    object Edit12: TEdit
      Left = 427
      Top = 113
      Width = 48
      Height = 21
      Color = cl3DLight
      Enabled = False
      TabOrder = 11
    end
    object Edit13: TEdit
      Left = 152
      Top = 141
      Width = 81
      Height = 21
      TabOrder = 12
      OnChange = Edit13Change
    end
    object Button1: TButton
      Left = 56
      Top = 176
      Width = 105
      Height = 33
      Caption = 'Profil Statyczny'
      TabOrder = 13
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 192
      Top = 176
      Width = 105
      Height = 33
      Caption = 'Profil dynamiczny'
      TabOrder = 14
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 328
      Top = 176
      Width = 105
      Height = 33
      Caption = 'Rozk'#322'ad jazdy'
      TabOrder = 15
      OnClick = Button3Click
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = '.xml|*.xml'
    Left = 168
  end
  object MainMenu1: TMainMenu
    Left = 256
    object PL1: TMenuItem
      Caption = 'Plik'
      object Oprogramie1: TMenuItem
        Caption = 'Zapisz Raport Jazdy'
      end
      object Oprogramie2: TMenuItem
        Caption = 'O programie'
        OnClick = Oprogramie2Click
      end
      object Pomoc1: TMenuItem
        Caption = 'Pomoc'
      end
      object Zakocz1: TMenuItem
        Caption = 'Zako'#324'cz'
        OnClick = Zakocz1Click
      end
    end
    object L1: TMenuItem
      Caption = 'Linia'
      object NowaLinia1: TMenuItem
        Caption = 'Nowa Linia'
        OnClick = NowaLinia1Click
      end
      object ZaladujLinie1: TMenuItem
        Caption = 'Zaladuj Linie'
        OnClick = ZaladujLinie1Click
      end
      object EdytujLinie1: TMenuItem
        Caption = 'Edytuj Linie'
        Enabled = False
        OnClick = EdytujLinie1Click
      end
      object W1: TMenuItem
        Caption = 'Wykres predkosci'
        Enabled = False
        OnClick = W1Click
      end
    end
    object Pojazd1: TMenuItem
      Caption = 'Pojazd'
      object Nowy1: TMenuItem
        Caption = 'Nowy'
        OnClick = Nowy1Click
      end
      object ZaladujPojazd1: TMenuItem
        Caption = 'Za'#322'aduj'
        OnClick = ZaladujPojazd1Click
      end
      object E1: TMenuItem
        Caption = 'Edytuj'
        Enabled = False
        OnClick = E1Click
      end
    end
  end
  object OpenDialog2: TOpenDialog
    Filter = 'xml|*.xml'
    Left = 216
  end
end
