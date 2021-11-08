# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/08 15:04:33 by jisokang          #+#    #+#              #
#    Updated: 2021/11/01 23:39:43 by jisokang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
NAME_BONUS	= so_long_bonus

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
AR			= ar rcs
RM			= rm -f

INCS_DIR	= ./include/
SRCS_DIR	= ./src/
LIB_DIR		= ./lib/
MLX_DIR		= ./mlx/

INCS_BONUS_DIR	= ./include_bonus/
SRCS_BONUS_DIR	= ./src_bonus/

LIB_NAME	= ./lib/lib_jisokang.a
INCS		= -I include
MLX_FLAGS	= -L./mlx -lmlx -framework OpenGL -framework Appkit

SRC		=	main.c collec.c ft_mlx.c error.c key.c init_game.c reset_game.c \
			map_check_ext.c map_compo_coord.c map_parse.c map_read.c map_draw.c \
			move_collision.c move_dir.c move_init.c move_spin.c util_lst.c \
			img_init.c draw_sprites.c player_draw.c step_count.c \
			enemy_draw.c enemy_script.c draw_scene.c \
			event.c \

SRC_BONUS	=	main_bonus.c collec_bonus.c ft_mlx_bonus.c error_bonus.c key_bonus.c init_game_bonus.c reset_game_bonus.c \
			map_check_ext_bonus.c map_compo_coord_bonus.c map_parse_bonus.c map_read_bonus.c map_draw_bonus.c \
			move_collision_bonus.c move_dir_bonus.c move_init_bonus.c move_spin_bonus.c util_lst_bonus.c \
			img_init_bonus.c draw_sprites_bonus.c player_draw_bonus.c step_count_bonus.c \
			enemy_draw_bonus.c enemy_script_bonus.c draw_scene_bonus.c \
			event_bonus.c \

SRCS		=	$(addprefix $(SRCS_DIR), $(SRC))
LIBS		=	$(addprefix $(LIB_DIR), $(LIB_NAME))
OBJS		=	$(SRCS:.c=.o)

SRCS_BONUS	=	$(addprefix $(SRCS_BONUS_DIR), $(SRC_BONUS))
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)


.c.o :
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $?

$(NAME) : $(OBJS)
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)
	$(CC) -o $(NAME) $(OBJS) -L $(LIB_DIR) -l_jisokang -I $(INCS_DIR) -L $(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

all : $(NAME)

clean :
	make -C $(LIB_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	make -C $(LIB_DIR) fclean
	$(RM) $(NAME) $(NAME_BONUS)

re : clean all

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)
	$(CC) -o $(NAME_BONUS) $(OBJS_BONUS) -L $(LIB_DIR) -l_jisokang -I $(INCS_BONUS_DIR) -L $(MLX_DIR) -lmlx -fsanitize=address -framework OpenGL -framework Appkit

PHONY	: all clean fclean re bonus
