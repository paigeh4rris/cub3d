/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:48:16 by cmeston           #+#    #+#             */
/*   Updated: 2022/12/29 18:21:31 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	maj_rayon(float rayon)
{
	if (rayon < 0)
		rayon += 2 * PI;
	if (rayon > 2 * PI)
		rayon -= 2 * PI;
	return (rayon);
}

void	init_ray(t_ray *ray)
{
	ray->ry = 0;
	ray->rx = 0;
	ray->yo = 0;
	ray->xo = 0;
	ray->mx = 0;
	ray->my = 0;
	ray->hx = 0;
	ray->hy = 0;
	ray->vx = 0;
	ray->vy = 0;
	ray->disthorizontal = 0;
	ray->distvertical = 0;
	ray->distance = 0;
	ray->color = 0;
	ray->line_height = 0;
	ray->line_offset = 0;
	ray->tmp_wall[0] = -1;
	ray->tmp_wall[1] = -1;
	ray->wall[0] = 0;
	ray->wall[1] = 0;
	ray->delta_y = 0;
	ray->ty_off = 0;
}

void	find_smaller_ray(t_ray *ray, t_data *data, float rayon)
{
	ray->tmp_wall[0] = ray->wall[0];
	ray->tmp_wall[1] = ray->wall[1];
	check_horizontal(ray, data, rayon);
	check_vertical(ray, data, rayon);
	if (ray->distvertical < ray->disthorizontal)
	{
		ray->distance = ray->distvertical;
		ray->color = 0x04B4AE;
		ray->wall[0] = ray->vx;
		ray->wall[1] = ray->vy;
	}
	else
	{
		ray->distance = ray->disthorizontal;
		ray->color = 0x088A85;
		ray->wall[0] = ray->hx;
		ray->wall[1] = ray->hy;
	}
	if (ray->wall[0] / 32 == ray->tmp_wall[0] / 32
		&& ray->wall[1] / 32 == ray->tmp_wall[1] / 32)
		ray->new_wall = 0;
	else
		ray->new_wall = 1;
}

void	print_ray3d(t_data *data, t_player *player)
{
	float	rayon;
	int		r;
	t_ray	ray;
	int		nb_r;

	rayon = maj_rayon(player->angle - RAD
			/ (data->screen_x / 60) * (data->screen_x / 2));
	r = 0;
	init_ray(&ray);
	nb_r = data->screen_x;
	while (r < nb_r)
	{
		find_smaller_ray(&ray, data, rayon);
		resize_ray_to_window(&ray, data, rayon);
		draw_3d(&ray, data, r, nb_r);
		rayon = maj_rayon(rayon + RAD / (data->screen_x / 60));
		r++;
	}
}
