//---------------------------------------------------------------------------

#pragma hdrstop

#include "Tree.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)


unsigned char Node::Height(Node* node)
{
	return node? node->height : 0;
}

int Node::BalanceFactor(Node* node)
{
	return Height(node->pRight) - Height(node->pLeft);
}

Node* Node::Add(Node *node, int num, String str)
{
	if (node == NULL)
	{
		node = new Node;
		node->value = num;
		node->str = str;
		node->pLeft =  NULL;
		node->pRight = NULL;
	}
	else
	{
		if(num == node->value)
		{
			return node;
		}
		if(num < node->value)
		{
			node->pLeft = Add(node->pLeft, num, str);
		}
		else
		{
			node->pRight = Add(node->pRight, num, str);
		}
	}
	return node->Balance(node);
}

Node* Node::RotateRight(Node* node1)
{
	Node* node2 = node1->pLeft;
	node1->pLeft = node2->pRight;
	node2->pRight = node1;
	FixHeight(node1);
	FixHeight(node2);
	return node2;
}

Node* Node::RotateLeft(Node* node1)
{
	Node* node2 = node1->pRight;
	node1->pRight = node2->pLeft;
	node2->pLeft = node1;
	FixHeight(node2);
	FixHeight(node1);
	return node2;
}

Node* Node::Find(Node* node, int key)
{
	if(node)
	{
		if(node->value == key)
		{
			return node;
		}
		if(node->value > key)
		{
			return Find(node->pLeft, key);
		}
		return Find(node->pRight, key);
	}
	return node;
}

Node* Node::Balance(Node* node)
{
	FixHeight(node);
	if(BalanceFactor(node) == 2)
	{
		if(BalanceFactor(node->pRight) < 0 )
		{
			node->pRight = RotateRight(node->pRight);
		}
		return RotateLeft(node);
	}
	if(BalanceFactor(node) == -2)
	{
		if(BalanceFactor(node->pLeft) > 0)
		{
			node->pLeft = RotateLeft(node->pLeft);
		}
		return RotateRight(node);
	}
	return node;
}

Node* Node::Delete(Node* node, int key)
{
	if (node == NULL)
	{
		return node;
	}
	if (key < node->value)
	{
		node->pLeft = Delete(node->pLeft, key);
	}
	else if (key > node->value)
	{
		node->pRight = Delete(node->pRight, key);
	}
	else
	{
		if (node->pLeft == NULL)
		{
			Node* temp = node->pRight;
			delete(node);
			return temp;
		}
		else if (node->pRight == NULL)
		{
			Node* temp = node->pLeft;
			delete(node);
			return temp;
		}

		Node* temp = MinValue(node->pRight);
		node->value = temp->value;
		node->pRight = Delete(node->pRight, temp->value);
	}
	return node->Balance(node);
}

void Node::FixHeight(Node* node)
{
	unsigned char hpLeft = Height(node->pLeft);
	unsigned char hpRight = Height(node->pRight);
	node->height = (hpLeft > hpRight? hpLeft : hpRight)+1;
}

Node* Node::MinValue(Node* node)
{
	Node* curNode = node;
	while (curNode && curNode->pLeft != NULL)
	{
		curNode = curNode->pLeft;
	}
	return curNode;
}

int Tree::CountOfRight(Node* node)
{
	if (node)
	{
		return 1 + CountOfRight(node->pLeft) + CountOfRight(node->pRight);
	}
	return 0;
}

