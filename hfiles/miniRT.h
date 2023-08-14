/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:12:08 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/14 15:02:24 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# define KEY_ESC 65307
# define WINX 800
# define WINY 600

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_data		img;
	t_list		*objs;
}				t_vars;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}				t_point;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}				t_rgb;

typedef struct s_a
{
	char	*id;
	float	ratio;
	t_rgb	color;
}				t_a;

typedef struct s_c
{
	char	*id;
	t_point	pos;
	t_point	dir;
	float	fov;
	t_rgb	color;
}				t_c;

typedef struct s_l
{
	char	*id;
	t_point	pos;
	float	ratio;
	t_rgb	color;
}				t_l;

typedef struct s_sp
{
	char	*id;
	t_point	pos;
	float	radius;
	t_rgb	color;
}				t_sp;

typedef struct s_pl
{
	char	*id;
	t_point	pos;
	t_point	dir;
	t_rgb	color;
}				t_pl;

typedef struct s_cy
{
	char	*id;
	t_point	pos;
	t_point	dir;
	float	diameter;
	float	height;
	t_rgb	color;
}				t_cy;

// parse.c
t_list	*parse(char *file);

// tabtoobj.c
t_a		*tabtoamb(char **tab);
t_c		*tabtocam(char **tab);
t_l		*tabtolight(char **tab);
t_sp	*tabtosphere(char **tab);
t_pl	*tabtoplane(char **tab);
t_cy	*tabtocylinder(char **tab);
void	*tabtoobj(char **tab);

// close.c
int		win_close(t_vars *vars);

// free.c
void	a_free(t_a *a);
void	c_free(t_c *c);
void	l_free(t_l *l);
void	freelst(void *content);
void	freetab(void *content);

// free2.c
void	sp_free(t_sp *sp);
void	pl_free(t_pl *pl);
void	cy_free(t_cy *cy);

// utils.c
int		ft_tablen(char **tab);
float	ft_atof(char *str);

#endif
