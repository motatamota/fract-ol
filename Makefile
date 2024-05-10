NAME		=	fract-ol
SRCS		=	main.c keymove.c mousemove.c
OBJS 		=	$(SRCS:.c=.o)
CC			=	cc
LIBX_FLAGS	=	-lmlx_Linux -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBX_FLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
