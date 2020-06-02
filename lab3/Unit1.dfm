object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 570
  ClientWidth = 878
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 80
    Width = 86
    Height = 16
    Caption = 'Serial number:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 110
    Width = 61
    Height = 16
    Caption = 'Full name:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 8
    Top = 145
    Width = 87
    Height = 16
    Caption = 'Home address:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 8
    Top = 167
    Width = 31
    Height = 16
    Caption = 'Date:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label7: TLabel
    Left = 8
    Top = 414
    Width = 31
    Height = 16
    Caption = 'Date:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label8: TLabel
    Left = 8
    Top = 467
    Width = 86
    Height = 16
    Caption = 'Serial number:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label9: TLabel
    Left = 8
    Top = 524
    Width = 57
    Height = 16
    Caption = 'Surname:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label10: TLabel
    Left = 521
    Top = 22
    Width = 66
    Height = 16
    Caption = 'Completed:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label11: TLabel
    Left = 521
    Top = 301
    Width = 54
    Height = 16
    Caption = 'Awaiting:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label12: TLabel
    Left = 753
    Top = 10
    Width = 19
    Height = 16
    Caption = 'All:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label13: TLabel
    Left = 8
    Top = 344
    Width = 140
    Height = 16
    Caption = 'Serial number to delete:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object ComboBox: TComboBox
    Left = 8
    Top = 24
    Width = 153
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    Text = 'List'
    OnChange = ComboBoxChange
  end
  object SerialNumberEdit: TEdit
    Left = 130
    Top = 77
    Width = 135
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object FullNameEdit: TEdit
    Left = 130
    Top = 107
    Width = 135
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
  object HomeAddressEdit: TEdit
    Left = 130
    Top = 137
    Width = 135
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
  end
  object SearchSerialNumberEdit: TEdit
    Left = 100
    Top = 464
    Width = 186
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
  end
  object SearchSurnameEdit: TEdit
    Left = 100
    Top = 515
    Width = 186
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
  end
  object AddButton: TButton
    Left = 8
    Top = 282
    Width = 105
    Height = 25
    Caption = 'Add'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = AddButtonClick
  end
  object EditButton: TButton
    Left = 144
    Top = 282
    Width = 121
    Height = 25
    Caption = 'Edit (Update)'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    OnClick = EditButtonClick
  end
  object SearchRegistrationDateButton: TButton
    Left = 298
    Top = 411
    Width = 75
    Height = 25
    Caption = 'Search'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
    OnClick = SearchRegistrationDateButtonClick
  end
  object SearchSerialNumberButton: TButton
    Left = 298
    Top = 464
    Width = 75
    Height = 24
    Caption = 'Search'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
    OnClick = SearchSerialNumberButtonClick
  end
  object SearchSurnameButton: TButton
    Left = 298
    Top = 515
    Width = 75
    Height = 25
    Caption = 'Search'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
    OnClick = SearchSurnameButtonClick
  end
  object Memo: TMemo
    Left = 663
    Top = 45
    Width = 207
    Height = 517
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    Lines.Strings = (
      '')
    ParentFont = False
    ReadOnly = True
    TabOrder = 11
  end
  object DateSearchPicker: TDateTimePicker
    Left = 100
    Top = 414
    Width = 186
    Height = 24
    Time = 0.478384942129196100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 12
  end
  object AwaitingMemo: TMemo
    Left = 460
    Top = 323
    Width = 173
    Height = 239
    ReadOnly = True
    TabOrder = 13
  end
  object CompletedMemo: TMemo
    Left = 460
    Top = 44
    Width = 173
    Height = 245
    ReadOnly = True
    TabOrder = 14
  end
  object CompletedViewButton: TButton
    Left = 252
    Top = 24
    Width = 88
    Height = 25
    Caption = 'View completed'
    TabOrder = 15
    OnClick = CompletedViewButtonClick
  end
  object AwaitingViewButton: TButton
    Left = 338
    Top = 24
    Width = 89
    Height = 25
    Caption = 'View awaiting'
    TabOrder = 16
    OnClick = AwaitingViewButtonClick
  end
  object DeleteRepeatsButton: TButton
    Left = 298
    Top = 274
    Width = 145
    Height = 41
    Caption = 'Delete duplicates'
    TabOrder = 17
    OnClick = DeleteRepeatsButtonClick
  end
  object ViewAllButton: TButton
    Left = 167
    Top = 24
    Width = 89
    Height = 25
    Caption = 'View all'
    TabOrder = 18
    OnClick = ViewAllButtonClick
  end
  object DeleteSerialNumberButton: TButton
    Left = 282
    Top = 338
    Width = 75
    Height = 27
    Caption = 'Delete'
    TabOrder = 19
    OnClick = DeleteSerialNumberButtonClick
  end
  object DeleteSerialNumberEdit: TEdit
    Left = 155
    Top = 341
    Width = 121
    Height = 21
    TabOrder = 20
  end
  object gbOrderStatus: TGroupBox
    Left = 8
    Top = 197
    Width = 116
    Height = 79
    Caption = 'Order status:'
    TabOrder = 21
    object rbCompleted: TRadioButton
      Left = 27
      Top = 25
      Width = 113
      Height = 17
      Caption = 'Completed'
      TabOrder = 0
    end
    object rbAwaiting: TRadioButton
      Left = 27
      Top = 48
      Width = 113
      Height = 17
      Caption = 'Awaiting'
      TabOrder = 1
    end
  end
  object DateInputPicker: TDateTimePicker
    Left = 130
    Top = 167
    Width = 135
    Height = 21
    Date = 43936.000000000000000000
    Time = 0.777195104165002700
    TabOrder = 22
  end
end
