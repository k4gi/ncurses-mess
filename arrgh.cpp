#include <ncurses.h>
#include <string>

int main() {
	std::string i_am = "frustrated";
	std::string and_i = "can't concentrate";

	initscr();
	cbreak();
	noecho();
	curs_set(0);

	char in;
	do {
		in = getch();
		switch(in) {
		case 'a':
			printw("aaaaaaaa");
			break;
		case 'q':
			printw("no rest");
			break;
		case 'p':
			printw("tser on");
			break;
		case 't':
			mvprintw(0,0,":");
			break;
		case 'g':
			mvprintw(10,0,":");
			break;
		case 'b':
			mvprintw(20,0,":");
			break;
		}
	} while(in != '.');

	endwin();
	return 0;
}
