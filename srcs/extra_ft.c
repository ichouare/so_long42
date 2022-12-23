/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:25:48 by ichouare          #+#    #+#             */
/*   Updated: 2022/12/23 20:56:46 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *str)
{
	char	*arr;
	int		i;

	arr = NULL;
	i = 0;
	arr = (char *)malloc((sizeof(char) * ft_strlen(str) + 1));
	if (!arr)
		return (NULL);
	while (*(str + i) != '\0')
	{
		*(arr + i) = *(str + i);
		i++;
	}
	*(arr + i) = '\0';
	return (arr);
}

int	ft_check_empty(t_vars *vars, int i, int fd)
{
	char	*str;
	int		j;

	str = NULL;
	j = 0;
	vars->ptr = ft_calloc(sizeof(char *), i);
	while (i > j)
	{
		str = get_next_line(fd);
		if (*str == '\n' || *str == '\0' || !str)
			ft_error(vars);
		vars->ptr[j] = ft_strdup(str);
		j++;
	}
	return (j);
}

void	ft_free(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->r)
	{
		free(vars->ptr[i]);
		i++;
	}
	free(vars->ptr);
}

void	ft_error(t_vars *vars)
{	
	if (vars->ptr)
		ft_free(vars);
	perror("not valible game with this map");
	exit(0);
}

int	ft_validation(t_vars *vars)
{
	int	count_c;
	int	exit_e;
	int	i;

	count_c = 0;
	exit_e = 0;
	i = 0;
	while (i < vars->coor.rear - 1)
	{
		if (vars->ptr[vars->coor.tabx[i]][vars->coor.taby[i]] == 'C')
			count_c++;
		if (vars->ptr[vars->coor.tabx[i]][vars->coor.taby[i]] == 'E')
			exit_e = 1;
		i++;
	}
	free(vars->coor.tabx);
	free(vars->coor.taby);
	if (count_c == vars->cnt_col && exit_e == 1)
		return (1);
	else
		return (0);
}
