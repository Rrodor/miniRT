/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:12:08 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/07 16:02:16 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include "color.h"

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_F 102
# define KEY_R 114
# define KEY_A 97
# define KEY_Q 113

# define WINX 600
# define WINY 600

# define RAY_MIN 0.0001
# define RAY_MAX 1.0e30

# define GREEN 0x00FF00

# include "ray.h"
# include "vector.h"
# include "inter.h"
# include "camera.h"
# include "color.h"
# include "viewport.h"
# include "libft.h"

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_data		img;
	t_data		img_progress;
	t_list		*objs;
	t_cam		*cam;
	t_viewport	*viewport;
}				t_vars;

// ambiant
typedef struct s_a
{
	char		*id;
	float		ratio;
	t_rgb		*color;
}				t_a;

// light
typedef struct s_l
{
	char		*id;
	t_vec		*pos;
	float		ratio;
	t_rgb		*color;
}				t_l;

// sphere
typedef struct s_sp
{
	char		*id;
	t_rgb		*color;
	t_vec		*pos;
	float		radius;
}				t_sp;

// plane
typedef struct s_pl
{
	char		*id;
	t_rgb		*color;
	t_vec		*pos;
	t_vec		*dir;
}				t_pl;

// cylinder
typedef struct s_cy
{
	char		*id;
	t_rgb		*color;
	t_vec		*pos;
	t_vec		*dir;
	float		radius;
	float		height;
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
int				objreq(t_list *list);

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
void			ray_free(t_ray *ray);
void			viewport_free(t_viewport *viewport);

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

// camera.c
t_cam			*getcam(t_list *list);
void			movecam(int keycode, t_vars *vars);

#endif
