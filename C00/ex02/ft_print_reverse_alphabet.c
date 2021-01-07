/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevdoki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:51:51 by myevdoki          #+#    #+#             */
/*   Updated: 2020/12/09 17:39:37 by myevdoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char last_letter;

	last_letter = 'z';
	while (last_letter >= 'a')
	{
		write(1, &last_letter, 1);
		last_letter--;
	}
}
