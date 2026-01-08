/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:21:40 by lheteau           #+#    #+#             */
/*   Updated: 2026/01/08 16:52:27 by lheteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
// def of buffer size constant
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

// libraries
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
//# include <fcntl.h>
//# include <stdio.h>

// functions
char	*get_next_line(int fd);
char	*fill_line(int fd, char **stash, char *buff);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, const char *s2);
size_t	ft_strlen(const char *str);

#endif