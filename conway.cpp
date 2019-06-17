#include <ncurses.h>
#include <cstdlib>

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

		if( in == '\n' ) {
			for( int i=0; i<y; i++ ) {
				for( int j=0; j<x; j++ ) {
					if(rand()%4 == 0) grid[i][j] = true;
				}
			}
		}

		bool mark[y][x];

		//mark
		for( int i=0; i<y; i++ ) {
			for( int j=0; j<x; j++ ) {
				int neighbours = 0;
				if(i > 0) {
					if(grid[i-1][j]) neighbours ++;
				}
				if(i < y) {
					if(grid[i+1][j]) neighbours ++;
				}
				if(j > 0) {
					if(grid[i][j-1]) neighbours ++;
				}
				if(j < x) {
					if(grid[i][j+1]) neighbours ++;
				}

				switch( neighbours ) {
				case 0:
				case 1:
				case 4:
					mark[i][j] = false;
					break;
				case 3:
					mark[i][j] = true;
					break;
				case 2:
					mark[i][j] = grid[i][j];
					break;
				}
			}
		}

		//save
		for( int i=0; i<y; i++ ) {
			for( int j=0; j<x; j++ ) {
				grid[i][j] = mark[i][j];

				//print
				if( grid[i][j] ) {
					mvwaddch(stdscr,i,j,'#');
				} else {
					mvwaddch(stdscr,i,j,' ');
				}
			}
		}
	} while( in != 'q' );
	
	endwin();
	return 0;
}

