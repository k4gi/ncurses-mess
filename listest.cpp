#include <ncurses.h>
#include <string>

#include "list.h"

int main() {
	initscr();
	printw("screen init\n");

	list mag;
	printw("list declared\n");

	mag.add('a','b');
	printw("node add\n");

	mag.add('b','c');
	printw("node add again\n");

	printw("find b: %c\n",mag.find('b'));

	printw("find c: %c\n",mag.find('c'));

	getch();

	printw(mag.show().c_str());

	getch();

	mag.remove('a','b');
	printw("removed ab\n");

	mag.remove('b');
	printw("removed b\n");

	getch();
	endwin();
	return 0;
}

