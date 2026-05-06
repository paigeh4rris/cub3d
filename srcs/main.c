/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:09:33 by caubry            #+#    #+#             */
/*   Updated: 2022/12/30 15:43:10 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		map->size[i] = 0;
		i++;
	}
	i = 0;
	while (i < 5)
	{
		map->texture[i] = NULL;
		i++;
	}
	map->color_floor[3] = 0;
	map->color_ceiling[3] = 0;
	map->player = '\0';
	map->init_map = NULL;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	draw_rect(t_draw param, t_data *data)
{
	int	i;
	int	j;

	if (data->win == NULL)
		return (1);
	i = 0;
	while (i < param.width)
	{
		j = 0;
		while (j < param.height)
		{
			my_mlx_pixel_put(data, param.x + i, param.y + j, param.color);
			j++;
		}
		i++;
	}
	return (0);
}

void	test_mlx(t_map *map, t_player *player)
{
	t_data	data;

	data.mlx_id = mlx_init();
	data.screen_x = 1920 * 3 / 5;
	data.screen_y = 1080 * 3 / 5;
	data.win = mlx_new_window(data.mlx_id, data.screen_x,
			data.screen_y, "Cub3D");
	if (data.win == NULL)
		return ;
	data.map = map;
	data.player = player;
	data.img = mlx_new_image(data.mlx_id, data.screen_x, data.screen_y);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	if (init_s_textures(data.textures, map, &data) == 1)
		ft_error("in test_mlx", "init_s_textures failed", 1, &data);
	print_ray3d(&data, player);
	mlx_put_image_to_window(data.mlx_id, data.win, data.img, 0, 0);
	mlx_hook(data.win, KeyPress, KeyPressMask, &ft_kinput, &data);
	mlx_hook(data.win, DestroyNotify,
		StructureNotifyMask, &closewin, &data);
	mlx_loop(data.mlx_id);
}

int	main(int ac, char **av)
{
	t_map		map;
	t_player	player;

	if (ac != 2)
		return (ft_printf("Error\nArgument requis : map uniquement\n"), 1);
	init_map(&map);
	if (!parsing(ac, av, &map))
		return (1);
	init_player(&player, &map);
	test_mlx(&map, &player);
	return (0);
}
