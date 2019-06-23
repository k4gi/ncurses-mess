#include <ncurses.h>

struct path_node {
	int ypos;
	int xpos;
}

struct path {
	path_node data;
	path *next;
}

struct mob {
	int hp;
	char sym;
	path *pos;
}

struct mob_wave {
	mob data;
	mob_wave *next;
}

int main() {
	initscr();
	cbreak();
	noecho();
	curs_set(0);

	int y,x;
	getmaxyx(stdscr,y,x);

	path *test_level;
	
	//ahh not right now
	return 0;
}

