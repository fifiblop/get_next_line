/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 16:53:20 by pdelefos          #+#    #+#             */
/*   Updated: 2016/01/27 18:39:03 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		add_buff(char **line, char *str)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	if (*line)
	{
		tmp = ft_strdup(*line);
		free(*line);
		len = ft_strlen(tmp) + ft_strlen(str);
		*line = (char*)ft_memalloc(len + 1);
		ft_strcpy(*line, tmp);
		free(tmp);
		while ((*line)[i])
			i++;
	}
	else
	{
		len = ft_strlen(str);
		*line = (char*)ft_memalloc(len + 1);
	}
	while (*str && *str != '\n')
		(*line)[i++] = *str++; 
	(*line)[i] = '\0';
}

static char		*get_after_nl(char *str)
{
	while (*str && *str != '\n')
		str++;
	if (*str == '\n' && str[1] != '\0')
		return (ft_strdup(++str));
	else
		return (NULL);
}

static int		init_next_line(char **line, char **after_nl)
{
	char *tmp;

	if (*after_nl && ft_strchr(*after_nl, '\n'))
	{
		add_buff(line,* after_nl);
		tmp = *after_nl;
		*after_nl = get_after_nl(tmp);
		free(tmp);
		return (1);
	}
	else if (*after_nl && !ft_strchr(*after_nl, '\n'))
	{
		*line = ft_strdup(*after_nl);
		free(*after_nl);
		after_nl = NULL;
	}
	return (0);
}

static int		check_last_line(char **line, char **after_nl, int const fd)
{
	if (line)
		*line = NULL;
	else
		return(-1);
	if (BUFF_SIZE <= 0 || fd < 0)
		return (-1);
	if (init_next_line(line, after_nl))
		return (1);
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	int			check;
	int			ret;
	char		*buff;
	static char	*after_nl = NULL;

	check = check_last_line(line, &after_nl, fd);
	if (check != 0)
		return (check);
	buff = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0 && !ft_strchr(buff, '\n'))
	{
		add_buff(line, buff);
		ft_bzero(buff, BUFF_SIZE + 1);
	}
	if (ret > 0)	
	{
		buff[ret] = '\0';
		add_buff(line, buff);
		after_nl = get_after_nl(buff);
	}
	free(buff);
	ret = (ret > 0) ? 1 : ret;
	ret = (ret == 0 && *line != NULL) ? 1 : ret;
	return (ret);
}
