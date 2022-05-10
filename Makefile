SHELL = /bin/zsh

NAME	= 	cub3d


SRCS_DIR	=	srcs
SRCS_FILES	= 	\
				cub3d.c \
				parse/identifiers/resolution.c \
				parse/identifiers/ident_parse.c \
				parse/identifiers/texture.c \
				parse/map/map.c \
				parse/map/symbol_check.c \
				parse/map/tmp_map.c \
				parse/map/player.c \
				parse/file_parse.c \
				parse/valid_input.c \
				screen/raycasting.c \
				screen/screen.c \
				screen/texturisation.c \
				screen/mini_map.c \
				utils/move.c \
				utils/turn.c \
				utils/err_exit.c \
				utils/init_struct.c \
				utils/bmp.c \
				utils/manage.c \
				screen/draw_sprite.c \
				screen/ray_walls.c \
	


SRCS 	=	$(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS	= 	$(SRCS:%.c=%.o)

# INC		= -I ./include -I ./libft -I ./mlx

INCLUDES_DIR 	=	./includes
LIBFT_DIR		=	./libft
LIBFT_INC_DIR	=	$(LIBFT_DIR)/includes


# MLX for Linux && Darwin
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLX = libmlx.a
	MLX_DIR = minilibx-linux
	FLAGS_LIB += -lX11 -lXext -lm
endif
ifeq ($(UNAME_S),Darwin)
	UNAME_R := $(shell uname -r | cut -d. -f1)
	VER := $(shell test $(UNAME_R) -ge 17 && echo 'new' || echo 'old')
	ifeq ($(VER),new)
		MLX = libmlx.dylib
		MLX_DIR = minilibx_mms_20191025_beta
	endif
	ifeq ($(VER),old)
		MLX = libmlx.a
		MLX_DIR = ./mlx
		FLAGS_LIB += -framework OpenGL -framework AppKit
	endif
endif



FLAGS_ERRORS	=	-Wall -Werror -Wextra
FLAGS_INCLUDES	=	-I$(INCLUDES_DIR) -I$(LIBFT_INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)
FLAGS_OPTI		=	-O2 -funroll-loops
FLAGS_DEBUG		=	-g #-fsanitize=address
FLAGS_LIB		+=	-L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx


FLAGS_FINAL		=	$(FLAGS_ERRORS)  \
					$(FLAGS_INCLUDES) $(FLAGS_DEBUG)
					
# MLX		=	-L ./mlx -lmlx -framework OpenGL -framework AppKit

.PHONY: all compile_libs clean fclean re

all :	$(NAME)

compile_libs:
	@$(MAKE) -s -C $(LIBFT_DIR)
	@$(MAKE) -s -C $(MLX_DIR)

%.o: %.c
	gcc $(FLAGS_FINAL) -c -o $@ $<

$(NAME): compile_libs  $(OBJS) 
	gcc $(OBJS) -o $(NAME) $(FLAGS_LIB)

flags:
	@echo $(FLAGS_FINAL) 
	@echo "********"
	@echo $(FLAGS_LIB)
	@echo "OBJS $(OBJS)"
	@echo "SRCS $(SRCS)"


clean:
	$(RM) -rf $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all