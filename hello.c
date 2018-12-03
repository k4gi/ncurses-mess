//oh yeah so I'm following this tutorial that was last updated in 2005
//haven't found anything newer that makes any sense so oh well
//url here: http://www.tldp.org/HOWTO/NCURSES-Programming-HOWTO/index.html

#include <ncurses.h>
#include <string.h>

void test_one();

int main() {

	initscr();
    
    move(10,10);
    addch('a');
    addch('b');
    addch('c');

    move(20,10);
    printw("Here lies one generic string");

    WINDOW *window_one;
    window_one = newwin(10,20,50,50); //height, width, starty, startx
    //box(window_one, 1, 2); //idk even what this is it doesn't seem do be doing anything
    wborder(window_one, 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'); //this isn't doing anything either
    wrefresh(window_one);

    move(5,5);
    int minx;
    int miny;
    int maxx;
    int maxy;
    getbegyx(window_one, miny, minx);
    getmaxyx(window_one, maxy, maxx);

    printw("%d,%d,%d,%d", miny, minx, maxy, maxx);
    //but how do you get dimensions of the whole screen tho?
    //getch();
    delwin(window_one);
    
    
    //test_one();
	
	getch(); //pls let me see what happened
	endwin(); // Restore normal terminal behavior
	return 0;
}

void test_one() {
    move(0,0);
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

    char list[10][20]; //array of..arrays..of characters...yep that's how it works
    strcpy(list[0], "listtop");
    printw("This is string: %s\n", list[0]); //oh cool this works too

    printw("i'm going to take some string input now, give me three words please\n");
    char input[20]; //input is 20 characters right? so why can i type more in than that? ahh some dark magic i suppose
    scanw("%s", &input); //reminder that scanw only reads until a space
    strcpy(list[1], input);
    printw("List 1:%s\n", list[1]); //ok this works too
    scanw("%s", &input);
    strcpy(list[2], input);
    printw("List 2:%s\n", list[2]);
    scanw("%s", &input);
    strcpy(list[3], input);
    printw("List 3:%s\n", list[3]);
}
