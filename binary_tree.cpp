//I'm gonna try to write a binary tree maze generator. Wish me luck!

#include <ncurses.h> //it's just nice
#include <stdlib.h> //for srand and rand?
#include <string>

#define HEIGHT 5
#define WIDTH 5


struct node {
	int id;
	node *parent;
	node *left;
	node *right;
};

void print_tree(WINDOW *win, node *curr) {
	if(curr != NULL) {
		wprintw(win,"%d-L{ ",curr->id);
		print_tree(win,curr->left);
		wprintw(win," } %d-R{ ",curr->id);
		print_tree(win,curr->right);
		wprintw(win," }");
	} else {
		wprintw(win,"NULL");
	}
}

int main() {
	initscr();
	node *root = new node;

	root->id = 0;
	root->parent = NULL;
	root->left = NULL;
	root->right = NULL;
	
	node *trav = root;
	int inc = 1;

	srand(0);
	do {
		int coin = rand() % 3;
		if(trav->left == NULL && coin == 0) {
			trav->left = new node;
			trav->left->parent = trav;
			trav->left->id = inc;
			trav->left->left = NULL;
			trav->left->right = NULL;
			trav = trav->left;
			inc ++;
		} else if(trav->right == NULL && coin == 1) {
			trav->right = new node;
			trav->right->parent = trav;
			trav->right->id = inc;
			trav->right->left = NULL;
			trav->right->right = NULL;
			trav = trav->right;
			inc ++;
		} else {
			trav = trav->parent;
		}
	} while(trav != NULL);

	print_tree(stdscr,root);
	getch();

	endwin();
	return 0;
}
/*
int main() {
	char grid[HEIGHT][WIDTH];
	initscr();
	WINDOW *mazewin = newwin(HEIGHT,WIDTH,0,0);

	srand(0);

	for(int i=0;i<HEIGHT;i++) {
		for(int j=0;j<WIDTH;j++) {
			int coin = rand() % 2;

			if(coin == 0) {
				grid[i][j] = '^';
			} else {
				grid[i][j] = '<';
			}
		}
		mvwprintw(mazewin,i,0,grid[i]);
	}
	wgetch(mazewin);
	endwin();
	return 0;
}*/
