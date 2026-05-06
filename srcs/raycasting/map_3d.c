/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:25:38 by caubry            #+#    #+#             */
/*   Updated: 2022/12/29 17:48:39 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	resize_ray_to_window(t_ray *ray, t_data *data, float rayon)
{
	float	ca;

	ca = data->player->angle - rayon;
	if (ca < 0)
		ca += 2 * PI;
	if (ca > 2 * PI)
		ca -= 2 * PI;
	ray->distance = ray->distance * cos(ca);
	ray->line_height = ((data->map->size[0] * data->map->size[1] * 32)
			/ ray->distance) * (data->screen_x / (data->map->size[1] * 32));
	ray->delta_y = 32 / (float)ray->line_height;
	ray->ty_off = 0;
	if (ray->line_height > data->screen_y)
	{
		ray->ty_off = (ray->line_height - data->screen_y) / 2;
		ray->line_height = data->screen_y;
	}
	ray->line_offset = ((data->screen_y - ray->line_height) / 2);
}

t_textures	*choose_texture(t_data *data, int r, int wall)
{
	float	angle;
	float	a_rayon;
	int		nb_r;

	angle = data->player->angle;
	nb_r = data->screen_x;
	if (r > data->screen_x / 2)
		a_rayon = (-1 * (nb_r / 2 - r)) * (RAD / (data->screen_x / 60));
	else
		a_rayon = (1 * (r - nb_r / 2)) * (RAD / (data->screen_x / 60));
	angle = maj_angle(angle, a_rayon);
	if (!wall)
	{
		if (angle >= PI / 2 && angle <= 3 * PI / 2)
			return (&data->textures[3]);
		else
			return (&data->textures[2]);
	}
	else
	{
		if (angle >= PI)
			return (&data->textures[0]);
		else
			return (&data->textures[1]);
	}
}

void	print_wall(t_data *data, t_ray *ray, int r)
{
	int				y;
	float			testy;
	unsigned int	*toput;
	float			delta;
	t_textures		*texture;

	y = 0;
	testy = ray->ty_off * ray->delta_y;
	if (ray->distvertical < ray->disthorizontal)
	{
		delta = (int)ray->wall[1] % 32;
		texture = choose_texture(data, r, 0);
	}
	else
	{
		delta = (int)ray->wall[0] % 32;
		texture = choose_texture(data, r, 2);
	}
	while (y < ray->line_height)
	{
		toput = pixel_put_texture(texture, (int)(delta), (int)(testy));
		my_mlx_pixel_put(data, r, ray->line_offset + y, *toput);
		testy += ray->delta_y;
		y++;
	}
}

void	draw_3d(t_ray *ray, t_data *data, int r, int nb_r)
{
	t_draw	param;

	param.height = ray->line_offset;
	param.x = r;
	print_wall(data, ray, r);
	param.y = 0;
	param.width = data->screen_x / nb_r;
	param.color = convert_color(data->map->color_ceiling);
	draw_rect(param, data);
	param.y = param.height + ray->line_height;
	param.width = data->screen_x / nb_r;
	param.color = convert_color(data->map->color_floor);
	draw_rect(param, data);
}

unsigned int	*pixel_put_texture(t_textures *texture, int x, int y)
{
	char	*dst;

	dst = texture->addr
		+ (y * texture->line_length + x * (texture->bits_per_pixel / 8));
	return ((unsigned int *)dst);
}
