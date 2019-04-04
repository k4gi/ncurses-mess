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

void list::remove(char in) {
	node *curr = head;
	node *prev;
	while( curr != NULL && (curr->data1 == in || curr->data2 == in) ) {
		prev = curr;
		head = curr = curr->next;
		free(prev);
	}
	while( curr != NULL ) {
		if( curr->data1 == in || curr->data2 == in ) {
			prev->next = curr->next;
			free(curr);
			curr = prev->next;
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
		out.append(1,temp->data1);
		out.append(1,temp->data2);
		out.append(1,';');
		temp = temp->next;
	}
	return out;
}
