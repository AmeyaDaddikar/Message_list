#include <iostream>
#include "header/list.h"
#include "header/message.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	list<Message> mylist;
	int option = 0;

	cout << "UMessage1.0 MESSAGE LIST" << endl;
	
	do
	{
		string p;
		
		cout << "0 --- EXIT" << endl;
		cout << "1 --- ADD MESSAGE" << endl;
		cout << "2 --- VIEW MESSAGES" << endl;
		cout << "3 --- DELETE MESSAGE (by message content)" << endl;
		cout << "4 --- DELETE MESSAGE (by message index)" << endl;
		
		cin >> option;
		
		switch(option)
		{
		case 0 :
			break;

		case 1 :
			cin.ignore();
			getline(cin,p);
			mylist._insert(*(new Message(p)));		
			break;

		case 2 :
			mylist.printList();
			break;
			
		case 3 :
			cin.ignore();		
			getline(cin,p);		
			mylist._delete(*(new Message(p)));
			break;
		
		case 4 :
			int index;
			cin >> index;
			mylist._delete(index);
			break;
		
		default :
			cout << "INVALID OPTION, CHOOSE AGAIN" << endl;							
		}
	}while(option != 0);
	
		cout << "THANK YOU FOR USING UMessage1.0" <<endl;
	return 0;
}
