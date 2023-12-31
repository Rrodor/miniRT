/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:56:52 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/13 15:04:00 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	opener(char *file, int *fd)
{
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
	{
		ft_printf("Error\ncannot open file %s\n", file);
		return (-1);
	}
	return (0);
}

void	*parse_error(char **tab, int fd, t_list *list)
{
	char	*line;

	while (get_next_line(fd, &line) > 0)
		free(line);
	ft_printf("Error\nfile is not compatible\n");
	freetab(tab);
	ft_lstclear(&list, freelst);
	close(fd);
	return (NULL);
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
		if (line[0] != '\n')
		{
			str = ft_strtrim(line, " \n");
			free(line);
			tab = ft_split(str, ' ');
			free(str);
			if (rt_error(tab) == -1)
				return (parse_error(tab, fd, list));
			ft_lstadd_back(&list, ft_lstnew(tabtoobj(tab)));
		}
		else
			free(line);
	}
	close(fd);
	return (list);
}
