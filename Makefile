SHELL = /bin/zsh

NAME	= 	cub3d

FLAGS	= 	-Wall -Werror -Wextra -g -fsanitize=address

SRC		= 	\
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
            cub3d.c

OBJ		= 	$(SRC:.c=.o)

INC		= -I ./include -I ./libft -I ./mlx

LIB_DIR = ./libft
LIBFT	=	-L $(LIB_DIR) -lft




UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLX = libmlx.a
	MLX_DIR = ./minilibx-linux
	LDFLAGS += -lX11 -lXext -lm
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
		LDFLAGS += -framework OpenGL -framework AppKit
	endif
endif



# MLX		=	-L ./mlx -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

lft:
	@$(MAKE) -s -C $(LIB_DIR)
	@$(MAKE) -s -C $(MLX_DIR)

$(NAME): $(OBJ) lft
	gcc $(FLAGS) $(INC) $(OBJ) $(LIBFT) $(MLX_DIR)/$(MLX) -o $(NAME)

clean:
	/bin/rm -rf $(OBJ)
	make -C ./libft/ clean
	make -C ./mlx/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./libft/ fclean

re: fclean all