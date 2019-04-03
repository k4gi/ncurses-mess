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
	if(head != NULL) {
		if( (head->data1 == in1 && head->data2 == in2) || (head->data1 == in2 && head->data2 == in1) ) {
			free(head);
			head = NULL;
		} else {
			node *prev = head;
			node *curr = head->next;
			while(curr != NULL) {
				if( (curr->data1 == in1 && curr->data2 == in2) || (curr->data1 == in2 && curr->data2 == in1) ) {
					prev->next = curr->next;
					free(curr);
					curr = NULL;
				} else {
					prev = curr;
					curr = curr->next;
				}	
			}
		}
	}
}

void list::remove(char in) {
	if(head != NULL) {
		if( head->data1 == in || head->data2 == in ) {
			free(head);
			head = NULL;
		} else {
			node *prev = head;
			node *curr = head->next;
			while(curr != NULL) {
				if( head->data1 == in || head->data2 == in ) {
					prev->next = curr->next;
					free(curr);
					curr = NULL;
				} else {
					prev = curr;
					curr = curr->next;
				}	
			}
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
