NAME= 	miniRT

SRC= 	main.c \
		parse.c \
		close.c \
		utils.c \
		tabtoobj.c \
		tabtoform.c \
		free.c \
		free2.c \
		error.c \
		errorform.c \
		vector_utils_1.c \
		vector_utils_2.c \
		vector_utils_3.c \
		vector_utils_4.c \
		ray.c \
		inter.c \
		render.c \
		position.c \
		camera.c \
		color.c \
		viewport.c

SRCPATH= ./cfiles/
OBJ= $(SRC:.c=.o)
OBJS= $(addprefix $(OBJPATH), $(OBJ))
SRCS= $(addprefix $(SRCPATH), $(SRC))
OBJPATH= ./ofiles/

LIBFT 	= ./libft/libft.a
LIBINC 	= -I./libft
LIBLINK = -L./libft -lft

MLX		= minilibx/libmlx.a
MLXINC	= -I./minilibx
MLXLINK = -L./minilibx -lmlx -lXext -lX11 -lm

CC= gcc -Wall -Wextra -Werror

all: makelib $(NAME)

makelib:
	make -C libft
	make -C minilibx

$(OBJPATH)%.o: $(SRCPATH)%.c
	mkdir -p $(OBJPATH)
	$(CC) -I./hfiles -I./libft -I./minilibx -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(MLXLINK) $(LIBLINK)

clean:
	rm -f $(OBJS)
	make clean -C ./libft
	make clean -C ./minilibx

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all