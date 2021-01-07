/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:14:15 by armgrigo          #+#    #+#             */
/*   Updated: 2020/12/13 17:32:00 by armgrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		ft_word_len(int i, char *argv)
{
	int		len;
	int		fd;
	char	buffer;

	len = 0;
	if ((fd = open(argv, O_RDONLY)) == -1)
		return (0);
	while (i-- > 0)
		read(fd, &buffer, 1);
	while (read(fd, &buffer, 1) && buffer == ' ')
		;
	read(fd, &buffer, 1);
	while (read(fd, &buffer, 1) && buffer == ' ')
		;
	while (read(fd, &buffer, 1) && buffer != '\n')
		len++;
	return (len);
}

char	*ft_get_word_in_dict(int fd, int nb_char, char buffer, char *argv)
{
	char	*str;
	int		i;
	int		read_bytes;

	i = ft_word_len(nb_char, argv);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1) * 100)))
		return (0);
	while (buffer == ' ')
		read_bytes = read(fd, &buffer, 1);
	read_bytes = read(fd, &buffer, 1);
	while (buffer == ' ')
		read_bytes = read(fd, &buffer, 1);
	i = 0;
	while (buffer != '\n' && read_bytes != 0)
	{
		str[i] = buffer;
		i++;
		read_bytes = read(fd, &buffer, 1);
	}
	str[i] = '\0';
	return (str);
}

void	ft_go_to_next_line(int *fd, int *i)
{
	char	buffer;

	while (read(*fd, &buffer, 1))
	{
		if (buffer == '\n')
			break ;
	}
	*i = 0;
}

char	*ft_remove_multiple_space(char *str)
{
	char	*str_cpy;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(str);
	if (!(str_cpy = (char *)malloc(sizeof(char) * (len + 100))))
		ft_error();
	i = 1;
	j = 1;
	str_cpy[0] = str[0];
	while (str[i])
	{
		if (!(str[i] == ' ' && str[i - 1] == ' '))
		{
			str_cpy[j] = str[i];
			j++;
		}
		i++;
	}
	str_cpy[j] = '\0';
	ft_realloc(&str_cpy, '-');
	return (str_cpy);
}

char	*ft_parse_dict(char *str, char *argv)
{
	int		fd;
	int		i;
	char	buffer;
	char	*output;

	if ((fd = open(argv, O_RDONLY)) == -1)
		return (0);
	i = 0;
	while (read(fd, &buffer, 1))
	{
		if (str[i] != buffer && str[i] != '\0')
		{
			ft_go_to_next_line(&fd, &i);
			continue ;
		}
		if ((buffer == ':' || buffer == ' ') && str[i] == '\0')
			output = ft_get_word_in_dict(fd, i, buffer, argv);
		if (str[i] == '\0')
		{
			ft_go_to_next_line(&fd, &i);
			continue ;
		}
		i++;
	}
	return (ft_remove_multiple_space(output));
}
