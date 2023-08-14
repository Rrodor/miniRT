/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:02:21 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/14 15:08:37 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		win_close(vars);
	return (0);
}

void	ft_lstprint(void *content)
{
	t_a	*a;

	a = (t_a *)content;
	ft_printf("%s\n", a->id);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_list	*list;

	if (argc != 2)
		return (0);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WINX, WINY, "miniRT");
	vars.img.img = mlx_new_image(vars.mlx, WINX, WINY);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &(vars.img).bits_per_pixel,
			&(vars.img).line_length, &(vars.img).endian);
	list = parse(argv[1]);
	if (list == NULL)
		return (1);
	vars.objs = list;
	ft_lstiter(list, &ft_lstprint);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_hook(vars.win, 17, 0L, win_close, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
