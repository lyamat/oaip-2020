object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 374
  ClientWidth = 798
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object TreeView: TTreeView
    Left = 24
    Top = 8
    Width = 217
    Height = 347
    Indent = 19
    TabOrder = 0
  end
  object Memo: TMemo
    Left = 400
    Top = 8
    Width = 178
    Height = 347
    TabOrder = 1
  end
  object CountOfRight: TButton
    Left = 272
    Top = 220
    Width = 99
    Height = 29
    Caption = 'Count Of Right'
    TabOrder = 2
    OnClick = CountOfRightClick
  end
  object Delete: TButton
    Left = 281
    Top = 52
    Width = 75
    Height = 25
    Caption = 'Delete'
    TabOrder = 3
    OnClick = DeleteClick
  end
  object Find: TButton
    Left = 281
    Top = 83
    Width = 75
    Height = 25
    Caption = 'Find'
    TabOrder = 4
    OnClick = FindClick
  end
  object Add: TButton
    Left = 281
    Top = 21
    Width = 75
    Height = 25
    Caption = 'Add'
    TabOrder = 5
    OnClick = AddClick
  end
  object RadioGroup1: TRadioGroup
    Left = 258
    Top = 271
    Width = 129
    Height = 83
    TabOrder = 6
  end
  object rbStraight: TRadioButton
    Left = 281
    Top = 284
    Width = 113
    Height = 17
    Caption = 'Show straight'
    TabOrder = 7
    OnClick = rbStraightClick
  end
  object rbReversed: TRadioButton
    Left = 281
    Top = 307
    Width = 113
    Height = 17
    Caption = 'Show reversed'
    TabOrder = 8
    OnClick = rbReversedClick
  end
  object rbSorted: TRadioButton
    Left = 281
    Top = 330
    Width = 113
    Height = 17
    Caption = 'Show sorted'
    TabOrder = 9
    OnClick = rbSortedClick
  end
  object NumEdit: TEdit
    Left = 258
    Top = 134
    Width = 121
    Height = 21
    TabOrder = 10
    Text = 'num'
  end
  object CityEdit: TEdit
    Left = 258
    Top = 177
    Width = 121
    Height = 21
    TabOrder = 11
    Text = 'city'
  end
  object StringGrid: TStringGrid
    Left = 637
    Top = 8
    Width = 153
    Height = 347
    ColCount = 2
    RowCount = 15
    TabOrder = 12
    RowHeights = (
      24
      24
      24
      24
      24
      24
      24
      24
      24
      26
      24
      24
      24
      24
      24)
  end
end
