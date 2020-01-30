//array_queue.h 
#ifndef ARRAY_QUEUE
#define ARRAY_QUEUE

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

template<typename T, int size = 10>
class ArrayQueue
{
	private:
		int first, last;
		T storage[size];
	public:
		ArrayQueue() {
			first = last = -1;
		}
		void clear() {
			first = last = -1;
		}
		bool isFull() {
			return ( (first == 0 && last == size - 1) || first == last + 1 );
		}
		bool isEmpty() {
			return first == -1;
		}
		T firstEl() {
			return storage[first];
		}
		void enqueue(const T & el);
		T dequeue();
};

template<typename T, int size>
void ArrayQueue<T,size>::enqueue(const T & el) {
	if(!isFull())
	{
		if(last = -1 || last == (size - 1))
		{
			storage[0] = el;
			last = 0;
			if(first == -1)
				first = 0;
		}
		else storage[++last] = el;
	}
	else cout << "Full queue.\n";
}

template<typename T, int size>
T ArrayQueue<T,size>::dequeue() {
	T temp = storage[first];
	if (first == last)
		first = last = -1;
	else if (first == size -1)
		first = 0;
	else
		first++;
	return temp;	
}

#endif
