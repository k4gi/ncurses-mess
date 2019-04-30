#include <ncurses.h>
#include <string>
#include "snake.h"

void snake_game() {
	int y,x;
	getmaxyx(stdscr,y,x);
	
	snake garry = snake(y/2,x/2,1);

	/*
		a 'snake' has a head that changes direction, and a body and tail that follow behind.
		The body consists of 0 or more tiles. There is always 1 head and 1 tail.
	*/

	srand(0);
	char in;

	//someting to aim for
	int y_goal = rand()%y;
	int x_goal = rand()%x;

	mvaddch(y_goal,x_goal,'Q');

	/* 2019-04-21 bugs to take note of
		snake tracking can get stuck when trying to move north/south back on itself
		also just normal loop collisions
		new targets can spawn anywhere! including on the snake
		i just saw one spawn right on the snake's head and it has no idea what to do it just froze
		so to fix, make target spawning happen NOT on the snake
		and give the snake some tools to try and move around itself (it might not always go well, maybe there's some kind of recursive solution to search ahead, and ahead, and ahead some more)
	*/

	//initial position
	garry.place(stdscr);

	//choose auto or manual play
	mvprintw(0,0,"Press 'a' for auto, other for manual");
	in = getch();
	mvprintw(0,0,"                                    ");
	timeout(100);

	if(in == 'a') {
		//autoplay loop
		do {
			in = getch(); //delay here with timeout()

			if(in == 'p') { //print
				garry.print(stdscr);
			} else if(in == 'g') { //g for grow
				garry.grow(stdscr,rand()%4);
			} else {
				if(garry.track(stdscr,y_goal,x_goal) == 2) { //spawn new target
					y_goal = rand()%y;
					x_goal = rand()%x;
					mvaddch(y_goal,x_goal,'Q');
				}
			}
		} while(in != 'q');
	} else {
		//manual loop
		int set_dir = 1;
		do {
			in = getch();

			switch(in) {
			case 'w':
				set_dir = 0;
				break;
			case 'd':
				set_dir = 1;
				break;
			case 's':
				set_dir = 2;
				break;
			case 'a':
				set_dir = 3;
				break;
			}

			switch(set_dir) {
			case 0:
				if(garry.getypos() -1 == y_goal && garry.getxpos() == x_goal) {
					garry.grow(stdscr,0);
					y_goal = rand()%y;
					x_goal = rand()%x;
					mvaddch(y_goal,x_goal,'Q');
				} else {
					garry.move(stdscr,0);
				}
				break;
			case 1:
				if(garry.getypos() == y_goal && garry.getxpos() +1 == x_goal) {
					garry.grow(stdscr,1);
					y_goal = rand()%y;
					x_goal = rand()%x;
					mvaddch(y_goal,x_goal,'Q');
				} else {
					garry.move(stdscr,1);
				}
				break;
			case 2:
				if(garry.getypos() +1 == y_goal && garry.getxpos() == x_goal) {
					garry.grow(stdscr,2);
					y_goal = rand()%y;
					x_goal = rand()%x;
					mvaddch(y_goal,x_goal,'Q');
				} else {
					garry.move(stdscr,2);
				}
				break;
			case 3:
				if(garry.getypos() == y_goal && garry.getxpos() -1 == x_goal) {
					garry.grow(stdscr,3);
					y_goal = rand()%y;
					x_goal = rand()%x;
					mvaddch(y_goal,x_goal,'Q');
				} else {
					garry.move(stdscr,3);
				}
				break;
			}
		} while(in != 'q');
	}

	//end
	garry.delete_snake();
	//getting seg faults even though i delete the list
	//am i doing it wrong?
	//is it something else?
	//i just don't know...
}

int main() {
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	
	//timeout(100); //milliseconds of delay for getch();
	//wtimeout(stdscr,1000); //window version
	
	snake_game();

	endwin();
	return 0;
}
	
