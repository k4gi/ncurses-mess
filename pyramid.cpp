//how about a roguelike that takes place in a pyramid? Like that classic game, The Scarab of Ra, which I still haven't figured out how to play on a modern computer. Every level down the map gets bigger. Let's make it out of square rooms, that may or may not be connected to each other. How to randomly generate a level? I've never done that before. Let's give it a go.

#include <ncurses.h>
#include <string>

void draw_room(WINDOW *win,int starty,int startx,int size) {
	//top & bottom
	for(int i=0;i<size;i++) {
		mvwaddch(win,starty,startx+i,'-');
		mvwaddch(win,starty+size-1,startx+i,'-');
	}
	//interior & sides
	for(int i=1;i<size-1;i++) {
		mvwaddch(win,starty+i,startx,'|');
		for(int j=1;j<size-1;j++) {
			mvwaddch(win,starty+i,startx+j,'.');
		}
		mvwaddch(win,starty+i,startx+size-1,'|');
	}
}

void snake_rooms(WINDOW *win,int starty,int startx, int size, int no_rooms) {
	//right...so what i was trying to make is a 'depth-first' maze generator
	//clearly this isn't one yet but it can't be that hard right let's do that
	int y,x;
	getmaxyx(win,y,x);
	for(int i=0;i<no_rooms;i++) {
		if( startx + (i+1)*size < x ) {
			draw_room(win, starty, startx + i*size, size);
		} else {
			break;
		}
	}
}


int main() {
	initscr();
	cbreak();
	noecho();
	curs_set(0);

	int y,x;
	getmaxyx(stdscr,y,x);
	WINDOW *mainwin = newwin(y,x-(x/4),0,0);
	WINDOW *logwin = newwin(y,(x/4),0,x-(x/4));
	box(mainwin,0,0);
	box(logwin,0,0);
	wrefresh(mainwin);
	wrefresh(logwin);

	snake_rooms(mainwin,10,10,7,20);
	wrefresh(mainwin);

	wgetch(logwin); //wait
	endwin();
	return 0;
}
