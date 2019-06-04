#include <ncurses.h>

int main() {
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	timeout(100);

	int y,x;
	getmaxyx(stdscr,y,x);

	int ypos = y/2, xpos = x/2;
	mvaddch(ypos, xpos, 'O');

	int dir = 0;

	char in;
	do {
		refresh();

		in = getch();

		switch(dir) {
		case 0:
			if(ypos-1 >= 0) {
				mvaddch(ypos, xpos, ' ');
				ypos --;
				mvaddch(ypos, xpos, 'O');
			} else {
				dir = 1;
			}
			break;
		case 1:
			if(xpos+1 < x) {
				mvaddch(ypos, xpos, ' ');
				xpos ++;
				mvaddch(ypos, xpos, 'O');
			} else {
				dir = 2;
			}
			break;
		case 2:
			if(ypos+1 < y) {
				mvaddch(ypos, xpos, ' ');
				ypos ++;
				mvaddch(ypos, xpos, 'O');
			} else {
				dir = 3;
			}
			break;
		case 3:
			if(xpos-1 >= 0) {
				mvaddch(ypos, xpos, ' ');
				xpos --;
				mvaddch(ypos, xpos, 'O');
			} else {
				dir = 0;
			}
			break;
		}

		if(in == '\n') {
			dir ++;
			if(dir > 3) dir = 0;
		}
	} while(in != 'q');

	endwin();
	return 0;
}

