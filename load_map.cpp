#include <fstream> //read & write

#include <ncurses.h>
#include <string>

#define FILENAME "basic_map.dat"

int main() {
	initscr();
	int y,x;
	getmaxyx(stdscr,y,x);

	std::ifstream map_loader;
	int pad_y = 0; //number of lines
	int pad_x = 0; //size of string

	/*
		how about we open the file once, measure, the map, then close it.
		Then open the file again to read it into a pad.
		It means running through the file twice but then I know what dimensions to make the pad.
		That's good, right?
	*/

	//measuring
	map_loader.open(FILENAME,std::ios::in);
	if( map_loader.is_open() ) {
		std::string input_line;

		while(std::getline(map_loader, input_line)) {
			pad_y ++;
			if(input_line.length() > pad_x) pad_x = input_line.length();
		}
		map_loader.close();
	}

	WINDOW *map_pad = newpad(pad_y,pad_x);

	//printing
	map_loader.open(FILENAME,std::ios::in);
	if( map_loader.is_open() ) {
		std::string input_line;
		int inc = 0;

		while(std::getline(map_loader, input_line)) {
			mvwprintw(map_pad,inc,0,input_line.c_str());
			inc ++;
		}
	}

	refresh();
	prefresh(map_pad,0,0,0,0,y-1,x-1);
	getch();

	endwin();
	return 0;
}
