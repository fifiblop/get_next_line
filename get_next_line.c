/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:22:17 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/23 19:02:18 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	int ret;

	ret = read(fd, line, BUFF_SIZE);
	*line[ret] = '\0';
	ft_putstr(*line);
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	char	**c;

	c = NULL;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		get_next_line(fd, c);
		// ft_putstr(*c);
	}
	return 0;
}