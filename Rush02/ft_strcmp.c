/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:32:44 by armgrigo          #+#    #+#             */
/*   Updated: 2020/12/13 17:34:32 by armgrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_print_separator_with_space(int j, char *argv)
{
	write(1, " ", 1);
	print_separator(j, argv);
}

void	ft_remove_start_zeros(char **str)
{
	char	*str_cpy;
	int		i;
	int		j;

	if (!(str_cpy = (char *)malloc(sizeof(char) * (ft_strlen(*str) + 1))))
		ft_error();
	i = 0;
	j = 0;
	while ((*str)[i] == '0')
		i++;
	while ((*str)[i])
	{
		str_cpy[j] = (*str)[i];
		i++;
		j++;
	}
	if (j == 0)
		str_cpy[j++] = '0';
	str_cpy[j] = '\0';
	*str = str_cpy;
	ft_realloc(str, '-');
}

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	if (s2[i] == '\0')
		return (0);
	else
		return (-s2[i]);
}
