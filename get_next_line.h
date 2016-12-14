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

#ifndef get_next_line
# define get_next_line
# define BUFF_SIZE 20

# include "libft.h"
# include <stdlib.h>

int		get_next_line(const int fd, char **line);

#endif
