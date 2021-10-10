/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:10:18 by gdel-giu          #+#    #+#             */
/*   Updated: 2021/10/10 23:05:31 by dlogli           ###   ########.fr       */
/*   Updated: 2021/10/09 15:53:18 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_error(void)
{
	write(1, "Error\n", 6);
}

int	main(int argc, char *argv[])
{
	int	values[16];
	int	mat[6][6];
	int	x;
	int	y;

	x = 1;
	y = 1;
	if (argc != 2)
	{
		print_error();
		return (0);
	}
	if (!(puzzle_is_possible(argv[1])))
	{
		print_error();
		return (0);
	}
	if (check_input(argv[1], values) == 16)
	{	
		puzzle_solver(values, mat);
		while (y < 5)
		{
			while (x < 5)
			{
				if (mat[y][x] != 0)
					printf("%d ", mat[y][x]);
				else
					printf("0 ");
				x++;
			}
			x = 1;
			y++;
		}
		return (0);
	}
	else
	{
		print_error();
		return (0);
	}
	print_error();
	return (0);
}
