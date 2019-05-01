#include <ncurses.h>
#include "snake.h"
#include "list.h"
#include <iostream>

int main() {
	std::cout << "start testing\n";

	std::cout << "init list\n";
	list kara;

	std::cout << "init snake\n";
	snake alex = snake(2,2,2);
	
	std::cout << "stop testing\n";

	return 0;
}
