#ifndef LIST_H
#define LIST_H

#include <iostream>

#ifndef NODE
#define NODE node<T>
#endif

template <class T>
struct node{

	NODE *next;
	T data;
};


template <class T>
class list{

	private:
		NODE *head;	
	
	public:

		void _insert(T data);
		void _delete(T data);
		void _delete(int index);
		void printList();
	
		 list();
		~list();
	
};

#include "list.cpp"

#endif
