#include <ncurses.h>
#include <string>

int main() {
	initscr(); //init ncurses
	cbreak(); //ctrl-c works
	noecho(); //dont repeat back
	curs_set(0); //no cursor
	
	int y,x;
	getmaxyx(stdscr,y,x); //how much space
	WINDOW *inwin = newwin(5,x,0,0);
	WINDOW *outwin = newwin(5,x,5,0);
	WINDOW *slotwin = newwin(y-15,x/2,10,0);
	WINDOW *plugwin = newwin(y-15,x/2,10,x/2);
	WINDOW *helpwin = newwin(5,x,y-5,0);
	box(inwin,0,0);
	box(outwin,0,0);
	box(slotwin,0,0);
	box(plugwin,0,0);
	box(helpwin,0,0);
	mvwprintw(inwin,0,3,"1:Input window");
	mvwprintw(outwin,0,3,"2:Output window");
	mvwprintw(slotwin,0,3,"3:Slot settings");
	mvwprintw(plugwin,0,3,"4:Plugboard settings");
	mvwprintw(helpwin,0,3,"5:Information");
	mvwprintw(helpwin,1,1,"Press 'q' to exit");
	wrefresh(inwin);
	wrefresh(outwin);
	wrefresh(slotwin);
	wrefresh(plugwin);
	wrefresh(helpwin);

	//time for a menu loop
	char in;
	do {
		in = wgetch(helpwin);
	} while(in != 'q');

	//wgetch(inwin); //temp. wait here
	endwin(); //stop ncurses
	return 0;
}
