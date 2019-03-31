#include <ncurses.h>
#include <string>

void clearWindow(WINDOW *win) {
	int y,x;
	getmaxyx(win,y,x);
	for(int i=1;i<y-1;i++) {
		for(int j=1;j<x-1;j++) {
			mvwaddch(win,i,j,' ');
		}
	}
}

void clearLine(WINDOW *win, int liney) {
	int y,x;
	getmaxyx(win,y,x);
	for(int i=1;i<x-1;i++) {
		mvwaddch(win,liney,i,' ');
	}
}

std::string getString(WINDOW *display) {
	std::string input;

	nocbreak();
	echo();
	curs_set(1);

	int ch = mvwgetch(display,1,1);

	while( ch != '\n' ) {
		input.push_back( ch );
		ch = wgetch(display);
	}

	cbreak();
	noecho();
	curs_set(0);

	return input;
}

int main() {
	initscr(); //init ncurses
	cbreak(); //ctrl-c works
	noecho(); //dont repeat back
	curs_set(0); //no cursor
	
	int y,x;
	getmaxyx(stdscr,y,x); //how much space
	WINDOW *inwin = newwin(5,x,0,0);
	WINDOW *outwin = newwin(5,x,5,0);
	WINDOW *slotwin = newwin(y-15,x/2,10,0);
	WINDOW *plugwin = newwin(y-15,x/2,10,x/2);
	WINDOW *helpwin = newwin(5,x,y-5,0);
	box(inwin,0,0);
	box(outwin,0,0);
	box(slotwin,0,0);
	box(plugwin,0,0);
	box(helpwin,0,0);
	mvwprintw(inwin,0,3,"1:Input window");
	mvwprintw(outwin,0,3,"2:Output window");
	mvwprintw(slotwin,0,3,"3:Slot settings");
	mvwprintw(plugwin,0,3,"4:Plugboard settings");
	mvwprintw(helpwin,0,3,"5:Information");
	mvwprintw(helpwin,3,1,"Press '12345' to navigate, and 'q' to exit");
	wrefresh(inwin);
	wrefresh(outwin);
	wrefresh(slotwin);
	wrefresh(plugwin);
	wrefresh(helpwin);
	
	//init slot menu here
	std::string slotoptions[] = {"Reflector","Slot I","Slot II","Slot III"};
	int slotsize = 4;
	std::string refoptions[] = {"Reflector A","Reflector B","Reflector C"};
	int refsize = 3;
	std::string wheeloptions[] = {"Wheel I","Wheel II","Wheel III","Wheel IV","Wheel V","Wheel VI","Wheel VII","Wheel VIII"};
	int wheelsize = 8;
	//save the settings we're making
	int ref = 0;
	int slot1 = 0;
	int slot2 = 0;
	int slot3 = 0;
	std::string plug = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //is there a better way to store this one?
	std::string input = ""; //the fabled secret message
	//navigation variables
	char in='q';
	char in2=' '; //oh my i need a second input for the plugboard
	int sel=0;
	int sel2=0;
	//uhh also a 'keyboard' string for showing what's changed with the plugboard
	std::string keyboard = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//main menu loop
	do {
		in = wgetch(helpwin);
		switch(in) {
		case '1':
			clearWindow(inwin);
			clearWindow(helpwin);
			wrefresh(inwin);
			mvwprintw(helpwin,1,1,"Selected: Input");
			mvwprintw(helpwin,2,1,"Press Enter to finish typing");
			wrefresh(helpwin);
			input = getString(inwin);
			clearWindow(helpwin);
			mvwprintw(helpwin,1,1,"Input done!");
			break;
		case '2':
			clearWindow(outwin);
			clearWindow(helpwin);
			mvwprintw(helpwin,1,1,"Selected: Output");
			mvwprintw(helpwin,2,1,"Press Enter to encode, any other key to exit");
			wrefresh(helpwin);
			if(wgetch(helpwin) == '\n') {
				mvwprintw(outwin,1,1,input.c_str());
			}
			wrefresh(outwin);
			clearWindow(helpwin);
			mvwprintw(helpwin,1,1,"Output done!");
			break;
		case '3':
			clearWindow(helpwin);
			mvwprintw(helpwin,1,1,"Selected: Slot settings");
			mvwprintw(helpwin,3,1,"Navigate submenu with 'hjkl', press 'd' when you're done");
			wrefresh(helpwin);
			do {
				clearWindow(slotwin);
				for(int i=0;i<slotsize;i++) {
					if(i==sel) wattron(slotwin,A_REVERSE); //attribute, reverse colours
					mvwprintw(slotwin,i+1,1,slotoptions[i].c_str());
					wattroff(slotwin,A_REVERSE);
				}
				wrefresh(slotwin);
				in = wgetch(helpwin);
				switch(in) {
				case 'k':
					if(sel>0) sel--;
					break;
				case 'j':
					if(sel<slotsize-1) sel++;
					break;
				case 'l':
					if(sel==0) { //reflector time
						do {
							for(int i=0;i<refsize;i++) {
								if(i==sel2) wattron(slotwin,A_REVERSE);
								mvwprintw(slotwin,i+sel+2,1,"  %s",refoptions[i].c_str());
								wattroff(slotwin,A_REVERSE);
							}
							wrefresh(slotwin);
							in = wgetch(helpwin);
							switch(in) {
							case 'k':
								if(sel2>0) sel2--;
								break;
							case 'j':
								if(sel2<refsize-1) sel2++;
								break;
							case 'h':
								ref=sel2;
								clearLine(helpwin,2);
								mvwprintw(helpwin,2,1,"You have selected %s",refoptions[ref].c_str());
								break;
							}
						} while(in != 'h');
					} else { //wheel time
						do {
							for(int i=0;i<wheelsize;i++) {
								if(i==sel2) wattron(slotwin,A_REVERSE);
								mvwprintw(slotwin,i+sel+2,1,"  %s",wheeloptions[i].c_str());
								wattroff(slotwin,A_REVERSE);
							}
							wrefresh(slotwin);
							in = wgetch(helpwin);
							switch(in) {
							case 'k':
								if(sel2>0) sel2--;
								break;
							case 'j':
								if(sel2<wheelsize-1) sel2++;
								break;
							case 'h':
								switch(sel) {
								case 1:
									slot1=sel2;
									clearLine(helpwin,2);
									mvwprintw(helpwin,2,1,"You have selected %s for Slot I",wheeloptions[slot1].c_str());
									break;
								case 2:
									slot2=sel2;
									clearLine(helpwin,2);
									mvwprintw(helpwin,2,1,"You have selected %s for Slot II",wheeloptions[slot2].c_str());
									break;
								case 3:
									slot3=sel2;
									clearLine(helpwin,2);
									mvwprintw(helpwin,2,1,"You have selected %s for Slot III",wheeloptions[slot3].c_str());
									break;
								}
								break;
							}
						} while(in != 'h');
					}
					sel2=0;
					break;
				}
			} while(in != 'd');
			sel = 0;
			clearWindow(slotwin);
			//put code here to show what settings were actually made, for reference
			wrefresh(slotwin);
			clearWindow(helpwin);
			mvwprintw(helpwin,1,1,"Slot settings done!");
			break;
		case '4':
			clearWindow(helpwin);
			mvwprintw(helpwin,1,1,"Selected: Plugboard settings");
			mvwprintw(helpwin,2,1,"Press a letter, then another letter, and they get connected");
			mvwprintw(helpwin,3,1,"Press Enter when you're done");
			do {
				clearWindow(plugwin);
				clearWindow(helpwin);
				mvwprintw(helpwin,1,1,"Selected: Plugboard settings");
				mvwprintw(helpwin,2,1,"Press a letter, then another letter, and they get connected");
				mvwprintw(helpwin,3,1,"Press Enter when you're done");
				mvwprintw(plugwin,1,1,"Plugs:");
				for(int i=0;i<keyboard.length();i++) {
					if(keyboard[i] != plug[i]) {
						wprintw(plugwin,"%c<->%c ",keyboard[i],plug[i]);
					}
				}
				in = toupper(wgetch(helpwin));
				if(keyboard.find(in) != std::string::npos) { //if found
					//um i gotta make the user give me another char so
					do {
						clearWindow(helpwin);
						mvwprintw(helpwin,1,1,"You entered %c, time for that second letter",in);
						in2 = toupper(wgetch(helpwin));
					} while(keyboard.find(in2) == std::string::npos);
					//todo: string manipulation..yay...make those changes to the plugboard
					//do we need any error checking here?
				}
			} while(in != '\n');
			clearWindow(plugwin);
			//code here to show what settings were made, again
			wrefresh(plugwin);
			clearWindow(helpwin);
			mvwprintw(helpwin,1,1,"Plugboard settings done!");
			break;
		case '5':
			clearWindow(helpwin);
			mvwprintw(helpwin,1,1,"Selected: Information");
			mvwprintw(helpwin,2,1,"Yeah idk why you'd select this one maybe to 'q'uit the program?");
			mvwprintw(helpwin,3,1,"Press '12345' to navigate, and 'q' to exit");
			break;
		default:
			clearWindow(helpwin);
			mvwprintw(helpwin,1,1,"You pressed the wrong key lol");
			mvwprintw(helpwin,3,1,"Press '12345' to navigate, and 'q' to exit");
		}
	} while(in != 'q');

	//wgetch(inwin); //temp. wait here
	endwin(); //stop ncurses
	return 0;
}
