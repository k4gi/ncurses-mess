#include "list.h"

list::list() {
	head = NULL;
}

void list::add(char in1,char in2) {
	node * newnode = new node;
	newnode->data1 = in1;
	newnode->data2 = in2;
	newnode->next = NULL;
	if(head == NULL) head = newnode;
	else {
		node *temp = head;
		while(temp->next != NULL) temp = temp->next;
		temp->next = newnode;
	}
}

void list::remove(char in1,char in2) {
	node *prev;
	node *curr = head;
	while(curr != NULL) {
		if( (curr->data1 == in1 && curr->data2 == in2) || (curr->data1 == in2 && curr->data2 == in1) ) {
			prev->next = curr->next;
			curr = NULL;
		} else {
			prev = curr;
			curr = curr->next;
		}
	}
}

void list::remove(char in) {
	node *prev;
	node *curr = head;
	while(curr != NULL) {
		if( curr->data1 == in || curr->data2 == in ) {
			prev->next = curr->next;
			curr = NULL;
		} else {
			prev = curr;
			curr = curr->next;
		}
	}
}

char list::find(char in) {
	node *temp = head;
	char out = ' ';
	while(temp != NULL) {
		if(temp->data1 == in) {
			out = temp->data2;
			temp = NULL;
		} else if(temp->data2 == in) {
			out = temp->data1;
			temp = NULL;
		} else {
			temp = temp->next;
		}
	}
	return out;
}

std::string list::show() {
	node *temp = head;
	std::string out = "";
	while(temp != NULL) {
		out.append("%c%c;",temp->data1,temp->data2);
		temp = temp->next;
	}
	return out;
}
