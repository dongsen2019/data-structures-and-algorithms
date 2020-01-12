//intSLList(test).cpp
#include <iostream>
#include "intSLList.h"
using std::cout;
using std::endl;

int main(void)
{
	IntSLList lst;
	cout << lst.isEmpty() << "\n";
	lst.addToHead(1);
	lst.addToTail(2);
	lst.addToTail(3);
	lst.addToTail(4);
	cout << lst.isEmpty() << endl;
	cout << "***********deleteFromHead**********" << endl;
	cout << "Before: " << lst.isInList(1) << endl;
	lst.deleteFromHead();
	cout << "After: " << lst.isInList(1) << endl;
	cout << "***********deleteFromTail**********" << endl;
	cout << "Before: " << lst.isInList(4) << endl;
	lst.deleteFromTail();
	cout << "After: " << lst.isInList(4) << endl;
	cout << "***********deleteNode**********" << endl;
	cout << "Before: " << lst.isInList(2) << endl;
	lst.deleteNode(2);
	cout << "After: " << lst.isInList(2) << endl;
	cout << "***********end**********" << endl;
	cout << lst.isInList(3);
	
	return 0;
}
