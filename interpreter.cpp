// interpreter.cpp
#include <cctype>
#include "interpreter.h"

//IdNode friend class
ostream & operator<<(ostream & os, const IdNode & node)
{
	os << node.id << " = " << node.value << endl;
	return os;
}

//statement friend class
ostream & operator<<(ostream & os, const Statement & s)
{
	list<IdNode>::const_iterator itor = s.idList.begin();
	for ( ; itor != s.idList.end() ; itor++)
		os <<  *itor;
	os << endl;
	return os;
}

//Statement private methods
double Statement::findValue(char * s)
{
	IdNode tmp(s);
	list<IdNode>::iterator itor = find(idList.begin(), idList.end(), tmp);
	if (itor != idList.end())
		return itor->value;
	else
		issueError("Unknown variable");
	return 0;
}

void Statement::processNode(char * s, double v)
{
	IdNode tmp(s, v);
	list<IdNode>::iterator itor = find(idList.begin(), idList.end(), tmp);
	if (itor != idList.end())
		itor->value = v;
	else
		idList.push_front(tmp);
}

void Statement::readId(char * s)
{
	int i = 0;
	if (isspace(ch))
	 	cin >> ch;
	if (isalpha(ch))
	{
		while (isalnum(ch))
		{
			s[i] = ch;
			i++;
			cin.get(ch);
		}
		s[i] = '\0';
	}
	else
		issueError("Identifier expected");
}

double Statement::factor()
{
	double var;
	double minus = 1.0;
	char id[200];
	cin >> ch;
	/*
	while(isspace(ch))
		cin >> ch;
	*/
	while(ch == '+' || ch == '-') //正负号
	{
		if (ch == '-')
			minus = -1.0;
		cin >> ch;
	}
	if (isdigit(ch)) //系数
	{
		cin.putback(ch);
		cin >> var >> ch; 
	}
	else if (ch == '(') //嵌套式
	{
		expression();
		if (ch == ')')
			cin >> ch;
		else
			issueError("Right paren left out");
	}
	else
	{
		readId(id);
		if (isspace(ch))
			cin >> ch;
		var = findValue(id);
	}
	return minus * var;
}

double Statement::term()
{
	double f = factor();
	while(true)
	{
		switch(ch)
		{
			case '*' : f *= factor(); break;
			case '/' : f /= factor(); break;
			default : return f;
		}
	}
}

double Statement::expression()
{
	double t = term();
	while(true)
	{
		switch(ch)
		{
			case '+' : t += term(); break;
			case '-' : t -= term(); break;
			default : return t;
		}
	}
}

//Statement public method
void Statement::getStatement()
{
	char id[20], command[20];
	double e;
	cout << "Enter a statement: ";
	cin >> ch;
	readId(id);
	int i;
    for (i = 0; id[i] != '\0'; i++)
    {
        command[i] = toupper(id[i]);
    }
    command[i] = '\0';
	//strupr(strcpy(command, id));
	if (strcmp(command,"PRINT") == 0)
	{
		readId(id);
		cout << id << " = " << findValue(id) << endl;
	}
	else if (strcmp(command,"STATUS") == 0)
	{
		cout << *this;
	}
	else if (strcmp(command,"END") == 0)
	{
		exit(0);
	}
	else
	{
		if (isspace(ch))
			cin >> ch;
		if (ch == '=')
		{
			e = expression();
			if (ch != ';')
				issueError("There are some extras in the statement");
			else
				processNode(id, e);
		}
		else
			issueError("'=' is missing");
	}
}
