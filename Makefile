NAME= miniRT
SRC= main.c parse.c close.c utils.c tabtoobj.c tabtoform.c free.c free2.c
SRCPATH= ./cfiles/
OBJ= $(SRC:.c=.o)
OBJS= $(addprefix $(OBJPATH), $(OBJ))
SRCS= $(addprefix $(SRCPATH), $(SRC))
OBJPATH= ./ofiles/

CC= gcc -Wall -Wextra -Werror

all: makelib $(NAME)

makelib:
	make -C ./libft
	make -C ./minilibx-linux

$(OBJPATH)%.o: $(SRCPATH)%.c
	mkdir -p $(OBJPATH)
	$(CC) -I./hfiles -I./libft -I./minilibx-linux -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -Llibft -lft -Lminilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz -I./libft2 -I./minilibx_linux -I./hfiles

clean:
	rm -f $(OBJS)
	make clean -C ./libft
	make clean -C ./minilibx-linux

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all
