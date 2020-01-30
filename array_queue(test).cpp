//array_queue.cpp
#include <iostream>
#include "array_queue.h"

using std::cout;
using std::cin;
using std::endl;

int main(void)
{
	ArrayQueue<int> que;
	cout << que.isEmpty() << endl;
	int num = 5;
	que.enqueue(num);
	cout << que.isEmpty() << endl;
	que.enqueue(8);
	cout << que.firstEl() << endl;
	que.dequeue();
	cout << que.firstEl() << endl;
	que.clear();
	cout << que.isEmpty() << endl; 
	 	
	return 0;
 } 
