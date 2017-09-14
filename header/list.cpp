#include <cstdlib>
#define TEMPLATE template<class T>
#define LIST list<T>

#ifndef NODE
#define NODE node<T>
#endif

using std::cout;
using std::endl;

TEMPLATE
void LIST:: _insert(T data)
	{
		NODE *new_node = new NODE();
		new_node->data = data;
		new_node->next = NULL;
		
		NODE *curr = head;
		NODE *prev = NULL;
		
		while(curr != NULL)
			if(curr->data < data)
				break;
			else
			{
				prev = curr;
				curr = curr->next;
			}
		
		if(prev == NULL)
		{
			new_node->next = head;
					head = new_node;
		}
		else
		{
			new_node->next  = prev->next;
				prev->next = new_node;
		}	
			
	}

TEMPLATE
void LIST:: _delete(T data)
	{
		NODE *temp;		
		NODE *curr = head;
		NODE *prev = NULL;
		
		while(curr != NULL)
			if(curr->data == data)
				break;
			else
			{
				prev = curr;
				curr = curr->next;
			}
		
		if(prev == NULL)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
		else if(curr != NULL)
		{
			prev->next = curr->next;
			delete curr;
		}	
	}

TEMPLATE
void LIST:: _delete(int index)
	{
		NODE *temp;		
		NODE *curr = head;
		NODE *prev = NULL;
		
		int i = 0;
		while(curr != NULL)
			if(i == index)
				break;
			else
			{
				prev = curr;
				curr = curr->next;
				i++;
			}
			
		if(i == index)
		{
			if(prev == NULL)
			{
				temp = head;
				head = head->next;
				delete temp;
			}
			else if(curr != NULL)
			{
				prev->next = curr->next;
				delete curr;
			}
		}	
	}

TEMPLATE
void LIST::printList()
	{
		int i = 0;
		
		NODE *curr = head;
		
		while(curr != NULL)
		{
			cout << endl << i++ << "::" << endl;
			cout << curr->data << endl;
			curr = curr->next;
		}
	
	}
	
TEMPLATE
LIST::list()
	{
		head = NULL;
	}
	
TEMPLATE
LIST::~list()
	{
		NODE *curr_node = head;
		NODE *temp_node;
		
		while(curr_node != NULL)
		{
			temp_node = curr_node;
			curr_node = curr_node->next;
			delete temp_node;			
		}
	}	

