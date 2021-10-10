/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:10:18 by gdel-giu          #+#    #+#             */
/*   Updated: 2021/10/10 12:23:29 by gdel-giu         ###   ########.fr       */
/*   Updated: 2021/10/09 15:53:18 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "input_checker.c"
#include "puzzle_solver.c"

int main(int argc, char *argv[])
{
	int values[16];
	
	if (argc !=  2)
		return (0);
	if (!(puzzle_is_possible(argv[1])))
		return (0);
	if (check_input(argv[1], values) == 16)
		puzzle_solver(values);
	else
		return (0);
}
