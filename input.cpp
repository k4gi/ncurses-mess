#include <ncurses.h>
#include <string>

std::string getstring() {
	std::string input;

	nocbreak();
	echo();

	int ch = getch();

	while( ch != '\n' ) {
		input.push_back( ch );
		ch = getch();
	}

	cbreak();
	noecho();

	return input;
}

int main() {
	initscr();

	std::string get = getstring();

	mvprintw(10,0,get.c_str());

	getch();
	endwin();
	return 0;
}
