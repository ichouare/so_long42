/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:33:00 by ichouare          #+#    #+#             */
/*   Updated: 2022/12/23 20:51:08 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef   GET_NEXT_LINE_H
# define    GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include  <stdio.h>
# include <mlx.h>

typedef struct path_coor
{
	int	*tabx;
	int	*taby;
	int	size;
	int	rear;
	int	front;

}	t_coor;

typedef struct s_vars
{
	void	*xlm;
	void	*win_ptr;
	void	*win;
	char	**ptr;
	int		xp;
	int		yp;
	int		sz_x;
	int		sz_y;
	int		img_w;
	int		img_h;
	char	*p_wl;
	char	*p_bg;
	char	*p_av;
	char	*pav2;
	char	*pav3;
	char	*p_dr2;
	char	*p_dr1;
	char	*p_dr3;
	int		en_pos;
	char	*p_col;
	char	*p_enemie;
	char	*p_ext;
	int		cntp;
	int		cnte;
	int		enemie_animy;
	t_coor	coor;
	int		r;
	int		c;
	int		mv;
	int		count_en;
	int		cnt_col;
	void	*img;
	void	*wl;
	void	*pl_1;
	void	*col;
	void	*en1;
	void	*en2;
	void	*en3;
	void	*flr;
	void	*out;
	void	*pl_2;
	void	*pl_3;
}	t_vars;

void	ft_init(t_vars *vars);
int		found_nl(const char *str, int c);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char const *s, unsigned int start, int len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t number, size_t size);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
void	ft_check_componenets(t_vars *vars, int i, int len);
void	so_long(t_vars *vars);
int		ft_valid_path(int r, int c, t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		draw(t_vars *vars);
char	*ft_itoa(int n);
void	ft_close(t_vars *vars, char *message);
int		mov_down(t_vars *vars, int tmpX, int tmpY);
int		movup(t_vars *vars, int tmpX, int tmpY);
int		mov_right(t_vars *vars, int tmpX, int tmpY);
int		mov_left(t_vars *vars, int tmpX, int tmpY);
void	sprite(t_vars *vars);
int		check_file(char *arg, t_vars *vars);
int		ft_strlen(char *str);
int		ft_one(char *str);
void	drow_o_no(t_vars *vars, int i, int j);
void	ft_error(t_vars *vars);
int		ft_check_empty(t_vars *vars, int i, int fd);
void	ft_components_map(t_vars *vars, int j, int k);
int		ft_validation(t_vars *vars);

#endif