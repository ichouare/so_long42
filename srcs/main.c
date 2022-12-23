/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:33:26 by ichouare          #+#    #+#             */
/*   Updated: 2022/12/23 20:59:06 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include "get_next_line.h"

void	ft_components_map(t_vars *vars, int j, int k)
{
	if (vars->ptr[j][k] != 'C' && vars->ptr[j][k] != 'P'
		&& vars->ptr[j][k] != 'E' && vars->ptr[j][k] != '1'
		&& vars->ptr[j][k] != '0' && vars->ptr[j][k] != 'D')
		ft_error(vars);
	if (vars->ptr[j][k] == 'P')
		vars->cntp++;
	if (vars->ptr[j][k] == 'E')
		vars->cnte++;
	if (vars->ptr[j][k] == 'D')
		vars->count_en++;
	if (vars->ptr[j][k] == 'C')
		vars->cnt_col++;
}

void	ft_check_componenets(t_vars *vars, int i, int len)
{
	int	j;
	int	k;

	j = 0;
	while (j < i)
	{
		k = 0;
		while (k < len - 1)
		{
			ft_components_map(vars, j, k);
			k++;
		}
		j++;
	}
}

void	check_map(int fd, int i, t_vars *vars)
{
	int	valid_path;
	int	j;

	valid_path = 0;
	j = ft_check_empty(vars, i, fd);
	if (j <= 1)
		ft_error(vars);
	ft_check_componenets(vars, i, ft_strlen(vars->ptr[j - 1]));
	j = 0;
	while (j < i - 1)
	{
		if (found_nl(vars->ptr[j], '\n') == ft_strlen(vars->ptr[i - 1])
			&& (ft_one(vars->ptr[0]) == 1 && ft_one(vars->ptr[i - 1]) == 1)
			&& (vars->ptr[j][0] == '1') && vars->cnt_col >= 1
			&& vars->cntp == vars->cnte == 1
			&& vars->ptr[j][ft_strlen(vars->ptr[i - 1]) - 1] == '1')
				j++;
		else
			ft_error(vars);
	}
	valid_path = ft_valid_path(i, ft_strlen(vars->ptr[i - 1]), vars);
	if (valid_path == 0)
		ft_error(vars);
	drow_o_no(vars, i, j);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	int		i;
	int		fd;
	int		ff;

	i = 0;
	ft_init(&vars);
	if (argc == 1 || check_file(argv[1], &vars) == 0)
		ft_error(&vars);
	fd = open("map.ber", O_RDONLY);
	ff = open("map.ber", O_RDONLY);
	while ((get_next_line(ff)))
		i++;
	if (i == 0)
		ft_error(&vars);
	else
		check_map(fd, i, &vars);
	return (0);
}
