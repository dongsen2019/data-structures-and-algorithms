//stack-vect.h
#ifndef STACK_H_
#define STACK_H_

#include <vector>

template<typename T, int capacity = 30>
class Stack
{
	private:
		std::vector<T> pool;
	public:
		Stack() {
			pool.reserve(capacity);
		}
		~Stack() {
			
		} 
		void clear() {
			pool.clear();
		}
		bool isEmpty() {
			return pool.empty();
		}
		void push(const T & el) {
			pool.push_back(el);
		}
		T pop() {
			T temp = pool.back();
			pool.pop_back();
			return temp;
		}
		T topEI() {
			if(!pool.empty())
				return pool.back();
		}
}; 

#endif
