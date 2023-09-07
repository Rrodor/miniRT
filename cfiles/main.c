/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:02:21 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/07 18:13:20 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		win_close(vars);
	else
		movecam(keycode, vars);
	return (0);
}

void	ft_lstprint(void *content)
{
	t_a	*a;

	a = (t_a *)content;
	ft_printf("%s\n", a->id);
}

int	testmain(int argc, char **argv, int *fd, t_list **list)
{
	if (argc != 2)
	{
		ft_printf("Error\nWrong number of arguments\n");
		return (-1);
	}
	if (opener(argv[1], fd) == -1)
		return (-1);
	*list = parse(*fd);
	if (objreq(*list) == -1)
		return (-1);
	if (*list == NULL)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_list	*list;
	int		fd;

	if (testmain(argc, argv, &fd, &list) == -1)
		return (1);
	vars.objs = list;
	vars.cam = getcam(list);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WINX, WINY, "miniRT");
	vars.img.img = mlx_new_image(vars.mlx, WINX, WINY);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &(vars.img).bits_per_pixel,
			&(vars.img).line_length, &(vars.img).endian);
	vars.img_progress.img = mlx_new_image(vars.mlx, WINX, WINY);
	vars.img_progress.addr = mlx_get_data_addr(vars.img_progress.img,
			&(vars.img_progress).bits_per_pixel,
			&(vars.img_progress).line_length, &(vars.img_progress).endian);
	vars.viewport = init_viewport(vars.cam);
	render(&vars);
	mlx_hook(vars.win, 17, 0L, win_close, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
