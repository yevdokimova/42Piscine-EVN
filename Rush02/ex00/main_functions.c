/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 21:16:07 by armgrigo          #+#    #+#             */
/*   Updated: 2020/12/13 21:18:10 by armgrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	div_string(int *i, char *str, char *argv, int *l)
{
	int		j;
	int		k;

	k = 0;
	j = 0;
	if (*i % 3 != 0)
		while (*i % 3 != 0)
		{
			str[k] = argv[*l];
			(*i)--;
			k++;
			(*l)++;
		}
	else
		while (j < 3)
		{
			str[k] = argv[*l];
			j++;
			k++;
			(*l)++;
		}
	str[k] = 0;
}

int		check_string(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		return (-1);
	if (argc > 3)
		return (-1);
	if (ft_strcmp(argv[1], "-p") == 0)
		argv[1] = get_nb_from_pipe();
	i = 0;
	if (argv[1][0] == '0')
		ft_remove_start_zeros(&argv[1]);
	if (argv[1][0] == '\0')
		return (-1);
	while (argv[1][i])
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
			return (-1);
		i++;
	}
	if (argc == 3)
		comp_str_dict(i, argv[2]);
	else
		comp_str_dict(i, "numbers.dict");
	return (i);
}

void	print_words_2(int argc, char *str, int j, char **argv)
{
	if (argc == 3)
		print_number(str, argv[2], argc);
	else
		print_number(str, "numbers.dict", argc);
	if (ft_strcmp(str, "000") != 0 && j != 1)
	{
		if (argc == 3)
			ft_print_separator_with_space(j, argv[2]);
		else
			ft_print_separator_with_space(j, "numbers.dict");
	}
}

void	print_words(int i, char **argv, char *str, int argc)
{
	int j;
	int k;
	int	l;

	j = i / 3;
	if (i % 3 != 0)
		j++;
	k = j;
	while (j != 0)
	{
		div_string(&i, str, argv[1], &l);
		if (j != k && ft_strcmp(str, "000") != 0)
		{
			if (argc == 2)
				write(1, ",", 1);
			write(1, " ", 1);
		}
		if ((j == 1 && ft_strcmp(str, "000") != 0 && str[0] == '0'
					&& k != 1) && argc == 2)
			write(1, "and ", 4);
		print_words_2(argc, str, j, argv);
		j--;
	}
	write(1, "\n", 1);
}
