/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_dict_length.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:34:54 by armgrigo          #+#    #+#             */
/*   Updated: 2020/12/13 17:37:04 by armgrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		ft_verif_dict_lenght(char *argv)
{
	int		i;
	int		j;
	int		fd;
	char	buffer;

	j = 0;
	i = -1;
	if ((fd = open(argv, O_RDONLY)) == -1)
		return (0);
	while (read(fd, &buffer, 1))
	{
		if (buffer == ' ' || buffer == ':')
		{
			if (i > j)
				j = i;
			ft_go_to_next_line(&fd, &i);
			continue ;
		}
		i++;
	}
	return (j + 2);
}

void	comp_str_dict(int len, char *argv)
{
	int len_max;

	len_max = ft_verif_dict_lenght(argv);
	if (len_max < len)
		ft_error();
}
