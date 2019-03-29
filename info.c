#include <ncurses.h>

int main() {
	initscr();

	
	int c_y, c_x, min_y, min_x, max_y, max_x;
	getyx(stdscr, c_y, c_x);
	getbegyx(stdscr, min_y, min_x);
	getmaxyx(stdscr, max_y, max_x);
	//printw("%d %d %d %d %d %d", c_y, c_x, min_y, min_x, max_y, max_x);

	WINDOW *left_win = newwin(5,10,0,0);
	WINDOW *right_win = newwin(5,10,0,25);

	box(left_win, 0, 0);
	box(right_win,0,0);
	refresh();
	wrefresh(left_win);
	wrefresh(right_win);

	int ly,lx,ry,rx;
	getmaxyx(left_win,ly,lx);
	getmaxyx(right_win,ry,rx);
	mvwprintw(left_win,1,1,"%d %d",ly,lx);
	mvwprintw(right_win,1,1,"%d %d",ry,rx);
	
	refresh();
	wrefresh(left_win);
	wrefresh(right_win);
	
	//menu code?
	int hl = 0;
	//keypad(left_win,true);
	while(1) {
		for(int i=0;i<3;i++) {
			if(i == hl) wattron(left_win,A_REVERSE);
			mvwprintw(left_win,i+1,1,"menuopt");
			wattroff(left_win,A_REVERSE);
		}
		char in = wgetch(left_win);
		if( in == 'a') break; else {
			switch(in) {
				case 'w':
					hl --;
					if(hl==-1) hl=0;
					break;
				case 's':
					hl ++;
					if(hl==3) hl=2;
					break;
				case 'd':
					mvwprintw(right_win,1,1,"hl=%d",hl);
					wrefresh(right_win);
					break;
			}
		}
	}

	
	
	//getch();
	endwin();
	return 0;
}
