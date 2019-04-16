class cell {
	int id,col,row;
	cell *north,*east,*south,*west;

	cell(id,y,x) {
		id = id;
		col = y;
		row = x;
		north = east = south = west = NULL;
	}

	void link(cell *next, bool repeat) {
		if(repeat) {
			next.link(this, false);
		}
}
