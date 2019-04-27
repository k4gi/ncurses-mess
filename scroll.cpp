#include <ncurses.h>

/*
	apparently there are these functions you can use for scrolling windows
	int scroll(WINDOW *win);
	int scrl(int n);
	int wscrl(WINDOW *win, int n);
	and you gotta call scrollok() first
	but is this the kind of scrolling I want? seems like it only scrolls up :(
	https://www.mkssoftware.com/docs/man3/curs_scroll.3.asp
	just for scrolling output up i guess...
	well lets give it a go
*/

int main() {
	initscr();
	cbreak();
	noecho();
	curs_set(0);

	int y,x;
	getmaxyx(stdscr,y,x);

	WINDOW *side = newwin(y,x/2,0,x/2);
	box(side,0,0);
	scrollok(side,true);

	char in;
	int increment = 0;
	do {
		in = wgetch(side);

		if(in == 'y') {
			wprintw(side,"%d-Line here\n",increment);
			increment ++;
			/*
				this does indeed scroll once it gets to the bottom of the window
				even without using the scroll() functions. just tell a window it's scrolling with scrollok()
			*/
		}
		if(in == 'n') {
			wscrl(side,2); //scroll up two lines?
			//yep, works as expected
		}
	} while( in != 'q');

	endwin();
	return 0;
}
