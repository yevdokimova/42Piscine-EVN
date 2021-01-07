/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 18:48:51 by armgrigo          #+#    #+#             */
/*   Updated: 2020/12/13 18:49:09 by armgrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <sys/types.h>

int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_parse_dict(char *str, char *argv);
void	print_number(char *str, char *argv, int argc);
void	div_string(int *i, char *str, char *argv, int *l);
void	print_tab2(char *str, char *argv);
void	print_tab3_2(char *str, int argc, char *argv);
void	print_tab3(char *str, char *argv, int argc);
char	*ft_cat(char c1, char c2);
char	*ft_string(char c1);
void	print_number(char *str, char *argv, int argc);
int		check_string(int argc, char **argv);
void	print_words(int i, char **argv, char *str, int argc);
void	putstr(char *str);
void	print_separator(int j, char *argv);
char	*create_number(int j);
char	*get_nb_from_pipe(void);
void	ft_go_to_next_line(int *fd, int *i);
void	ft_error(void);
void	comp_str_dict(int len, char *argv);
void	ft_remove_start_zeros(char **str);
int		ft_realloc(char **str, char sign);
void	ft_print_separator_with_space(int j, char *argv);

#endif
