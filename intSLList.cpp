//intSLList.cpp
#include <iostream>
#include "intSLList.h"

IntSLList::~IntSLList() 
{
	IntSLLNode * temp;
	while(!isEmpty())
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}

void IntSLList::addToHead(int el)
{
	IntSLLNode * temp = new IntSLLNode(el, head);
	if (isEmpty())
	{
		head = temp;
		tail = head;
	}
	else
	{
		head = temp;
	}	
}

void IntSLList::addToTail(int el)
{
	IntSLLNode * temp = new IntSLLNode(el);
	if (isEmpty())
	{
		head = temp;
		tail = temp;
	} 
	else
	{
		tail->next = temp;
		tail = tail->next;
	}
}

int IntSLList::deleteFromHead()
{
	int el = head->info; 
	IntSLLNode * temp = head;
	if (head == tail)
		head = tail = 0;
	else
		head = head->next;
	delete temp;
	return el;
}

int IntSLList::deleteFromTail()
{
	int el = head->info; 
	IntSLLNode * temp = tail;
	if (tail == head)
		tail = head =0;
	else
	{	
		IntSLLNode * p = head;
		while(p->next != tail)
			p = p->next;
		p->next = 0;
		tail = p;
	}
	delete temp;
	return el;
}

/*
删除节点时需要考虑没有该值(el)的节点、链表为空、
链表只有一个节点以及链表有多个节点el在首节点上
四种情况 
*/ 
void IntSLList::deleteNode(int el)  
{
	if (head != 0)
		if (head == tail && el == head->info)
		{
			IntSLLNode * temp = head;
			head = tail = 0;
			delete temp;
		}
		else if (el == head->info)
		{
			IntSLLNode * temp = head;
			head = head->next;
			delete temp;
		}
		else
		{
			IntSLLNode * pre;
			IntSLLNode * cur = head;
			while(cur != 0 && cur->info != el)
			{
				pre = cur;
				cur = cur->next;
			}
			if (cur != 0)
			{
				pre->next = cur->next;
				if (cur == tail)
					tail = pre;
				delete cur;
			}
		}
}

bool IntSLList::isInList(int el) const
{
	IntSLLNode * temp = head;
	while (temp != 0 && temp->info != el)
		temp = temp->next;
	if (temp != 0)
		return true;
	else
		return false;
}
