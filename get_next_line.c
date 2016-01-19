/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:22:17 by pdelefos          #+#    #+#             */
/*   Updated: 2016/01/19 18:33:43 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_cleanjoin(char *s1, char *s2)
{
	char *str;

	str = ft_strjoin(s1, s2);
	ft_putstr("hello");
	free(s1);
	return (str);
}


int		get_next_line(int const fd, char **line)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];

	/*if (!line || BUFF_SIZE <= 0 || fd < 0)*/
		/*return (-1);*/
	(void)line;
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		ft_putstr(buff);
		/**line = str_cleanjoin(*line, buff);*/
		if (ft_strchr(buff, '\n') != NULL)
			return (0);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	int		gnl;
	char	**c;

	if (ac == 2)
	{
		c = NULL;
		fd = open(av[1], O_RDONLY);
		gnl = get_next_line(fd, c);

	}
	return (0);
}
