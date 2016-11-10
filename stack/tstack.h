#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include "../list/tlist.h"

using namespace std;

template <class ValType>
class TStack: public TList<ValType>
{
public:
	TStack();						// конструктор
	TStack(const TStack &st);		// конструктор копирования

	void Put(const ValType elem);	// добавить элемент в стек
	void Clr();						// очистить стек
	ValType Get();					// извлечь элемент из стека
	ValType Look();					// поросмотреть вершину стека

};

template <class ValType>
TStack<ValType>::TStack() {
	body = 0;
}

template <class ValType>
TStack<ValType>::TStack(const TStack<ValType> &st) 
{
	if(st.body)
	{
		node<ValType>* temp = st.body;
		body = new node<ValType>;
		while(temp->next)
		{
			body->data = temp->data;
			body->next = new node<ValType>;
			
			temp = temp->next;
			body = body->next;
		}
		body->data = temp->data;
		body->next = 0;
	}
	else body = 0;
}

template <class ValType>
void TStack<ValType>::Put(const ValType elem)
{
	node<ValType>* temp = body;
	body = new node<ValType>;
	body->data = elem;
	body->next = temp;
}

template <class ValType>
void TStack<ValType>::Clr()
{
	if (body !=0 )
	{
		node<ValType>* temp;
		while(body->next != 0) 
		{
			temp = body;
			body = body->next;
			delete temp;
		}
	}
	body = 0;
}

template <class ValType>
ValType TStack<ValType>::Get()
{
	if(body)
	{
		node<ValType>* temp = body;
		body = body->next;
		ValType res = temp->data;
		delete temp;
		return res;
	}
	else throw "Stack is empty";
}

template <class ValType>
ValType TStack<ValType>::Look()
{
	if(body)
	{
		node<ValType>* temp = body;
		body = body->next;
		ValType res = temp->data;
		delete temp;
		return res;
	}
	else throw "Stack is empty";
}

#endif