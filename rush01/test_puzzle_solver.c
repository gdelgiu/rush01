enum e_dir
{    
    DOWN,
    RIGHT
};

void frame_builder(int *buffer, int x, int y, int dir, int *mtx);

void puzzle_solver(int *values)
{
    int mtx[6][6];
	int *ptr;

	ptr = &mtx[0][0];
    frame_builder(values, 1, 0, DOWN, ptr);
    //frame_builder(values, )
}

void    frame_builder(int *buffer, int x, int y, int dir, int *mtx)
{
    int a;
    
    a = 0;
    while (a < 4)
    {
        mtx[y][x] = buffer++;
        if (dir == DOWN)
            y++;
        if (dir == RIGHT)
            x++;
        a++;
    }
}

int main() {
	
	int array[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7};
  puzzle_solver(array);
}
