NAME	= 	cub3d

FLAGS	= 	-Wall -Werror -Wextra -g

SRC		= 	\
            src/parce/identifiers/ident_parce.c \
            src/parce/identifiers/resolution.c \
            src/parce/identifiers/texture.c \
            src/parce/map/map.c \
            src/parce/map/symbol_check.c \
            src/parce/map/tmp_map.c \
            src/parce/map/player.c \
            src/parce/map/doors_init.c \
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

INC		= -I./include -I./libft -I$(MLX_DIR)

LIBFT	=	-L ./libft -lft
MLX		=	-L$(MLX_DIR) -lmlx

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLX_DIR = ./minilibx-linux
	MLX += -lX11 -lXext -lm
endif
ifeq ($(UNAME_S),Darwin)
	UNAME_R := $(shell uname -r | cut -d. -f1)
	VER := $(shell test $(UNAME_R) -ge 17 && echo 'new' || echo 'old')
	ifeq ($(VER),new)
		MLX_DIR = ./mlx
		MLX += -framework OpenGL -framework AppKit

	endif
	ifeq ($(VER),old)
		MLX_DIR = ./mlx
		MLX += -framework OpenGL -framework AppKit
	endif
endif

all : $(NAME)

lft:
	make -C ./libft
	make -C $(MLX_DIR)

$(NAME): $(OBJ) lft
	gcc $(FLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME) $(MLX) 

clean:
	/bin/rm -rf $(OBJ)
	make -C ./libft/ clean
	make -C $(MLX_DIR) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./libft/ fclean

re: fclean all