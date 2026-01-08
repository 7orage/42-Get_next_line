/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:26:36 by lheteau           #+#    #+#             */
/*   Updated: 2026/01/08 15:40:31 by lheteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = fill_line(fd, &stash, buffer);
	free(buffer);
	return (line);
}

static int	read_and_stash(int fd, char **stash, char *buff)
{
	char	*tmp;
	int		b_read;

	b_read = 1;
	while (b_read > 0 && !ft_strchr(*stash, '\n'))
	{
		b_read = read(fd, buff, BUFFER_SIZE);
		if (b_read <= 0)
			return (b_read);
		buff[b_read] = '\0';
		tmp = *stash;
		*stash = ft_strjoin(tmp, buff);
		free(tmp);
	}
	return (b_read);
}

static void	free_tmp(char **stash)
{
	char	*tmp;

	tmp = *stash;
	*stash = ft_strdup(ft_strchr(tmp, '\n'));
	free(tmp);
	return ;
}

static char	*extract_line(char **stash)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!stash || !*stash)
		return (NULL);
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] == '\n')
	{
		line = ft_substr(*stash, 0, i + 1);
		free_tmp(stash);
		return (line);
	}
	if (**stash == '\0')
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	line = ft_substr(*stash, 0, ft_strlen(*stash));
	free(*stash);
	*stash = NULL;
	return (line);
}

char	*fill_line(int fd, char **stash, char *buff)
{
	if (!*stash)
		*stash = ft_strdup("");
	if (read_and_stash(fd, stash, buff) < 0)
		return (NULL);
	return (extract_line(stash));
}

/*Ce que fait chaque partie (ultra résumé)

read_and_stash
→ lit le fichier et remplit stash jusqu’à \n ou EOF

extract_line
→ extrait la ligne à retourner et met à jour stash

fill_line
→ fonction orchestratrice, courte et normée*/

/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("1char.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("1line : %s\n", line);
	free(line);

	line = get_next_line(fd);
	printf("2line : %s\n", line);
	free(line);

	line = get_next_line(fd);
	printf("3line : %s\n", line);
	free(line);
}*/