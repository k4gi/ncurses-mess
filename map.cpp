#include <ncurses.h>
#include <string>

int main() {
	initscr();

	WINDOW *bigmap = newwin(100,100,0,0);
	WINDOW *view = subwin(bigmap,10,10,10,10);
	box(bigmap,0,0);
	box(view,0,0);
	wrefresh(bigmap);
	wrefresh(view);
	
	refresh();

	getch();
	endwin();
	return 0;
}
