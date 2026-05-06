/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:37:18 by caubry            #+#    #+#             */
/*   Updated: 2022/12/29 18:40:43 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	convert_color(int *color)
{
	return (color[0] << 16 | color[1] << 8 | color[2]);
}

float	maj_angle(float angle, float a_rayon)
{
	angle = angle + a_rayon;
	if (angle < 0)
		angle = 2 * PI + angle;
	if (angle > 2 * PI)
		angle = 0 + (angle - 2 * PI);
	return (angle);
}

int	create_textures(t_textures *texture, t_data *data)
{
	int	i;
	int	size;

	i = 0;
	size = 32;
	while (i < 4)
	{
		texture[i].img = mlx_xpm_file_to_image(data->mlx_id,
				texture[i].path, &size, &size);
		if (!texture[i].img)
			return (1);
		texture[i].addr = mlx_get_data_addr(texture[i].img,
				&texture[i].bits_per_pixel,
				&texture[i].line_length, &texture[i].endian);
		if (!texture[i].addr)
			return (1);
		i++;
	}
	return (0);
}
