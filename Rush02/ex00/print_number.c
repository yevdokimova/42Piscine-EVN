/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:43:30 by armgrigo          #+#    #+#             */
/*   Updated: 2020/12/13 18:21:03 by armgrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_cat(char c1, char c2)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 3)))
		return (0);
	str[0] = c1;
	str[1] = c2;
	str[2] = 0;
	return (str);
}

char	*ft_string(char c1)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (0);
	str[0] = c1;
	str[1] = 0;
	return (str);
}

void	print_number(char *str, char *argv, int argc)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	if (len == 1)
		putstr(ft_parse_dict(str, argv));
	else if (len == 2)
		print_tab2(str, argv);
	else
		print_tab3(str, argv, argc);
}
