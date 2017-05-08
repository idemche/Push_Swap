/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 20:42:49 by idemchen          #+#    #+#             */
/*   Updated: 2017/05/06 22:16:17 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char			*ft_charplus(char const *s1, char c)
{
	char		*str;
	size_t		count;
	size_t		length;

	if (s1 == NULL || !c)
		return (NULL);
	length = __builtin_strlen(s1);
	if ((str = ft_strnew(length + 1)) == NULL)
		return (NULL);
	count = 0;
	while (count < length)
	{
		*(str + count) = *(s1 + count);
		count++;
	}
	*(str + count) = c;
	return (str);
}

static int			ft_copy(char **dst, char *src, char c)
{
	int		one;
	int		two;
	int		point;
	char	*str;

	one = -1;
	two = -1;
	while (src[++one])
		if (src[one] == c)
			break ;
	point = one;
	if (*dst)
		free(*dst);
	if (!(*dst = ft_strnew(one)))
		return (0);
	str = *dst;
	while (src[++two] && two < one)
	{
		if (!(*dst = ft_charplus(*dst, src[two])))
			return (0);
		if (str)
			free(str);
		str = *dst;
	}
	return (point);
}

static int			gnl(char *current[4096][3], char buffer[], const int fd)
{
	size_t		buf;

	buf = 0;
	while ((buf = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[buf] = '\0';
		if (current[fd][0] == NULL)
		{
			if (current[fd][1])
				free(current[fd][1]);
			current[fd][0] = ft_strnew(__builtin_strlen(buffer));
			current[fd][1] = current[fd][0];
		}
		if (!(current[fd][0] = ft_strjoin(current[fd][0], buffer)))
			return (-1);
		if (current[fd][2])
			free(current[fd][2]);
		current[fd][2] = current[fd][0];
		if (__builtin_strchr(buffer, '\n'))
			break ;
	}
	if (buf < BUFF_SIZE &&
		(!current[fd][0] || !__builtin_strlen(current[fd][0])))
		return (0);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	char			buffer[BUFF_SIZE + 1];
	static	char	*file[4096][3];
	int				flag;
	int				ret;

	flag = 0;
	if ((fd < 0 || line == NULL || read(fd, buffer, 0) < 0)
			|| !(*line = ft_strnew(1)))
		return (-1);
	if (!file[fd][0])
	{
		file[fd][0] = NULL;
		file[fd][1] = NULL;
		file[fd][2] = NULL;
	}
	if ((ret = gnl(file, buffer, fd)) == 0)
		return (0);
	else if (ret == -1)
		return (-1);
	((flag = ft_copy(line, file[fd][0], '\n'))
		< (int)__builtin_strlen(file[fd][0])) ?
		file[fd][0] += (flag + 1) : ft_strclr(file[fd][0]);
	return (1);
}
