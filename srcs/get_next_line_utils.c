/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:32:46 by ichouare          #+#    #+#             */
/*   Updated: 2022/12/16 18:01:00 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found_nl(const char *str, int c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != (char)c)
		i++;
	return (i);
}

//join function 
static char	*strimplement(char *str, char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s1[j])
	{
		str[i] = s1[j];
		j++;
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char			*str;

	if (!s2)
		return (NULL);
	str = NULL;
	str = (char *)malloc(sizeof(char) * (found_nl(s1, '\0')
				+ found_nl(s2, '\0') + 1));
	if (!str)
		return (NULL);
	return (strimplement(str, s1, s2));
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*arr;
	size_t	i;
	int		size;

	arr = NULL;
	i = 0;
	if (!s)
		return (NULL);
	if (found_nl(s, '\0') > len)
		size = len;
	else
		size = found_nl(s, '\0') - start;
	arr = (char *)(malloc(sizeof(char) * (size + 1)));
	if (!arr)
		return (NULL);
	while (size--)
	{
		*(arr + i) = *(s + start + i);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

//fucntion strchr for '\n
char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char)c)
	{
		if (!*s)
			return (0);
		s++;
	}
	return (s);
}
