/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevdoki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 20:22:54 by myevdoki          #+#    #+#             */
/*   Updated: 2020/12/07 20:29:26 by myevdoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int a1;
	int b1;

	a1 = *a;
	b1 = *b;
	*a = a1 / b1;
	*b = a1 % b1;
}
