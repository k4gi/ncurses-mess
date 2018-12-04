//oh yeah so I'm following this tutorial that was last updated in 2005
//haven't found anything newer that makes any sense so oh well
//url here: http://www.tldp.org/HOWTO/NCURSES-Programming-HOWTO/index.html

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void test_one();
void test_two();


int main() {
    initscr();
    
    int winner = 0;
    char in[10];
    do {
        printw("Welcome to hello.c. May I take your order?\n");
        printw("Enter 'Yes' or 'No' > ");
        scanw("%s", &in);
        
        if(strcmp(in, "Yes") == 0) {
            printw("You have entered Yes! Congrats!\n");
            winner = 1;
        } else if(strcmp(in, "No") == 0) {
            printw("You have entered No! Congrats!\n");
            winner = 2;
        }
    } while(winner == 0);
    if(winner == 1) {
        printw("So you've decided on our vegan option? Excellent. It won't be far away.\n");
        do {
            printw("While you're waiting why not try an appetizer? Today we have...\n");
            printw("Enter 'Bread' or 'Soup' > ");
            scanw("%s", &in);
            
            if(strcmp(in, "Bread") == 0) {
                printw("You have entered Bread!\n");
                winner = 3;
            } else if(strcmp(in, "Soup") == 0) {
                printw("You have entered Soup!\n");
                winner = 4;
            }
        } while(winner == 1);
        if(winner == 3) {
			printw("*The waiter brings you a loaf of garlic bread. You are overjoyed.\n");
		} else if(winner == 4) {
			printw("*The waitress brings you a bowl of chicken & corn soup. It smells tasty.\n");
		}
		printw(". . . . . .\n. . . . . .\n. . . . . .\n");
		printw("*You've been waiting a while now for your vegan lamb. Your patience wears thin.\n");
		if(winner == 3) {
			printw("*Bread crumbs cover the table.\n");
		} else if(winner == 4) {
			printw("*The soup bowl sits empty.\n");
		}
		do {
			printw("*You consider stepping into the kitchen for a 'quiet' 'word'.\n");
			printw("Enter 'Attack' or 'Retreat' > ");
			scanw("%s", &in);
			
			if(strcmp(in, "Attack") == 0) {
				printw("You have entered -ATTACK-\n");
				winner = 88;
			} else if(strcmp(in, "Retreat") == 0) {
				printw("...chicken\n");
				winner = 81;
			}
		} while(winner < 80);
    } else if(winner == 2) {
        do {
            printw("Piss off then, we've got paying customers wanting this table!\n");
            printw("Enter 'Yes' or 'No' > ");
            scanw("%s", &in);
            
            if(strcmp(in, "Yes") == 0) {
                printw("You have entered Yes!\n");
                winner = 5;
            } else if(strcmp(in, "No") == 0) {
                printw("You have entered No!\n");
                winner = 6;
            }
        } while(winner == 2);
        if(winner == 5) {
			printw("The game has ended peacefully.\n");
		} else if(winner == 6) {
			printw("It's battle time!\n");
			winner = 99;
		}
    }
    
    if((winner == 99) | (winner == 88)) {
		//action
		printw("*You stride up to the double-hinged kitchen doors and burst through them!\n");
		printw("*Most of the staff are too startled to question you.\n");
		printw("*This chef's going to get what's coming to him.\n");
		printw("*The chef rushes you, and slaps you on the head with his ladle!\n");
		printw("*You are dazed! Quick, do some sums to help you focus!\n");
		
		//its sums time
		srandom(time(NULL));
		int random1;
		int random2;
		winner = 5;
		int sum_in = 0;
		do {
			random1 = random() % 100;
			random2 = random() % 100;
			printw("What is... %d + %d ???\n", random1, random2);
			scanw("%d", &sum_in);
			if(random1 + random2 == sum_in) {
				winner --;
				printw("Correct! %d more sums!\n", winner);
			} else {
				printw("Incorrect... %d more sums!\n", winner);
			}
		} while(winner > 0);
		winner = 100;
		printw("*You shake your head, and your vision stops spinning. The chef is in front of you.\n");
		printw("What do you do???????\n");
		printw("Enter 'Punch' or 'Kick' > ");
		scanw("%s", &in);
	}
	
	if(winner < 85) {
		printw("----This is the no-conflict end state. Goodbye now.");
	}
    
    
    //test_one();
    //test_two();
	
	getch(); //pls let me see what happened
	endwin(); // Restore normal terminal behavior
	return 0;
}

void test_two() {
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
