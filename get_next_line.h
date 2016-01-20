/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <pdelefos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:22:52 by pdelefos          #+#    #+#             */
/*   Updated: 2016/01/20 20:45:51 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define BUFF_SIZE 1

int		get_next_line(int const fd, char **line);

void	ft_putstr(char *str);
void	ft_putendl(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
char	**ft_strsplit(char const *s, char c);
char	*ft_strnew(size_t size);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(char *str);

#endif
