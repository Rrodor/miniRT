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
		collision.c \
		inter.c \
		render.c \
		camera.c \
		color.c \
		color2.c \
		viewport.c \
		lighting.c \
		objcmp.c \
		rotation.c

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

rt:
	gcc -I./hfiles -I./libft -I./minilibx -o miniRT $(SRCS) $(MLXLINK) $(LIBLINK)
	./miniRT map/test4.rt

candle:
	gcc -I./hfiles -I./libft -I./minilibx -o miniRT $(SRCS) $(MLXLINK) $(LIBLINK)
	./miniRT map/candleingreenbox.rt

re: fclean all

grind:
	gcc -I./hfiles -I./libft -I./minilibx -o miniRT $(SRCS) $(MLXLINK) $(LIBLINK) -g
	valgrind --leak-check=full --show-leak-kinds=all ./miniRT map/candleingreenbox.rt
