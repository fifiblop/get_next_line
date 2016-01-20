/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:22:17 by pdelefos          #+#    #+#             */
/*   Updated: 2016/01/20 20:48:11 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_clnjoin(char *s1, char *s2)
{
	char	*merged;

	merged = ft_strjoin(s1, s2);
	free(s1);
	return (merged);
}

int		sizeofline(char *buff)
{
	char *pos;

	if ((pos = ft_strchr(buff, '\n')))
		return (ft_strlen(buff) - ft_strlen(pos));
	return (0);
}

char	*get_last(char **last_nl, char **line)
{
	char	*tmp;
	int		size;

	tmp = *last_nl;
	if ((tmp = ft_strchr(*last_nl, '\n')) != NULL)
	{
		*tmp = '\0';
		size = ft_strlen(*last_nl);
		*tmp = '\n';
		*line = ft_strsub(*last_nl, 0, size);
		return (*last_nl + size);
	}
	*line = ft_strdup(*last_nl);
	return (*last_nl + ft_strlen(*last_nl));
}

int		split_buff(char *buff, char **last_nl, char **line)
{
	/*int	linesize;*/

	if ((*last_nl = ft_strchr(buff, '\n')) != NULL)
	{
		/*linesize = sizeofline(buff);*/
		/**last_nl = ft_strsub(buff, linesize, ft_strlen(*last_nl) + 1);*/
		*last_nl = ft_strsub(buff, ft_strlen(buff) - ft_strlen(*last_nl), 
					ft_strlen(*last_nl));
		if (*line)
			*line = ft_strjoin(*line, ft_strsub(buff, 0, ft_strlen(buff)
					- ft_strlen(*last_nl)));
		else
			*line = ft_strdup(ft_strsub(buff, 0, ft_strlen(buff)
					- ft_strlen(*last_nl)));
		return (1);
	}
	if (*line)
		*line = ft_strjoin(*line, buff);
	else
		*line = ft_strdup(buff);
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static char	*last_nl;
	int			ret;
	char		buff[BUFF_SIZE + 1];

	if (!line || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (last_nl)
	{
		last_nl = get_last(&last_nl, line);
		if (*last_nl == '\n')
		{
			last_nl++;
			return (1);
		}
	}
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (split_buff(buff, &last_nl, line) == 1)
			return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		gnl;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		gnl = get_next_line(fd, &line);
		ft_putnbr(gnl);
		ft_putendl(line);
		gnl = get_next_line(fd, &line);
		ft_putnbr(gnl);
		ft_putendl(line);
	}
	return (0);
}
