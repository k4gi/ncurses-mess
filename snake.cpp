#include "snake.h"


void snake::shunt(WINDOW *win) { //every snake segment moves forward (except the head)
	//due to being dumb this puts every segment in the same position :)
	//if I make this function recursive i can get the changes to happen at the tail end first??
	//maybe it would be easier to make the snake double-linked though
	//recursion it is
	
	shunt_step(win,head);
}

void snake::shunt_step(WINDOW *win, segment *prev) {
	segment *curr = prev->next;
	if(curr != NULL) {
		shunt_step(win,curr); //recursion!!
		if(curr->next == NULL) mvwaddch(win,curr->ypos,curr->xpos,symbols[0]); //vacate
		curr->ypos = prev->ypos;
		curr->xpos = prev->xpos;
		mvwaddch(win,curr->ypos,curr->xpos,symbols[curr->id]); //redraw
	}
}

void snake::add_body(WINDOW *win) {
	segment *body = new segment;
	body->id = 1;
	body->ypos = head->ypos;
	body->xpos = head->xpos;
	body->next = head->next;
	head->next = body;

	mvwaddch(win,body->ypos,body->xpos,symbols[body->id]);
}

snake::snake(int y,int x,int dir) {
	head->id = 0;
	head->ypos = y;
	head->xpos = x;

	segment *tail = new segment;
	tail->id = 2;
	switch(dir) {
	case 0: //north
		tail->ypos = y+1;
		tail->xpos = x;
		break;
	case 1: //east
		tail->ypos = y;
		tail->xpos = x-1;
		break;
	case 2: //south
		tail->ypos = y-1;
		tail->xpos = x;
		break;
	case 3: //west
		tail->ypos = y;
		tail->xpos = x+1;
		break;
	}
	tail->next = NULL;
	head->next = tail;
}

void snake::place(WINDOW *win) { //just draw the snake where it is
	segment *curr = head;

	if(curr->id == 0) { //it bloody well ought to be but whatever
		if(     curr->ypos < curr->next->ypos) mvwaddch(win,curr->ypos,curr->xpos,head_symbols[0]);
		else if(curr->xpos > curr->next->xpos) mvwaddch(win,curr->ypos,curr->xpos,head_symbols[1]);
		else if(curr->ypos > curr->next->ypos) mvwaddch(win,curr->ypos,curr->xpos,head_symbols[2]);
		else if(curr->xpos < curr->next->xpos) mvwaddch(win,curr->ypos,curr->xpos,head_symbols[3]);

		curr = curr->next;
	}

	while(curr != NULL) {
		mvwaddch(win,curr->ypos,curr->xpos,symbols[curr->id]);
		curr = curr->next;
	}
}

int snake::move(WINDOW *win, int dir) {
	//shunt snake forward
	//then move head and draw
	int y,x,out=1;
	getmaxyx(stdscr,y,x);
	switch(dir) {
	case 0: //north
		if(head->ypos > 0 && mvwinch(win,head->ypos -1,head->xpos) != '#') {
			shunt(win);
			head->ypos --;
			out=0;
		}
		break;
	case 1: //east
		if(head->xpos < x-1 && mvwinch(win,head->ypos,head->xpos +1) != '#') {
			shunt(win);
			head->xpos ++;
			out=0;
		}
		break;
	case 2: //south
		if(head->ypos < y-1 && mvwinch(win,head->ypos +1,head->xpos) != '#') {
			shunt(win);
			head->ypos ++;
			out=0;
		}
		break;
	case 3: //west
		if(head->xpos > 0 && mvwinch(win,head->ypos,head->xpos -1) != '#') {
			shunt(win);
			head->xpos --;
			out=0;
		}
		break;
	}
	mvwaddch(win,head->ypos,head->xpos,head_symbols[dir]);
	return out;
}

int snake::grow(WINDOW *win, int dir) {
	//do not shunt the snake
	//instead add a new body piece right behind the head
	int y,x,out=1;
	getmaxyx(stdscr,y,x);
	switch(dir) {
	case 0: //north
		if(head->ypos > 0 && mvwinch(win,head->ypos -1,head->xpos) != '#') {
			add_body(win);
			head->ypos --;
			out=0;
		}
		break;
	case 1: //east
		if(head->xpos < x-1 && mvwinch(win,head->ypos,head->xpos +1) != '#') {
			add_body(win);
			head->xpos ++;
			out=0;
		}
		break;
	case 2: //south
		if(head->ypos < y-1 && mvwinch(win,head->ypos +1,head->xpos) != '#') {
			add_body(win);
			head->ypos ++;
			out=0;
		}
		break;
	case 3: //west
		if(head->xpos > 0 && mvwinch(win,head->ypos,head->xpos -1) != '#') {
			add_body(win);
			head->xpos --;
			out=0;
		}
		break;
	}
	mvwaddch(win,head->ypos,head->xpos,head_symbols[dir]);
	return out;
}

int snake::track(WINDOW *win, int ypos, int xpos) { //moving towards a target
	/*
		return: 0 for successful move
			1 for failure
			2 for finding target and growing
	*/
	int out = 1;

	//lets just prioritise north/south
	if(head->ypos > ypos) { //north
		if(head->ypos -1 == ypos && head->xpos == xpos) { //target reached
			grow(win,0);
			out = 2;
		} else {
			move(win,0);
			out = 1;
		}
	} else if(head->ypos < ypos) { //south
		if(head->ypos +1 == ypos && head->xpos == xpos) {
			grow(win,2);
			out = 2;
		} else {
			move(win,2);
			out = 1;
		}
	} else if(head->xpos > xpos) { //west
		if(head->xpos -1 == xpos && head->ypos == ypos) {
			grow(win,3);
			out = 2;
		} else {
			move(win,3);
			out = 1;
		}
	} else if(head->xpos < xpos) { //east
		if(head->xpos +1 == xpos && head->ypos == ypos) {
			grow(win,1);
			out = 2;
		} else {
			move(win,1);
			out = 1;
		}
	}
	
	//oh no i'm stuck i'd better try and find a way around myself
	if(out == 1) {
		//find the snake's corners to go around?
		/*
			a corner is a segment where
			one of its neighbours has the same ypos and a different xpos
			and the other has a different ypos and the same xpos
		*/
	}		
		
	return out;
}

int *snake::find_corner() {
	segment *prev = head;
	segment *curr = head->next;
	int out[2] = {-1,-1};

	while(curr->next != NULL) {
		//searching
	}
	//i guess the end counts as a corner?
	//idk whatever
	return out;
}

int *snake::find_next_corner(int y,int x) {
	segment *prev = head;
	segment *curr = head->next;
	int out[2] = {-1,-1};

	while(curr->next != NULL && curr->ypos != y && curr->xpos != x) {
		//skip through
		prev = curr;
		curr = curr->next;
	}

	while(curr->next != NULL) {
		//searching
	}

	return out;
}

void snake::print(WINDOW *win) { //debug
	int iterations = 0;
	for(segment *curr = head; curr != NULL; curr = curr->next) {
		mvwprintw(win, iterations, 0, "%d %c y%d x%d", iterations, symbols[curr->id], curr->ypos, curr->xpos);
		iterations ++;
	}
}

void snake::delete_snake() { //free all the memory, only run at the end pls
	segment *prev = head;
	segment *curr = head->next;

	while(curr != NULL) {
		prev->next = curr->next;
		delete curr;
		curr = prev->next;
	}

	delete curr;
}

int snake::getypos() {
	return head->ypos;
}

int snake::getxpos() {
	return head->xpos;
}
