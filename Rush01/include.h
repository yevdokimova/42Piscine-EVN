/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 21:26:01 by marhamba          #+#    #+#             */
/*   Updated: 2020/12/06 23:09:47 by marhamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# define UNDEFINED 0
# define TRUE 1
# define FALSE 0

enum	e_view_point
{
	col_up,
	col_down,
	row_left,
	row_right
};
typedef	enum e_view_point	t_view_point;

int		solution(int **content, int **input, int *slt);
int		find_zero(int **content, int *row, int *col);
int		is_alone(int **content, int sm, int row, int col);
int		check_viewinput(int **content, int **input);
int		check_line(int **content, t_view_point view, int view_line,
		int cont_viewed);
int	**int_array(char *arg);
int **crt_sqr(int size);
int **sqr_copy(int **sqr);
void	destroy_sqr(int **sqr);
void	display_sqr(int **sqr);
int		view_content(int **content, t_view_point view, int view_line,
		int line_index);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		check_input(char *str);

#endif
