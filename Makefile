CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = cub3D
NAME_BONUS = cub3D_bonus


SRC =	srcs/main.c\
		srcs/parsing/parsing.c\
		srcs/parsing/parsing_utils.c\
		srcs/parsing/check_texture.c\
		srcs/parsing/check_color.c\
		srcs/parsing/check_map_valid.c\
		srcs/parsing/check_map_closed.c\
		srcs/libft/printf/ft_printf.c\
		srcs/libft/printf/ft_printf_utils.c\
		srcs/libft/get_next_line.c\
		srcs/libft/isdigit.c\
		srcs/libft/split.c\
		srcs/libft/strchr.c\
		srcs/libft/strcmp.c\
		srcs/libft/strdup.c\
		srcs/libft/strjoin.c\
		srcs/libft/strlen.c\
		srcs/libft/strtrim.c\
		srcs/libft/ft_strcpy.c\
		srcs/utils.c\
		srcs/raycasting/raycasting.c\
		srcs/raycasting/player.c\
		srcs/raycasting/mouv_camera.c\
		srcs/raycasting/mouv_player.c\
		srcs/raycasting/check_horizontal.c\
		srcs/raycasting/check_vertical.c\
		srcs/raycasting/map_3d.c\
		srcs/raycasting/draw_map_utils.c\
		srcs/raycasting/init.c\

SRC_BONUS = srcs/main_bonus.c\
			srcs/parsing/parsing.c\
			srcs/parsing/parsing_utils.c\
			srcs/parsing/check_texture.c\
			srcs/parsing/check_color.c\
			srcs/parsing/check_map_valid.c\
			srcs/parsing/check_map_closed.c\
			srcs/libft/printf/ft_printf.c\
			srcs/libft/printf/ft_printf_utils.c\
			srcs/libft/get_next_line.c\
			srcs/libft/isdigit.c\
			srcs/libft/split.c\
			srcs/libft/strchr.c\
			srcs/libft/strcmp.c\
			srcs/libft/strdup.c\
			srcs/libft/strjoin.c\
			srcs/libft/strlen.c\
			srcs/libft/strtrim.c\
			srcs/libft/ft_strcpy.c\
			srcs/utils.c\
			srcs/raycasting/raycasting.c\
			srcs/raycasting/player_bonus.c\
			srcs/raycasting/mouv_camera.c\
			srcs/raycasting/mouv_player.c\
			srcs/raycasting/check_horizontal.c\
			srcs/raycasting/check_vertical.c\
			srcs/raycasting/map_3d.c\
			srcs/raycasting/draw_map_utils.c\
			srcs/raycasting/init.c\
			srcs/raycasting/minimap.c\
			srcs/raycasting/minimap_utils.c\


OBJ = ${SRC:.c=.o}

BONUS_OBJ = $(SRC_BONUS:.c=.o)

FT		= ./libft2/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft2
FT_LNK	= -L ./libft2 -l ft

all: lib $(NAME)

$(NAME): ${OBJ}
	$(CC) $(OBJ) $(FT_LNK) -Lmlx_linux -L/usr/lib -Imlx_linux -lmlx_Linux -lXext -lX11 -lm -lz -o $(NAME)

${NAME_BONUS} : ${BONUS_OBJ}
	$(CC) $(BONUS_OBJ) $(FT_LNK) -Lmlx_linux -L/usr/lib -Imlx_linux -lmlx_Linux -lXext -lX11 -lm -lz -o $(NAME_BONUS)

bonus : lib ${NAME_BONUS}

.c.o:
	${CC} ${CFLAGS} -I/usr/include -Imlx_linux -c $< -o $@

lib:
	make -C $(FT)
	make -C mlx_linux

clean:
	rm -f ${OBJ}
	rm -f ${BONUS_OBJ}
	make clean -C $(FT)

fclean:	clean
	rm -f ${NAME}
	rm -f ${NAME_BONUS}
	make fclean -C $(FT)

re: fclean all
	make re -C mlx_linux

.PHONY: all clean fclean re lib bonus
