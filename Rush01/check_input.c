/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:49:10 by marhamba          #+#    #+#             */
/*   Updated: 2020/12/10 21:58:51 by myevdoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int		check_input(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '1' && str[i] <= '4'))
			return (FALSE);
		i++;
		if(!str[i])
			break ;
		if (str[i] != ' ')
			return (FALSE);
		i++;
	}
	if (i != 31)
		return (FALSE);
	return (TRUE);
}
