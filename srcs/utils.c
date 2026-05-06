/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:31:24 by cmeston           #+#    #+#             */
/*   Updated: 2022/12/29 18:26:22 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		while (str[i] == to_find[j])
		{
			i++;
			j++;
			if (to_find[j] == '\0')
				return (&str[i - j]);
		}
		i -= j;
		j = 0;
		i++;
	}
	return (0);
}

void	ft_error(char *name, char *error, int ex, t_data *data)
{
	write(2, "Error\n ", 6);
	write(2, name, __strlen(name));
	write(2, ": ", 2);
	write(2, error, __strlen(error));
	write(2, "\n", 1);
	(void)data;
	if (ex)
	{
		exit(EXIT_FAILURE);
	}
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	ft_printf("north texture = %s\n", map->texture[0]);
	ft_printf("south texture = %s\n", map->texture[1]);
	ft_printf("west texture = %s\n", map->texture[2]);
	ft_printf("east texture = %s\n", map->texture[3]);
	ft_printf("color floor = %d,%d,%d\n", map->color_floor[0],
		map->color_floor[1], map->color_floor[2]);
	ft_printf("color ceiling = %d,%d,%d\n", map->color_ceiling[0],
		map->color_ceiling[1], map->color_ceiling[2]);
	ft_printf("map width = %d\n", map->size[0]);
	ft_printf("map height = %d\n", map->size[1]);
	while (map && map->init_map && map->init_map[i])
	{
		ft_printf("%s\n", map->init_map[i]);
		i++;
	}
}

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab[i]);
	tab[i] = NULL;
	free(tab);
	tab = NULL;
}

char	*strjoin(char *s1, char *s2, int i)
{
	char	*cat;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = __strlen(s1) + __strlen(s2) + 1;
	cat = malloc(sizeof(char) * len);
	if (cat == NULL)
		return (NULL);
	ft_strcpy(cat, s1);
	ft_strcpy(cat + __strlen(s1), s2);
	if (i == 1)
		free(s1);
	return (cat);
}
