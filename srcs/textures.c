/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:00:00 by ichouare          #+#    #+#             */
/*   Updated: 2022/12/23 19:57:20 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_one(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_file(char *arg, t_vars *vars)
{
	int		i;
	char	*str;
	char	*str2;

	i = ft_strlen(arg) - 1;
	str2 = ".ber";
	while (i > 0)
	{
		if (arg[i] == '.')
			str = &arg[i];
		i--;
	}
	i = 0;
	if (!str)
		return (0);
	while (str2[i])
	{
		if (str[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

void	sprite(t_vars *vars)
{
	if (vars->en_pos <= (vars->count_en * 5))
	{
		vars->en_pos++;
		vars->img = vars->en1;
	}
	else if (vars->en_pos > (vars->count_en * 5)
		&& vars->en_pos <= (vars->count_en * 5 * 4))
	{
		vars->en_pos++;
		vars->img = vars->en2;
	}
	else if (vars->en_pos > (vars->count_en * 5 * 4)
		&& vars->en_pos <= (vars->count_en * 5 * 4))
	{
		vars->en_pos++;
		vars->img = vars->en3;
	}
	else if (vars->en_pos > (vars->count_en * 5 * 4))
		vars->en_pos = 0;
}

void	ft_close(t_vars *vars, char *message)
{
	write (1, message, ft_strlen(message) + 1);
	vars->ptr[vars->xp][vars->yp] = '0';
	mlx_destroy_window(vars->xlm, vars->win_ptr);
	exit(0);
}
