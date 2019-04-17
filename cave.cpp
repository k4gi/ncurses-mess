#include <ncurses.h>
#include <string>
#include "Character.h"

void draw_room(WINDOW *win,int height, int width, int starty, int startx) {
	for(int i=0;i<width;i++) {
		mvwaddch(win,starty,startx+i,'-');
		mvwaddch(win,starty+height-1,startx+i,'-');
	}
	for(int i=1;i<height-1;i++) {
		mvwaddch(win,starty+i,startx,'|');
		for(int j=1;j<width-1;j++) {
			mvwaddch(win,starty+i,startx+j,'.');
		}
		mvwaddch(win,starty+i,startx+width-1,'|');
	}
}

void draw_corridor(WINDOW *win, bool is_vertical, int length, int starty, int startx) {
	if(is_vertical) {
		for(int i=0;i<length;i++) {
			mvwprintw(win,starty+i,startx,"|.|");
		}
	} else {
		for(int i=0;i<length;i++) {
			mvwaddch(win,starty,startx+i,'-');
			mvwaddch(win,starty+1,startx+i,'.');
			mvwaddch(win,starty+2,startx+i,'-');
		}
	}
}

void spawn_character(WINDOW *win, char sym, Character out) {
	int y,x;
	getmaxyx(win,y,x);
	while(1) {
		int ys = rand()%y;
		int xs = rand()%x;
		if(mvwinch(win,ys,xs) == '.') {
			out = Character(ys,xs,sym);
		}
	}
}

void draw_preset(WINDOW *win) {
	int y,x;
	getmaxyx(win,y,x);
	if(x>=30 && y>=19) {
		// measures        .0   .5   .10  .15  .20  .25  .30
		mvwprintw(win, 0,0,"==============================");
		mvwprintw(win, 1,0,"|..|.....|.........|.........|");
		mvwprintw(win, 2,0,"|..|.....|.........|.........|");
		mvwprintw(win, 3,0,"|..|..|..|====.====|.........|");
		mvwprintw(win, 4,0,"|.....|..|.........|======...|");
		mvwprintw(win, 5,0,"|.....|..|.======.=|.....|...|");
		mvwprintw(win, 6,0,"|===..|..|.|.......|.....|...|");
		mvwprintw(win, 7,0,"|..|..|..|.|.......|.....|...|");
		mvwprintw(win, 8,0,"|.....|....|.............|...|");
		mvwprintw(win, 9,0,"|..|..|....|.......|.....|...|");
		mvwprintw(win,10,0,"|===..|====|.......|.....|...|");
		mvwprintw(win,11,0,"|.....|....========|.....|...|");
		mvwprintw(win,12,0,"|.....|............|======...|");
		mvwprintw(win,13,0,"|..|..|............|.....|...|");
		mvwprintw(win,14,0,"|..|..|............|.....|...|");
		mvwprintw(win,15,0,"|..|..==============..|..|...|");
		mvwprintw(win,16,0,"|..|..................|......|");
		mvwprintw(win,17,0,"|..|..................|......|");
		mvwprintw(win,18,0,"|..==========================|");
		mvwprintw(win,19,0,"====                         =");
	}
}

void cave() {
	int y,x;
	getmaxyx(stdscr,y,x);
	WINDOW *mainwin = newwin(y-10,x-10,5,5);
	box(mainwin,0,0);

	//draw_room(mainwin,5,5,5,5);
	//draw_room(mainwin,7,10,7,18);
	//draw_corridor(mainwin,false,10,7,9);
	
	draw_preset(mainwin);

	wrefresh(mainwin);

	Character hamster = Character('@',1,1);
	mvwaddch(mainwin,hamster.row(),hamster.col(),hamster.symbol());

	Character goblin = Character('g',3,25);
	mvwaddch(mainwin,goblin.row(),goblin.col(),goblin.symbol());

	srand(255);

	char in = 'q';
	do {
		in = wgetch(mainwin);
		//mvwaddch(mainwin,goblin.row(),goblin.col(),goblin.symbol());
		switch(in) {
		//case 'p':
		//	spawn_character(mainwin,'p',goblin);
		//	mvwaddch(mainwin,goblin.row(),goblin.col(),goblin.symbol());
		//	break;
		case 'a':
			mvwprintw(mainwin,1,1,"Big Black Bat");
			break;
		case 'b':
			mvwprintw(mainwin,2,1,"can you tell i'm a placeholder?");
			break;
		case 'c':
			mvwprintw(mainwin,1,1,"                   ");
			mvwprintw(mainwin,2,1,"                              ");
			break;
		case 'x':
			for(int i=0;i<x;i++) {
				if(i<y) mvwprintw(mainwin,i,0,"%d",i);
				mvwprintw(mainwin,0,i,"%d",i%10);
			}
			break;
		case 'k':
			//move up
			if(mvwinch(mainwin,hamster.row()-1,hamster.col()) == '.') {
				mvwaddch(mainwin,hamster.row(),hamster.col(),'.');
				hamster.pos(hamster.row()-1,hamster.col());
			} else if(mvwinch(mainwin,hamster.row()-1,hamster.col()) == goblin.symbol()) {
			       mvwaddch(mainwin,goblin.row(),goblin.col(),'X');
			}
			break;
		case 'j':
			//move down
			if(mvwinch(mainwin,hamster.row()+1,hamster.col()) == '.') {
				mvwaddch(mainwin,hamster.row(),hamster.col(),'.');
				hamster.pos(hamster.row()+1,hamster.col());
			} else if(mvwinch(mainwin,hamster.row()+1,hamster.col()) == goblin.symbol()) {
			       mvwaddch(mainwin,goblin.row(),goblin.col(),'X');
			}
			break;
		case 'h':
			//move left
			if(mvwinch(mainwin,hamster.row(),hamster.col()-1) == '.') {
				mvwaddch(mainwin,hamster.row(),hamster.col(),'.');
				hamster.pos(hamster.row(),hamster.col()-1);
			} else if(mvwinch(mainwin,hamster.row(),hamster.col()-1) == goblin.symbol()) {
			       mvwaddch(mainwin,goblin.row(),goblin.col(),'X');
			}
			break;
		case 'l':
			//move right
			if(mvwinch(mainwin,hamster.row(),hamster.col()+1) == '.') {
				mvwaddch(mainwin,hamster.row(),hamster.col(),'.');
				hamster.pos(hamster.row(),hamster.col()+1);
			} else if(mvwinch(mainwin,hamster.row(),hamster.col()+1) == goblin.symbol()) {
			       mvwaddch(mainwin,goblin.row(),goblin.col(),'X');
			}
			break;
		}
		mvwaddch(mainwin,hamster.row(),hamster.col(),hamster.symbol());

		
		//goblin movement
		switch(rand()%10) {
		case 2:	
			//move up
			if(mvwinch(mainwin,goblin.row()-1,goblin.col()) == '.') {
				mvwaddch(mainwin,goblin.row(),goblin.col(),'.');
				goblin.pos(goblin.row()-1,goblin.col());
			}
			break;
		case 4:
			//move down
			if(mvwinch(mainwin,goblin.row()+1,goblin.col()) == '.') {
				mvwaddch(mainwin,goblin.row(),goblin.col(),'.');
				goblin.pos(goblin.row()+1,goblin.col());
			}
			break;
		case 6:
			//move left
			if(mvwinch(mainwin,goblin.row(),goblin.col()-1) == '.') {
				mvwaddch(mainwin,goblin.row(),goblin.col(),'.');
				goblin.pos(goblin.row(),goblin.col()-1);
			}
			break;
		case 8:
			//move right
			if(mvwinch(mainwin,goblin.row(),goblin.col()+1) == '.') {
				mvwaddch(mainwin,goblin.row(),goblin.col(),'.');
				goblin.pos(goblin.row(),goblin.col()+1);
			}
			break;
		}
		mvwaddch(mainwin,goblin.row(),goblin.col(),goblin.symbol());

	} while(in != 'q');
}

int main() {
	initscr();
	cbreak();
	noecho();
	curs_set(0);

	cave();

	endwin();
	return 0;
}
