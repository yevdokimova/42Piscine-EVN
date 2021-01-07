/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 21:41:09 by marhamba          #+#    #+#             */
/*   Updated: 2020/12/10 22:15:14 by myevdoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "include.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	p_nb;

	p_nb = nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		p_nb = -nb;
	}
	if (p_nb > 9)
		ft_putnbr(p_nb / 10);
	ft_putchar(p_nb % 10 + '0');
}

int		view_content(int **content, t_view_point view, int view_line,
					int line_index)
{
	if (view == row_left)
		return (content[view_line][line_index]);
	if (view == row_right)
		return (content[view_line][3 - line_index]);
	if (view == col_up)
		return (content[line_index][view_line]);
	if (view == col_down)
		return (content[3 - line_index][view_line]);
	return (-1);
}
