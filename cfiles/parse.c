/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:56:52 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/13 18:11:48 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_list	*parse(char *file)
{
	t_list	*list;
	int		fd;
	char	*line;
	char	*str;
	char	**tab;

	list = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		str = ft_strtrim(line, " \n");
		free(line);
		tab = ft_split(str, ' ');
		free(str);
		ft_lstadd_back(&list, ft_lstnew(tabtoobj(tab)));
	}
	//if (error(list) == -1)
	//	return (NULL);
	close(fd);
	return (list);
}
