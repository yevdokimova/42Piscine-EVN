/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   working_with_sqr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:25:28 by marhamba          #+#    #+#             */
/*   Updated: 2020/12/10 23:07:21 by myevdoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "include.h"

int		**int_array(char *arg)
{
	int	i;
	int	j;
	int	**input;

	input = crt_sqr(4);
	i = 0;
	j = 0;
	while (i < 16)
	{
		if (arg[i] == ' ')
		{
			arg++;
			continue;
		}
		input[j][i % 4] = arg[i] - '0';
		if (i % 4 == 3)
			j++;
		i++;
	}
	return (input);
}

int		**crt_sqr(int size)
{
	int i;
	int j;
	int **sqr;

	sqr = malloc(sizeof(int*) * size);
	i = 0;
	while (i < size)
	{
		sqr[i] = malloc(sizeof(int) * size);
		j = 0;
		while (j < size)
			sqr[i][j++] = 0;
		i++;
	}
	return (sqr);
}

int		**sqr_copy(int **sqr)
{
	int **clone;
	int i;
	int j;

	clone = crt_sqr(4);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			clone[i][j] = sqr[i][j];
			j++;
		}
		i++;
	}
	return (clone);
}

void	destroy_sqr(int **sqr)
{
	int i;

	i = 0;
	while (i < 4)
		free(sqr[i++]);
	free(sqr);
}

void	display_sqr(int **content)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putnbr(content[i][j]);
			j++;
			if (j != 4)
				ft_putchar(' ');
		}
		ft_putchar('\n');
		i++;
	}
}
