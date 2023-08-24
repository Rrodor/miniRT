/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:12:08 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/24 17:46:14 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

# define KEY_ESC 65307

# define WINX 500
# define WINY 500

# define RAY_MIN 0.0001
# define RAY_MAX 1.0e30

# include "ray.h"
# include "vector.h"
# include "inter.h"
# include "position.h"
# include "camera.h"
# include "color.h"

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_vars
{
	void		*mlx;
	void		*win;
	t_data		img;
	t_list		*objs;
}				t_vars;

// ambiant
typedef struct	s_a
{
	char		*id;
	float		ratio;
	t_rgb		color;
}				t_a;

// light
typedef struct	s_l
{
	char		*id;
	t_pos		pos;
	float		ratio;
	t_rgb		color;
}				t_l;

// sphere
typedef struct	s_sp
{
	char		*id;
	t_pos		pos;
	float		radius;
	t_rgb		color;
}				t_sp;

// plane
typedef struct 	s_pl
{
	char		*id;
	t_pos		*pos;
	t_vec		*dir;
	t_rgb		color;
}				t_pl;

// cylinder
typedef struct	s_cy
{
	char		*id;
	t_pos		pos;
	t_vec		dir;
	float		diameter;
	float		height;
	t_rgb		color;
}				t_cy;

// parse.c
t_list			*parse(int fd);
int				opener(char *file, int *fd);

// tabtoobj.c
t_a				*tabtoamb(char **tab);
t_cam			*tabtocam(char **tab);
t_l				*tabtolight(char **tab);
t_sp			*tabtosphere(char **tab);
t_pl			*tabtoplane(char **tab);
t_cy			*tabtocylinder(char **tab);
void			*tabtoobj(char **tab);

// close.c
int				win_close(t_vars *vars);

// free.c
void			a_free(t_a *a);
void			c_free(t_cam *c);
void			l_free(t_l *l);
void			freelst(void *content);
void			freetab(void *content);

// free2.c
void			sp_free(t_sp *sp);
void			pl_free(t_pl *pl);
void			cy_free(t_cy *cy);

// utils.c
int				tablen(char **tab);
float			ft_atof(char *str);
int				isfloat(char *str);

// error.c
int				rt_error(char **str);
int				error_a(char **str);
int				error_c(char **str);
int				error_l(char **str);
int				error_color(char *str);

// errorform.c
int				errorform(char **str);
int				error_sp(char **str);
int				error_pl(char **str);
int				error_cy(char **str);
int				error_vector(char *str);

// render.c
int				render(t_vars *vars);

// viewport.h
t_pos			*get_pixel_center(int x, int y);

//ray.h
int		hit_plane(t_pl *plane, t_ray *ray);

#endif
