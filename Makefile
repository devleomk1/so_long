# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/08 15:04:33 by jisokang          #+#    #+#              #
#    Updated: 2021/08/09 12:30:39 by jisokang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
AR			= ar rcs
RM			= rm -f

INCS_DIR	= ./include/
SRCS_DIR	= ./src/
LIB_DIR		= ./lib/
MLX_DIR		= ./mlx/

INCS		= -I include -I mlx
MLX_LIB		= -L mlx -l mlx -framework OpenGL -framework Appkit

SRC			=	main.c collec.c ft_mlx.c error.c key.c init_game.c reset_game.c \
				map_check_ext.c map_compo_coord.c map_parse.c map_read.c map_draw.c \
				move_collision.c move_dir.c move_init.c move_spin.c util_lst.c \
				img_init.c draw_sprites.c player_draw.c step_count.c \
				enemy_draw.c enemy_script.c draw_scene.c \
				event.c \

SRCS		= $(addprefix $(SRCS_DIR), $(OBJS))
LIBS		= $(addprefix $(LIB_DIR), $(LIB_NAME))
OBJS		= $(SRC:.c=.o)

all		: $(NAME)

$(LIB_NAME) :
	make -C $(LIB_DIR)

$(MLX)	:
	make -C $(MLX_DIR)

$(NAME)	: $(LIBS) $(MLX) $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

bonus	: $(OBJS_BONUS)

clean	:
	make clean -C $(LIB_DIR)
	make clean -C $(MLX_DIR)
	$(RM) $(SRCS)

fclean	: clean
	make fclean -C $(LIB_DIR)
	make fclean -C $(MLX_DIR)
	$(RM) $(NAME)

re		: clean all

PHONY	: all clean fclean re bonus
