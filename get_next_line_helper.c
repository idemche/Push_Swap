/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 00:41:46 by idemchen          #+#    #+#             */
/*   Updated: 2017/05/04 00:45:10 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strnew(size_t size)
{
	char	*str;
	size_t	counter;

	counter = 0;
	str = NULL;
	if ((str = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	while ((size-- + 1) != 0)
		str[counter++] = '\0';
	return (str);
}

void		ft_strclr(char *s)
{
	if (s == NULL)
		return ;
	while (*s)
		*s++ = '\0';
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		c;
	int		cc;
	char	*str;

	c = 0;
	cc = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (s1[c++])
		;
	while (s2[cc++])
		;
	if ((str = (char*)malloc(sizeof(str) * (c + cc + 1))) == NULL)
		return (NULL);
	c = -1;
	while (s1[++c])
		str[c] = s1[c];
	cc = 0;
	while (s2[cc])
		str[c++] = s2[cc++];
	str[c] = '\0';
	return (str);
}
