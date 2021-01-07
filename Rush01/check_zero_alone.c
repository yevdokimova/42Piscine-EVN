/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zero_alone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 21:12:55 by marhamba          #+#    #+#             */
/*   Updated: 2020/12/10 22:13:55 by myevdoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int		find_zero(int **content, int *row, int *col)
{
	*row = 0;
	while (*row < 4)
	{
		*col = 0;
		while (*col < 4)
		{
			if (content[*row][*col] == UNDEFINED)
				return (TRUE);
			(*col)++;
		}
		(*row)++;
	}
	return (FALSE);
}

int		is_alone(int **content, int row, int col, int same)
{
	int i;

	i = 0;
	while (i < 4)
		if (content[row][i++] == same)
			return (FALSE);
	i = 0;
	while (i < 4)
		if (content[i++][col] == same)
			return (FALSE);
	return (TRUE);
}
