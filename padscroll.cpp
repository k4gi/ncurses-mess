#include <ncurses.h>
#include <cstdlib>

#include "map_loader.h"

#define FILENAME "generated_map.dat"

int main() {
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	
	int y,x;
	getmaxyx(stdscr,y,x);

	//int pad_y = y*1.5, pad_x = x*1.5;

	int ypos = 0, xpos = 0; //top left corner of the visible map
	int c_ypos = 1, c_xpos = 3; //position of the player

	map_loader dan;


	int log_width = 40, hp_height = 3; //size of the hud

	int map_start_y = hp_height, map_start_x = 0, map_end_y = y-1, map_end_x = x-log_width-1; //start and end points for drawing the map

	WINDOW *hp_win = newwin(hp_height,x-log_width,0,0);
	WINDOW *log_win = newwin(y,log_width,0,x-log_width);

	box(hp_win,0,0);
	box(log_win,0,0);

	WINDOW *map = dan.load_map(FILENAME);
	
	mvwaddch(map,c_ypos,c_xpos,'@');
	refresh();
	wrefresh(hp_win);
	wrefresh(log_win);
	prefresh(map,ypos,xpos,map_start_y,map_start_x,map_end_y,map_end_x);
	
	//input loop
	char in;
	do {
		in = getch();

		switch(in) {
		case 'w':
			if(ypos>0 && c_ypos-ypos+map_start_y == (map_end_y+1)/2) ypos --;
			if(mvwinch(map,c_ypos-1,c_xpos) == '.') {
				mvwaddch(map,c_ypos,c_xpos,'.');
				c_ypos --;
				mvwaddch(map,c_ypos,c_xpos,'@');
			}
			break;
		case 's':
			if(ypos+(map_end_y+1) < dan.gety() && c_ypos-ypos+map_start_y == (map_end_y+1)/2) ypos ++;
			if(mvwinch(map,c_ypos+1,c_xpos) == '.') {
				mvwaddch(map,c_ypos,c_xpos,'.');
				c_ypos ++;
				mvwaddch(map,c_ypos,c_xpos,'@');
			}
			break;
		case 'a':
			if(xpos>0 && c_xpos-xpos+map_start_x == (map_end_x+1)/2) xpos --;
			if(mvwinch(map,c_ypos,c_xpos-1) == '.') {
				mvwaddch(map,c_ypos,c_xpos,'.');
				c_xpos --;
				mvwaddch(map,c_ypos,c_xpos,'@');
			}
			break;
		case 'd':
			if(xpos+(map_end_x+1) < dan.getx() && c_xpos-xpos+map_start_x == (map_end_x+1)/2) xpos ++;
			if(mvwinch(map,c_ypos,c_xpos+1) == '.') {
				mvwaddch(map,c_ypos,c_xpos,'.');
				c_xpos ++;
				mvwaddch(map,c_ypos,c_xpos,'@');
			}
			break;
		}		
		prefresh(map,ypos,xpos,map_start_y,map_start_x,map_end_y,map_end_x);
		//mvderwin(view,ypos,xpos);
		//wrefresh(view);
	} while(in != 'q');

	//wgetch(view); //wait
	endwin();
	return 0;
}
