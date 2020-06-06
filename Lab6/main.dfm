object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 280
  ClientWidth = 386
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Memo: TMemo
    Left = 8
    Top = 8
    Width = 375
    Height = 145
    ReadOnly = True
    TabOrder = 0
  end
  object SpacingDeleteButton: TButton
    Left = 270
    Top = 159
    Width = 113
    Height = 32
    Caption = 'Delete from K1 to K2'
    TabOrder = 1
    OnClick = SpacingDeleteButtonClick
  end
  object AddButton: TButton
    Left = 143
    Top = 159
    Width = 98
    Height = 32
    Caption = 'Add'
    TabOrder = 2
    OnClick = AddButtonClick
  end
  object RandomFillingButton: TButton
    Left = 8
    Top = 159
    Width = 98
    Height = 32
    Caption = 'Random filling '
    TabOrder = 3
    OnClick = RandomFillingButtonClick
  end
  object K1Edit: TEdit
    Left = 303
    Top = 201
    Width = 41
    Height = 21
    TabOrder = 4
  end
  object K2Edit: TEdit
    Left = 303
    Top = 224
    Width = 41
    Height = 21
    TabOrder = 5
  end
  object StaticText1: TStaticText
    Left = 277
    Top = 228
    Width = 27
    Height = 17
    Caption = 'K2 ='
    TabOrder = 6
  end
  object StaticText2: TStaticText
    Left = 277
    Top = 205
    Width = 27
    Height = 17
    Caption = 'K1 ='
    TabOrder = 7
  end
  object KeyEdit: TEdit
    Left = 8
    Top = 220
    Width = 65
    Height = 21
    TabOrder = 8
  end
  object StaticText3: TStaticText
    Left = 14
    Top = 197
    Width = 54
    Height = 17
    Caption = 'Input key:'
    TabOrder = 9
  end
  object DeleteButton: TButton
    Left = 143
    Top = 215
    Width = 98
    Height = 32
    Caption = 'Delete'
    TabOrder = 10
    OnClick = DeleteButtonClick
  end
end
