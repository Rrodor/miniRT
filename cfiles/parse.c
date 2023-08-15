/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:56:52 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/15 13:28:14 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	opener(char *file, int *fd)
{
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
	{
		ft_printf("Error: cannot open file %s\n", file);
		return (-1);
	}
	return (0);
}

t_list	*parse(int fd)
{
	t_list	*list;
	char	*line;
	char	*str;
	char	**tab;

	list = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		str = ft_strtrim(line, " \n");
		free(line);
		tab = ft_split(str, ' ');
		free(str);
		if (rt_error(tab) == -1)
		{
			ft_printf("Error: file is not compatible\n");
			freetab(tab);
			ft_lstclear(&list, &freelst);
			close (fd);
			return (NULL);
		}
		ft_lstadd_back(&list, ft_lstnew(tabtoobj(tab)));
	}
	close(fd);
	return (list);
}
