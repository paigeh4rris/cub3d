/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeston <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:45:46 by cmeston           #+#    #+#             */
/*   Updated: 2022/12/30 14:45:54 by cmeston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	create_minimap_img(t_map *map, t_player *player, t_data *data)
{
	int		x;
	int		y;

	data->mm[0].img = mlx_new_image(data->mlx_id, map->size[0], map->size[1]);
	if (data->mm[0].img == NULL)
		return ;
	data->mm[0].addr = mlx_get_data_addr(data->mm->img,
			&data->mm[0].bits_per_pixel, &data->mm[0].line_length,
			&data->mm[0].endian);
	x = 0;
	while (x < map->size[1])
	{
		y = 0;
		while (y < map->size[0])
		{
			if (map->init_map[x][y] == '1')
				*(pixel_put_texture(&data->mm[0], y * 1, x * 1)) = 0x00ABCDEF;
			else if (map->init_map[x][y] == '0')
				*(pixel_put_texture(&data->mm[0], y * 1, x * 1)) = 0;
			y++;
		}
		x++;
	}
	draw_2d_map(map, player, data);
}

void	draw_mm(t_textures *mm, t_draw *param, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->map->size[0])
	{
		while (y < data->map->size[1])
		{
			param->color = *(unsigned int *)(mm[0].addr
					+ (y * mm[0].line_length + x * (mm[0].bits_per_pixel / 8)));
			mm_draw_rect(param, &mm[1]);
			y++;
			param->y += 4;
		}
		y = 0;
		param->y = 0;
		x++;
		param->x += 4;
	}
}

void	create_mm_img_addr(t_map *map, t_textures *mm, t_data *data)
{
	int	x;
	int	y;

	x = data->screen_x;
	y = data->screen_y;
	x = x / 5 * 5;
	y = y / 5 * 5;
	(void)map;
	if (x > data->screen_x || y > data->screen_y)
		ft_error("Map", "map too big", 1, data);
	mm->img = mlx_new_image(data->mlx_id, x, y);
	mm->addr = mlx_get_data_addr(mm->img, &mm->bits_per_pixel, &mm->line_length,
			&mm->endian);
}

void	init_mm_params(t_draw *param)
{
	param->x = 0;
	param->y = 0;
	param->height = 5;
	param->width = 5;
}

void	draw_2d_map(t_map *map, t_player *player, t_data *data)
{
	t_draw	param;
	t_draw	line;

	create_mm_img_addr(map, &data->mm[1], data);
	init_mm_params(&param);
	draw_mm(data->mm, &param, data);
	param.x = player->px / 32 * 4 - 2;
	param.y = player->py / 32 * 4 - 2;
	if ((int)param.x < 2)
		param.x = 2;
	if ((int)param.y < 2)
		param.y = 2;
	param.color = 0xFFFFFF;
	param.height = 4;
	param.width = 4;
	mm_draw_rect(&param, &data->mm[1]);
	line.x = param.x + 2;
	line.y = param.y + 2;
	line.width = (param.x + 2 + player->delx * 1);
	line.height = (param.y + 2 + player->dely * 1);
	draw_line(line, &data->mm[1], 2552550);
	mlx_put_image_to_window(data->mlx_id, data->win, data->mm[1].img,
		data->screen_x - map->size[0] * 4 + 1 - 5, data->screen_y
		- map->size[1] * 4 + 1 - 5);
}
