/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:08:11 by caubry            #+#    #+#             */
/*   Updated: 2022/12/30 15:43:56 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	check_extension(char *map)
{
	int		i;
	char	*tmp;

	i = 0;
	while (map[i])
		i++;
	tmp = map + i - 4;
	if (ft_strcmp(tmp, ".cub"))
		return (false);
	return (true);
}

bool	parsing_loop(char *tmp, int *i, t_map *map)
{
	bool	check;

	if (tmp_length(ft_strtrim(tmp, " ")) > 0 || *i > 5)
	{
		if (*i < 6)
		{
			if (is_texture_or_color(ft_strtrim(tmp, " ")) == 1)
				check = check_texture(ft_strtrim(tmp, " "), map);
			else if (is_texture_or_color(ft_strtrim(tmp, " ")) == 2)
				check = check_colors(ft_strtrim(tmp, " "), map);
			else
				return (free(tmp), false);
		}
		else
		{
			if (*i == 6 && tmp_length(ft_strtrim(tmp, " \n")) == 0)
				return (true);
			check = check_map(ft_strtrim(tmp, "\n"), map);
		}
		if (!check)
			return (free(tmp), false);
		(*i)++;
	}
	return (true);
}

int	ft_check_cub(char *arg)
{
	int		fd;
	char	*buf;

	if (!check_extension(arg))
		ft_error(arg, "wrong type", 1, NULL);
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		ft_error(arg, strerror(errno), 1, NULL);
	buf = malloc(sizeof(char) * 1);
	if (buf != NULL)
	{
		if (read(fd, buf, 1) == -1)
		{
			close(fd);
			free(buf);
			ft_error(arg, strerror(errno), 1, NULL);
		}
		close(fd);
		free(buf);
		return (0);
	}
	return (1);
}

char	*boucle_map_in_line(char *tmp, t_map *map, int *i, int fd)
{
	char	*map_in_line;

	map_in_line = NULL;
	while (tmp)
	{
		if (!parsing_loop(tmp, i, map))
		{
			clean_tmp(tmp, fd);
			if (map_in_line)
				free(map_in_line);
			return (free_textures(map), NULL);
		}
		free(tmp);
		tmp = get_next_line(fd);
		if (tmp && *i == 6)
		{
			if (map_in_line)
				free(map_in_line);
			map_in_line = ft_strdup(tmp);
		}
		else if (tmp && *i > 6)
			map_in_line = strjoin(map_in_line, tmp, 1);
	}
	return (map_in_line);
}

bool	parsing(int ac, char **av, t_map *map)
{
	int		i;
	int		fd;
	char	*tmp;
	char	*map_in_line;

	i = 0;
	if (ac != 2)
		return (false);
	if (ft_check_cub(av[1]) == 1)
		return (false);
	fd = open(av[1], O_RDONLY);
	tmp = get_next_line(fd);
	map_in_line = boucle_map_in_line(tmp, map, &i, fd);
	close(fd);
	if (!map_in_line)
		return (false);
	create_map(map, i - 6, map_in_line);
	free(map_in_line);
	if (!map_is_closed(map->init_map, map->size[1], map))
		return (ft_free(map->init_map), free_textures(map),
			ft_printf("Erreur map\n"), false);
	return (true);
}
