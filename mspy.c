#include <ncurses.h>

int main(void) {
	MEVENT mort;
	int ch;

	initscr();
	noecho();
	keypad(stdscr,TRUE); //need this for mouse
	curs_set(2); //super cursor?

	mousemask(ALL_MOUSE_EVENTS,NULL);

	do {
		ch = getch();
		if(ch == KEY_MOUSE) {
			getmouse(&mort);
			/*
			move(0,0);
			clrtoeol();
			printw("Mouse clicked at %d, %d",mort.y,mort.x);
			*/
			mvaddch(mort.y,mort.x,'X');
			refresh();
		}
	} while(ch != '\n');

	endwin();
	return 0;
}
