/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevdoki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 23:45:36 by myevdoki          #+#    #+#             */
/*   Updated: 2020/12/16 09:49:12 by myevdoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *base)
{
	int len;

	len = 0;
	while (base[len])
		len++;
	return (len);
}

int		ft_check_base(char *base)
{
	int i;
	int j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		if (!(base[i] >= 'A' && base[i] <= 'Z')
				&& !(base[i] >= 'a' && base[i] <= 'z')
				&& !(base[i] >= '0' && base[i] <= '9'))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int len;

	if (!(ft_check_base(base)))
		return ;
	len = ft_strlen(base);
	if (nbr <= -2147483648)
	{
		write(1, "-", 1);
		ft_putnbr_base((-(long int)nbr) / len, base);
		ft_putnbr_base((-(long int)nbr) % len, base);
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr_base(-nbr, base);
	}
	else if (nbr < len)
	{
		write(1, &base[nbr], 1);
	}
	else
	{
		ft_putnbr_base(nbr / len, base);
		ft_putnbr_base(nbr % len, base);
	}
}
