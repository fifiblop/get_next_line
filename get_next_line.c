/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:22:17 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/28 18:42:09 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	int ret;
	char	*str;

	line = (char**)malloc(sizeof(char*) * 1);
	if (!(*line = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	str = (char*)malloc(sizeof(char) * 12);
	ret = read(fd, str, BUFF_SIZE);
	ft_putnbr(ret);
	str[ret] = '\0';
	ft_strcpy(*line, str);
	ft_putstr(*line);
	return (ret);
}

int		main(int ac, char **av)
{
	int		fd;
	char	**c;

	ft_putnbr(sizeof(unsigned int));
	if (ac == 2)
	{
		c = NULL;
		fd = open(av[1], O_RDONLY);
		get_next_line(fd, c);
	}
	return 0;
}