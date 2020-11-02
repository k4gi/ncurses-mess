/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <ncurses.h>
#include <string>
#include <ctime>
#include "list.h"

void clearWindow(WINDOW *win) {
	int y,x;
	getmaxyx(win,y,x);
	for(int i=1;i<y-1;i++) {
		for(int j=1;j<x-1;j++) {
			mvwaddch(win,i,j,' ');
		}
	}
}

void clearLine(WINDOW *win, int liney) {
	int y,x;
	getmaxyx(win,y,x);
	for(int i=1;i<x-1;i++) {
		mvwaddch(win,liney,i,' ');
	}
}

std::string getString(WINDOW *display) {
	std::string input;

	nocbreak();
	echo();
	curs_set(1);

	int ch = mvwgetch(display,1,1);

	while( ch != '\n' ) {
		input.push_back( ch );
		ch = wgetch(display);
	}

	cbreak();
	noecho();
	curs_set(0);

	return input;
}

int main() {
	initscr(); //init ncurses
	cbreak(); //ctrl-c works
	noecho(); //dont repeat back
	curs_set(0); //no cursor
	
	int y,x;
	getmaxyx(stdscr,y,x); //how much space
	
	clock_t time_eye;


	mvwaddstr(stdscr,0,0,"ALEX IS AWAKE . . .");

	mvwaddstr( stdscr , 1 , 0 , std::to_string( time( &time_eye ) ).c_str() ); //good lord this is busy

	getch();
	endwin(); //stop ncurses
	return 0;
}
