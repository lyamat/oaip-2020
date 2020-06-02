//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------

#include <string>
#include <exception>

using namespace std;

class C2Ppn
{
	char curc;
	string str_in, str_out;
	int iin;

	char nextChar();
	bool isDigit(char c);
	int prior(char c);
  public:
	void convert(string);
	double calc();
	string get_str_out()const;
	void change_str_out(string);
};

template <class T>
class Stack
{
	T* pstack;
	int istack;
	int size;

	friend class C2Ppn;

	void push(T x)
	{
	  if(istack < size) pstack[istack++] = x;
	  else {}
	}
	T pop()
	{
	    return (istack > 0)? pstack[--istack]: EOS;
    }
	T top()const
	{
		return (istack > 0)? pstack[istack-1]: EOS;
	}

  public:
	const char EOS;
	Stack(): EOS(0x01), size(50)
	{
		istack = 0;
		pstack = new T[size];
	}
	~Stack() {if(pstack) delete[] pstack;}
};

#include <exception>

template <typename T>
class Mstack
{
public:

	friend class C2Ppn;

	Mstack() { _top = nullptr; size = 0; }

    ~Mstack();

	unsigned int Size() { return size; }

	void push(T data);

	void pop();

    T& top();

	class node
	{
    public:
        node(T el, node* pnext = nullptr) : data(el)
        {
            this->pnext = pnext;
        }

        node* pnext;
        T data;
    };


private:
	unsigned int size;


	node* _top;
};


template <typename T>
void Mstack<T>::push(T data)
{
    node* temp = new node(data);
    temp->pnext = _top;
    _top = temp;

    size++;

}

template <typename T>
void Mstack<T>::pop()
{
    node* temp = _top;
    _top = _top->pnext;
    delete temp;
    size--;
}

template <typename T>
T& Mstack<T>::top()
{
    return _top->data;
}

template <typename T>
Mstack<T>::~Mstack<T>()
{
    while (size)
    {
        pop();
    }
}

#endif
