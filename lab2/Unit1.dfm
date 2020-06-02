object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 534
  ClientWidth = 684
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object OrderNumberLabel: TLabel
    Left = 8
    Top = 56
    Width = 103
    Height = 21
    Caption = 'Order number'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object TableNumberLabel: TLabel
    Left = 8
    Top = 104
    Width = 102
    Height = 21
    Caption = 'Table number'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object DishNameLabel: TLabel
    Left = 8
    Top = 152
    Width = 79
    Height = 21
    Caption = 'Dish name'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object NumberOfServingsLabel: TLabel
    Left = 8
    Top = 224
    Width = 143
    Height = 21
    Caption = 'Number of servings'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object OrderInvoiceLabel: TLabel
    Left = 8
    Top = 272
    Width = 98
    Height = 21
    Caption = 'Order invoice'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object SearchLabel: TLabel
    Left = 8
    Top = 423
    Width = 177
    Height = 21
    Caption = 'Name of dish to search:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object DishCostLabel: TLabel
    Left = 7
    Top = 179
    Width = 122
    Height = 21
    Caption = 'Dish Cost (EUR)'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label: TLabel
    Left = 8
    Top = 487
    Width = 4
    Height = 15
    Color = clInfoBk
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'PMingLiU-ExtB'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object ComboBox: TComboBox
    Left = 79
    Top = 12
    Width = 145
    Height = 21
    TabOrder = 0
    Text = 'Orders'
    OnChange = ComboBoxChange
  end
  object AddButton: TButton
    Left = 8
    Top = 312
    Width = 147
    Height = 25
    Caption = 'Add'
    TabOrder = 2
    OnClick = AddButtonClick
  end
  object EditButton: TButton
    Left = 5
    Top = 343
    Width = 146
    Height = 25
    Caption = 'Edit'
    TabOrder = 3
    OnClick = EditButtonClick
  end
  object GetDateButton: TButton
    Left = 551
    Top = 12
    Width = 127
    Height = 25
    Caption = 'Get data'
    TabOrder = 4
    OnClick = GetDateButtonClick
  end
  object SortButton: TButton
    Left = 551
    Top = 200
    Width = 127
    Height = 33
    Caption = 'Sort by Order Invoise'
    TabOrder = 5
    OnClick = SortButtonClick
  end
  object SearchButton: TButton
    Left = 191
    Top = 442
    Width = 130
    Height = 25
    Caption = 'Search'
    TabOrder = 6
    OnClick = SearchButtonClick
  end
  object TopDishesButton: TButton
    Left = 551
    Top = 169
    Width = 127
    Height = 25
    Caption = 'Top Dishes'
    TabOrder = 7
    OnClick = TopDishesButtonClick
  end
  object SaveDataButton: TButton
    Left = 551
    Top = 43
    Width = 127
    Height = 25
    Caption = 'Save data'
    TabOrder = 8
    OnClick = SaveDataButtonClick
  end
  object OrderNumberEdit: TEdit
    Left = 200
    Top = 59
    Width = 121
    Height = 21
    TabOrder = 9
  end
  object TableNumberEdit: TEdit
    Left = 200
    Top = 107
    Width = 121
    Height = 21
    TabOrder = 10
  end
  object DishNameEdit: TEdit
    Left = 200
    Top = 155
    Width = 121
    Height = 21
    TabOrder = 11
  end
  object NumberOfServingsEdit: TEdit
    Left = 200
    Top = 227
    Width = 121
    Height = 21
    TabOrder = 12
  end
  object OrderInvoiceEdit: TEdit
    Left = 200
    Top = 275
    Width = 121
    Height = 21
    TabOrder = 13
  end
  object SearchEdit: TEdit
    Left = 191
    Top = 415
    Width = 130
    Height = 21
    TabOrder = 14
  end
  object Memo1: TMemo
    Left = 560
    Top = 423
    Width = 118
    Height = 106
    Lines.Strings = (
      '')
    ParentShowHint = False
    ShowHint = False
    TabOrder = 15
    Visible = False
  end
  object Memo: TMemo
    Left = 351
    Top = 12
    Width = 193
    Height = 517
    ReadOnly = True
    TabOrder = 1
  end
  object DishCostEdit: TEdit
    Left = 200
    Top = 182
    Width = 121
    Height = 21
    TabOrder = 16
  end
  object ViewAllButton: TButton
    Left = 551
    Top = 138
    Width = 127
    Height = 25
    Caption = 'View all'
    TabOrder = 17
    OnClick = ViewAllButtonClick
  end
  object SaveDialog: TSaveDialog
    Left = 600
    Top = 352
  end
  object FileOpenDialog: TFileOpenDialog
    FavoriteLinks = <>
    FileTypes = <>
    Options = []
    Left = 600
    Top = 280
  end
end
