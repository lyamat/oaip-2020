//---------------------------------------------------------------------------

#include <vcl.h>
#include <cstdlib>
#include <stdlib.h>
#include <map>


//#include "stdafx.h"
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

using namespace std;

Stack<char> op_stack;


map <char,double> operands = {
								{ 'a', 9.1 },
								{ 'b', 0.6 },
								{ 'c', 2.4 },
								{ 'd', 3.7 },
								{ 'e', 8.5 }};

void AddVariable(char name, long double value)
{
	for (auto i: operands)
	{
		if(name == i.first)
		{
			ShowMessage("This variable already exist");
			return;
		}
	}
   	operands.insert( {name, value} ) ;
}

string USToString(UnicodeString strU)
{
	string str;
	str.reserve(strU.Length());

	for(unsigned short i = 0; i < strU.Length(); i++)
	{
		str[i] = strU[i+1];
	}
	return str;
}

inline bool C2Ppn::isDigit(char c) {
	return (c>='0' && c<='9');
}

inline int C2Ppn::prior(char c) {
    switch(c) {
        case '(': return 1;
        case '+': case '-': return 2;
        case '*': case '/': return 3;
        default: return 0;
    }
}

inline char C2Ppn::nextChar() {
    if(iin < str_in.length()) {
		return curc = str_in[iin++];
    }
    else return curc = '\0';
}

inline string C2Ppn::get_str_out()const {
	return str_out;
}

void C2Ppn::change_str_out(string ns)
{
	 str_out = ns;
}

void C2Ppn::convert(string str)
{
	int was_op = 0, np = 0;

	iin = 0;

	str_in = str;
	str_out.clear();


    while (nextChar() != '\0') {
	   if(isalpha(curc)) {
		   str_out += curc;
		   was_op = 0;
		   continue;
	   }

       switch (curc) {
           case '(':
			   op_stack.push(curc);
			   ++np;
			   was_op = 0;
			   break;
           case '*': case '/': case '+': case '-':


			   if(!was_op)
			   {
			       was_op = 1;
				   while(prior(curc) <= prior(op_stack.top())) {
			           str_out += op_stack.pop();
				   }
                   if(prior(curc) > prior(op_stack.top())){
				       op_stack.push(curc);
				   }
			       break;
			   }
			   else {};

		   case ')':
			   if (was_op) {}
			   else
				   while((curc = op_stack.pop())!= '(' && np>0)
				   {
				       str_out += curc;
				   }
			   --np;
			   break;
		   default:{}
	   }
	}
	while(op_stack.top() != op_stack.EOS)
		str_out += op_stack.pop();
}

double C2Ppn::calc()
{
	Mstack<long double> val_stack;
	long double a = 0;

	for(char i: str_out)
	{
		if(i >= 'a' && i <= 'z')
		{
			   val_stack.push(operands.find(i)->second);
		}
		else
		{
			a = val_stack.top();
			val_stack.pop();

			switch(i)
			{
			   case '+':
			   {
					val_stack.top() += a;
					break;
			   }
				case '-':
			   {
					val_stack.top() -= a;
					break;
			   }
				case '*':
			   {
					val_stack.top() *= a;
					break;
			   }
				case '/':
			   {
					val_stack.top() /= a;
					break;
			   }
			}

		}
	}

	a = val_stack.top();
	val_stack.pop();
	return a;
}


void __fastcall TForm1::Button1Click(TObject *Sender)
{
		try
		{
			string str_in;
			UnicodeString ustr_in;

			ustr_in = Edit1->Text;

			AnsiString astr_in = ustr_in;

			str_in = astr_in.c_str();

			C2Ppn ppn;
			ppn.convert(str_in);
			Edit3->Text = ppn.get_str_out().c_str();

			string new_out = ppn.get_str_out();

			ppn.change_str_out(new_out);
			Edit4->Text = ppn.calc();

		}
		catch(string exc) {
		   //Edit4->Text = exc.c_str();
		}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button2Click(TObject *Sender)
{
	try
	{
		if (Edit10->Text == "")
		{
			throw "Empty name field";
		}
		if (Edit11->Text == "")
		{
			throw "Empty value field";
		}
	}
	catch (UnicodeString &str)
	{
		ShowMessage(str);
		return;
	}
	AddVariable(Edit10->Text[1], std::stod(USToString(Edit11->Text)));
}
//---------------------------------------------------------------------------

