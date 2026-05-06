/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:06:23 by caubry            #+#    #+#             */
/*   Updated: 2022/12/29 17:50:08 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	is_wall(t_data *data)
{
	t_map		*map;
	t_player	*player;
	int			x;
	int			y;

	player = data->player;
	map = data->map;
	x = player->px / 32;
	y = player->py / 32;
	if (map->init_map[y][x] == '1')
		return (true);
	return (false);
}

void	ft_left(t_data *data)
{
	t_player	*player;

	player = data->player;
	player->px += cos(player->angle - PI / 2) * 5;
	player->py += sin(player->angle - PI / 2) * 5;
	if (is_wall(data))
	{
		player->px -= cos(player->angle - PI / 2) * 5;
		player->py -= sin(player->angle - PI / 2) * 5;
	}
}

void	ft_right(t_data *data)
{
	t_player	*player;

	player = data->player;
	player->px += cos(player->angle + PI / 2) * 5;
	player->py += sin(player->angle + PI / 2) * 5;
	if (is_wall(data))
	{
		player->px -= cos(player->angle + PI / 2) * 5;
		player->py -= sin(player->angle + PI / 2) * 5;
	}
}

void	ft_up(t_data *data)
{
	t_player	*player;

	player = data->player;
	player->px += player->delx;
	player->py += player->dely;
	if (is_wall(data))
	{
		player->px -= player->delx;
		player->py -= player->dely;
	}
}

void	ft_down(t_data *data)
{
	t_player	*player;

	player = data->player;
	player->px -= player->delx;
	player->py -= player->dely;
	if (is_wall(data))
	{
		player->px += player->delx;
		player->py += player->dely;
	}
}
