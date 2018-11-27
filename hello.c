
#include <ncurses.h>

int main() {

	initscr();
	printw("This is a story about how!\n");
	printw("I got better at programming\n");
	printw("Because I refused to let my self-doubt define me anymore\n");
	int i = 0;
	printw("%d", i);
 
	int a;
	scanw("%d", &a);
 
	printw("%d", a);
	//yay i got number input working i'm such a legend
	
	
	
	getch();
	endwin(); // Restore normal terminal behavior
	return 0;
}
