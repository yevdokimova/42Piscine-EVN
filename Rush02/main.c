/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:39:31 by armgrigo          #+#    #+#             */
/*   Updated: 2020/12/13 17:43:12 by armgrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		main(int argc, char **argv)
{
	int		i;
	char	*str;

	if ((i = check_string(argc, argv)) == -1)
		ft_error();
	if (!(str = (char *)malloc(sizeof(char) * 4)))
		ft_error();
	print_words(i, argv, str, argc);
}
