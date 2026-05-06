/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vertical.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:31:20 by caubry            #+#    #+#             */
/*   Updated: 2022/12/19 15:08:53 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ray_left(t_ray *ray, float n_tan, t_player *player)
{
	ray->rx = (((int)player->px / 32) * 32) - 0.0001;
	ray->ry = (player->px - ray->rx) * n_tan + player->py;
	ray->xo = -32;
	ray->yo = -(ray->xo) * n_tan;
}

void	ray_right(t_ray *ray, float n_tan, t_player *player)
{
	ray->rx = (((int)player->px / 32) * 32) + 32;
	ray->ry = (player->px - ray->rx) * n_tan + player->py;
	ray->xo = 32;
	ray->yo = -(ray->xo) * n_tan;
}

int	ray_vertical(t_ray *ray, t_map *map, t_player *player)
{
	int	dof;

	ray->ry = player->py;
	ray->rx = player->px;
	dof = map->size[0];
	return (dof);
}

int	boucle_dof_vertical(t_ray *ray, int dof, t_data *data)
{
	int	mx;
	int	my;

	mx = (int)(ray->rx) / 32;
	my = (int)(ray->ry) / 32;
	if (mx < data->map->size[0] && my < data->map->size[1]
		&& my >= 0 && mx >= 0
		&& data->map->init_map[my][mx] == '1')
		dof = data->map->size[0];
	else
	{
		ray->rx += ray->xo;
		ray->ry += ray->yo;
		dof += 1;
	}
	return (dof);
}

void	check_vertical(t_ray *ray, t_data *data, float rayon)
{
	int			dof;
	float		n_tan;
	t_player	*player;
	float		delta_x;
	float		delta_y;

	dof = 0;
	n_tan = -tan(rayon);
	player = data->player;
	if (rayon > PI / 2 && rayon < 3 * PI / 2)
		ray_left(ray, n_tan, player);
	else if (rayon < PI / 2 || rayon > 3 * PI / 2)
		ray_right(ray, n_tan, player);
	else if (rayon == PI / 2 || rayon == 3 * PI / 2)
		dof = ray_vertical(ray, data->map, player);
	while (dof < data->map->size[0])
		dof = boucle_dof_vertical(ray, dof, data);
	ray->vx = ray->rx;
	ray->vy = ray->ry;
	delta_x = (ray->rx - player->px) * (ray->rx - player->px);
	delta_y = (ray->ry - player->py) * (ray->ry - player->py);
	ray->distvertical = sqrt(delta_x + delta_y);
}
