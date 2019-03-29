#include <ncurses.h>

#include "Character.h"

int main() {
	initscr();
	noecho();
	Character *greg = new Character('g',1,1);
	WINDOW *win = newwin(10,20,5,10);
	box(win,0,0);
	int max_y, max_x;
	getmaxyx(win,max_y,max_x);
	mvwaddch(win,greg->row(),greg->col(),greg->symbol());
	char input;
	do {
		input = wgetch(win);
		mvwaddch(win,greg->row(),greg->col(),'.');
		switch(input) {
			case 'w':
				if( greg->row()-1 > 0 )
					greg->pos( greg->row()-1, greg->col() );
				break;
			case 's':
				if( greg->row()+1 < max_y-1 )
					greg->pos( greg->row()+1, greg->col() );
				break;
			case 'a':
				if( greg->col()-1 > 0 )
					greg->pos( greg->row(), greg->col()-1 );
				break;
			case 'd':
				if( greg->col()+1 < max_x-1 )
					greg->pos( greg->row(), greg->col()+1 );
				break;
		}
		mvwaddch(win,greg->row(),greg->col(),greg->symbol());
	} while(input != 'q');
	//getch();
	endwin();
}
