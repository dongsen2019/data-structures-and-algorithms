//stack-vect.cpp
#include <iostream>
#include "stack-vect.h"

using namespace std;

int main(void)
{
	Stack<int> arr;
	cout << arr.isEmpty() << endl;
	arr.push(5);
	cout << "After push 5" << endl << arr.isEmpty() << endl;
	arr.push(6);
	cout << arr.topEI() << endl;
	arr.push(7);
	cout << arr.topEI() << endl;
	arr.push(8);
	cout << arr.topEI() << endl;
	arr.push(9);
	cout << arr.topEI() << endl;
	arr.pop();
	cout << arr.topEI() << endl;
	arr.clear();
	cout << arr.isEmpty() <<endl;
	
	return 0;
}
