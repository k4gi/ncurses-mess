#include <fstream>
#include <iostream>

#define FILENAME "generated_map.dat"

int main() {

	int pad_y = 100, pad_x = 100;
	
	char out[pad_y][pad_x];

	srand(0);
	for(int i=0;i<pad_y;i++) {
		for(int j=0;j<pad_x;j++) {
			if(i==0 || j==0 || i==pad_y-1 || j==pad_x-1) { //border
				out[i][j] = '#';
				//mvwaddch(map,i,j,'#');
			} else {
				switch(rand()%10) {
				case 0:
				//case 1:
				//case 2:
					out[i][j] = '^';
					//mvwaddch(map,i,j,'^');
					break;
				default:
					out[i][j] = '.';
					//mvwaddch(map,i,j,'.');
					break;
				}
			}
		}
	}

	std::ofstream billy;

	billy.open(FILENAME, std::ios::trunc | std::ios::out);
	if(billy.is_open()) {
		for(int i=0;i<pad_y;i++) {
			billy << out[i] << std::endl;
		}
		std::cout << "Output done :)\n";
	} else std::cout << "Output failed :(\n";
	
	return 0;
}
