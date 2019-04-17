//ruby is confusing

#include <cstddef> //??????

class cell {
	int id,y,x;

	//0=north,1=east,2=south,3=west
	cell *neighbour[4];

	bool linked[4];

public:
	cell(int num,int col,int row) {
		id = num;
		y = col;
		x = row;

		for(int i=0;i<4;i++) {
			neighbour[i] = NULL;
			linked[i] = false;
		}
	}

	int get_id() {
		return id;
	}

	int get_y() {
		return y;
	}

	int get_x() {
		return x;
	}

	cell *get_neighbour(int dir) {
		return neighbour[dir];
	}

	void set_neighbour(int dir, cell *new_nbr) {
		neighbour[dir] = new_nbr;
	}

	bool is_linked(int dir) {
		return linked[dir];
	}

	void link(int dir,bool repeat) {
		if(neighbour[dir] != NULL) {
			linked[dir] = true;

			if(repeat) {
				switch(dir) {
				case 0:
					neighbour[0]->link(2,false);
					break;
				case 1:
					neighbour[1]->link(3,false);
					break;
				case 2:
					neighbour[2]->link(0,false);
					break;
				case 3:
					neighbour[3]->link(1,false);
					break;
				}
			}
		}
	}

	void unlink(int dir,bool repeat) {
		if(neighbour[dir] != NULL) {
			linked[dir] = false;

			if(repeat) {
				switch(dir) {
				case 0:
					neighbour[0]->unlink(2,false);
					break;
				case 1:
					neighbour[1]->unlink(3,false);
					break;
				case 2:
					neighbour[2]->unlink(0,false);
					break;
				case 3:
					neighbour[3]->unlink(1,false);
					break;
				}
			}
		}
	}
};
