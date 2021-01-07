/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevdoki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 17:45:33 by myevdoki          #+#    #+#             */
/*   Updated: 2020/12/09 20:44:15 by myevdoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int *range, int n)
{
	int i;
	int display;

	display = 1;
	i = 0;
	while (++i < n)
	{
		if (range[i - 1] >= range[i])
			display = 0;
	}
	if (!display)
		return ;
	i = -1;
	while (++i < n)
	{
		ft_putchar(range[i] + '0');
	}
	if (range[0] < (10 - n))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_combn(int n)
{
	int i;
	int range[10];

	if (n < 1 || n > 9)
		return ;
	i = -1;
	while (++i < n)
		range[i] = i;
	while (range[0] <= (10 - n) && n >= 1)
	{
		ft_print(range, n);
		if (n == 10)
			break ;
		range[n - 1]++;
		i = n;
		while (i && n > 1)
		{
			i--;
			if (range[i] > 9)
			{
				range[i - 1]++;
				range[i] = 0;
			}
		}
	}
}
