#include <ncurses.h>
#include <string>
#include "snake.h"

void snake_game() {
	int y,x;
	getmaxyx(stdscr,y,x);
	
	snake garry = snake(y/2,x/2,1);

	/*
		a 'snake' has a head that changes direction, and a body and tail that follow behind.
		The body consists of 0 or more tiles. There is always 1 head and 1 tail.
	*/

	srand(0);
	char in;

	//initial position
	garry.place(stdscr);
	do {
		in = getch(); //delay here with timeout()

		if(in == 'g') { //g for grow
			garry.grow(stdscr,rand()%4);
		} else {
			garry.move(stdscr,rand()%4);
		}
	} while(in != 'q');

	//end
	garry.delete_snake();
	//getting seg faults even though i delete the list
	//am i doing it wrong?
	//is it something else?
	//i just don't know...
}

int main() {
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	
	timeout(100); //milliseconds of delay for getch();
	//wtimeout(stdscr,1000); //window version
	
	snake_game();

	endwin();
	return 0;
}
	
