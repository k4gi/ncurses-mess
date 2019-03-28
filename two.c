#include <ncurses.h>

int main() {
	initscr();
	int height = 10;
	int width = 20;
	int start_y = 10;
	int start_x = 10;

	WINDOW *win = newwin(height, width, start_y, start_x);
	refresh();

	//box(win,0,0);
	wborder(win,'l','r','t','b','a','b','c','d');
	mvwprintw(win,1,1, "text time");
	wrefresh(win);

	getch();
	endwin();
	return 0;
}
