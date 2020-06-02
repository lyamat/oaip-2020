//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------

#include <vcl.h>
//#include <stdlib.h>
//#include <iostream>

using std::string;

struct Elem
{
   UnicodeString data;
   Elem * next, * prev;
};

class List
{
   Elem * Head, * Tail;
   int Count;

public:

   List();

   ~List();

   int GetCount();

   void DelAll();

   UnicodeString GetElemData(int);

   void Del(int pos = 0);

   void Add(UnicodeString n);

};

List::List()
{
   Head = Tail = NULL;
   Count = 0;
}

List::~List()
{
   DelAll();
}

void List::Add(UnicodeString n)
{

   Elem * temp = new Elem;

   temp->next = 0;

   temp->data = n;

   temp->prev = Tail;

   if(Tail != 0)
      Tail->next = temp;

   if(Count == 0)
      Head = Tail = temp;
   else
   Tail = temp;

   Count++;
}

void List::Del(int pos)
{
   if(pos < 1 || pos > Count)
   {
	  return;
   }

   int i = 1;

   Elem * Del = Head;

   while(i < pos)
   {
      Del = Del->next;
      i++;
   }

   Elem * PrevDel = Del->prev;

   Elem * AfterDel = Del->next;

   if(PrevDel != 0 && Count != 1)
	  PrevDel->next = AfterDel;

    if(AfterDel != 0 && Count != 1)
      AfterDel->prev = PrevDel;

   if(pos == 1)
       Head = AfterDel;
   if(pos == Count)
       Tail = PrevDel;

   delete Del;

   Count--;
}


void List::DelAll()
{
   while(Count != 0)
	  Del(1);
}

UnicodeString List::GetElemData(int pos)
{
   Elem *temp = Head;

   if(pos < 1 || pos > Count)
   {
      return 0;
   }

   int i = 1;
   while(i < pos && temp != 0)
   {
      temp = temp->next;
      i++;
   }

   if(temp == 0)
      return 0;
   else
	  return temp->data;
}

int List::GetCount()
{
	return Count;
}

#endif
