#ifndef MSG
#define MSG

#include <iostream>
#include <string>
#include <ctime>

using std::string;
using std::istream;
using std::ostream;

class Message{

private:
	string msg;
	time_t m_time;
public:
	
	bool operator >  (Message &m);
	bool operator <  (Message &m);
	bool operator == (Message &m);
	bool operator == (string s);
	
	friend istream& operator >> (istream& in, Message m);
	friend ostream& operator << (ostream& out,Message m);
	
	 Message();
	 Message(string inp);
	//~Message();
	
};

#include "message.cpp"

#endif
