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
	
	mvwaddch(stdscr, 10,10, 97 | A_ALTCHARSET);

	//F
	mvwaddch(stdscr, 10,11, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 10,12, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 10,13, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 10,14, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 11,10, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 12,10, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 13,10, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 14,10, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,10, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 16,10, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 17,10, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 18,10, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,10, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,11, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,12, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,13, 97 | A_ALTCHARSET);
	

	//u
	mvwaddch(stdscr, 15,16, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 16,16, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 17,16, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 18,16, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,16, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,17, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,18, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,19, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,20, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 18,20, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 17,20, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 16,20, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,20, 97 | A_ALTCHARSET);

	//c	
	mvwaddch(stdscr, 15,23, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,24, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,25, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,26, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 16,23, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 17,23, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 18,23, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,23, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,24, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,25, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,26, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,27, 97 | A_ALTCHARSET);

	//k
	mvwaddch(stdscr, 19,30, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 18,30, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 17,30, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 16,30, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,30, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 14,30, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 13,30, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 12,30, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 11,30, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 10,30, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 16,31, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 17,32, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 18,33, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,34, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,32, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,33, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,34, 97 | A_ALTCHARSET);

	//P
	mvwaddch(stdscr, 19,40, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 18,40, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 17,40, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 16,40, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,40, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 14,40, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 13,40, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 12,40, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 11,40, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 10,40, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 10,41, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 10,42, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 10,43, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 10,44, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 10,45, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 11,46, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 12,46, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 13,46, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 14,46, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,45, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,44, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,43, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,42, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,41, 97 | A_ALTCHARSET);
	
	//r
	mvwaddch(stdscr, 19,49, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 18,49, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 17,49, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 16,49, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,49, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 16,50, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,51, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,52, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,53, 97 | A_ALTCHARSET);

	//o
	mvwaddch(stdscr, 18,57, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 17,57, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 16,57, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,58, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,59, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,60, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 16,61, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 17,61, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 18,61, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,60, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,59, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,58, 97 | A_ALTCHARSET);

	//g
	mvwaddch(stdscr, 18,64, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 17,64, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 16,64, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,65, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,66, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,67, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 16,68, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 17,68, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 18,68, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,67, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,66, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,65, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,68, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 20,68, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 21,68, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 22,68, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 23,68, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 24,68, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 25,67, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 25,66, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 25,65, 97 | A_ALTCHARSET);

	//r
	mvwaddch(stdscr, 19,71, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 18,71, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 17,71, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 16,71, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,71, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 16,72, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,73, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,74, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,75, 97 | A_ALTCHARSET);

	//a
	mvwaddch(stdscr, 18,78, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 17,78, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 16,78, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,79, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,80, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,81, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 16,82, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 17,82, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 18,82, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,81, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,80, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,79, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,82, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,83, 97 | A_ALTCHARSET);

	//m
	mvwaddch(stdscr, 19,86, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 18,86, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 17,86, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 16,86, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,87, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,88, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,89, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 16,90, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 17,90, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 18,90, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,91, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,92, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,93, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 16,94, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 17,94, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 18,94, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,94, 97 | A_ALTCHARSET);
	
	//m
	mvwaddch(stdscr, 19,97, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 18,97, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 17,97, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 16,97, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,98, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,99, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,100, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 16,101, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 17,101, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 18,101, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,102, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,103, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,104, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 16,105, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 17,105, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 18,105, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,105, 97 | A_ALTCHARSET);
	
	//i
	mvwaddch(stdscr, 19,108, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 18,108, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 17,108, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 16,108, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,108, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 12,108, 97 | A_ALTCHARSET);
	
	//n
	mvwaddch(stdscr, 19,111, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 18,111, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 17,111, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 16,111, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,111, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,112, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,113, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,114, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 16,115, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 17,115, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 18,115, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,115, 97 | A_ALTCHARSET);
	
	//g
	mvwaddch(stdscr, 18,118, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 17,118, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 16,118, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,119, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,120, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 15,121, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 16,122, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 17,122, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 18,122, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,121, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,120, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,119, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 19,122, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 20,122, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 21,122, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 22,122, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 23,122, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 24,122, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 25,121, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 25,120, 97 | A_ALTCHARSET);
	mvwaddch(stdscr, 25,119, 97 | A_ALTCHARSET);

	getch();
	endwin(); //stop ncurses
	return 0;
}
