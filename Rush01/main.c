/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:00:57 by marhamba          #+#    #+#             */
/*   Updated: 2020/12/10 22:10:09 by myevdoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "include.h"

int		main(int argc, char **argv)
{
	int **input;
	int **content;
	int	finished;

	if (argc != 2)
	{
		write(1, "Error1\n", 6);
		return (0);
	}
	if (!check_input(argv[1]))
	{
		write(1, "Error2\n", 6);
		return (0);
	}
	input = int_array(argv[1]);
	content = crt_sqr(4);
	finished = FALSE;
	solution(content, input, &finished);
	if (!finished)
		write(1, "Error3\n", 6);
	return (0);
}
