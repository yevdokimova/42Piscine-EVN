/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevdoki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 23:46:04 by myevdoki          #+#    #+#             */
/*   Updated: 2020/12/16 09:46:51 by myevdoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		get_value(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	if (i >= ft_strlen(base))
		return (-1);
	return (i);
}

int		ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int		ft_check_base(char *str)
{
	int i;
	int j;

	if (ft_strlen(str) <= 1)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 127 || ft_isspace(str[i]) ||
				str[i] == '-' || str[i] == '+')
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[j] == str[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_atoi_base(char *str, char *base)
{
	int		i;
	int		b;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (!ft_check_base(base))
		return (0);
	b = ft_strlen(base);
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (get_value(str[i], base) >= 0)
	{
		res = res * b + get_value(str[i], base);
		i++;
	}
	return (res * sign);
}
