/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:55:46 by bbauer            #+#    #+#             */
/*   Updated: 2017/01/09 21:37:32 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1024

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct						s_file_info
{
	int								fd;
	char							*current_line;
	char							*file;
	struct s_file_info				*next;
}									t_file_info;

int									get_next_line(int const fd, char **line);

#endif
