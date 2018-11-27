
#include <ncurses.h>
#include <string.h>

int main() {

	initscr();
	printw("This is a story about how!\n");
	printw("I got better at programming\n");
	printw("Because I refused to let my self-doubt define me anymore\n");
	//int i = 0;
	//printw("%d", i);
 
	int a;
	scanw("%d", &a);
 
	printw("%d", a);
	//yay i got number input working i'm such a legend
	
	//ok so we're going to program a simple menu
    printw("Enter 1 for beef, 2 for chicken or 3 for vegan\n");
    scanw("%d", &a);
    switch(a) {
        case 1:
            printw("you selected beef\n");
            break;
        case 2:
            printw("you selected chicken\n");
            break;
        case 3:
            printw("sorry we don't have a vegan option\n");
            break;
    } //ok cool it works

    char list[10][20];
    strcpy(list[0], "listtop");
    printw("This is string: %s\n", list[0]);

	
	getch(); //pls let me see what happened
	endwin(); // Restore normal terminal behavior
	return 0;
}
