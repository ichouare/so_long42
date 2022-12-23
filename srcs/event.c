/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:32:38 by ichouare          #+#    #+#             */
/*   Updated: 2022/12/23 20:43:06 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"
#include <mlx.h>

int	key_hook(int keycode, t_vars *vars)
{
	int	tmpx;
	int	tmpy;

	tmpx = 0;
	tmpy = 0;
	if (keycode == 0)
		mov_left(vars, tmpx, tmpy);
	else if (keycode == 2)
		mov_right(vars, tmpx, tmpy);
	else if (keycode == 13)
		movup(vars, tmpx, tmpy);
	else if (keycode == 1)
		mov_down(vars, tmpx, tmpy);
	else if (keycode == 53)
		ft_close(vars, "good by");
	return (0);
}

int	mov_left(t_vars *vars, int tmpx, int tmpy)
{
	if (vars->ptr[vars->xp][vars->yp - 1] == 'E')
	{
		if (vars->cnt_col == 0)
			ft_close(vars, "good by!!!");
		return (0);
	}
	else if (vars->ptr[vars->xp][vars->yp - 1] == 'D')
		ft_close(vars, "Game over!!!");
	else if (vars->ptr[vars->xp][vars->yp - 1] != '1')
	{
		if (vars->ptr[vars->xp][vars->yp - 1] == 'C')
			vars->cnt_col--;
		tmpx = vars->xp;
		tmpy = vars->yp;
		vars->ptr[tmpx][tmpy] = '0';
		vars->yp -= 1;
		vars->ptr[vars->xp][vars->yp] = 'R';
		vars->mv += 1;
	}
	return (0);
}

int	mov_down(t_vars *vars, int tmpx, int tmpy)
{
	if (vars->ptr[vars->xp + 1][vars->yp] == 'E')
	{
		if (vars->cnt_col == 0)
			ft_close(vars, "good by!!!");
		return (0);
	}
	else if (vars->ptr[vars->xp + 1][vars->yp] == 'D')
		ft_close(vars, "Game over!!!");
	else if (vars->ptr[vars->xp + 1][vars->yp] != '1')
	{
		if (vars->ptr[vars->xp + 1][vars->yp] == 'C')
			vars->cnt_col--;
		tmpx = vars->xp;
		tmpy = vars->yp;
		vars->ptr[tmpx][tmpy] = '0';
		vars->xp += 1;
		vars->ptr[vars->xp][vars->yp] = 'P';
		vars->mv += 1;
	}
	return (0);
}

int	movup(t_vars *vars, int tmpx, int tmpy)
{
	if (vars->ptr[vars->xp - 1][vars->yp] == 'E')
	{
		if (vars->cnt_col == 0)
			ft_close(vars, "good by!!!");
		return (0);
	}
	else if (vars->ptr[vars->xp - 1][vars->yp] == 'D')
		ft_close(vars, "Game over!!!");
	else if (vars->ptr[vars->xp - 1][vars->yp] != '1')
	{
		if (vars->ptr[vars->xp - 1][vars->yp] == 'C')
			vars->cnt_col--;
		tmpx = vars->xp;
		tmpy = vars->yp;
		vars->ptr[tmpx][tmpy] = '0';
		vars->xp -= 1;
		vars->ptr[vars->xp][vars->yp] = 'P';
		vars->mv += 1;
	}
	return (0);
}

int	mov_right(t_vars *vars, int tmpx, int tmpy)
{
	if (vars->ptr[vars->xp][vars->yp + 1] == 'E')
	{
		if (vars->cnt_col == 0)
			ft_close(vars, "good by!!!");
		return (0);
	}
	else if (vars->ptr[vars->xp][vars->yp + 1] == 'D')
		ft_close(vars, "Game over!!!");
	else if (vars->ptr[vars->xp][vars->yp + 1] != '1')
	{
		if (vars->ptr[vars->xp][vars->yp + 1] == 'C')
			vars->cnt_col--;
		tmpx = vars->xp;
		tmpy = vars->yp;
		vars->ptr[tmpx][tmpy] = '0';
		vars->yp += 1;
		vars->ptr[vars->xp][vars->yp] = 'L';
		vars->mv += 1;
	}
	return (0);
}
