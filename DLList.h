//DLList.h
#ifndef DLLIST_H_
#define DLLIST_H_

template<typename T>
class DLLNode {
	public:
		T item;
		DLLNode * prev;
		DLLNode * next;
		DLLNode() {
			prev = 0;
			next = 0;
		}
		DLLNode(const T & el, DLLNode * p = 0, DLLNode * n = 0) {
			item = el;
			prev = p;
			next = n;
		}
};

template<typename T>
class DoublyLinkedList {
	private:
		DLLNode<T> * head;
		DLLNode<T> * tail;
	public:
		DoublyLinkedList() {
			head = 0;
			tail = 0;
		}
		~DoublyLinkedList();
		bool isEmpty() {
			return (head == 0);
		}
		void addToDLLHead(const T & el);
		void addToDLLTail(const T & el);
		T deleteFromDLLHead();
		T deleteFromDLLTail();
		void deleteDLLNode(const T & el);
 		bool isInList(const T & el) const;
};

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	DLLNode<T> * temp = head;
	while (head != 0)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}

template<typename T>
void DoublyLinkedList<T>::addToDLLHead(const T & el)
{
	DLLNode<T> * temp = new DLLNode<T>(el);
	if (isEmpty())
	{
		head = temp;
		tail = temp;
	}
	else
	{
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
}

template<typename T>
void DoublyLinkedList<T>::addToDLLTail(const T & el)
{
	DLLNode<T> * temp = new DLLNode<T>(el);
	if (isEmpty())
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
}

template<typename T>
T DoublyLinkedList<T>::deleteFromDLLHead()
{
	T hel = head->item;
	if (head == tail)
	{
		delete head;
		head = tail = 0;
	}
	else
	{
		DLLNode<T> * hptr = head;
		head = head->next;
		head->prev = 0;
		delete hptr;
	}

	return hel;
}

template<typename T>
T DoublyLinkedList<T>::deleteFromDLLTail()
{
	T tel = tail->item;
	if(head == tail)
	{
		delete head;
		head = tail = 0;
	}
	else
	{
		DLLNode<T> * tptr = tail;
		tail = tail->prev;
		tail->next = 0;
		delete tptr;
	}

	return tel;
}

template<typename T>
void DoublyLinkedList<T>::deleteDLLNode(const T & el)
{
	if (!isEmpty())
	{
		if (head == tail && (el == head->item))
		{
			delete head;
			head = tail = 0;
		}
		else if (el == head->item)
		{
			DLLNode<T> * hptr = head;
			head = head->next;
			head->prev = 0;
			delete hptr;
		}
		else if (el == tail->item)
		{
			DLLNode<T> * tptr = tail;
			tail = tail->prev;
			tail->next = 0;
			delete tptr;
		}
		else
		{
			DLLNode<T> * p;
			DLLNode<T> * c;
			p = head, c = head->next;
			while((el != c->item) && (c != 0))
			{
				p = p->next;
				c = c->next;
			}
			if (c != 0)
			{
				p->next = c->next;
				p->next->prev = p;
				delete c;
			}
		}
	}
}

template<typename T>
bool DoublyLinkedList<T>::isInList(const T & el) const
{
	DLLNode<T> * temp = head;
	while (temp != 0 && (temp->item != el))
		temp = temp->next;
	return (temp != 0);
}

#endif
