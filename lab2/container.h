/*template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

template<typename T>
class Container
{
public:
	Container();
	~Container();

	void push_back (T data);
	unsigned int GetSize() { return size; }

private:
	unsigned int size;
	Node<T>* head;

};

template<typename T>
Container<T>::Container()
{
	size = 0;
	head = nullptr;
}


template<typename T>
Container<T>::~Container()
{
	clear();
}

template<typename T>
void Container<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = head;
		for (; current->pNext; current = current->pNext);
		current->pNext = new Node<T>(data);
	}
	size++;
}    */
