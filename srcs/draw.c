/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:18:53 by ichouare          #+#    #+#             */
/*   Updated: 2022/12/23 20:51:48 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_init(t_vars *vars)
{
	vars->coor.rear = -1;
	vars->coor.front = -1;
	vars->cnte = 0;
	vars->cntp = 0;
	vars->xp = 0;
	vars->yp = 0;
	vars->mv = 0;
	vars->en_pos = 0;
	vars->count_en = 0;
	vars->cnt_col = 0;
	vars->img = NULL;
	vars->p_wl = "./wall1.xpm";
	vars->p_bg = "./bg2.xpm";
	vars->p_av = "./avatar3.xpm";
	vars->pav2 = "./avatar2.xpm";
	vars->pav3 = "./avatar1.xpm";
	vars->p_col = "./collectible.xpm";
	vars->p_enemie = "./enemi1.xpm";
	vars->p_ext = "./exit.xpm";
	vars->p_dr2 = "./dragon2.xpm";
	vars->p_dr1 = "./dragon.xpm";
	vars->p_dr3 = "./dragon3.xpm";
}

void	so_long(t_vars *vs)
{
	vs->sz_x = vs->c * 50;
	vs->sz_y = vs->r * 50;
	vs->xlm = mlx_init();
	vs->wl = mlx_xpm_file_to_image(vs->xlm, vs->p_wl, &vs->img_w, &vs->img_h);
	vs->pl_1 = mlx_xpm_file_to_image(vs->xlm, vs->p_av, &vs->img_w, &vs->img_h);
	vs->col = mlx_xpm_file_to_image(vs->xlm, vs->p_col, &vs->img_w, &vs->img_h);
	vs->en1 = mlx_xpm_file_to_image(vs->xlm, vs->p_dr1, &vs->img_w, &vs->img_h);
	vs->en2 = mlx_xpm_file_to_image(vs->xlm, vs->p_dr2, &vs->img_w, &vs->img_h);
	vs->en3 = mlx_xpm_file_to_image(vs->xlm, vs->p_dr3, &vs->img_w, &vs->img_h);
	vs->flr = mlx_xpm_file_to_image(vs->xlm, vs->p_bg, &vs->img_w, &vs->img_h);
	vs->out = mlx_xpm_file_to_image(vs->xlm, vs->p_ext, &vs->img_w, &vs->img_h);
	vs->pl_2 = mlx_xpm_file_to_image(vs->xlm, vs->pav2, &vs->img_w, &vs->img_h);
	vs->pl_3 = mlx_xpm_file_to_image(vs->xlm, vs->pav3, &vs->img_w, &vs->img_h);
	vs->win_ptr = mlx_new_window(vs->xlm, vs->sz_x, vs->sz_y, "Dragons GAME.");
	vs->img = mlx_new_image(vs->xlm, 50, 50);
	mlx_hook(vs->win_ptr, 2, 1L << 2, &key_hook, vs);
	mlx_loop_hook(vs->xlm, &draw, vs);
	mlx_loop(vs->xlm);
}

void	input_map(int i, int j, t_vars *vars)
{
	if (vars->ptr[i][j] == '1')
		vars->img = vars->wl;
	else if (vars->ptr[i][j] == '0')
		vars->img = vars->flr;
	else if (vars->ptr[i][j] == 'P')
		vars->img = vars->pl_1;
	else if (vars->ptr[i][j] == 'C')
		vars->img = vars->col;
	else if (vars->ptr[i][j] == 'E')
		vars->img = vars->out;
	else if (vars->ptr[i][j] == 'R')
		vars->img = vars->pl_3;
	else if (vars->ptr[i][j] == 'L')
		vars->img = vars->pl_2;
	else if (vars->ptr[i][j] == 'D')
		sprite(vars);
}

int	draw(t_vars *vars)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	mlx_clear_window(vars->xlm, vars->win_ptr);
	while (i < vars->r && y < vars->sz_y)
	{
		j = 0;
		x = 0;
		while (j < vars->c && x < vars->sz_x)
		{
			input_map(i, j, vars);
			mlx_put_image_to_window(vars->xlm, vars->win_ptr, vars->img, x, y);
			j++;
			x += 50;
		}
		i++;
		y += 50;
	}
	mlx_string_put(vars->xlm, vars->win_ptr, 20, 20, 0xEEE, ft_itoa(vars->mv));
	return (0);
}

void	drow_o_no(t_vars *vars, int i, int j)
{
	if (j == i - 1)
	{
		vars->c = ft_strlen(vars->ptr[i - 1]);
		vars->r = i;
		so_long(vars);
	}
	else
		ft_error(vars);
}
