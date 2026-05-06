/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeston <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:24:54 by cmeston           #+#    #+#             */
/*   Updated: 2022/12/14 13:25:01 by cmeston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_mm_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		data->mm[i].path = NULL;
		data->mm[i].img = NULL;
		data->mm[i].addr = NULL;
		data->mm[i].bits_per_pixel = 0;
		data->mm[i].endian = 0;
		data->mm[i].line_length = 0;
		i++;
	}
}

int	init_s_textures(t_textures *texture, t_map *map, t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		texture[i].path = map->texture[i];
		texture[i].img = NULL;
		texture[i].addr = NULL;
		texture[i].bits_per_pixel = 0;
		texture[i].endian = 0;
		texture[i].line_length = 0;
		i++;
	}
	if (create_textures(texture, data) == 1)
		return (1);
	init_mm_textures(data);
	return (0);
}
