/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:46:56 by idemchen          #+#    #+#             */
/*   Updated: 2017/05/06 05:21:28 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFF_SIZE 32

char		*ft_strnew(size_t size);
void		ft_strclr(char *s);
char		*ft_strjoin(char const *s1, char const *s2);
int			get_next_line(const int fd, char **line);

#endif
