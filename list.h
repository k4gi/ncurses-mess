#ifndef LIST_H
#define LIST_H

#include <string>

struct node {
	char data1,data2;
	node *next;
};

class list {
	node *head;
public:
	list();
	void add(char in1,char in2);
	void remove(char in1,char in2);
	char find(char in);
	std::string show();
};

#endif
