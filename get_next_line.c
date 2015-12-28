/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifiblop <fifiblop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:22:17 by pdelefos          #+#    #+#             */
/*   Updated: 2015/12/26 16:30:37 by fifiblop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	int ret;
	char *str;

	(void)line;
	str = "";
	ret = read(fd, str, BUFF_SIZE);
	if (ret > 0)
	{
		ft_putnbr(ret);
		str[ret] = '\0';
		ft_putstr(str);
		return (1);
	}
	return (ret);
}

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	c[BUFF_SIZE + 1];

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		ret = read(fd, c, BUFF_SIZE);
		c[ret] = '\0';
		ft_putstr(c);
		// get_next_line(fd, c);
		// ft_putstr(*c);
	}
	return 0;
}