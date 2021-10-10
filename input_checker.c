/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:20:49 by gdel-giu          #+#    #+#             */
/*   Updated: 2021/10/10 22:57:06 by mlatifi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "stdlib.h"

int	puzzle_is_possible(char *str)
{
	int	i;
	int	strk;

	i = 0;
	strk = 0;
	while (str[i])
	{	
		if (str[i] == '4')
			strk++;
		i++;
	}
	if (strk > 2)
		return (0);
	i = 0;
	strk = 0;
	while (str[i])
	{
		if (str[i] == '1')
			strk++;
		i++;
	}
	if (strk != 4)
		return (0);
	return (1);
}

int	check_input(char *str, int *input)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (str[i])
	{
		if ((str[i] >= '1' && str[i] <= '4')
			&& (str[i + 1] == ' '
				|| (str[i + 1] == '\0' && str[i - 1] == ' ')))
		{
			input[check] = str[i] - '0';
			check++;
			i++;
		}
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		else
			return (check);
	}
	input[check] = '\0';
	return (check);
}
