/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:33:08 by ichouare          #+#    #+#             */
/*   Updated: 2022/12/21 14:31:46 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <stdio.h>
#include "get_next_line.h"

void	enqueue(int i, int j, t_vars *vars, int size)
{
	int	k;

	if (vars->coor.rear == -1 && vars->coor.front == -1)
	{
		vars->coor.rear = 0;
		vars->coor.front = 0;
		vars->coor.tabx[vars->coor.rear] = i;
		vars->coor.taby[vars->coor.rear] = j;
	}
	else if (vars->coor.rear == size - 1)
		return ;
	else
	{
		k = 0;
		while (k <= vars->coor.rear)
		{
			if (vars->coor.tabx[k] == i && vars->coor.taby[k] == j)
				return ;
			k++;
		}
		vars->coor.rear++;
		vars->coor.tabx[vars->coor.rear] = i;
		vars->coor.taby[vars->coor.rear] = j;
	}
}

void	put_coordination(int *tabx, int *taby, t_vars *vars, int size)
{
	int	i;
	int	j;

	while (vars->coor.front <= vars->coor.rear)
	{
		i = tabx[vars->coor.front];
		j = taby[vars->coor.front];
		if (vars->ptr[i][j + 1] != '1')
			enqueue(i, j + 1, vars, size);
		if (vars->ptr[i][j - 1] != '1')
			enqueue(i, j - 1, vars, size);
		if (vars->ptr[i + 1][j] != '1')
			enqueue(i + 1, j, vars, size);
		if (vars->ptr[i - 1][j] != '1')
			enqueue(i - 1, j, vars, size);
		vars->coor.front++;
	}
}

int	ft_extra_check(t_vars *vars, int i, int j)
{
	if (vars->ptr[i][j] == 'C')
	{
		if (vars->ptr[i + 1][j] == '1' && vars->ptr[i - 1][j] == '1'
			&& vars->ptr[i][j + 1] == '1' && vars->ptr[i][j - 1] == '1')
			return (0);
	}
	return (0);
}

int	ft_coor_player(int j, int i, int size, t_vars *vars)
{
	if (vars->ptr[i][j] == 'C')
	{
		if (vars->ptr[i + 1][j] == '1' && vars->ptr[i - 1][j] == '1'
			&& vars->ptr[i][j + 1] == '1' && vars->ptr[i][j - 1] == '1')
			return (0);
	}
	if (vars->ptr[i][j] == 'P')
	{
		vars->xp = i;
		vars->yp = j;
		enqueue(i, j, vars, size);
		return (0);
	}
	return (0);
}

int	ft_valid_path(int r, int c, t_vars *vars)
{
	int	size;
	int	j;
	int	i;

	size = r * c;
	vars->coor.tabx = malloc(sizeof(int) * (size + 1));
	vars->coor.taby = malloc(sizeof(int) * (size +1));
	vars->coor.front = -1;
	vars->coor.rear = -1;
	i = 0;
	j = 0;
	while (i < r - 1)
	{
		j = 0;
		while (j < c - 1)
		{
			ft_coor_player(j, i, size, vars);
			j++;
		}
		i++;
	}
	put_coordination(vars->coor.tabx, vars->coor.taby, vars, size);
	return (ft_validation(vars));
}
