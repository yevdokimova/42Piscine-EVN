/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 21:55:55 by marhamba          #+#    #+#             */
/*   Updated: 2020/12/10 22:12:33 by myevdoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int		solution(int **content, int **input, int *finished)
{
	int row;
	int col;
	int i;
	int **cont_clone;

	if (!find_zero(content, &row, &col))
		return (TRUE);
	i = 0;
	while (++i <= 4)
	{
		if (!is_alone(content, row, col, i))
			continue;
		cont_clone = sqr_copy(content);
		cont_clone[row][col] = i;
		if (solution(cont_clone, input, finished) &&
				check_viewinput(cont_clone, input))
		{
			*finished = TRUE;
			display_sqr(cont_clone);
			destroy_sqr(cont_clone);
			return (TRUE);
		}
		destroy_sqr(cont_clone);
	}
	return (FALSE);
}

int		check_viewinput(int **content, int **input)
{
	t_view_point	view;
	int	j;

	view = col_up;
	while (view <= row_right)
	{
		j = 0;
		while (j < 4)
		{
			if (!check_line(content, view, j, input[view][j]))
				return (FALSE);
			j++;
		}
		view++;
	}
	return (TRUE);
}

int		check_line(int **content, t_view_point view, int view_line,
				int cont_viewed)
{
	int i;
	int tmp_same;

	i = 0;
	while (i < 4)
	{
		tmp_same = view_content(content, view, view_line, i);
		if (tmp_same == UNDEFINED)
			return (FALSE);
		cont_viewed--;
		while (i + 1 < 4 && tmp_same > view_content(
					content, view, view_line, i + 1))
			i++;
		i++;
	}
	return (cont_viewed == 0);
}
