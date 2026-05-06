/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:52:41 by caubry            #+#    #+#             */
/*   Updated: 2022/12/29 19:31:56 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef M
#  define M "0123456789abcdef"
# endif

# ifndef D
#  define D "0123456789"
# endif

# ifndef R
#  define R "0123456789ABCDEF"
# endif

# define PI 3.1415926535

# define RAD 0.0174533

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
# include <errno.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libft2/libft.h"

typedef struct s_struct
{
	char	conversion;
	int		ret;

}	t_struct;

typedef struct s_func_ptr
{
	int		keysym;
	void	(*ptr)();
}	t_func_ptr;

typedef struct s_player
{
	float		px;
	float		py;
	float		delx;
	float		dely;
	float		angle;
	t_func_ptr	key[6];
}	t_player;

typedef struct s_ray
{
	float	ry;
	float	rx;
	float	yo;
	float	xo;
	int		mx;
	int		my;
	float	hx;
	float	hy;
	float	vx;
	float	vy;
	float	disthorizontal;
	float	distvertical;
	float	distance;
	int		color;
	int		line_height;
	float	line_offset;
	int		wall[2];
	int		tmp_wall[2];
	int		new_wall;
	float	delta_y;
	float	ty_off;
}	t_ray;

typedef struct s_map
{
	int		size[2];
	char	**init_map;
	int		color_floor[4];
	int		color_ceiling[4];
	char	*texture[5];
	char	player;
	int		player_pos[2];
	float	angle;
}	t_map;

typedef struct s_textures {
	char		*path;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_textures;

typedef struct s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx_id;
	void		*win;
	int			screen_x;
	int			screen_y;
	t_textures	textures[4];
	t_map		*map;
	t_player	*player;
	t_textures	mm[2];
}	t_data;

typedef struct s_draw {
	float	x;
	float	y;
	int		width;
	int		height;
	int		color;
}	t_draw;

//   ---     MAIN     ---

void			init_map(t_map *map);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				draw_rect(t_draw param, t_data *data);
void			draw_2D_map(t_map *map, t_player *player, t_data *data);
void			test_3d(t_map *map, t_player *player, t_data *data);

// utils.c

void			print_map(t_map *map);
char			*ft_strstr(char *str, char *to_find);
void			ft_error(char *name, char *error, int ex, t_data *data);
void			ft_free(char **tab);
char			*strjoin(char *s1, char *s2, int i);

//   ---     PARSING     ---

// parsing.c

bool			check_extension(char *map);
bool			check_map(char *tmp, t_map *map);
bool			parsing_loop(char *tmp, int *i, t_map *map);
bool			parsing(int ac, char **av, t_map *map);

// check_texture.c

bool			init_textures(char *tmp, int i, t_map *map);
bool			check_texture(char	*tmp, t_map *map);
int				is_texture_or_color(char *tmp);

// check_color.c

bool			valid_color(char *tmp, int *ptr_i, int comma, int *color);
bool			init_color(char *tmp, int *color);
bool			check_colors(char *tmp, t_map *map);

// check_map_valid.c

void			config_player(t_map *config, char **map, int x, int y);
void			fill_line(char *real_map, char *tab_map, int width);
void			create_map(t_map *map, int height, char *map_in_line);
bool			check_map(char *tmp, t_map *map);

// check_map_closed.c

bool			check_over_under(char *under_over, int y);
bool			check_side(char *empty, int y);
bool			inside_map(char **map, int x, t_map *config);
bool			map_is_closed(char **map, int height, t_map *config);

// parsing_utils.c

int				tmp_length(char	*tmp);
int				line_map_length(char *tmp);
void			free_textures(t_map *map);
void			clean_tmp(char *tmp, int fd);

//   ---     EXEC     ---

// player.c

void			ft_pixel_put(t_player *player, int x, int y, int color);
int				init_player(t_player *data, t_map *map);
int				closewin(t_data *data);
int				ft_kinput(int keysym, t_data *data);
int				ft_kinput3d(int keysym, t_data *data);

// mouv_camera.c

void			ft_cam_left(t_data *data);
void			ft_cam_right(t_data *data);

// mouv_player.c

void			ft_left(t_data *data);
void			ft_right(t_data *data);
void			ft_up(t_data *data);
void			ft_down(t_data *data);

// raycasting.c

int				horizontal_rc(t_data *data, t_player *player);
void			print_ray(t_data *data, t_player *player);
void			init_ray(t_ray *ray);
float			maj_rayon(float rayon);
void			print_ray3d(t_data *data, t_player *player);

// check_horizontal.c

void			ray_up(t_ray *ray, float aTan, t_player *player);
void			ray_down(t_ray *ray, float aTan, t_player *player);
int				ray_horizontal(t_ray *ray, t_map *map, t_player *player);
int				boucle_dof_horizontal(t_ray *ray, int dof, t_data *data);
void			check_horizontal(t_ray *ray, t_data *data, float rayon);

// check_vertical.c

void			ray_left(t_ray *ray, float nTan, t_player *player);
void			ray_right(t_ray *ray, float nTan, t_player *player);
int				ray_vertical(t_ray *ray, t_map *map, t_player *player);
int				boucle_dof_vertical(t_ray *ray, int dof, t_data *data);
void			check_vertical(t_ray *ray, t_data *data, float rayon);

// map_3d.c

void			resize_ray_to_window(t_ray *ray, t_data *data, float rayon);
void			draw_3d(t_ray *ray, t_data *data, int r, int nb_r);
int				create_textures(t_textures *texture, t_data *data);
unsigned int	*pixel_put_texture(t_textures *texture, int x, int y);
t_textures		*choose_texture(t_data *data, int r, int wall);

// draw_map_utils.c

int				convert_color(int *color);
float			maj_angle(float angle, float a_rayon);
int				create_textures(t_textures *texture, t_data *data);

// init.c 

int				init_s_textures(t_textures *texture, t_map *map, t_data *data);

//minimap.c

void			create_minimap_img(t_map *map, t_player *player, t_data *data);
void			draw_2d_map(t_map *map, t_player *player, t_data *data);

//minimap_utils.c

int				draw_player(t_draw *param, t_textures *texture);
void			draw_line(t_draw line, t_textures *data, int color);
int				mm_draw_rect(t_draw *param, t_textures *texture);

//   ---     LIBFT     ---

// ft_printf.c

int				ft_printf(const char *format_str, ...);
void			__treat_format(t_struct *content, va_list argument);

// ft_printf_utils.c

void			__print_memory(void *nb, t_struct *content);
void			__putnbr(int n, t_struct *content);
void			__base(unsigned long long nb, char *base, t_struct *content);
void			__putstr(char *str, t_struct *content);
void			__putchar(char c, t_struct *content);

// get_next_line.c

int				_is_newline(char c);
char			*_get_line(char *str);
int				_is_line(char *str);
char			*_get_save(char *save);
char			*get_next_line(int fd);

// strtrim.c

int				__is_charset(char *sep, char c);
int				__calculate_str(char *str, char *sep);
char			*ft_strtrim(char const *s1, char const *set);

// split.c

char			**ft_split(char const *s, char c);

// Autres fonctions libft

int				ft_isdigit(int c);
int				ft_strcmp(char *s1, char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char *s1, char *s2);
size_t			__strlen(const char *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dest, char *src);

#endif
