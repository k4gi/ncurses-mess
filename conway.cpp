#include <ncurses.h>
#include <cstdlib>

int check_neighbours(int ysize, int xsize, int y, int x, bool g[][xsize]) {
	int out = 0;
	if(y > 0) {
		if(g[y-1][x]) out ++;
	}
	if(y < ysize) {
		if(g[y+1][x]) out ++;
	}
	if(x > 0) {
		if(g[y][x-1]) out ++;
	}
	if(x < xsize) {
		if(g[y][x+1]) out ++;
	}
	return out;
}

void populate(int ysize, int xsize, bool g[][xsize]) {
	for( int i=0; i<ysize; i++ ) {
		for( int j=0; j<xsize; j++ ) {
			if(rand()%4 == 0) g[i][j] = true;
		}
	}
}

int main() {
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	//nodelay();
	
	srand(0);

	int y,x;
	getmaxyx(stdscr,y,x);

	bool grid[y][x];
	for( int i=0; i<y; i++ ) {
		for( int j=0; j<x; j++ ) {
			grid[i][j] = false;
		}
	}

	//game loop
	char in = ' ';
	do {
		in = getch();

		if( in == '\n' ) populate(y, x, grid);

		for( int i=0; i<y; i++ ) {
			for( int j=0; j<x; j++ ) {
				switch( check_neighbours( y, x, i, j, grid ) ) {
				case 0:
				case 1:
				case 4:
					grid[i][j] = false;
					break;
				case 3:
					grid[i][j] = true;
					break;
				}
			}
		}
	} while( in != 'q' );
	
	endwin();
	return 0;
}

