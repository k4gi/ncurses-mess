#include <ncurses.h>
#include <string>

std::string getstring(WINDOW *display) {
	std::string input;

	nocbreak();
	echo();

	int ch = mvwgetch(display,1,0);

	while( ch != '\n' ) {
		input.push_back( ch );
		ch = wgetch(display);
	}

	cbreak();
	noecho();

	return input;
}

int main() {
	initscr();
	cbreak();
	noecho();

	int y,x;
	getmaxyx(stdscr,y,x);

	WINDOW *inwin = newwin(5,x,0,0);
	wborder(inwin,' ',' ','=','=','#','#','#','#');
	WINDOW *outwin = newwin(5,x,5,0);
	box(outwin,0,0);

	std::string get = getstring(inwin);

	mvwprintw(outwin,1,1,"%d %s",get.length(),get.c_str());

	wgetch(outwin);
	endwin();
	return 0;
}
