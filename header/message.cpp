#include <string>
#include <ctime>

using std::string;
using std::istream;
using std::ostream;
using std::endl;

bool Message::operator > (Message &m)
	{
		if(this->m_time > m.m_time)
			return true;
		else
			return false;	
	}

bool Message::operator < (Message &m)
	{
		if(this->m_time < m.m_time)
			return true;
		else
			return false;	
	}

bool Message::operator == (Message &m)
	{
		if(this->msg == m.msg)
			return true;
		else
			return false;
	}	

bool Message::operator == (string s)
	{
		if(this->msg == s)
			return true;
		else
			return false;
	}
	
istream& operator >> (istream& in, Message m)
	{
		in >> m.msg;
		return in;	
	}
	
ostream& operator << (ostream& out,Message m)
	{
		struct tm* curr_time = localtime(&m.m_time);
		
		out << asctime(curr_time) << "   " << m.msg << endl;
		return out;
	}
	
Message::Message()
	{
		msg = "";
		time(&m_time);
	}

Message::Message(string inp)
	{
		msg = inp;
		time(&m_time);
	}
