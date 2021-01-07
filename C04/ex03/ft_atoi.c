/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevdoki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 23:30:50 by myevdoki          #+#    #+#             */
/*   Updated: 2020/12/16 14:14:08 by myevdoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(char c)
{
	if (c == '\n' || c == '\t' || c == '\v'
			|| c == '\r' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int		ft_atoi(char *str)
{
	int i;
	int sign;
	int num;

	sign = 1;
	i = 0;
	num = 0;
	while (ft_isspace(*str))
		str++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = sign * (-1);
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10;
			num = num + (str[i++] - '0');
		}
		else
			return (num * sign);
	}
	return (num * sign);
}
