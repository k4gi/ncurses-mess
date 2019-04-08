//copied from Dan Gookin - Programmer's Guide to ncurses (2007, Wiley Pub), Listing 9-1

#include <ncurses.h>

int main() {
	WINDOW *sonny;

	initscr();
	start_color(); //remember to check for errors!
	init_pair(1,COLOR_WHITE,COLOR_BLUE);
	init_pair(2,COLOR_RED,COLOR_YELLOW);

	//create subwindow
	sonny = subwin(stdscr,5,20,10,30);
	if(sonny == NULL) {
		addstr("Unable to create subwindow\n");
		endwin();
		return 1;
	}

	//color windows and splash some text
	bkgd(COLOR_PAIR(1));
	addstr("Hello, son.");
	wbkgd(sonny,COLOR_PAIR(2));
	waddstr(sonny,"Hello, Dad.");
	refresh();
	getch();

	endwin();
	return 0;
}
