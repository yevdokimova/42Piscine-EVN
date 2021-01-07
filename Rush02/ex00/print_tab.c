/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 21:19:10 by armgrigo          #+#    #+#             */
/*   Updated: 2020/12/13 21:20:29 by armgrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	print_tab2(char *str, char *argv)
{
	if (str[0] == '1')
		putstr(ft_parse_dict(ft_cat(str[0], str[1]), argv));
	else
	{
		putstr(ft_parse_dict(ft_cat(str[0], '0'), argv));
		if (str[1] != '0')
		{
			write(1, "-", 1);
			putstr(ft_parse_dict(ft_string(str[1]), argv));
		}
	}
}

void	print_tab3_2(char *str, int argc, char *argv)
{
	putstr(ft_parse_dict(ft_string(str[0]), argv));
	write(1, " ", 1);
	putstr(ft_parse_dict("100", argv));
	if (str[1] != '0' || str[2] != '0')
	{
		if (argc == 2)
			write(1, " and", 4);
		write(1, " ", 1);
	}
}

void	print_tab3(char *str, char *argv, int argc)
{
	if (str[0] != '0')
	{
		print_tab3_2(str, argc, argv);
	}
	if (str[1] != '0' || str[2] != '0')
	{
		if (str[1] == '0')
			putstr(ft_parse_dict(&str[2], argv));
		else if (str[1] == '1')
			putstr(ft_parse_dict(ft_cat(str[1], str[2]), argv));
		else
		{
			putstr(ft_parse_dict(ft_cat(str[1], '0'), argv));
			if (str[2] != '0')
			{
				if (argc == 2)
					write(1, "-", 1);
				putstr(ft_parse_dict(ft_string(str[2]), argv));
			}
		}
	}
}
