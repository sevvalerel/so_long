/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:29:58 by buket             #+#    #+#             */
/*   Updated: 2025/03/16 13:52:53 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_new(char *buffer);
char	*f_read(int fd, char *buffer);
size_t	ft_strlen_modif(char *x);
int		new_check(const char *s);
char	*f_swap(char *buffer);
char	*ft_strjoin_modif(char *line, char *buff);

#endif
