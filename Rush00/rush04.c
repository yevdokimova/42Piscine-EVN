/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:48:10 by sgabriel          #+#    #+#             */
/*   Updated: 2020/11/29 15:56:38 by sgabriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	first_width(int x)
{
	int i;

	ft_putchar('A');
	i = 1;
	while (i < x - 1)
	{
		ft_putchar('B');
		i++;
	}
	if (x > 1)
		ft_putchar('C');
	ft_putchar('\n');
}

void	area(int x, int y)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (j < y - 1)
	{
		ft_putchar('B');
		i = 1;
		while (i < x - 1)
		{
			ft_putchar(' ');
			i++;
		}
		if (x != 1)
			ft_putchar('B');
		ft_putchar('\n');
		j++;
	}
}

void	last_width(int x)
{
	int i;

	ft_putchar('C');
	i = 1;
	while (i < x - 1)
	{
		ft_putchar('B');
		i++;
	}
	if (x > 1)
		ft_putchar('A');
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
		return ;
	first_width(x);
	if (y != 1)
	{
		area(x, y);
		last_width(x);
	}
}
