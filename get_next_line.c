/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:22:17 by pdelefos          #+#    #+#             */
/*   Updated: 2016/01/13 19:26:18 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	int		ret;
	char	*str;

	line = (char**)malloc(sizeof(char*));
	if (!(*line = (char*)malloc(sizeof(char))))
		return (-1);
	str = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while ((ret = read(fd, str, BUFF_SIZE)))
	{
		str[ret] = '\0';
		*line = ft_strjoin(*line, str);
		if (ft_strchr(*line, '\n') != NULL)
		{
			*line = ft_strsplit(*line, '\n')[0];
			ft_putstr(*line);
			return (ret);
		}
	}
	return (ret);
}

int		main(int ac, char **av)
{
	int		fd;
	char	**c;

	if (ac == 2)
	{
		c = NULL;
		fd = open(av[1], O_RDONLY);
		get_next_line(fd, c);
		/*get_next_line(fd, c);*/
		/*get_next_line(fd, c);*/
		/*get_next_line(fd, c);*/
	}
	return (0);
}
