//DLList(test).cpp
#include <iostream>
#include "DLList.h"
using std::cout;
using std::endl;

int main(void)
{
	DoublyLinkedList<int> lst;
	cout << lst.isEmpty() << "\n";
	lst.addToDLLHead(1);
	lst.addToDLLTail(2);
	lst.addToDLLTail(3);
	lst.addToDLLTail(4);
	cout << lst.isEmpty() << endl;
	cout << "***********deleteFromHead**********" << endl;
	cout << "Before: " << lst.isInList(1) << endl;
	lst.deleteFromDLLHead();
	cout << "After: " << lst.isInList(1) << endl;
	cout << "***********deleteFromTail**********" << endl;
	cout << "Before: " << lst.isInList(4) << endl;
	lst.deleteFromDLLTail();
	cout << "After: " << lst.isInList(4) << endl;
	cout << "***********deleteNode**********" << endl;
	cout << "Before: " << lst.isInList(2) << endl;
	lst.deleteDLLNode(2);
	cout << "After: " << lst.isInList(2) << endl;
	cout << "***********end**********" << endl;
	cout << lst.isInList(3);
	
	return 0;
}
