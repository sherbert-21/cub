SHELL = /bin/zsh

NAME	= 	cub3d

SRC		= 	\
			src/main/cub3d.c \
            src/parce/identifiers/ident_parce.c \
            src/parce/identifiers/resolution.c \
            src/parce/identifiers/texture.c \
            src/parce/map/map.c \
            src/parce/map/symbol_check.c \
            src/parce/map/tmp_map.c \
            src/parce/map/player.c \
            src/parce/file_parce.c \
            src/parce/valid_input.c \
            src/screen/raycasting.c \
            src/screen/screen.c \
            src/screen/texturisation.c \
            src/screen/mini_map.c \
            src/utils/move.c \
            src/utils/turn.c \
            src/screen/draw_sprite.c \
            src/screen/ray_walls.c \
            src/utils/err_exit.c \
            src/utils/init_struct.c \
            src/utils/bmp.c \
	        src/utils/manage.c \

OBJ		= 	$(SRC:.c=.o)

# INC		= -I ./include -I ./libft -I ./mlx

INCLUDES_DIR 	=	./includes/
LIBFT_DIR		=	./libft/

# MLX for Linux && Darwin
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLX = libmlx.a
	MLX_DIR = ./minilibx-linux
	FLAGS_LIB += -lX11 -lXext -lm
endif
ifeq ($(UNAME_S),Darwin)
	UNAME_R := $(shell uname -r | cut -d. -f1)
	VER := $(shell test $(UNAME_R) -ge 17 && echo 'new' || echo 'old')
	ifeq ($(VER),new)
		MLX = libmlx.dylib
		MLX_DIR = ./minilibx_mms_20191025_beta
	endif
	ifeq ($(VER),old)
		MLX = libmlx.a
		MLX_DIR = ./minilibx_macos
		FLAGS_LIB += -framework OpenGL -framework AppKit
	endif
endif


FLAGS_ERRORS	=	-Wall -Werror -Wextra
FLAGS_INCLUDES	=	-I$(INCLUDES_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)
FLAGS_OPTI		=	-O2 -funroll-loops
FLAGS_DEBUG		=	-g -fsanitize=address
FLAGS_LIB		=	-L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx


FLAGS_FINAL		=	$(FLAGS_ERRORS) $(FLAGS_INCLUDES) \
					$(FLAGS_OPTI) $(FLAGS_DEBUG) $(FLAGS_LIB)



# MLX		=	-L ./mlx -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

lft:
	echo $(FLAGS_FINAL)
	$(MAKE) -s -C $(LIBFT_DIR)
	$(MAKE) -s -C $(MLX_DIR)

$(NAME): $(OBJ) lft
	echo $(FLAGS_FINAL)
	gcc $(FLAGS_FINAL) $(OBJ) -o $(NAME)

clean:
	$(RM) -rf $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all