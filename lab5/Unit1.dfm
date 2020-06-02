object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 476
  ClientWidth = 730
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 656
    Top = 79
    Width = 17
    Height = 26
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label1: TLabel
    Left = 16
    Top = 336
    Width = 75
    Height = 13
    Caption = #1054#1090#1082#1088#1099#1074#1072#1077#1090' txt'
  end
  object Label3: TLabel
    Left = 8
    Top = 408
    Width = 209
    Height = 13
    Caption = #1047#1072#1087#1080#1089#1099#1074#1072#1077#1090' '#1089#1090#1088#1086#1082#1080' '#1074' '#1076#1074#1091#1089#1074#1103#1079#1085#1099#1081' '#1089#1087#1080#1089#1086#1082
  end
  object Label4: TLabel
    Left = 200
    Top = 336
    Width = 352
    Height = 13
    Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1089#1090#1088#1086#1082#1080', '#1082#1086#1090#1086#1088#1099#1077' '#1073#1091#1076#1077#1090#1077' '#1074#1089#1090#1072#1074#1083#1103#1090#1100' '#1087#1077#1088#1077#1076' '#1076#1088#1091#1075#1086#1081' '#1089#1090#1088#1086#1082#1086#1081
  end
  object Label5: TLabel
    Left = 240
    Top = 355
    Width = 285
    Height = 13
    Caption = #1055#1088#1080' '#1101#1090#1086#1084', '#1086#1089#1090#1072#1074#1100#1090#1077' '#1086#1076#1085#1091' '#1083#1102#1073#1091#1102' '#1089#1090#1088#1086#1082#1091' '#1085#1077' '#1074#1099#1076#1077#1083#1077#1085#1085#1086#1081
  end
  object Label6: TLabel
    Left = 254
    Top = 408
    Width = 308
    Height = 13
    Caption = #1058#1077#1087#1077#1088#1100' '#1089#1090#1088#1086#1082#1091', '#1087#1077#1088#1077#1076' '#1082#1086#1090#1086#1088#1086#1081' '#1074#1089#1090#1072#1074#1080#1090#1100' '#1074#1099#1076#1077#1083#1077#1085#1085#1099#1077' '#1088#1072#1085#1077#1077
  end
  object ListBox1: TListBox
    Left = 8
    Top = 8
    Width = 585
    Height = 153
    ItemHeight = 13
    TabOrder = 0
  end
  object OpenFileButton: TButton
    Left = 8
    Top = 355
    Width = 97
    Height = 43
    Caption = 'OpenFile'
    TabOrder = 1
    OnClick = OpenFileButtonClick
  end
  object ListBox2: TListBox
    Left = 8
    Top = 185
    Width = 585
    Height = 145
    ItemHeight = 13
    MultiSelect = True
    TabOrder = 2
  end
  object ToListButton: TButton
    Left = 8
    Top = 427
    Width = 97
    Height = 43
    Caption = 'ToList'
    TabOrder = 3
    OnClick = ToListButtonClick
  end
  object ChooseAndDeleteButton: TButton
    Left = 568
    Top = 336
    Width = 137
    Height = 37
    Caption = 'ChooseAndDelete'
    TabOrder = 4
    OnClick = ChooseAndDeleteButtonClick
  end
  object ChooseAndInputButton: TButton
    Left = 568
    Top = 394
    Width = 137
    Height = 43
    Caption = 'ChooseAndInput'
    TabOrder = 5
    OnClick = ChooseAndInputButtonClick
  end
  object FileOpenDialog1: TFileOpenDialog
    FavoriteLinks = <>
    FileTypes = <>
    Options = []
    Left = 664
    Top = 136
  end
  object SaveDialog1: TSaveDialog
    Left = 664
    Top = 192
  end
end
