/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:18:47 by cmeston           #+#    #+#             */
/*   Updated: 2022/12/30 15:49:45 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	init_player(t_player *player, t_map *map)
{
	player->angle = map->angle;
	player->px = map->player_pos[1] * 32 + (32 / 2);
	player->py = map->player_pos[0] * 32 + (32 / 2);
	map->init_map[map->player_pos[0]][map->player_pos[1]] = '0';
	player->delx = cos(player->angle) * 5;
	player->dely = sin(player->angle) * 5;
	player->key[0].keysym = XK_a;
	player->key[0].ptr = &ft_left;
	player->key[1].keysym = XK_d;
	player->key[1].ptr = &ft_right;
	player->key[2].keysym = XK_w;
	player->key[2].ptr = &ft_up;
	player->key[3].keysym = XK_s;
	player->key[3].ptr = &ft_down;
	player->key[4].keysym = XK_Left;
	player->key[4].ptr = &ft_cam_left;
	player->key[5].keysym = XK_Right;
	player->key[5].ptr = &ft_cam_right;
	return (0);
}

int	closewin(t_data *data)
{
	int	i;

	i = 0;
	if (data->win)
	{
		mlx_destroy_window(data->mlx_id, data->win);
		data->win = NULL;
	}
	if (data->img)
		mlx_destroy_image(data->mlx_id, data->img);
	if (data->map->init_map)
		ft_free(data->map->init_map);
	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(data->mlx_id, data->textures[i].img);
		free(data->map->texture[i]);
		i++;
	}
	if (data->mlx_id)
	{
		mlx_destroy_display(data->mlx_id);
		free(data->mlx_id);
	}
	exit(0);
}

int	ft_kinput(int keysym, t_data *data)
{
	int	i;

	i = 0;
	if (keysym == XK_Escape)
		closewin(data);
	else
	{
		while (i < 6)
		{
			if (keysym == data->player->key[i].keysym)
			{
				data->player->key[i].ptr(data);
				break ;
			}
			i++;
		}
		if (data->img)
			mlx_destroy_image(data->mlx_id, data->img);
		data->img = mlx_new_image(data->mlx_id, data->screen_x, data->screen_y);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
				&data->line_length, &data->endian);
		print_ray3d(data, data->player);
		mlx_put_image_to_window(data->mlx_id, data->win, data->img, 0, 0);
	}
	return (0);
}
