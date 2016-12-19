/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:55:06 by bbauer            #+#    #+#             */
/*   Updated: 2016/12/15 16:48:36 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_memdel(void **ap)
{
	if (!ap)
		return ;
	if (*ap)
	{
		free(*ap);
		*ap = NULL;
	}
	return ;
}

void	*ft_realloc(void *ptr, size_t size_original, size_t size_add)
{
	void	*new;

	if (!size_original && !size_add)
		size_add = 1;
	if (!(new = malloc(size_original + size_add)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(new, ptr, size_original);
		ft_memdel(&ptr);
	}
	return (new);
}

void		read_file(int fd, t_file_info *lininf)
{
	int			ret;
	char		buffer[BUFF_SIZE + 1];
	int			temp;

	ret = 1;
	while (ret)
	{
		if (-1 == (ret = read(fd, buffer, BUFF_SIZE)))
			return ;
		buffer[ret] = '\0';
		if (!lininf->file_content)
		{
			lininf->file_content = (char *)malloc(sizeof(char) * (ret + 1));
			ft_strcpy(lininf->file_content, buffer);
			lininf->file_content[ret] = '\0';
		}
		else if (ret)
		{
			temp = ft_strlen(lininf->file_content) + 1;
			lininf->file_content = ft_realloc(lininf->file_content, temp, ret);
			ft_strcat(lininf->file_content, buffer);
		}
	}
	return ;
}

/*
** Finds the next \n or \0 character.
*/

int			find_end_of_line(char *str)
{
	int		i;

	i = 1;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (i == 1 && str[i] == '\0')
		return (0); // There is no next line!
	return (i); // number of bytes to the newline
}

void		set_struct_zero(t_file_info *lininf)
{
	lininf->fd = 0;
	lininf->file_content = NULL;
	lininf->current_line = NULL;
	return ;
}

int			get_next_line(int const fd, char **line)
{
	static t_file_info		lininf;  // "Line Info"

	if (!(lininf.fd) || lininf.fd != fd)
		set_struct_zero(&lininf);
	if (!line)
		return (-1);
	read_file(fd, &lininf);
	if (!find_end_of_line(lininf.file_content))
		return (0);
	lininf.current_line = lininf.file_content;
	*line = ft_strndup(lininf.current_line, find_end_of_line(lininf.current_line));
	if (lininf.current_line)
		lininf.current_line = &lininf.current_line[find_end_of_line(lininf.current_line)];
	else
		lininf.current_line = &lininf.file_content[find_end_of_line(lininf.file_content)];
	return (1);
}
