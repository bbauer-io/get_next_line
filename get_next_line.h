/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:55:46 by bbauer            #+#    #+#             */
/*   Updated: 2016/12/13 21:07:52 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# define BUFF_SIZE 4
# define NEWLINE 10

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_file_info
{
	int				fd;
	char			*current_line;
	char			*file_content;
}					t_file_info;

int		get_next_line(int const fd, char **line);

#endif
