/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeston <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:47:10 by cmeston           #+#    #+#             */
/*   Updated: 2022/12/30 14:47:21 by cmeston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	mm_draw_rect(t_draw *param, t_textures *texture)
{
	int	i;
	int	j;

	i = 0;
	while (i < param->width)
	{
		j = 0;
		while (j < param->height)
		{
			*(pixel_put_texture(texture, param->x + i, param->y + j))
				= param->color;
			j++;
		}
		i++;
	}
	return (0);
}

int	draw_player(t_draw *param, t_textures *texture)
{
	int	i;
	int	j;

	i = 0;
	while (i < param->width)
	{
		j = 0;
		while (j < param->height)
		{
			*(pixel_put_texture(texture, param->x - 2 + i, param->y - 2 + j))
				= param->color;
			j++;
		}
		i++;
	}
	return (0);
}

void	draw_line(t_draw line, t_textures *data, int color)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixel_x;
	double	pixel_y;

	delta_x = line.width - line.x;
	delta_y = line.height - line.y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = line.x;
	pixel_y = line.y;
	while (pixels)
	{	
		*(pixel_put_texture(data, pixel_x, pixel_y)) = color;
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
}
