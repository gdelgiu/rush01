/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:38:08 by gdel-giu          #+#    #+#             */
/*   Updated: 2021/10/10 13:04:27 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

enum e_dir
{
	UP,
    DOWN,
	LEFT,
    RIGHT
};

void frame_builder(int *buffer, int x, int y, int dir, int mtx[6][6]);

void check_obvious(int mtx[6][6], int dir);

void puzzle_solver(int *values)
{
    int mtx[6][6];

    frame_builder(values, 1, 0, RIGHT, mtx);
    frame_builder(values + 4, 1, 5, RIGHT, mtx);
    frame_builder(values + 8, 0, 1, DOWN, mtx);
    frame_builder(values + 12, 5, 1, DOWN, mtx);
	check_obvious(mtx, UP)
}

void check_obvious(int mtx[6][6], int dir)
{
	int i;
	int scan;

	i = 1;
	
	if ( dir == UP)
	{

		while (i < 5)
		{
			if (mtx[0][i] == 4)
			{
				scan = 1;
				while (scan < 5)
				{
					mtx[scan][i] = scan;
					scan++;
				}
			}
			if (mtx[0][i] == 1)
			{
				mtx[1][i] = 4;
			}
		i++;	
		}
	i = 0;
	}
	if ( dir == DOWN)
	{
		while (i < 5)
		{
			if (mtx[5][i] == 4)
			{
				scan = 5;
				while (scan < 5)
				{
					mtx[scan][i] = scan;
					scan--;
				}
			}
			if (mtx[5][i] == 1)
			{
				mtx[4][i] = 4;
			}
		i++;	
		}
	i = 0;
	}
	if ( dir == LEFT)
	{
		while (i < 5)
		{
			if (mtx[i][0] == 4)
			{
				scan = 1;
				while (scan < 5)
				{
					mtx[i][scan] = scan;
					scan++;
				}
			}
			if (mtx[i][0] == 1)
			{
				mtx[i][1] = 4;
			}
		i++;	
		}
	i = 0;
	}
	if ( dir == RIGHT)
	{
		while (i < 5)
		{
			if (mtx[i][5] == 4)
			{
				scan = 5;
				while (scan < 5)
				{
					mtx[i][scan] = scan;
					scan--;
				}
			}
			if (mtx[i][5] == 1)
			{
				mtx[i][4] = 4;
			}
		i++;	
		}
	i = 0;
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

