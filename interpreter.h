//interpreter.h
#ifndef INTERPRETER_H_
#define INTERPRETER_H_

#include <iostream>
#include <list>
#include <algorithm>
#include <string.h>

using namespace std;

class IdNode
{
	public:
		friend class Statement;
		friend ostream & operator<<(ostream & os, const IdNode & node);
		IdNode(char * s = "null", double e = 0) {
		    int len = strlen(s);
		    id = new char[len + 1];
			strcpy(id, s);
			value = e;
		}
		bool operator==(const IdNode & node) {
			return strcmp(id,node.id) == 0;
		}
	private:
		char *id;
		double value;
};

class Statement
{
	private:
		list<IdNode> idList;
		char ch;
		double factor();
		double term();
		double expression();
		void readId(char * s);
		void issueError(char * s) {
			cerr << s << endl; exit(1);
		}

		double findValue(char * s);
		void processNode(char * s, double v);
		friend ostream & operator<<(ostream & os, const Statement & s);
	public:
		Statement() {

		}
		void getStatement();
};

#endif
