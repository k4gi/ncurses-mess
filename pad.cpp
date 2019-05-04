#include <ncurses.h>
#include <cstdlib>

#define FILENAME "test_map.dat"

int main() {
	FILE *wfile;
	srand(0);

	initscr();

	int map_y = 300, map_x = 300;
	WINDOW *map = NULL;// = newpad(map_y,map_x);

	int y,x;
	getmaxyx(stdscr,y,x);

	char in = 'q';

	refresh();

	do {
		in = getch();

		switch(in) {
		case 'g':
			//fill window pls
			if(map !=  NULL) delwin(map);
			map = newpad(map_y,map_x);

			for(int i=0;i<map_y;i++) {
				for(int j=0;j<map_x;j++) {
					if(i==0 || j==0 || i==map_y-1 || j==map_x-1) { //border
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
			break;
		case 'i':
			//load map
			//open the file
			wfile = fopen(FILENAME,"r");

			//write the window's data
			map = getwin(wfile);

			fclose(wfile);
			break;
		case 'o':
			//save map
			wfile = fopen(FILENAME,"w");

			putwin(map,wfile);

			fclose(wfile);
			break;
		case 'p':
			//print ... ...
			prefresh(map,0,0,0,0,y-1,x-1);
			//wgetch(map);
			break;
		}
	} while(in != 'q');

	//mvwprintw(map,0,0,"Hello there I'm a pad");

	//prefresh(map,0,0,0,0,y-1,x-1);
	//pnoutrefresh(map,0,0,0,0,y,x);
	//doupdate();

	//wgetch(map);
	//getch();
	endwin();
	return 0;
}
