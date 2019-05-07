#include <ncurses.h>
#include <cstdlib>

#include "map_loader.h"

#define FILENAME "basic_map.dat"

int main() {
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	
	int y,x;
	getmaxyx(stdscr,y,x);

	//int pad_y = y*1.5, pad_x = x*1.5;

	int ypos = 0, xpos = 0;
	int c_ypos = 1, c_xpos = 3;

	map_loader dan;

	WINDOW *map = dan.load_map(FILENAME);

	/*
	//fill pad pls
	srand(0);
	for(int i=0;i<pad_y;i++) {
		for(int j=0;j<pad_x;j++) {
			if(i==0 || j==0 || i==pad_y-1 || j==pad_x-1) { //border
				mvwaddch(map,i,j,'#');
			} else {
				switch(rand()%10) {
				case 0:
				case 1:
				case 2:
					mvwaddch(map,i,j,'^');
					break;
				default:
					mvwaddch(map,i,j,'.');
					break;
				}
			}
		}
	}
	*/

	mvwaddch(map,c_ypos,c_xpos,'@');
	refresh();
	prefresh(map,ypos,xpos,0,0,y-1,x-1);
	
	//input loop
	char in;
	do {
		in = getch();

		switch(in) {
		case 'w':
			if(ypos>0 && c_ypos-ypos == y/2) ypos --;
			if(mvwinch(map,c_ypos-1,c_xpos) == '.') {
				mvwaddch(map,c_ypos,c_xpos,'.');
				c_ypos --;
				mvwaddch(map,c_ypos,c_xpos,'@');
			}
			break;
		case 's':
			if(ypos+y<dan.gety() && c_ypos-ypos == y/2) ypos ++;
			if(mvwinch(map,c_ypos+1,c_xpos) == '.') {
				mvwaddch(map,c_ypos,c_xpos,'.');
				c_ypos ++;
				mvwaddch(map,c_ypos,c_xpos,'@');
			}
			break;
		case 'a':
			if(xpos>0 && c_xpos-xpos == x/2) xpos --;
			if(mvwinch(map,c_ypos,c_xpos-1) == '.') {
				mvwaddch(map,c_ypos,c_xpos,'.');
				c_xpos --;
				mvwaddch(map,c_ypos,c_xpos,'@');
			}
			break;
		case 'd':
			if(xpos+x<dan.getx() && c_xpos-xpos == x/2) xpos ++;
			if(mvwinch(map,c_ypos,c_xpos+1) == '.') {
				mvwaddch(map,c_ypos,c_xpos,'.');
				c_xpos ++;
				mvwaddch(map,c_ypos,c_xpos,'@');
			}
			break;
		}
		prefresh(map,ypos,xpos,0,0,y-1,x-1);
		//mvderwin(view,ypos,xpos);
		//wrefresh(view);
	} while(in != 'q');

	//wgetch(view); //wait
	endwin();
	return 0;
}
