NAME		=	fract-ol
SRCS		=	main.c keymove.c mousemove.c mypixel.c color.c
FLAG		=	-Wall -Wextra -Werror
OBJS 		=	$(SRCS:.c=.o)
CC			=	cc
LIBX_FLAGS	=	-lmlx_Linux -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAG) $(OBJS) $(LIBX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) -c $(FLAG) $< -o $@ $(LIBX_FLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
