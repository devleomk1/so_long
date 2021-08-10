# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/08 15:04:33 by jisokang          #+#    #+#              #
#    Updated: 2021/08/09 19:58:56 by jisokang         ###   ########.fr        #
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

LIB_NAME	= ./lib/lib_jisokang.a
INCS		= -I include
MLX_FLAGS	= -L./mlx -lmlx -framework OpenGL -framework Appkit

SRC		=	main.c collec.c ft_mlx.c error.c key.c init_game.c reset_game.c \
			map_check_ext.c map_compo_coord.c map_parse.c map_read.c map_draw.c \
			move_collision.c move_dir.c move_init.c move_spin.c util_lst.c \
			img_init.c draw_sprites.c player_draw.c step_count.c \
			enemy_draw.c enemy_script.c draw_scene.c \
			event.c \

SRCS		=	$(addprefix $(SRCS_DIR), $(SRC))
LIBS		=	$(addprefix $(LIB_DIR), $(LIB_NAME))
OBJS		=	$(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $?

$(NAME) : $(OBJS)
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)
	$(CC) -o $(NAME) $(OBJS) -L $(LIB_DIR) -l_jisokang -I $(INCS_DIR) -L $(MLX_DIR) -lmlx -framework OpenGL -framework Appkit
# -g -fsanitize=address

all : $(NAME)

clean :
	make -C $(LIB_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS)

fclean : clean
	make -C $(LIB_DIR) fclean
	$(RM) $(NAME)

re : clean all

bonus : all

PHONY	: all clean fclean re bonus
