/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:29:58 by buket             #+#    #+#             */
/*   Updated: 2025/03/12 16:09:43 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>
#include "libft/libft.h"

char	*get_next_line(int fd);
char	*get_new(char *buffer);
char	*f_read(int fd, char *buffer);
int		new_check(const char *s);
char	*f_swap(char *buffer);

#endif
