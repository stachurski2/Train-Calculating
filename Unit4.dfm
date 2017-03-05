object Form4: TForm4
  Left = -38
  Top = 208
  BorderStyle = bsToolWindow
  Caption = 'Form4'
  ClientHeight = 432
  ClientWidth = 1323
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
  object Shape22: TShape
    Left = 29
    Top = 15
    Width = 1
    Height = 320
  end
  object Shape24: TShape
    Left = 1319
    Top = 15
    Width = 1
    Height = 320
  end
  object Label22: TLabel
    Left = 14
    Top = 335
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Label24: TLabel
    Left = 14
    Top = 290
    Width = 12
    Height = 13
    Caption = '40'
  end
  object Shape25: TShape
    Left = 29
    Top = 295
    Width = 1290
    Height = 2
  end
  object Shape26: TShape
    Left = 29
    Top = 335
    Width = 1290
    Height = 2
  end
  object Label25: TLabel
    Left = 14
    Top = 250
    Width = 12
    Height = 13
    Caption = '80'
  end
  object Shape27: TShape
    Left = 29
    Top = 255
    Width = 1290
    Height = 2
  end
  object Shape28: TShape
    Left = 29
    Top = 215
    Width = 1290
    Height = 2
  end
  object Label26: TLabel
    Left = 8
    Top = 210
    Width = 18
    Height = 13
    Caption = '120'
  end
  object Shape29: TShape
    Left = 29
    Top = 135
    Width = 1290
    Height = 2
  end
  object Label27: TLabel
    Left = 8
    Top = 170
    Width = 18
    Height = 13
    Caption = '160'
  end
  object Label28: TLabel
    Left = 6
    Top = 130
    Width = 18
    Height = 13
    Caption = '200'
  end
  object Shape1: TShape
    Left = 29
    Top = 175
    Width = 1290
    Height = 2
  end
  object Label1: TLabel
    Left = 238
    Top = 374
    Width = 69
    Height = 13
    Caption = 'Skala wykresu'
  end
  object Label2: TLabel
    Left = 287
    Top = 393
    Width = 46
    Height = 13
    Caption = 'px = 1 km'
  end
  object Label3: TLabel
    Left = 29
    Top = 373
    Width = 111
    Height = 13
    Caption = 'Przesuwanie wykresu o'
  end
  object Label4: TLabel
    Left = 197
    Top = 376
    Width = 11
    Height = 13
    Caption = 'm.'
  end
  object Label5: TLabel
    Left = 360
    Top = 374
    Width = 32
    Height = 13
    Caption = 'Label5'
  end
  object Label6: TLabel
    Left = 361
    Top = 398
    Width = 32
    Height = 13
    Caption = 'Label6'
  end
  object Label7: TLabel
    Left = 536
    Top = 374
    Width = 32
    Height = 13
    Caption = 'Label7'
  end
  object Label8: TLabel
    Left = 536
    Top = 398
    Width = 32
    Height = 13
    Caption = 'Label8'
  end
  object Label9: TLabel
    Left = 744
    Top = 374
    Width = 32
    Height = 13
    Caption = 'Label9'
  end
  object Label10: TLabel
    Left = 744
    Top = 398
    Width = 38
    Height = 13
    Caption = 'Label10'
  end
  object Shape2: TShape
    Left = 29
    Top = 95
    Width = 1290
    Height = 2
  end
  object Label11: TLabel
    Left = 6
    Top = 90
    Width = 18
    Height = 13
    Caption = '240'
  end
  object Shape3: TShape
    Left = 29
    Top = 55
    Width = 1290
    Height = 2
  end
  object Label12: TLabel
    Left = 6
    Top = 50
    Width = 18
    Height = 13
    Caption = '280'
  end
  object Shape4: TShape
    Left = 28
    Top = 55
    Width = 1290
    Height = 2
  end
  object Shape5: TShape
    Left = 29
    Top = 15
    Width = 1290
    Height = 2
  end
  object Label13: TLabel
    Left = 6
    Top = 10
    Width = 18
    Height = 13
    Caption = '320'
  end
  object Button1: TButton
    Left = 118
    Top = 396
    Width = 57
    Height = 16
    Caption = '>'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 243
    Top = 390
    Width = 41
    Height = 21
    TabOrder = 1
    Text = '1000'
    OnChange = Edit1Change
  end
  object Button2: TButton
    Left = 54
    Top = 396
    Width = 57
    Height = 16
    Caption = '<'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Edit2: TEdit
    Left = 144
    Top = 371
    Width = 49
    Height = 21
    TabOrder = 3
    Text = '100'
  end
end
