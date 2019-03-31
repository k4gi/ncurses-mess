#include <ncurses.h>
#include <string>

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
	mvwprintw(helpwin,3,1,"Press 'q' to exit");
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
	//navigation variables
	char in='q';
	int sel=0;
	int sel2=0;
	//main menu loop
	do {
		in = wgetch(helpwin);
		switch(in) {
		case '1':
			mvwprintw(helpwin,1,1,"Selected: Input");
			mvwprintw(helpwin,2,1,"Press Enter to finish typing (once that's implemented)");
			wrefresh(helpwin);
			break;
		case '2':
			mvwprintw(helpwin,1,1,"Selected: Output");
			mvwprintw(helpwin,2,1,"Press Enter to encode!(soon)");
			wrefresh(helpwin);
			break;
		case '3':
			mvwprintw(helpwin,1,1,"Selected: Slot settings");
			mvwprintw(helpwin,2,1,"Navigate submenu with 'hjkl', press 'd' when you're done");
			wrefresh(helpwin);
			do {
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
									mvwprintw(helpwin,2,1,"You have selected %s for Slot I",wheeloptions[slot1].c_str());
									break;
								case 2:
									slot2=sel2;
									mvwprintw(helpwin,2,1,"You have selected %s for Slot II",wheeloptions[slot2].c_str());
									break;
								case 3:
									slot3=sel2;
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
			mvwprintw(helpwin,1,1,"Done!");
			wrefresh(helpwin);
			break;
		case '4':
			mvwprintw(helpwin,1,1,"Selected: Plugboard settings");
			mvwprintw(helpwin,2,1,"Press a letter, then another letter, and they get connected(soon)");
			wrefresh(helpwin);
			break;
		case '5':
			mvwprintw(helpwin,1,1,"Selected: Information");
			mvwprintw(helpwin,2,1,"Yeah idk why you'd select this one maybe to 'q'uit the program?");
			wrefresh(helpwin);
			break;
		default:
			mvwprintw(helpwin,1,1,"You pressed the wrong key lol");
			wrefresh(helpwin);
		}
	} while(in != 'q');

	//wgetch(inwin); //temp. wait here
	endwin(); //stop ncurses
	return 0;
}
