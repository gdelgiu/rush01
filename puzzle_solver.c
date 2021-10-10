/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:38:08 by gdel-giu          #+#    #+#             */
/*   Updated: 2021/10/10 14:44:29 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

enum e_dir
{
	UP,
    DOWN,
	LEFT,
    RIGHT
};

void frame_builder(int *buffer, int x, int y, int dir, int mtx[6][6]);

void check_obvious(int mtx[6][6], int x, int y, int start, int dir);

void empty_tab(int mtx[6][6])
{
	int i = 1;
	int j = 1;

	while (i <= 4)
	{
		while (j <= 4)
		{
			mtx[i][j] = 0;
			j++;
		}
		i++;
		j = 1;
	}
}

int absolute(int val)
{
	if (val < 0)
		val = -val;
	return (val);
}

void puzzle_solver(int *values, int mtx[6][6])
{
	int i;
	int max_iters = 2;

	empty_tab(mtx);
    frame_builder(values, 1, 0, RIGHT, mtx);
    frame_builder(values + 4, 1, 5, RIGHT, mtx);
    frame_builder(values + 8, 0, 1, DOWN, mtx);
    frame_builder(values + 12, 5, 1, DOWN, mtx);
	i = 0;
	while (i < max_iters)
	{
	check_obvious(mtx, 0, 1, 1, UP);
	check_obvious(mtx, 5, 0, 4, DOWN);
	check_obvious(mtx, 1, 0, 1, LEFT);
    check_obvious(mtx, 0, 5, 4, RIGHT);
	i++;
	}
}

void check_obvious(int mtx[6][6], int x, int y, int start, int dir)
{
	int scan;
	int delta;
	int iter;

	scan = start;
	delta = 0;
	iter = 0;
	if (start > 1)
		delta = 5;
	if (dir == UP || dir == DOWN)
	{
		while (y < 5)
		{
			if (mtx[x][y] == 4)
			{
				while (iter < 5)
				{
					mtx[scan][y] = absolute(delta - scan);
					if (dir == UP)
						scan++;
					else
						scan--;
					iter++;
				}
			}
			if (mtx[x][y] == 1)
			{
				if (dir == UP)
					mtx[x + 1][y] = 4;
				else
					mtx[x - 1][y] = 4; 
			}
			if (mtx[x][y] == 3)
			{
				scan = 1;
				if (dir == UP)
				{
					if (mtx[x + 1][y] == 0)
					{
						while (scan <= 4)
						{
							if (mtx[scan][y] == 1)
								mtx[x + 1][y] = 2;
							else if (mtx[scan][y] == 2)
								mtx[x + 1][y] = 1;
							scan++;
						}
					}
				}
				if (dir == DOWN)
				{
					if (mtx[x - 1][y] == 0)
					{
						while (scan <= 4)
						{
							//printf("%d %d = %d\n", scan, y, mtx[5 - scan][y]);
							if (mtx[5 - scan][y] == 1)
								mtx[x + 1][y] = 2;
							else if (mtx[5 - scan][y] == 2)
								mtx[x + 1][y] = 1;
							scan++;
						}
					}
				}
			}
			y++;
		}	
	}
	iter = 0;
	if (dir == LEFT || dir == RIGHT)
	{
		while (x < 5)
		{
			if (mtx[x][y] == 4)
			{	
				while (iter < 5)
				{
					mtx[x][scan] = absolute(delta - scan);
					if (dir == LEFT)
						scan++;
					else
						scan--;
					iter++;
				}
			}
			if (mtx[x][y] == 1)
			{
				if (dir == LEFT)
					mtx[x][y + 1] = 4;
				else
					mtx[x][y - 1] = 4;
			}
			if (mtx[x][y] == 3)
			{
				scan = 1;
				if (dir == RIGHT)
				{
					if (mtx[x][y - 1] == 0)
					{
						while (scan <= 4)
						{
							//printf("%d %d = %d\n", scan, y, mtx[scan][y]);
							if (mtx[y][5 - scan] == 1){
								mtx[y + 1][x] = 2;
								printf("%d %d = %d\n", scan, y, mtx[scan][y]);}
							else if (mtx[y][y] == 2)
								mtx[y - 1][x] = 1;
							scan++;
						}
					}
				}
				if (dir == LEFT)
				{
					if (mtx[x][y - 1] == 0)
					{
						while (scan <= 4)
						{
							//printf("%d %d = %d\n", scan, y, mtx[5 - scan][y]);
							if (mtx[x][5 - scan] == 1)
								mtx[x + 1][y] = 2;
							else if (mtx[5 - scan][y] == 2)
								mtx[x + 1][y] = 1;
							scan++;
						}
					}
				}
			}
			x++;
		}	
	}
}

void    frame_builder(int *buffer, int x, int y, int dir, int mtx[6][6])
{
    int a;
    
    a = 0;
    while (a < 4)
    {
        mtx[y][x] = *buffer;
        buffer++;
        if (dir == DOWN)
            y++;
        if (dir == RIGHT)
            x++;
        a++;
    }
}

