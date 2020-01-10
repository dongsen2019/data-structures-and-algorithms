//intSLList.h
//		(singly-linked list class to store integers)	
#ifndef INTSLLIST_H_
#define INTSLLIST_H_
class IntSLLNode {
	public:
		int info;
		IntSLLNode * next;
		IntSLLNode() {
			next = 0;
		}
		IntSLLNode(int el, IntSLLNode * ptr = 0): info(el), next(0) { }
};

class IntSLList {
	private:
		IntSLLNode * head;
		IntSLLNode * tail;
	public:
		IntSLList(){
			head = tail = 0;
		}
		~IntSLList();
		void addToHead(const int & el);
		void addToTail(const int & el);
		int deleteFromHead();
		int deleteFromTail();
		void deleteNode(const int & el);
		bool isInList(int & el) const;
};

#endif
