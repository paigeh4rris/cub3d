/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_horizontal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:01:26 by caubry            #+#    #+#             */
/*   Updated: 2022/12/29 17:48:02 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ray_up(t_ray *ray, float a_tan, t_player *player)
{
	ray->ry = (((int)player->py / 32) * 32) - 0.0001;
	ray->rx = (player->py - ray->ry) * a_tan + player->px;
	ray->yo = -32;
	ray->xo = -(ray->yo) * a_tan;
}

void	ray_down(t_ray *ray, float a_tan, t_player *player)
{
	ray->ry = (((int)player->py / 32) * 32) + 32;
	ray->rx = (player->py - ray->ry) * a_tan + player->px;
	ray->yo = 32;
	ray->xo = -(ray->yo) * a_tan;
}

int	ray_horizontal(t_ray *ray, t_map *map, t_player *player)
{
	int	dof;

	ray->ry = player->py;
	ray->rx = player->px;
	dof = map->size[0];
	return (dof);
}

int	boucle_dof_horizontal(t_ray *ray, int dof, t_data *data)
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

void	check_horizontal(t_ray *ray, t_data *data, float rayon)
{
	int			dof;
	float		a_tan;
	t_player	*player;
	float		delta_x;
	float		delta_y;

	dof = 0;
	a_tan = -1 / tan(rayon);
	player = data->player;
	if (rayon > PI)
		ray_up(ray, a_tan, data->player);
	else if (rayon < PI && rayon != 0)
		ray_down(ray, a_tan, data->player);
	else if (rayon == PI || rayon == 0)
		dof = ray_horizontal(ray, data->map, player);
	while (dof < data->map->size[0])
		dof = boucle_dof_horizontal(ray, dof, data);
	ray->hx = ray->rx;
	ray->hy = ray->ry;
	delta_x = (ray->rx - player->px) * (ray->rx - player->px);
	delta_y = (ray->ry - player->py) * (ray->ry - player->py);
	ray->disthorizontal = sqrt(delta_x + delta_y);
}
