#include "cell.cpp"

#define GRID_MAX_SIZE 255 //shit i don't know

class grid {
	int y,x;
	cell data[][GRID_MAX_SIZE];

public:
	grid(int col,int row) {
		y = col;
		x = row;

		int temp = 0;
		for(int i=0;i<y;i++) {
			for(int j=0;j<x;j++) {
				data[i][j] = cell(temp,i,j);
				temp ++;
			}
		}

		for(int i=0;i<y;i++) {
			for(int j=0;j<x;j++) {
				if(i>0) { //north
					data[i][j].set_neighbour(0,&data[i-1][j]);
				}
				if(j<x-1) { //east
					data[i][j].set_neighbour(1,&data[i][j+1]);
				}
				if(i<y-1) { //south
					data[i][j].set_neighbour(2,&data[i+1][j]);
				}
				if(j>0) { //west
					data[i][j].set_neighbour(3,&data[i][j-1]);
				}
			}
		}
	}

	int get_size() {
		return y*x;
	}

	cell get_cell(int col,int row) {
		return data[col][row];
	}
};
