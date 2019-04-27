#include <ncurses.h>
#include <cstdlib>

/*
	so i want any top-down games i end up making to scroll the map and keep the player in the centre.
	all signs point to this not being a native feature of ncurses, :(
	but look!
	http://www.roguebasin.com/index.php?title=Scrolling_map
	the algorithm is here.
	it's simple and i think maybe i've even done this before? but
	yeah, lots of programming stuff is simple. when you know how. otherwise it's horribly confusing.
*/

int main() {
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	
	int y,x;
	getmaxyx(stdscr,y,x);

	int ypos = y/2-10, xpos = x/2-10;
	int ywidth = 20, xwidth = 20;

	WINDOW *map = newwin(y,x,0,0);
	WINDOW *view = subwin(map,ywidth,xwidth,ypos,xpos);

	//fill window pls
	srand(0);
	for(int i=0;i<y;i++) {
		for(int j=0;j<x;j++) {
			if(i==0 || j==0 || i==y-1 || j==x-1) { //border
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
	
	//input loop
	char in;
	do {
		in = wgetch(view);

		switch(in) {
			case 'w':
				if(ypos>0) ypos --;
				break;
			case 's':
				if(ypos+ywidth<y) ypos ++;
				break;
			case 'a':
				if(xpos>0) xpos --;
				break;
			case 'd':
				if(xpos+xwidth<x) xpos ++;
				break;
		}
		mvderwin(view,ypos,xpos);
		wrefresh(view);
	} while(in != 'q');

	//wgetch(view); //wait
	endwin();
	return 0;
}
