/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:06:54 by caubry            #+#    #+#             */
/*   Updated: 2022/12/12 11:39:38 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_cam_left(t_data *data)
{
	t_player	*player;

	player = data->player;
	player->angle -= 0.1;
	if (player->angle < 0)
		player->angle += 2 * PI;
	player->delx = cos(player->angle) * 5;
	player->dely = sin(player->angle) * 5;
}

void	ft_cam_right(t_data *data)
{
	t_player	*player;

	player = data->player;
	player->angle += 0.1;
	if (player->angle > 2 * PI)
		player->angle -= 2 * PI;
	player->delx = cos(player->angle) * 5;
	player->dely = sin(player->angle) * 5;
}
