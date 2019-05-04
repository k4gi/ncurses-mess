#include <ncurses.h>

int main(void) {
	WINDOW *p;
	int x,c;

	initscr();

	// create a new pad
	p = newpad(50,100);
	if(p == NULL) {
		addstr("Unable to create new pad");
		refresh();
		getch();
		endwin();

		return 1;
	} else {
		addstr("New pad created");
		refresh();
		getch();
		endwin();

		return 0;
	}
}

