/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:22:52 by pdelefos          #+#    #+#             */
/*   Updated: 2016/01/27 18:34:33 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define BUFF_SIZE 8

int		get_next_line(int const fd, char **line);

char	*ft_strdup(const char *s1);
int		ft_strlen(char *str);
void	*ft_memalloc(size_t size);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
char	*ft_strnew(size_t size);

void	ft_putnbr(int nb);
void	ft_putstr(char *str);
void	ft_putendl(char *str);

#endif
