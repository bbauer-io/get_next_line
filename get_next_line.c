/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:55:06 by bbauer            #+#    #+#             */
/*   Updated: 2017/01/03 15:20:53 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_file_info		*find_fd_in_list(int const fd, t_file_info *list)
{
	if (list)
		while (list->fd != fd && list->next)
			list = list->next;
	if (!list || (!list->next && fd != list->fd))
	{
		if (NULL == (list = (t_file_info *)malloc(sizeof(t_file_info))))
			return (NULL);
		list->fd = fd;
		list->file = NULL;
		list->current_line = NULL;
		list->next = NULL;
	}
	return (list);
}

void			null_termination_check(t_file_info *li, int ret)
{
	if (li->file[ret - 1] != '\0')
	{
		ft_realloc(li->file, ret, 1);
		li->file[ret] = '\0';
	}
	return ;
}

void			read_file(int const fd, t_file_info *li)
{
	int		ret;
	char	buffer[BUFF_SIZE + 1];

	ret = 1;
	while (ret)
	{
		if (-1 == (ret = read(fd, buffer, BUFF_SIZE)))
			return ;
		buffer[ret] = '\0';
		if (!li->file)
		{
			li->file = (char *)malloc(sizeof(char) * (ret + 1));
			ft_strcpy(li->file, buffer);
			li->file[ret] = '\0';
		}
		else if (ret)
		{
			li->file = ft_realloc(li->file, ft_strlen(li->file) + 1, ret);
			ft_strcat(li->file, buffer);
		}
		li->current_line = li->file;
	}
	null_termination_check(li, ret);
	return ;
}

int				get_next_line(int const fd, char **line)
{
	static t_file_info		*list; // points to  beginning of list.
	t_file_info				*li;   // points to relevant list item.

	if (NULL == (li = find_fd_in_list(fd, list)))
		return (-1);
	if (!list)
		list = li;
	if (!line || fd < 0)           // check for valid parameters.
		return (-1);
	if (!(li->file))                 // check if fd has been read yet.
		read_file(fd, li);
	if (li->current_line == NULL || *li->current_line == '\0')   // strchr returns NULL after final line read
		return (0);
	*line = ft_strndup(li->current_line, ft_wrdlen(li->current_line, '\n'));
	li->current_line = ft_strchr(li->current_line, '\n');
	while (li->current_line && *li->current_line == '\n') // skip over consecutive or trailing '\n' chars
		li->current_line++;
	return (1);
}
