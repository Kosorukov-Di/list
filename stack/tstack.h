#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include "../list/tlist.h"

using namespace std;

template <class ValType>
class TStack: public TList<ValType>
{
public:
	TStack();						// ???????????
	TStack(const TStack &st);		// ??????????? ???????????

	void Push(const ValType elem);	// ???????? ??????? ? ????
	void Clr();						// ?Ö?????? ????
	ValType Pop();					// ?????Ö? ??????? ?? ?????
	ValType Top();					// ???????????? ??????? ?????

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
		/* 
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
		*/
		
		node<ValType>* temp = st.body;
		body = temp;
		while(temp->next)
		{
			TList<ValType>::InsertAtBegin(temp->next);
			temp = temp->next;
		}
	}
	else body = 0;
}

template <class ValType>
void TStack<ValType>::Push(const ValType elem)
{

	TList<ValType>::InsertAtBegin(new node<ValType>(elem));
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
		delete body;
	}
	body = 0;
}

template <class ValType>
ValType TStack<ValType>::Pop()
{
	if(body)
	{
		ValType res = body->data;
		TList<ValType>::DeleteAtBegin();
		return res;
	}
	else throw "Stack is empty";
}

template <class ValType>
ValType TStack<ValType>::Top()
{
	if(body)
	{
		ValType res = body->data;
		return res;
	}
	else throw "Stack is empty";
}

#endif






















































































































































// ^_^ :) :3:3:3