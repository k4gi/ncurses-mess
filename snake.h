#ifndef SNAKE_H
#define SNAKE_H

#include <ncurses.h>

struct segment {
	int id; //0 for head, 1 for body, 2 for tail
	int ypos,xpos; //current co-ordinates
	segment *next; //a snake is kind of like a linked list
};

class snake {
	segment *head;
	char symbols[3] = {'.','#','/'}; //blank, body, tail
	char head_symbols[4] = {'^','>','v','<'}; //imaginitive names here

	void shunt(WINDOW *win);
	void shunt_step(WINDOW *win, segment *prev);
	void add_body(WINDOW *win);
public:
	snake(int y,int x,int dir);
	void place(WINDOW *win); //just draw the snake where it is
	void move(WINDOW *win, int dir);
	void grow(WINDOW *win, int dir);
	int track(WINDOW *win, int ypos, int xpos);
	void print(WINDOW *win);
	void delete_snake();
};

#endif
