//DLL_QUEUE.h
#ifndef DLL_QUEUE
#define DLL_QUEUE

#include <list> 
using namespace std;

template<typename T>
class DDLQueue 
{
	private:
		list<T> que;
	public:
		DLLQueue() {
			head = tail = 0;
		}
		void clear() {
			que.clear();
		}
		bool isEmpty() {
			return que.empty();
		}
		void enqueue(const T & el) {
			que.push_back(el);
		}
		T dequeue() {
			T temp = que.front();
			que.pop_front();
			return temp;
		}
		T firstEl() {
			return que.front();
		}	
}; 

#endif 
