#ifndef __LIST_H__
#define __LIST_H__

#include <iostream>

using namespace std;

#ifndef __NODE__
#define __NODE__
template <class ValType>
struct node{
	node* next;
	ValType data;
};
#endif

template <class ValType>
class TList
{
protected:
	node<ValType>* body;	// ��������� �� ������ �������
public:

  	TList();
	~TList();
	bool IsEmpty() const;
	void Print() const;
	
//  �������
	void InsertAtBegin(node<ValType>* elem);			// �������� � ������ ������� elem
	void InsertAtEnd(node<ValType>* elem);				// �������� � ����� ������� elem
	void Insert(node<ValType>* i, node<ValType>* elem);	// �������� ������� elem ����� i

//  ��������
	void DeleteAtBegin();				// ������� ������� �� ������
	void DeleteAtEnd();					// ������� ������� � ������
	void Delete(node<ValType>* elem);	// ������� ������� ����� elem

	node<ValType>* Search(ValType a);	// ����� �������� a
};

template <class ValType>
TList<ValType>::TList() {
	body = 0;
}

template <class ValType>
TList<ValType>::~TList()
{
	if (body != 0)
	{
		node<ValType>* temp;
		while(body->next != 0) 
		{
			temp = body;
			body = body->next;
			delete[] temp;
		}
	}
}

template <class ValType>
bool TList<ValType>::IsEmpty() const
{
	return !body;
}

template <class ValType>
void TList<ValType>::Print() const
{
	if(body)
	{
		node<ValType>* temp = body;
		while(temp->next)
		{
			cout<<temp->data<<' ';
			temp = temp->next;
		}
		cout<<temp->data<<'\n';
	}
	else cout<<"List is empty!"<<'\n';
}



template <class ValType>
void TList<ValType>::InsertAtBegin(node<ValType>* elem)
{
	if(elem)
	{
		elem->next = body;
		body = elem;
	}
	else throw "error";
}

template <class ValType>
void TList<ValType>::InsertAtEnd(node<ValType>* elem)
{
	if(elem)
	{
		if(body)
		{
			node<ValType>* temp = body;
			while(temp->next != 0) temp = temp->next;
			temp->next = elem;
		}
		else body = elem;
		elem->next = 0;
	}
	else throw "error";
}

template <class ValType>
void TList<ValType>::Insert(node<ValType>* i, node<ValType>* elem)
{
	if(elem && i)
	{
		elem->next = i->next;
		i->next = elem;
	}
	else throw "error";
}



template <class ValType>
void TList<ValType>::DeleteAtBegin()
{
	if(body)
	{
		node<ValType>* temp = body;
		body = body->next;
		delete temp;
	}
}

template <class ValType>
void TList<ValType>::DeleteAtEnd()
{
	if(body)
	{
		if(body->next)
		{
			node<ValType>* temp = body;
			while(temp->next->next) temp = temp->next;
			delete temp->next;
			temp->next = 0;
		}
		else
		{
			delete body;
			body = 0;
		}
	}
}

template <class ValType>
void TList<ValType>::Delete(node<ValType>* elem)
{
	if(elem && elem->next)
	{
		node<ValType>* temp = elem->next;
		elem->next = elem->next->next;
		delete temp;
	}
}

template <class ValType>
node<ValType>* TList<ValType>::Search(ValType a)
{
	if(body)
	{
		node<ValType>* temp = body;
		while(temp && temp->data != a) temp = temp->next;
		return temp;
	}
	else return false;
}


#endif






















































































































































// ^_^ :) :3:3:3